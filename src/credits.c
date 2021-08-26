#include "global.h"
#include "palette.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "malloc.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "international_string_util.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "constants/rgb.h"
#include "trainer_pokemon_sprites.h"
#include "starter_choose.h"
#include "decompress.h"
#include "intro_credits_graphics.h"
#include "sound.h"
#include "trig.h"
#include "graphics.h"
#include "pokedex.h"
#include "event_data.h"
#include "random.h"
#include "data/credits.h"

#define COLOR_DARK_GREEN RGB(7, 11, 6)
#define COLOR_LIGHT_GREEN RGB(13, 20, 12)

#define TAG_MON_BG 1001

// Positions for the Pokémon images
enum {
    POS_LEFT,
    POS_CENTER,
    POS_RIGHT,
};

enum {
    MODE_NONE,
    MODE_BIKE_SCENE,
    MODE_SHOW_MONS,
};

#define tState data[0]

// Task data for the main Credits tasks
#define tTaskId_BgScenery  data[0] // ID for Task_BicycleBgAnimation (created by CreateBicycleBgAnimationTask)
#define tTaskId_BikeScene  data[1] // ID for Task_BikeScene
#define tTaskId_SceneryPal data[2] // ID for Task_CycleSceneryPalette
#define tTaskId_ShowMons   data[3] // ID for Task_ShowMons
#define tEndCredits        data[4]
#define tPlayerSpriteId    data[5]
#define tRivalSpriteId     data[6]
#define tSceneNum          data[7]
// data[8]-[10] are unused
#define tNextMode          data[11]
#define tTheEndDelay       data[12]
#define tCurrentMode       data[13]
#define tPrintedPage       data[14]
#define tTaskId_UpdatePage data[15]

#define NUM_MON_SLIDES 71

struct CreditsData
{
    u16 monToShow[NUM_MON_SLIDES]; // List of Pokemon species ids that will show during the credits
    u16 imgCounter; //how many mon images have been shown
    u16 nextImgPos; //if the next image spawns left/center/right
    u16 currShownMon; //index into monToShow
    u16 numMonToShow; //number of pokemon to show, always NUM_MON_SLIDES after determine function
    u16 caughtMonIds[NATIONAL_DEX_COUNT]; //temporary location to hold a condensed array of all caught pokemon
    u16 numCaughtMon; //count of filled spaces in caughtMonIds
    u16 unused[7];
};

struct CreditsEntry
{
    u8 unk; // Never read
    bool8 isTitle;
    const u8 *text;
};

static EWRAM_DATA s16 sUnkVar = 0; // Never read, only set to 0
static EWRAM_DATA u16 sSavedTaskId = 0;
EWRAM_DATA bool8 gHasHallOfFameRecords = 0;
static EWRAM_DATA bool8 sUsedSpeedUp = 0; // Never read
static EWRAM_DATA struct CreditsData *sCreditsData = {0};

static const u16 sCredits_Pal[] = INCBIN_U16("graphics/credits/credits.gbapal");
static const u32 sCreditsCopyrightEnd_Gfx[] = INCBIN_U32("graphics/credits/the_end_copyright.4bpp.lz");

static void SpriteCB_CreditsMonBg(struct Sprite *);
static void Task_WaitPaletteFade(u8);
static void Task_CreditsMain(u8);
static void Task_ReadyBikeScene(u8);
static void Task_SetBikeScene(u8);
static void Task_LoadShowMons(u8);
static void Task_ReadyShowMons(u8);
static void Task_CreditsTheEnd1(u8);
static void Task_CreditsTheEnd2(u8);
static void Task_CreditsTheEnd3(u8);
static void Task_CreditsTheEnd4(u8);
static void Task_CreditsTheEnd5(u8);
static void Task_CreditsTheEnd6(u8);
static void Task_CreditsSoftReset(u8);
static void ResetGpuAndVram(void);
static void Task_UpdatePage(u8);
static u8 CheckChangeScene(u8, u8);
static void Task_ShowMons(u8);
static void Task_CycleSceneryPalette(u8);
static void Task_BikeScene(u8);
static bool8 LoadBikeScene(u8 data, u8);
static void ResetCreditsTasks(u8);
static void LoadTheEndScreen(u16, u16, u16);
static void DrawTheEnd(u16, u16);
static void SpriteCB_Player(struct Sprite *);
static void SpriteCB_Rival(struct Sprite *);
static u8 CreateCreditsMonSprite(u16, s16, s16, u16);
static void DeterminePokemonToShow(void);

static const u8 sTheEnd_LetterMap_T[] =
{
    0,    1, 0,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
};

static const u8 sTheEnd_LetterMap_H[] =
{
    1, 0xFF, 1,
    1, 0xFF, 1,
    1, 2,    1,
    1, 0xFF, 1,
    1, 0xFF, 1,
};

static const u8 sTheEnd_LetterMap_E[] =
{
    1, 0, 0,
    1, 0xFF, 0xFF,
    1, 2,    2,
    1, 0xFF, 0xFF,
    1, 0x80, 0x80,
};

static const u8 sTheEnd_LetterMap_N[] =
{
    1, 3, 1,
    1, 4, 1,
    1, 5, 1,
    1, 0xC4, 1,
    1, 0xC3, 1,
};

static const u8 sTheEnd_LetterMap_D[] =
{
    1, 6, 7,
    1, 8, 9,
    1, 0xFF, 1,
    1, 0x88, 0x89,
    1, 0x86, 0x87,
};

static const u8 gCreditsText_EmptyString[] = _("");
static const u8 gCreditsText_Credits[] = _("Credits");
static const u8 gCreditsText_PkmnEmeraldVersion[] = _("Pokémon Emerald");
static const u8 gCreditsText_EmeraldEnhanced [] = _("Emerald Enhanced");
static const u8 gCreditsText_CreatedBy [] = _("Created by:");
static const u8 gCreditsText_Ryuhouji []= _("Ryuhouji");
static const u8 gCreditsText_Donors[] = _("Donors:");
static const u8 gCreditsText_Donorsp1[] = _("Kouta Pkbwgsc");
static const u8 gCreditsText_Donorsp2[] = _("Rascal ustaN");
static const u8 gCreditsText_Donorsp3[] = _("Rin    Nick");
static const u8 gCreditsText_Donorsp4[] = _("Vexy    Swap");
static const u8 gCreditsText_Donorsp5[] = _("Ludi    Rayan");
static const u8 gCreditsText_Donorsp6[] = _("TJ    DeltaRayQ");
static const u8 gCreditsText_Donorsp7[] = _("Vios    Johnny G");
static const u8 gCreditsText_Donorsp8[] = _("Optfine    Vexy");
static const u8 gCreditsText_Donorsp9[] = _("NjDeli    Cordigoth");
static const u8 gCreditsText_Donorsp10[] = _("Dylkill    Katara");
static const u8 gCreditsText_Donorsp11[] = _("MysticR    Vloshko");
static const u8 gCreditsText_Donorsp12[] = _("Officer12    Vexy");
static const u8 gCreditsText_Donorsp13[] = _("Galexio    Shikoi");
static const u8 gCreditsText_Donorsp14[] = _("Shinya    Maou 0");
static const u8 gCreditsText_Donorsp15[] = _("Senate    Airbud");
static const u8 gCreditsText_Donorsp16[] = _("FBGunner    JustinD1234");
static const u8 gCreditsText_Donorsp17[] = _("xBard    3ryce");
static const u8 gCreditsText_Donorsp18[] = _("Dr Squish    unodostres");
static const u8 gCreditsText_Donorsp19[] = _("Metaright    Dr");
static const u8 gCreditsText_Donorsp20[] = _("Dominaeus    Cthyla");
static const u8 gCreditsText_DevelopmentBy[] = _("Primary Developers:");

static const u8 gCreditsText_StoryboardingBy[] = _("Storyboarding by:");
static const u8 gCreditsText_Kouta[] = _("Kouta Xenova");
static const u8 gCreditsText_GraphicsBy[] = _("Custom art by:");
static const u8 gCreditsText_EEGraphics1[] = _("Rayan");
static const u8 gCreditsText_EEGraphics2[] = _("kendyvevo");
static const u8 gCreditsText_DocumentationBy[] = _("Documentation By:");
static const u8 gCreditsText_Toby[] = _("Toby");
static const u8 gCreditsText_QADirectors[] = _("QA Directors:");
static const u8 gCreditsText_Pidgey[] = _("Pidgey");
static const u8 gCreditsText_Kageru[] = _("kageru");
static const u8 gCreditsText_BaseGameCredits[] = _("");
static const u8 gCreditsText_Consultation[] = _("Consultants:");
static const u8 gCreditsText_GriffinR[] = _("GriffinR");
static const u8 gCreditsText_DizzyEggg[] = _("DizzyEggg");
static const u8 gCreditsText_ExecutiveDirector[] = _("Executive Director");
static const u8 gCreditsText_Director[] = _("Director");
static const u8 gCreditsText_ArtDirector[] = _("Art Director");
static const u8 gCreditsText_BattleDirector[] = _("Battle Director");
static const u8 gCreditsText_MainProgrammer[] = _("Main Programmer");
static const u8 gCreditsText_BattleSystemPgrms[] = _("Battle System Programmers");
static const u8 gCreditsText_FieldSystemPgrms[] = _("Field System Programmer");
static const u8 gCreditsText_Programmers[] = _("Programmers");
static const u8 gCreditsText_MainGraphicDesigner[] = _("Main Graphic Designer");
static const u8 gCreditsText_GraphicDesigners[] = _("Graphic Designers");
static const u8 gCreditsText_PkmnDesigners[] = _("Pokémon Designers");
static const u8 gCreditsText_MusicComposition[] = _("Music Composition");
static const u8 gCreditsText_SoundEffectsAndPkmnVoices[] = _("Sound Effects & Pokémon Voices");
static const u8 gCreditsText_GameDesigners[] = _("Game Designers");
static const u8 gCreditsText_ScenarioPlot[] = _("Scenario Plot");
static const u8 gCreditsText_Scenario[] = _("Scenario");
static const u8 gCreditsText_ScriptDesigners[] = _("Script Designers");
static const u8 gCreditsText_MapDesigners[] = _("Map Designers");
static const u8 gCreditsText_MapDataDesigners[] = _("Map Data Designers");
static const u8 gCreditsText_ParametricDesigners[] = _("Parametric Designers");
static const u8 gCreditsText_PokedexText[] = _("Pokédex Text");
static const u8 gCreditsText_EnvAndToolPgrms[] = _("Environment & Tool Programmers");
static const u8 gCreditsText_NCLProductTesting[] = _("NCL Product Testing");
static const u8 gCreditsText_SpecialThanks[] = _("Special Thanks");
static const u8 gCreditsText_Coordinators[] = _("Coordinators");
static const u8 gCreditsText_Producers[] = _("Producers");
static const u8 gCreditsText_ExecProducers[] = _("Executive Producers");
static const u8 gCreditsText_InfoSupervisors[] = _("Information Supervisors");
static const u8 gCreditsText_TaskManagers[] = _("Task Managers");
static const u8 gCreditsText_BrailleCodeCheck[] = _("Braille Code Check");
static const u8 gCreditsText_WorldDirector[] = _("World Director");
static const u8 gCreditsText_BattleFrontierData[] = _("Battle Frontier Data");
static const u8 gCreditsText_SupportProgrammers[] = _("Support Programmers");
static const u8 gCreditsText_Artwork[] = _("Artwork");
static const u8 gCreditsText_LeadProgrammer[] = _("Lead Programmer");
static const u8 gCreditsText_LeadGraphicArtist[] = _("Lead Graphic Artist");
static const u8 gCreditsText_SatoshiTajiri[] = _("Satoshi Tajiri");
static const u8 gCreditsText_JunichiMasuda[] = _("Junichi Masuda");
static const u8 gCreditsText_KenSugimori[] = _("Ken Sugimori");
static const u8 gCreditsText_ShigekiMorimoto[] = _("Shigeki Morimoto");
static const u8 gCreditsText_TetsuyaWatanabe[] = _("Tetsuya Watanabe");
static const u8 gCreditsText_HisashiSogabe[] = _("Hisashi Sogabe");
static const u8 gCreditsText_SosukeTamada[] = _("Sosuke Tamada");
static const u8 gCreditsText_AkitoMori[] = _("Akito Mori");
static const u8 gCreditsText_KeitaKagaya[] = _("Keita Kagaya");
static const u8 gCreditsText_YoshinoriMatsuda[] = _("Yoshinori Matsuda");
static const u8 gCreditsText_HiroyukiNakamura[] = _("Hiroyuki Nakamura");
static const u8 gCreditsText_MasaoTaya[] = _("Masao Taya");
static const u8 gCreditsText_SatoshiNohara[] = _("Satoshi Nohara");
static const u8 gCreditsText_TomomichiOhta[] = _("Tomomichi Ohta");
static const u8 gCreditsText_MiyukiIwasawa[] = _("Miyuki Iwasawa");
static const u8 gCreditsText_TakenoriOhta[] = _("Takenori Ohta");
static const u8 gCreditsText_HironobuYoshida[] = _("Hironobu Yoshida");
static const u8 gCreditsText_MotofumiFujiwara[] = _("Motofumi Fujiwara");
static const u8 gCreditsText_SatoshiOhta[] = _("Satoshi Ohta");
static const u8 gCreditsText_AsukaIwashita[] = _("Asuka Iwashita");
static const u8 gCreditsText_AimiTomita[] = _("Aimi Tomita");
static const u8 gCreditsText_TakaoUnno[] = _("Takao Unno");
static const u8 gCreditsText_KanakoEo[] = _("Kanako Eo");
static const u8 gCreditsText_JunOkutani[] = _("Jun Okutani");
static const u8 gCreditsText_AtsukoNishida[] = _("Atsuko Nishida");
static const u8 gCreditsText_MuneoSaito[] = _("Muneo Saito");
static const u8 gCreditsText_RenaYoshikawa[] = _("Rena Yoshikawa");
static const u8 gCreditsText_GoIchinose[] = _("Go Ichinose");
static const u8 gCreditsText_MorikazuAoki[] = _("Morikazu Aoki");
static const u8 gCreditsText_KojiNishino[] = _("Koji Nishino");
static const u8 gCreditsText_KenjiMatsushima[] = _("Kenji Matsushima");
static const u8 gCreditsText_TetsujiOhta[] = _("Tetsuji Ohta");
static const u8 gCreditsText_HitomiSato[] = _("Hitomi Sato");
static const u8 gCreditsText_TakeshiKawachimaru[] = _("Takeshi Kawachimaru");
static const u8 gCreditsText_TeruyukiShimoyamada[] = _("Teruyuki Shimoyamada");
static const u8 gCreditsText_ShigeruOhmori[] = _("Shigeru Ohmori");
static const u8 gCreditsText_TadashiTakahashi[] = _("Tadashi Takahashi");
static const u8 gCreditsText_ToshinobuMatsumiya[] = _("Toshinobu Matsumiya");
static const u8 gCreditsText_AkihitoTomisawa[] = _("Akihito Tomisawa");
static const u8 gCreditsText_HirokiEnomoto[] = _("Hiroki Enomoto");
static const u8 gCreditsText_KazuyukiTerada[] = _("Kazuyuki Terada");
static const u8 gCreditsText_YuriSakurai[] = _("Yuri Sakurai");
static const u8 gCreditsText_HiromiSagawa[] = _("Hiromi Sagawa");
static const u8 gCreditsText_KenjiTominaga[] = _("Kenji Tominaga");
static const u8 gCreditsText_YoshioTajiri[] = _("Yoshio Tajiri");
static const u8 gCreditsText_TeikoSasaki[] = _("Teiko Sasaki");
static const u8 gCreditsText_SachikoHamano[] = _("Sachiko Hamano");
static const u8 gCreditsText_ChieMatsumiya[] = _("Chie Matsumiya");
static const u8 gCreditsText_AkikoShinozaki[] = _("Akiko Shinozaki");
static const u8 gCreditsText_AstukoFujii[] = _("Astuko Fujii");
static const u8 gCreditsText_NozomuSaito[] = _("Nozomu Saito");
static const u8 gCreditsText_KenkichiToyama[] = _("Kenkichi Toyama");
static const u8 gCreditsText_SuguruNakatsui[] = _("Suguru Nakatsui");
static const u8 gCreditsText_YumiFunasaka[] = _("Yumi Funasaka");
static const u8 gCreditsText_NaokoYanase[] = _("Naoko Yanase");
static const u8 gCreditsText_NCLSuperMarioClub[] = _("NCL Super Mario Club");
static const u8 gCreditsText_AtsushiTada[] = _("Atsushi Tada");
static const u8 gCreditsText_TakahiroOhnishi[] = _("Takahiro Ohnishi");
static const u8 gCreditsText_NorihideOkamura[] = _("Norihide Okamura");
static const u8 gCreditsText_HiroNakamura[] = _("Hiro Nakamura");
static const u8 gCreditsText_HiroyukiUesugi[] = _("Hiroyuki Uesugi");
static const u8 gCreditsText_TerukiMurakawa[] = _("Teruki Murakawa");
static const u8 gCreditsText_AkiraKinashi[] = _("Akira Kinashi");
static const u8 gCreditsText_MichikoTakizawa[] = _("Michiko Takizawa");
static const u8 gCreditsText_MakikoTakada[] = _("Makiko Takada");
static const u8 gCreditsText_TakanaoKondo[] = _("Takanao Kondo");
static const u8 gCreditsText_AiMashima[] = _("Ai Mashima");
static const u8 gCreditsText_GakujiNomoto[] = _("Gakuji Nomoto");
static const u8 gCreditsText_TakehiroIzushi[] = _("Takehiro Izushi");
static const u8 gCreditsText_HitoshiYamagami[] = _("Hitoshi Yamagami");
static const u8 gCreditsText_KyokoWatanabe[] = _("Kyoko Watanabe");
static const u8 gCreditsText_TakaoNakano[] = _("Takao Nakano");
static const u8 gCreditsText_HiroyukiJinnai[] = _("Hiroyuki Jinnai");
static const u8 gCreditsText_HiroakiTsuru[] = _("Hiroaki Tsuru");
static const u8 gCreditsText_TsunekazIshihara[] = _("Tsunekaz Ishihara");
static const u8 gCreditsText_SatoruIwata[] = _("Satoru Iwata");
static const u8 gCreditsText_KazuyaSuyama[] = _("Kazuya Suyama");
static const u8 gCreditsText_SatoshiMitsuhara[] = _("Satoshi Mitsuhara");
static const u8 gCreditsText_JapanBrailleLibrary[] = _("Japan Braille Library");
static const u8 gCreditsText_TomotakaKomura[] = _("Tomotaka Komura");
static const u8 gCreditsText_MikikoOhhashi[] = _("Mikiko Ohhashi");
static const u8 gCreditsText_DaisukeHoshino[] = _("Daisuke Hoshino");
static const u8 gCreditsText_KenjiroIto[] = _("Kenjiro Ito");
static const u8 gCreditsText_RuiKawaguchi[] = _("Rui Kawaguchi");
static const u8 gCreditsText_ShunsukeKohori[] = _("Shunsuke Kohori");
static const u8 gCreditsText_SachikoNakamichi[] = _("Sachiko Nakamichi");
static const u8 gCreditsText_FujikoNomura[] = _("Fujiko Nomura");
static const u8 gCreditsText_KazukiYoshihara[] = _("Kazuki Yoshihara");
static const u8 gCreditsText_RetsujiNomoto[] = _("Retsuji Nomoto");
static const u8 gCreditsText_AzusaTajima[] = _("Azusa Tajima");
static const u8 gCreditsText_ShusakuEgami[] = _("Shusaku Egami");
static const u8 gCreditsText_PackageAndManual[] = _("Package & Manual Illustration");
static const u8 gCreditsText_EnglishVersion[] = _("English Version Coordinators");
static const u8 gCreditsText_Translator[] = _("Translator");
static const u8 gCreditsText_TextEditor[] = _("Text Editor");
static const u8 gCreditsText_NCLCoordinator[] = _("NCL Coordinator");
static const u8 gCreditsText_GraphicDesigner[] = _("Graphic Designer");
static const u8 gCreditsText_NOAProductTesting[] = _("NOA Product Testing");
static const u8 gCreditsText_HideyukiNakajima[] = _("Hideyuki Nakajima");
static const u8 gCreditsText_HidenoriSaeki[] = _("Hidenori Saeki");
static const u8 gCreditsText_YokoWatanabe[] = _("Yoko Watanabe");
static const u8 gCreditsText_SakaeKimura[] = _("Sakae Kimura");
static const u8 gCreditsText_ChiakiShinkai[] = _("Chiaki Shinkai");
static const u8 gCreditsText_SethMcMahill[] = _("Seth McMahill");
static const u8 gCreditsText_NobOgasawara[] = _("Nob Ogasawara");
static const u8 gCreditsText_TeresaLillygren[] = _("Teresa Lillygren");
static const u8 gCreditsText_KimikoNakamichi[] = _("Kimiko Nakamichi");
static const u8 gCreditsText_SouichiYamamoto[] = _("Souichi Yamamoto");
static const u8 gCreditsText_YuichiroIto[] = _("Yuichiro Ito");
static const u8 gCreditsText_ThomasHertzog[] = _("Thomas Hertzog");
static const u8 gCreditsText_MikaKurosawa[] = _("Mika Kurosawa");
static const u8 gCreditsText_NationalFederationBlind[] = _("National Federation of the Blind");
static const u8 gCreditsText_PatriciaAMaurer[] = _("Patricia A. Maurer");
static const u8 gCreditsText_EuropeanBlindUnion[] = _("European Blind Union");
static const u8 gCreditsText_AustralianBrailleAuthority[] = _("Australian Braille Authority");
static const u8 gCreditsText_RoyalNewZealandFederationBlind[] = _("Royal New Zealand Federation for the Blind");
static const u8 gCreditsText_MotoyasuTojima[] = _("Motoyasu Tojima");
static const u8 gCreditsText_NicolaPrattBarlow[] = _("Nicola Pratt-Barlow");
static const u8 gCreditsText_ShellieDow[] = _("Shellie Dow");
static const u8 gCreditsText_ErikJohnson[] = _("Erik Johnson");

static const struct CreditsEntry gCreditsEntry_PkmnEmeraldVersion[];
static const struct CreditsEntry gCreditsEntry_EmeraldEnhanced[] = {0, TRUE, gCreditsText_EmeraldEnhanced};
//page
static const struct CreditsEntry gCreditsEntry_CreatedBy[] = {0, TRUE, gCreditsText_CreatedBy};
static const struct CreditsEntry gCreditsEntry_Ryuhouji[] =  {0, FALSE, gCreditsText_Ryuhouji};
//page
static const struct CreditsEntry gCreditsEntry_Donors[] =  {0, TRUE, gCreditsText_Donors};
static const struct CreditsEntry gCreditsEntry_Donorsp1[] = {0, FALSE, gCreditsText_Donorsp1};
static const struct CreditsEntry gCreditsEntry_Donorsp2[] = {0, FALSE, gCreditsText_Donorsp2};
static const struct CreditsEntry gCreditsEntry_Donorsp3[] = {0, FALSE, gCreditsText_Donorsp3};
static const struct CreditsEntry gCreditsEntry_Donorsp4[] = {0, FALSE, gCreditsText_Donorsp4};
static const struct CreditsEntry gCreditsEntry_Donorsp5[] = {0, FALSE, gCreditsText_Donorsp5}; 
static const struct CreditsEntry gCreditsEntry_Donorsp6[] = {0, FALSE, gCreditsText_Donorsp6};
static const struct CreditsEntry gCreditsEntry_Donorsp7[] = {0, FALSE, gCreditsText_Donorsp7};
static const struct CreditsEntry gCreditsEntry_Donorsp8[] = {0, FALSE, gCreditsText_Donorsp8};
static const struct CreditsEntry gCreditsEntry_Donorsp9[] = {0, FALSE, gCreditsText_Donorsp9};
static const struct CreditsEntry gCreditsEntry_Donorsp10[] = {0, FALSE, gCreditsText_Donorsp10};
static const struct CreditsEntry gCreditsEntry_Donorsp11[] = {0, FALSE, gCreditsText_Donorsp11};
static const struct CreditsEntry gCreditsEntry_Donorsp12[] = {0, FALSE, gCreditsText_Donorsp12};
static const struct CreditsEntry gCreditsEntry_Donorsp13[] = {0, FALSE, gCreditsText_Donorsp13};
static const struct CreditsEntry gCreditsEntry_Donorsp14[] = {0, FALSE, gCreditsText_Donorsp14};
static const struct CreditsEntry gCreditsEntry_Donorsp15[] = {0, FALSE, gCreditsText_Donorsp15};
static const struct CreditsEntry gCreditsEntry_Donorsp16[] = {0, FALSE, gCreditsText_Donorsp16};
static const struct CreditsEntry gCreditsEntry_Donorsp17[] = {0, FALSE, gCreditsText_Donorsp17};
static const struct CreditsEntry gCreditsEntry_Donorsp18[] = {0, FALSE, gCreditsText_Donorsp18};
static const struct CreditsEntry gCreditsEntry_Donorsp19[] = {0, FALSE, gCreditsText_Donorsp19};
static const struct CreditsEntry gCreditsEntry_Donorsp20[] = {0, FALSE, gCreditsText_Donorsp20};
//page
static const struct CreditsEntry gCreditsEntry_StoryboardingBy[] = {0, TRUE, gCreditsText_StoryboardingBy};
static const struct CreditsEntry gCreditsEntry_Kouta[] = {0, FALSE, gCreditsText_Kouta};
//page
static const struct CreditsEntry gCreditsEntry_GraphicsBy[] = {0, TRUE, gCreditsText_GraphicsBy};
static const struct CreditsEntry gCreditsEntry_EEGraphics1[] = {0, FALSE, gCreditsText_EEGraphics1};
static const struct CreditsEntry gCreditsEntry_EEGraphics2[] = {0, FALSE, gCreditsText_EEGraphics2};
//page
static const struct CreditsEntry gCreditsEntry_DocumentationBy[] = {0, TRUE, gCreditsText_DocumentationBy};
static const struct CreditsEntry gCreditsEntry_Toby[] = {0, FALSE, gCreditsText_Toby};
//page
static const struct CreditsEntry gCreditsEntry_QADirectors[] = {0, TRUE, gCreditsText_QADirectors};
static const struct CreditsEntry gCreditsEntry_Pidgey[] = {0, FALSE, gCreditsText_Pidgey};
static const struct CreditsEntry gCreditsEntry_Kageru[] = {0, FALSE, gCreditsText_Kageru};
static const struct CreditsEntry gCreditsEntry_BaseGameCredits[] = {0, FALSE, gCreditsText_BaseGameCredits};

static const struct CreditsEntry gCreditsEntry_Consultation[] ={0, TRUE, gCreditsText_Consultation};
static const struct CreditsEntry gCreditsEntry_GriffinR[] = {0, FALSE, gCreditsText_GriffinR};
static const struct CreditsEntry gCreditsEntry_DizzyEggg[] = {0, FALSE, gCreditsText_DizzyEggg};
static const struct CreditsEntry gCreditsEntry_DevelopmentBy[] = {0, FALSE, gCreditsText_DevelopmentBy};

static const struct CreditsEntry gCreditsEntry_EmptyString[] = {0, FALSE, gCreditsText_EmptyString};
static const struct CreditsEntry gCreditsEntry_PkmnEmeraldVersion[] = {7, TRUE, gCreditsText_PkmnEmeraldVersion};
static const struct CreditsEntry gCreditsEntry_Credits[] = {11, TRUE, gCreditsText_Credits};
static const struct CreditsEntry gCreditsEntry_ExecutiveDirector[] = {8, TRUE, gCreditsText_ExecutiveDirector};
static const struct CreditsEntry gCreditsEntry_Director[] = {12, TRUE, gCreditsText_Director};
static const struct CreditsEntry gCreditsEntry_ArtDirector[] = {10, TRUE, gCreditsText_ArtDirector};
static const struct CreditsEntry gCreditsEntry_BattleDirector[] = {10, TRUE, gCreditsText_BattleDirector};
static const struct CreditsEntry gCreditsEntry_MainProgrammer[] = {10, TRUE, gCreditsText_MainProgrammer};
static const struct CreditsEntry gCreditsEntry_BattleSystemPgrms[] = {8, TRUE, gCreditsText_BattleSystemPgrms};
static const struct CreditsEntry gCreditsEntry_FieldSystemPgrms[] = {7, TRUE, gCreditsText_FieldSystemPgrms};
static const struct CreditsEntry gCreditsEntry_Programmers[] = {12, TRUE, gCreditsText_Programmers};
static const struct CreditsEntry gCreditsEntry_MainGraphicDesigner[] = {7, TRUE, gCreditsText_MainGraphicDesigner};
static const struct CreditsEntry gCreditsEntry_GraphicDesigners[] = {9, TRUE, gCreditsText_GraphicDesigners};
static const struct CreditsEntry gCreditsEntry_PkmnDesigners[] = {10, TRUE, gCreditsText_PkmnDesigners};
static const struct CreditsEntry gCreditsEntry_MusicComposition[] = {13, TRUE, gCreditsText_MusicComposition};
static const struct CreditsEntry gCreditsEntry_SoundEffectsAndPkmnVoices[] = {4, TRUE, gCreditsText_SoundEffectsAndPkmnVoices};
static const struct CreditsEntry gCreditsEntry_GameDesigners[] = {11, TRUE, gCreditsText_GameDesigners};
static const struct CreditsEntry gCreditsEntry_ScenarioPlot[] = {11, TRUE, gCreditsText_ScenarioPlot};
static const struct CreditsEntry gCreditsEntry_Scenario[] = {13, TRUE, gCreditsText_Scenario};
static const struct CreditsEntry gCreditsEntry_ScriptDesigners[] = {10, TRUE, gCreditsText_ScriptDesigners};
static const struct CreditsEntry gCreditsEntry_MapDesigners[] = {11, TRUE, gCreditsText_MapDesigners};
static const struct CreditsEntry gCreditsEntry_MapDataDesigners[] = {9, TRUE, gCreditsText_MapDataDesigners};
static const struct CreditsEntry gCreditsEntry_ParametricDesigners[] = {9, TRUE, gCreditsText_ParametricDesigners};
static const struct CreditsEntry gCreditsEntry_PokedexText[] = {11, TRUE, gCreditsText_PokedexText};
static const struct CreditsEntry gCreditsEntry_EnvAndToolPgrms[] = {6, TRUE, gCreditsText_EnvAndToolPgrms};
static const struct CreditsEntry gCreditsEntry_NCLProductTesting[] = {11, TRUE, gCreditsText_NCLProductTesting};
static const struct CreditsEntry gCreditsEntry_SpecialThanks[] = {10, TRUE, gCreditsText_SpecialThanks};
static const struct CreditsEntry gCreditsEntry_Coordinators[] = {11, TRUE, gCreditsText_Coordinators};
static const struct CreditsEntry gCreditsEntry_Producers[] = {11, TRUE, gCreditsText_Producers};
static const struct CreditsEntry gCreditsEntry_ExecProducers[] = {7, TRUE, gCreditsText_ExecProducers};
static const struct CreditsEntry gCreditsEntry_InfoSupervisors[] = {10, TRUE, gCreditsText_InfoSupervisors};
static const struct CreditsEntry gCreditsEntry_TaskManagers[] = {8, TRUE, gCreditsText_TaskManagers};
static const struct CreditsEntry gCreditsEntry_BrailleCodeCheck[] = {10, TRUE, gCreditsText_BrailleCodeCheck};
static const struct CreditsEntry gCreditsEntry_WorldDirector[] = {10, TRUE, gCreditsText_WorldDirector};
static const struct CreditsEntry gCreditsEntry_BattleFrontierData[] = {8, TRUE, gCreditsText_BattleFrontierData};
static const struct CreditsEntry gCreditsEntry_SupportProgrammers[] = {10, TRUE, gCreditsText_SupportProgrammers};
static const struct CreditsEntry gCreditsEntry_Artwork[] = {12, TRUE, gCreditsText_Artwork};
static const struct CreditsEntry gCreditsEntry_LeadProgrammer[] = {10, TRUE, gCreditsText_LeadProgrammer};
static const struct CreditsEntry gCreditsEntry_LeadGraphicArtist[] = {9, TRUE, gCreditsText_LeadGraphicArtist};
static const struct CreditsEntry gCreditsEntry_SatoshiTajiri[] = {11, FALSE, gCreditsText_SatoshiTajiri};
static const struct CreditsEntry gCreditsEntry_JunichiMasuda[] = {11, FALSE, gCreditsText_JunichiMasuda};
static const struct CreditsEntry gCreditsEntry_KenSugimori[] = {11, FALSE, gCreditsText_KenSugimori};
static const struct CreditsEntry gCreditsEntry_ShigekiMorimoto[] = {11, FALSE, gCreditsText_ShigekiMorimoto};
static const struct CreditsEntry gCreditsEntry_TetsuyaWatanabe[] = {11, FALSE, gCreditsText_TetsuyaWatanabe};
static const struct CreditsEntry gCreditsEntry_HisashiSogabe[] = {11, FALSE, gCreditsText_HisashiSogabe};
static const struct CreditsEntry gCreditsEntry_SosukeTamada[] = {11, FALSE, gCreditsText_SosukeTamada};
static const struct CreditsEntry gCreditsEntry_AkitoMori[] = {11, FALSE, gCreditsText_AkitoMori};
static const struct CreditsEntry gCreditsEntry_KeitaKagaya[] = {11, FALSE, gCreditsText_KeitaKagaya};
static const struct CreditsEntry gCreditsEntry_YoshinoriMatsuda[] = {11, FALSE, gCreditsText_YoshinoriMatsuda};
static const struct CreditsEntry gCreditsEntry_HiroyukiNakamura[] = {11, FALSE, gCreditsText_HiroyukiNakamura};
static const struct CreditsEntry gCreditsEntry_MasaoTaya[] = {11, FALSE, gCreditsText_MasaoTaya};
static const struct CreditsEntry gCreditsEntry_SatoshiNohara[] = {11, FALSE, gCreditsText_SatoshiNohara};
static const struct CreditsEntry gCreditsEntry_TomomichiOhta[] = {11, FALSE, gCreditsText_TomomichiOhta};
static const struct CreditsEntry gCreditsEntry_MiyukiIwasawa[] = {11, FALSE, gCreditsText_MiyukiIwasawa};
static const struct CreditsEntry gCreditsEntry_TakenoriOhta[] = {11, FALSE, gCreditsText_TakenoriOhta};
static const struct CreditsEntry gCreditsEntry_HironobuYoshida[] = {11, FALSE, gCreditsText_HironobuYoshida};
static const struct CreditsEntry gCreditsEntry_MotofumiFujiwara[] = {11, FALSE, gCreditsText_MotofumiFujiwara};
static const struct CreditsEntry gCreditsEntry_SatoshiOhta[] = {11, FALSE, gCreditsText_SatoshiOhta};
static const struct CreditsEntry gCreditsEntry_AsukaIwashita[] = {11, FALSE, gCreditsText_AsukaIwashita};
static const struct CreditsEntry gCreditsEntry_AimiTomita[] = {11, FALSE, gCreditsText_AimiTomita};
static const struct CreditsEntry gCreditsEntry_TakaoUnno[] = {11, FALSE, gCreditsText_TakaoUnno};
static const struct CreditsEntry gCreditsEntry_KanakoEo[] = {11, FALSE, gCreditsText_KanakoEo};
static const struct CreditsEntry gCreditsEntry_JunOkutani[] = {11, FALSE, gCreditsText_JunOkutani};
static const struct CreditsEntry gCreditsEntry_AtsukoNishida[] = {11, FALSE, gCreditsText_AtsukoNishida};
static const struct CreditsEntry gCreditsEntry_MuneoSaito[] = {11, FALSE, gCreditsText_MuneoSaito};
static const struct CreditsEntry gCreditsEntry_RenaYoshikawa[] = {11, FALSE, gCreditsText_RenaYoshikawa};
static const struct CreditsEntry gCreditsEntry_GoIchinose[] = {11, FALSE, gCreditsText_GoIchinose};
static const struct CreditsEntry gCreditsEntry_MorikazuAoki[] = {11, FALSE, gCreditsText_MorikazuAoki};
static const struct CreditsEntry gCreditsEntry_KojiNishino[] = {11, FALSE, gCreditsText_KojiNishino};
static const struct CreditsEntry gCreditsEntry_KenjiMatsushima[] = {11, FALSE, gCreditsText_KenjiMatsushima};
static const struct CreditsEntry gCreditsEntry_TetsujiOhta[] = {11, FALSE, gCreditsText_TetsujiOhta};
static const struct CreditsEntry gCreditsEntry_HitomiSato[] = {11, FALSE, gCreditsText_HitomiSato};
static const struct CreditsEntry gCreditsEntry_TakeshiKawachimaru[] = {11, FALSE, gCreditsText_TakeshiKawachimaru};
static const struct CreditsEntry gCreditsEntry_TeruyukiShimoyamada[] = {11, FALSE, gCreditsText_TeruyukiShimoyamada};
static const struct CreditsEntry gCreditsEntry_ShigeruOhmori[] = {11, FALSE, gCreditsText_ShigeruOhmori};
static const struct CreditsEntry gCreditsEntry_TadashiTakahashi[] = {11, FALSE, gCreditsText_TadashiTakahashi};
static const struct CreditsEntry gCreditsEntry_ToshinobuMatsumiya[] = {11, FALSE, gCreditsText_ToshinobuMatsumiya};
static const struct CreditsEntry gCreditsEntry_AkihitoTomisawa[] = {11, FALSE, gCreditsText_AkihitoTomisawa};
static const struct CreditsEntry gCreditsEntry_HirokiEnomoto[] = {11, FALSE, gCreditsText_HirokiEnomoto};
static const struct CreditsEntry gCreditsEntry_KazuyukiTerada[] = {11, FALSE, gCreditsText_KazuyukiTerada};
static const struct CreditsEntry gCreditsEntry_YuriSakurai[] = {11, FALSE, gCreditsText_YuriSakurai};
static const struct CreditsEntry gCreditsEntry_HiromiSagawa[] = {11, FALSE, gCreditsText_HiromiSagawa};
static const struct CreditsEntry gCreditsEntry_KenjiTominaga[] = {11, FALSE, gCreditsText_KenjiTominaga};
static const struct CreditsEntry gCreditsEntry_YoshioTajiri[] = {11, FALSE, gCreditsText_YoshioTajiri};
static const struct CreditsEntry gCreditsEntry_TeikoSasaki[] = {11, FALSE, gCreditsText_TeikoSasaki};
static const struct CreditsEntry gCreditsEntry_SachikoHamano[] = {11, FALSE, gCreditsText_SachikoHamano};
static const struct CreditsEntry gCreditsEntry_ChieMatsumiya[] = {11, FALSE, gCreditsText_ChieMatsumiya};
static const struct CreditsEntry gCreditsEntry_AkikoShinozaki[] = {11, FALSE, gCreditsText_AkikoShinozaki};
static const struct CreditsEntry gCreditsEntry_AstukoFujii[] = {11, FALSE, gCreditsText_AstukoFujii};
static const struct CreditsEntry gCreditsEntry_NozomuSaito[] = {11, FALSE, gCreditsText_NozomuSaito};
static const struct CreditsEntry gCreditsEntry_KenkichiToyama[] = {11, FALSE, gCreditsText_KenkichiToyama};
static const struct CreditsEntry gCreditsEntry_SuguruNakatsui[] = {11, FALSE, gCreditsText_SuguruNakatsui};
static const struct CreditsEntry gCreditsEntry_YumiFunasaka[] = {11, FALSE, gCreditsText_YumiFunasaka};
static const struct CreditsEntry gCreditsEntry_NaokoYanase[] = {11, FALSE, gCreditsText_NaokoYanase};
static const struct CreditsEntry gCreditsEntry_NCLSuperMarioClub[] = {11, FALSE, gCreditsText_NCLSuperMarioClub};
static const struct CreditsEntry gCreditsEntry_AtsushiTada[] = {11, FALSE, gCreditsText_AtsushiTada};
static const struct CreditsEntry gCreditsEntry_TakahiroOhnishi[] = {11, FALSE, gCreditsText_TakahiroOhnishi};
static const struct CreditsEntry gCreditsEntry_NorihideOkamura[] = {11, FALSE, gCreditsText_NorihideOkamura};
static const struct CreditsEntry gCreditsEntry_HiroNakamura[] = {11, FALSE, gCreditsText_HiroNakamura};
static const struct CreditsEntry gCreditsEntry_HiroyukiUesugi[] = {11, FALSE, gCreditsText_HiroyukiUesugi};
static const struct CreditsEntry gCreditsEntry_TerukiMurakawa[] = {11, FALSE, gCreditsText_TerukiMurakawa};
static const struct CreditsEntry gCreditsEntry_AkiraKinashi[] = {11, FALSE, gCreditsText_AkiraKinashi};
static const struct CreditsEntry gCreditsEntry_MichikoTakizawa[] = {11, FALSE, gCreditsText_MichikoTakizawa};
static const struct CreditsEntry gCreditsEntry_MakikoTakada[] = {11, FALSE, gCreditsText_MakikoTakada};
static const struct CreditsEntry gCreditsEntry_TakanaoKondo[] = {11, FALSE, gCreditsText_TakanaoKondo};
static const struct CreditsEntry gCreditsEntry_AiMashima[] = {11, FALSE, gCreditsText_AiMashima};
static const struct CreditsEntry gCreditsEntry_GakujiNomoto[] = {11, FALSE, gCreditsText_GakujiNomoto};
static const struct CreditsEntry gCreditsEntry_TakehiroIzushi[] = {11, FALSE, gCreditsText_TakehiroIzushi};
static const struct CreditsEntry gCreditsEntry_HitoshiYamagami[] = {11, FALSE, gCreditsText_HitoshiYamagami};
static const struct CreditsEntry gCreditsEntry_KyokoWatanabe[] = {11, FALSE, gCreditsText_KyokoWatanabe};
static const struct CreditsEntry gCreditsEntry_TakaoNakano[] = {11, FALSE, gCreditsText_TakaoNakano};
static const struct CreditsEntry gCreditsEntry_HiroyukiJinnai[] = {11, FALSE, gCreditsText_HiroyukiJinnai};
static const struct CreditsEntry gCreditsEntry_HiroakiTsuru[] = {11, FALSE, gCreditsText_HiroakiTsuru};
static const struct CreditsEntry gCreditsEntry_TsunekazIshihara[] = {11, FALSE, gCreditsText_TsunekazIshihara};
static const struct CreditsEntry gCreditsEntry_SatoruIwata[] = {11, FALSE, gCreditsText_SatoruIwata};
static const struct CreditsEntry gCreditsEntry_KazuyaSuyama[] = {11, FALSE, gCreditsText_KazuyaSuyama};
static const struct CreditsEntry gCreditsEntry_SatoshiMitsuhara[] = {11, FALSE, gCreditsText_SatoshiMitsuhara};
static const struct CreditsEntry gCreditsEntry_JapanBrailleLibrary[] = {9, FALSE, gCreditsText_JapanBrailleLibrary};
static const struct CreditsEntry gCreditsEntry_TomotakaKomura[] = {11, FALSE, gCreditsText_TomotakaKomura};
static const struct CreditsEntry gCreditsEntry_MikikoOhhashi[] = {11, FALSE, gCreditsText_MikikoOhhashi};
static const struct CreditsEntry gCreditsEntry_DaisukeHoshino[] = {11, FALSE, gCreditsText_DaisukeHoshino};
static const struct CreditsEntry gCreditsEntry_KenjiroIto[] = {11, FALSE, gCreditsText_KenjiroIto};
static const struct CreditsEntry gCreditsEntry_RuiKawaguchi[] = {11, FALSE, gCreditsText_RuiKawaguchi};
static const struct CreditsEntry gCreditsEntry_ShunsukeKohori[] = {11, FALSE, gCreditsText_ShunsukeKohori};
static const struct CreditsEntry gCreditsEntry_SachikoNakamichi[] = {11, FALSE, gCreditsText_SachikoNakamichi};
static const struct CreditsEntry gCreditsEntry_FujikoNomura[] = {11, FALSE, gCreditsText_FujikoNomura};
static const struct CreditsEntry gCreditsEntry_KazukiYoshihara[] = {11, FALSE, gCreditsText_KazukiYoshihara};
static const struct CreditsEntry gCreditsEntry_RetsujiNomoto[] = {11, FALSE, gCreditsText_RetsujiNomoto};
static const struct CreditsEntry gCreditsEntry_AzusaTajima[] = {11, FALSE, gCreditsText_AzusaTajima};
static const struct CreditsEntry gCreditsEntry_ShusakuEgami[] = {11, FALSE, gCreditsText_ShusakuEgami};
static const struct CreditsEntry gCreditsEntry_PackageAndManual[] = {0, TRUE, gCreditsText_PackageAndManual};
static const struct CreditsEntry gCreditsEntry_EnglishVersion[] = {0, TRUE, gCreditsText_EnglishVersion};
static const struct CreditsEntry gCreditsEntry_Translator[] = {0, TRUE, gCreditsText_Translator};
static const struct CreditsEntry gCreditsEntry_TextEditor[] = {0, TRUE, gCreditsText_TextEditor};
static const struct CreditsEntry gCreditsEntry_NCLCoordinator[] = {0, TRUE, gCreditsText_NCLCoordinator};
static const struct CreditsEntry gCreditsEntry_GraphicDesigner[] = {0, TRUE, gCreditsText_GraphicDesigner};
static const struct CreditsEntry gCreditsEntry_NOAProductTesting[] = {0, TRUE, gCreditsText_NOAProductTesting};
static const struct CreditsEntry gCreditsEntry_HideyukiNakajima[] = {0, FALSE, gCreditsText_HideyukiNakajima};
static const struct CreditsEntry gCreditsEntry_HidenoriSaeki[] = {0, FALSE, gCreditsText_HidenoriSaeki};
static const struct CreditsEntry gCreditsEntry_YokoWatanabe[] = {0, FALSE, gCreditsText_YokoWatanabe};
static const struct CreditsEntry gCreditsEntry_SakaeKimura[] = {0, FALSE, gCreditsText_SakaeKimura};
static const struct CreditsEntry gCreditsEntry_ChiakiShinkai[] = {0, FALSE, gCreditsText_ChiakiShinkai};
static const struct CreditsEntry gCreditsEntry_SethMcMahill[] = {0, FALSE, gCreditsText_SethMcMahill};
static const struct CreditsEntry gCreditsEntry_NobOgasawara[] = {0, FALSE, gCreditsText_NobOgasawara};
static const struct CreditsEntry gCreditsEntry_TeresaLillygren[] = {0, FALSE, gCreditsText_TeresaLillygren};
static const struct CreditsEntry gCreditsEntry_KimikoNakamichi[] = {0, FALSE, gCreditsText_KimikoNakamichi};
static const struct CreditsEntry gCreditsEntry_SouichiYamamoto[] = {0, FALSE, gCreditsText_SouichiYamamoto};
static const struct CreditsEntry gCreditsEntry_YuichiroIto[] = {0, FALSE, gCreditsText_YuichiroIto};
static const struct CreditsEntry gCreditsEntry_ThomasHertzog[] = {0, FALSE, gCreditsText_ThomasHertzog};
static const struct CreditsEntry gCreditsEntry_MikaKurosawa[] = {0, FALSE, gCreditsText_MikaKurosawa};
static const struct CreditsEntry gCreditsEntry_NationalFederationBlind[] = {0, FALSE, gCreditsText_NationalFederationBlind};
static const struct CreditsEntry gCreditsEntry_PatriciaAMaurer[] = {0, FALSE, gCreditsText_PatriciaAMaurer};
static const struct CreditsEntry gCreditsEntry_EuropeanBlindUnion[] = {0, FALSE, gCreditsText_EuropeanBlindUnion};
static const struct CreditsEntry gCreditsEntry_AustralianBrailleAuthority[] = {0, FALSE, gCreditsText_AustralianBrailleAuthority};
static const struct CreditsEntry gCreditsEntry_RoyalNewZealandFederationBlind[] = {0, FALSE, gCreditsText_RoyalNewZealandFederationBlind};
static const struct CreditsEntry gCreditsEntry_MotoyasuTojima[] = {0, FALSE, gCreditsText_MotoyasuTojima};
static const struct CreditsEntry gCreditsEntry_NicolaPrattBarlow[] = {0, FALSE, gCreditsText_NicolaPrattBarlow};
static const struct CreditsEntry gCreditsEntry_ShellieDow[] = {0, FALSE, gCreditsText_ShellieDow};
static const struct CreditsEntry gCreditsEntry_ErikJohnson[] = {0, FALSE, gCreditsText_ErikJohnson};

#define _ gCreditsEntry_EmptyString
static const struct CreditsEntry *const gCreditsEntryPointerTable[][5] =
{
    {
        gCreditsEntry_EmeraldEnhanced,
        _,
        _,
        _,
        _
    },
    {
        gCreditsEntry_CreatedBy,
        _,
        gCreditsEntry_Ryuhouji,
        _,
        _
    },
    {
        gCreditsEntry_Donors,
        gCreditsEntry_Donorsp1,
        gCreditsEntry_Donorsp2,
        gCreditsEntry_Donorsp3,
        _
    },
    {
        gCreditsEntry_Donorsp4,
        gCreditsEntry_Donorsp5,
        gCreditsEntry_Donorsp6,
        gCreditsEntry_Donorsp7,
        _
    },
    {
        gCreditsEntry_Donorsp8,
        gCreditsEntry_Donorsp9,
        gCreditsEntry_Donorsp10,
        gCreditsEntry_Donorsp11,
        _
    },
    {
        gCreditsEntry_Donorsp12,
        gCreditsEntry_Donorsp13,
        gCreditsEntry_Donorsp14,
        gCreditsEntry_Donorsp15,
        _
    },
    {
        gCreditsEntry_Donorsp16,
        gCreditsEntry_Donorsp17,
        gCreditsEntry_Donorsp18,
        gCreditsEntry_Donorsp19,
        _
    },
    {
        gCreditsEntry_Donorsp20,
        _,
        _,
        _,
        _
    },
    {
        gCreditsEntry_DevelopmentBy,
        gCreditsEntry_Ryuhouji,
        gCreditsEntry_Pidgey,
        gCreditsEntry_Kageru,
        _
    },
    {
        gCreditsEntry_StoryboardingBy,
        _,
        gCreditsEntry_Kouta,
        _,
        _
    },
    {
        gCreditsEntry_GraphicsBy,
        gCreditsEntry_EEGraphics1,
        _,
        gCreditsEntry_EEGraphics2,
        _
    },
    {
        gCreditsEntry_DocumentationBy,
        _,
        gCreditsEntry_Toby,
        _,
        _
    },
    {
        gCreditsEntry_QADirectors,
        
        gCreditsEntry_Toby,
        gCreditsEntry_Kageru,
        _,
        _,

    },
    {
        gCreditsEntry_Consultation,
        gCreditsEntry_GriffinR,
        gCreditsEntry_DizzyEggg,
        gCreditsEntry_Pidgey,
        _
    },
    {
        _,
        _,
        _,
        _,
        _
    },
    {
        _,
        gCreditsEntry_PkmnEmeraldVersion,
        gCreditsEntry_Credits,
        _,
        _
    },
    {
        _,
        gCreditsEntry_Director,
        gCreditsEntry_ShigekiMorimoto,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_ArtDirector,
        gCreditsEntry_KenSugimori,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_WorldDirector,
        gCreditsEntry_JunichiMasuda,
        _,
        _,
    },
    {
        gCreditsEntry_LeadProgrammer,
        gCreditsEntry_HisashiSogabe,
        gCreditsEntry_LeadGraphicArtist,
        gCreditsEntry_MotofumiFujiwara,
        _,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_HisashiSogabe,
        gCreditsEntry_TomomichiOhta,
        gCreditsEntry_NozomuSaito,
        gCreditsEntry_EmptyString,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_AkitoMori,
        gCreditsEntry_HiroyukiNakamura,
        gCreditsEntry_MasaoTaya,
        _,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_SatoshiNohara,
        gCreditsEntry_MiyukiIwasawa,
        gCreditsEntry_YoshinoriMatsuda,
        gCreditsEntry_KeitaKagaya,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_TetsuyaWatanabe,
        gCreditsEntry_SosukeTamada,
        gCreditsEntry_TakenoriOhta,
        _,
    },
    {
        _,
        gCreditsEntry_GraphicDesigners,
        gCreditsEntry_MotofumiFujiwara,
        gCreditsEntry_SatoshiOhta,
        _,
    },
    {
        gCreditsEntry_GraphicDesigners,
        gCreditsEntry_KenkichiToyama,
        gCreditsEntry_AsukaIwashita,
        gCreditsEntry_TakaoUnno,
        _,
    },
    {
        gCreditsEntry_GraphicDesigners,
        gCreditsEntry_KenSugimori,
        gCreditsEntry_HironobuYoshida,
        gCreditsEntry_AimiTomita,
        gCreditsEntry_KanakoEo,
    },
    {
        gCreditsEntry_MusicComposition,
        gCreditsEntry_GoIchinose,
        gCreditsEntry_JunichiMasuda,
        gCreditsEntry_MorikazuAoki,
        gCreditsEntry_HitomiSato,
    },
    {
        _,
        gCreditsEntry_SoundEffectsAndPkmnVoices,
        gCreditsEntry_GoIchinose,
        gCreditsEntry_MorikazuAoki,
        _,
    },
    {
        gCreditsEntry_GameDesigners,
        gCreditsEntry_ShigekiMorimoto,
        gCreditsEntry_TeruyukiShimoyamada,
        gCreditsEntry_TakeshiKawachimaru,
        gCreditsEntry_AkihitoTomisawa,
    },
    {
        gCreditsEntry_GameDesigners,
        gCreditsEntry_SuguruNakatsui,
        gCreditsEntry_TetsujiOhta,
        gCreditsEntry_HitomiSato,
        gCreditsEntry_KenjiMatsushima,
    },
    {
        gCreditsEntry_GameDesigners,
        gCreditsEntry_JunichiMasuda,
        gCreditsEntry_KojiNishino,
        gCreditsEntry_ShigeruOhmori,
        gCreditsEntry_TadashiTakahashi,
    },
    {
        gCreditsEntry_ScenarioPlot,
        gCreditsEntry_AkihitoTomisawa,
        gCreditsEntry_JunichiMasuda,
        gCreditsEntry_KojiNishino,
        _,
    },
    {
        gCreditsEntry_Scenario,
        gCreditsEntry_AkihitoTomisawa,
        gCreditsEntry_HitomiSato,
        gCreditsEntry_ToshinobuMatsumiya,
        _,
    },
    {
        gCreditsEntry_ScriptDesigners,
        gCreditsEntry_TomomichiOhta,
        gCreditsEntry_SatoshiNohara,
        _,
        _,
    },
    {
        gCreditsEntry_MapDesigners,
        gCreditsEntry_SuguruNakatsui,
        gCreditsEntry_TeruyukiShimoyamada,
        gCreditsEntry_ShigeruOhmori,
        gCreditsEntry_TetsujiOhta,
    },
    {
        _,
        gCreditsEntry_BattleFrontierData,
        gCreditsEntry_TetsujiOhta,
        _,
        _,
    },
    {
        gCreditsEntry_ParametricDesigners,
        gCreditsEntry_TeruyukiShimoyamada,
        gCreditsEntry_ShigekiMorimoto,
        gCreditsEntry_TetsujiOhta,
        gCreditsEntry_KojiNishino,
    },
    {
        _,
        gCreditsEntry_PokedexText,
        gCreditsEntry_KenjiMatsushima,
        _,
        _,
    },
    {
        gCreditsEntry_EnvAndToolPgrms,
        gCreditsEntry_HisashiSogabe,
        gCreditsEntry_SosukeTamada,
        gCreditsEntry_HiroyukiNakamura,
        gCreditsEntry_AkitoMori,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_KenSugimori,
        gCreditsEntry_MotofumiFujiwara,
        gCreditsEntry_ShigekiMorimoto,
        _,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_HironobuYoshida,
        gCreditsEntry_SatoshiOhta,
        gCreditsEntry_AsukaIwashita,
        _,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_TakaoUnno,
        gCreditsEntry_KanakoEo,
        gCreditsEntry_AimiTomita,
        _,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_AtsukoNishida,
        gCreditsEntry_MuneoSaito,
        gCreditsEntry_RenaYoshikawa,
        gCreditsEntry_JunOkutani,
    },
    {
        _,
        gCreditsEntry_SupportProgrammers,
        gCreditsEntry_SatoshiMitsuhara,
        gCreditsEntry_DaisukeHoshino,
        _,
    },
    {
        _,
        gCreditsEntry_NCLProductTesting,
        gCreditsEntry_NCLSuperMarioClub,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_PackageAndManual,
        gCreditsEntry_KenSugimori,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_KenjiTominaga,
        gCreditsEntry_HirokiEnomoto,
        _,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_KazuyaSuyama,
        gCreditsEntry_KenjiroIto,
        gCreditsEntry_MichikoTakizawa,
        gCreditsEntry_MakikoTakada,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_MikikoOhhashi,
        gCreditsEntry_TakanaoKondo,
        gCreditsEntry_RuiKawaguchi,
        _,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_TakahiroOhnishi,
        gCreditsEntry_NorihideOkamura,
        gCreditsEntry_ShunsukeKohori,
        _,
    },
    {
        gCreditsEntry_InfoSupervisors,
        gCreditsEntry_KazuyukiTerada,
        gCreditsEntry_YuriSakurai,
        gCreditsEntry_YumiFunasaka,
        gCreditsEntry_NaokoYanase,
    },
    {
        _,
        gCreditsEntry_Artwork,
        gCreditsEntry_SachikoNakamichi,
        gCreditsEntry_FujikoNomura,
        _,
    },
    {
        _,
        gCreditsEntry_Artwork,
        gCreditsEntry_HideyukiNakajima,
        gCreditsEntry_HidenoriSaeki,
        _,
    },
    {
        gCreditsEntry_Artwork,
        gCreditsEntry_YokoWatanabe,
        gCreditsEntry_SakaeKimura,
        gCreditsEntry_ChiakiShinkai,
        _,
    },
    {
        gCreditsEntry_Coordinators,
        gCreditsEntry_KazukiYoshihara,
        gCreditsEntry_AkiraKinashi,
        gCreditsEntry_RetsujiNomoto,
        _,
    },
    {
        _,
        gCreditsEntry_EnglishVersion,
        gCreditsEntry_HiroNakamura,
        gCreditsEntry_SethMcMahill,
        _,
    },
    {
        _,
        gCreditsEntry_Translator,
        gCreditsEntry_NobOgasawara,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_TextEditor,
        gCreditsEntry_TeresaLillygren,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_NCLCoordinator,
        gCreditsEntry_KimikoNakamichi,
        _,
        _,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_TerukiMurakawa,
        gCreditsEntry_SouichiYamamoto,
        gCreditsEntry_YuichiroIto,
        gCreditsEntry_AkiraKinashi,
    },
    {
        _,
        gCreditsEntry_GraphicDesigner,
        gCreditsEntry_AkiraKinashi,
        _,
        _,
    },
    {
        gCreditsEntry_EnvAndToolPgrms,
        gCreditsEntry_TerukiMurakawa,
        gCreditsEntry_SouichiYamamoto,
        gCreditsEntry_KimikoNakamichi,
        _,
    },
    {
        gCreditsEntry_NOAProductTesting,
        gCreditsEntry_ThomasHertzog,
        gCreditsEntry_ErikJohnson,
        gCreditsEntry_MikaKurosawa,
        _,
    },
    {
        gCreditsEntry_BrailleCodeCheck,
        gCreditsEntry_NationalFederationBlind,
        gCreditsEntry_PatriciaAMaurer,
        gCreditsEntry_JapanBrailleLibrary,
        gCreditsEntry_EuropeanBlindUnion,
    },
    {
        _,
        gCreditsEntry_BrailleCodeCheck,
        gCreditsEntry_AustralianBrailleAuthority,
        gCreditsEntry_RoyalNewZealandFederationBlind,
        _,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_HiroyukiUesugi,
        gCreditsEntry_MotoyasuTojima,
        gCreditsEntry_NicolaPrattBarlow,
        gCreditsEntry_ShellieDow,
    },
    {
        _,
        gCreditsEntry_TaskManagers,
        gCreditsEntry_AzusaTajima,
        gCreditsEntry_ShusakuEgami,
        _,
    },
    {
        gCreditsEntry_Producers,
        gCreditsEntry_HiroyukiJinnai,
        gCreditsEntry_HitoshiYamagami,
        gCreditsEntry_GakujiNomoto,
        gCreditsEntry_HiroakiTsuru,
    },
    {
        _,
        gCreditsEntry_ExecutiveDirector,
        gCreditsEntry_SatoshiTajiri,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_ExecProducers,
        gCreditsEntry_SatoruIwata,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_ExecProducers,
        gCreditsEntry_TsunekazIshihara,
        _,
        _,
    },
};
#undef _

static const struct BgTemplate sBackgroundTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};
static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 9,
        .width = 30,
        .height = 12,
        .paletteNum = 8,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE,
};
static const u8 sMonSpritePos[][2] =
{
    {104, 36},
    {120, 36},
    {136, 36},
};

static const union AnimCmd sAnim_Player_Slow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Player_Fast[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Player_LookBack[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_FRAME(384, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Player_LookForward[] =
{
    ANIMCMD_FRAME(384, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Player[] =
{
    sAnim_Player_Slow,
    sAnim_Player_Fast,
    sAnim_Player_LookBack,
    sAnim_Player_LookForward,
};

static const union AnimCmd sAnim_Rival_Slow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Rival_Fast[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Rival_Still[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Rival[] =
{
    sAnim_Rival_Slow,
    sAnim_Rival_Fast,
    sAnim_Rival_Still,
};

#define MONBG_OFFSET (MON_PIC_SIZE * 3)
static const struct SpriteSheet sSpriteSheet_MonBg[] = {
    { gDecompressionBuffer, MONBG_OFFSET, TAG_MON_BG },
    {},
};
static const struct SpritePalette sSpritePalette_MonBg[] = {
    { (const u16 *)&gDecompressionBuffer[MONBG_OFFSET], TAG_MON_BG },
    {},
};

static const struct OamData sOamData_MonBg =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_MonBg_Yellow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonBg_Red[] =
{
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonBg_Blue[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_MonBg[] =
{
    [POS_LEFT]   = sAnim_MonBg_Yellow,
    [POS_CENTER] = sAnim_MonBg_Red,
    [POS_RIGHT]  = sAnim_MonBg_Blue,
};

static const struct SpriteTemplate sSpriteTemplate_CreditsMonBg =
{
    .tileTag = TAG_MON_BG,
    .paletteTag = TAG_MON_BG,
    .oam = &sOamData_MonBg,
    .anims = sAnims_MonBg,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CreditsMonBg,
};

static void VBlankCB_Credits(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_Credits(void)
{
    RunTasks();
    AnimateSprites();

    if ((JOY_HELD(B_BUTTON))
     && gHasHallOfFameRecords
     && gTasks[sSavedTaskId].func == Task_CreditsMain)
    {
        // Speed up credits
        VBlankCB_Credits();
        RunTasks();
        AnimateSprites();
        sUsedSpeedUp = TRUE;
    }
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void InitCreditsBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
    LoadPalette(sCredits_Pal, 0x80, 64);
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
    ShowBg(0);
}

static void FreeCreditsBgsAndWindows(void)
{
    void *ptr;
    FreeAllWindowBuffers();
    ptr = GetBgTilemapBuffer(0);
    if (ptr)
        Free(ptr);
}

static void PrintCreditsText(const u8 *string, u8 y, bool8 isTitle)
{
    u8 x;
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;

    if (isTitle == TRUE)
    {
        color[1] = TEXT_COLOR_LIGHT_GRAY;
        color[2] = TEXT_COLOR_RED;
    }
    else
    {
        color[1] = TEXT_COLOR_WHITE;
        color[2] = TEXT_COLOR_DARK_GRAY;
    }

    x = GetStringCenterAlignXOffsetWithLetterSpacing(1, string, DISPLAY_WIDTH, 1);
    AddTextPrinterParameterized4(0, 1, x, y, 1, 0, color, -1, string);
}

#define tMainTaskId data[1]

void CB2_StartCreditsSequence(void)
{
    u8 taskId;
    s16 bikeTaskId;
    u8 pageTaskId;

    ResetGpuAndVram();
    SetVBlankCallback(NULL);
    InitHeap(gHeap, HEAP_SIZE);
    ResetPaletteFade();
    ResetTasks();
    InitCreditsBgsAndWindows();

    taskId = CreateTask(Task_WaitPaletteFade, 0);

    gTasks[taskId].tEndCredits = FALSE;
    gTasks[taskId].tSceneNum = SCENE_OCEAN_MORNING;
    gTasks[taskId].tNextMode = MODE_NONE;
    gTasks[taskId].tCurrentMode = MODE_BIKE_SCENE;

    while (TRUE)
    {
        if (LoadBikeScene(SCENE_OCEAN_MORNING, taskId))
            break;
    }

    bikeTaskId = gTasks[taskId].tTaskId_BikeScene;
    gTasks[bikeTaskId].tState = 40;

    SetGpuReg(REG_OFFSET_BG0VOFS, 0xFFFC);

    pageTaskId = CreateTask(Task_UpdatePage, 0);

    gTasks[pageTaskId].tMainTaskId = taskId;
    gTasks[taskId].tTaskId_UpdatePage = pageTaskId;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_Credits);
    m4aSongNumStart(MUS_CREDITS);
    SetMainCallback2(CB2_Credits);
    sUsedSpeedUp = FALSE;
    sCreditsData = AllocZeroed(sizeof(struct CreditsData));

    DeterminePokemonToShow();

    sCreditsData->imgCounter = 0;
    sCreditsData->nextImgPos = POS_LEFT;
    sCreditsData->currShownMon = 0;

    sSavedTaskId = taskId;
}

static void Task_WaitPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_CreditsMain;
}

static void Task_CreditsMain(u8 taskId)
{
    u16 mode;

    if (gTasks[taskId].tEndCredits)
    {
        s16 bikeTaskId = gTasks[taskId].tTaskId_BikeScene;
        gTasks[bikeTaskId].tState = 30;

        gTasks[taskId].tTheEndDelay = 256;
        gTasks[taskId].func = Task_CreditsTheEnd1;
        return;
    }

    sUnkVar = 0;
    mode = gTasks[taskId].tNextMode;

    if (gTasks[taskId].tNextMode == MODE_BIKE_SCENE)
    {
        // Start a bike cutscene
        gTasks[taskId].tCurrentMode = mode;
        gTasks[taskId].tNextMode = MODE_NONE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ReadyBikeScene;
    }
    else if (gTasks[taskId].tNextMode == MODE_SHOW_MONS)
    {
        // Start a Pokémon interlude
        gTasks[taskId].tCurrentMode = mode;
        gTasks[taskId].tNextMode = MODE_NONE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ReadyShowMons;
    }
}

static void Task_ReadyBikeScene(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetCreditsTasks(taskId);
        gTasks[taskId].func = Task_SetBikeScene;
    }
}

static void Task_SetBikeScene(u8 taskId)
{
    SetVBlankCallback(NULL);

    if (LoadBikeScene(gTasks[taskId].tSceneNum, taskId))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Credits);
        gTasks[taskId].func = Task_WaitPaletteFade;
    }
}

static void Task_ReadyShowMons(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetCreditsTasks(taskId);
        gTasks[taskId].func = Task_LoadShowMons;
    }
}

static void Task_LoadShowMons(u8 taskId)
{
    switch (gMain.state)
    {
    default:
    case 0:
    {
        u16 i;
        u16 *temp;

        ResetSpriteData();
        ResetAllPicSprites();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
        LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));
        LoadPalette(gBirchBagGrassPal[0] + 1, 1, 31 * 2);

        for (i = 0; i < MON_PIC_SIZE; i++)
            gDecompressionBuffer[i] = 0x11;
        for (i = 0; i < MON_PIC_SIZE; i++)
            (gDecompressionBuffer + MON_PIC_SIZE)[i] = 0x22;
        for (i = 0; i < MON_PIC_SIZE; i++)
            (gDecompressionBuffer + MON_PIC_SIZE * 2)[i] = 0x33;

        temp = (u16 *)(&gDecompressionBuffer[MONBG_OFFSET]);
        temp[0] = RGB_BLACK;
        temp[1] = RGB(31, 31, 20); // light yellow
        temp[2] = RGB(31, 20, 20); // light red
        temp[3] = RGB(20, 20, 31); // light blue

        LoadSpriteSheet(sSpriteSheet_MonBg);
        LoadSpritePalette(sSpritePalette_MonBg);

        gMain.state++;
        break;
    }
    case 1:
        gTasks[taskId].tTaskId_ShowMons = CreateTask(Task_ShowMons, 0);
        gTasks[gTasks[taskId].tTaskId_ShowMons].tState = 1;
        gTasks[gTasks[taskId].tTaskId_ShowMons].tMainTaskId = taskId;
        gTasks[gTasks[taskId].tTaskId_ShowMons].data[2] = gTasks[taskId].tSceneNum; // data[2] never read

        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 32);
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);

        gMain.state = 0;
        gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_NORMAL;
        gTasks[taskId].func = Task_WaitPaletteFade;
        break;
    }
}

static void Task_CreditsTheEnd1(u8 taskId)
{
    if (gTasks[taskId].tTheEndDelay)
    {
        gTasks[taskId].tTheEndDelay--;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 12, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_CreditsTheEnd2;
}

static void Task_CreditsTheEnd2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetCreditsTasks(taskId);
        gTasks[taskId].func = Task_CreditsTheEnd3;
    }
}

#define tDelay data[0]

static void Task_CreditsTheEnd3(u8 taskId)
{
    ResetGpuAndVram();
    ResetPaletteFade();
    LoadTheEndScreen(0, 0x3800, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(PALETTES_ALL, 8, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON);

    gTasks[taskId].tDelay = 235; //set this to 215 to actually show "THE END" in time to the last song beat
    gTasks[taskId].func = Task_CreditsTheEnd4;
}

static void Task_CreditsTheEnd4(u8 taskId)
{
    if (gTasks[taskId].tDelay)
    {
        gTasks[taskId].tDelay--;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 6, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_CreditsTheEnd5;
}

static void Task_CreditsTheEnd5(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DrawTheEnd(0x3800, 0);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0, RGB_BLACK);
        gTasks[taskId].tDelay = 7200;
        gTasks[taskId].func = Task_CreditsTheEnd6;
    }
}

static void Task_CreditsTheEnd6(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tDelay == 0 || gMain.newKeys)
        {
            FadeOutBGM(4);
            BeginNormalPaletteFade(PALETTES_ALL, 8, 0, 16, RGB_WHITEALPHA);
            gTasks[taskId].func = Task_CreditsSoftReset;
            return;
        }

        if (gTasks[taskId].tDelay == 7144)
            FadeOutBGM(8);

        if (gTasks[taskId].tDelay == 6840)
            m4aSongNumStart(MUS_END);

        gTasks[taskId].tDelay--;
    }
}

#undef tDelay

static void Task_CreditsSoftReset(u8 taskId)
{
    if (!gPaletteFade.active)
        SoftReset(RESET_ALL);
}

static void ResetGpuAndVram(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
}

#define tCurrentPage data[2]
#define tDelay       data[3]

static void Task_UpdatePage(u8 taskId)
{
    int i;

    switch (gTasks[taskId].tState)
    {
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    default:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tState = 1;
            gTasks[taskId].tDelay = 72;
            gTasks[gTasks[taskId].tMainTaskId].tPrintedPage = FALSE;
            sUnkVar = 0;
        }
        return;
    case 1:
        if (gTasks[taskId].tDelay != 0)
        {
            gTasks[taskId].tDelay--;
            return;
        }
        gTasks[taskId].tState++;
        return;
    case 2:
        if (gTasks[gTasks[taskId].tMainTaskId].func == Task_CreditsMain)
        {
            if (gTasks[taskId].tCurrentPage < PAGE_COUNT)
            {
                // Print text for this Credits page
                for (i = 0; i < ENTRIES_PER_PAGE; i++)
                    PrintCreditsText(
                        sCreditsEntryPointerTable[gTasks[taskId].tCurrentPage][i]->text,
                         5 + i * 16, 
                         sCreditsEntryPointerTable[gTasks[taskId].tCurrentPage][i]->isTitle);
                CopyWindowToVram(0, 2);

                gTasks[taskId].tCurrentPage++;
                gTasks[taskId].tState++;

                gTasks[gTasks[taskId].tMainTaskId].tPrintedPage = TRUE;

                if (gTasks[gTasks[taskId].tMainTaskId].tCurrentMode == MODE_BIKE_SCENE)
                    BeginNormalPaletteFade(0x300, 0, 16, 0, COLOR_LIGHT_GREEN);
                else // MODE_SHOW_MONS
                    BeginNormalPaletteFade(0x300, 0, 16, 0, COLOR_DARK_GREEN);
                return;
            }

            // Reached final page of Credits, end task
            gTasks[taskId].tState = 10;
            return;
        }
        gTasks[gTasks[taskId].tMainTaskId].tPrintedPage = FALSE;
        return;
    case 3:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tDelay = 115;
            gTasks[taskId].tState++;
        }
        return;
    case 4:
        if (gTasks[taskId].tDelay != 0)
        {
            gTasks[taskId].tDelay--;
            return;
        }

        if (CheckChangeScene((u8)gTasks[taskId].tCurrentPage, (u8)gTasks[taskId].tMainTaskId))
        {
            gTasks[taskId].tState++;
            return;
        }
        gTasks[taskId].tState++;
        if (gTasks[gTasks[taskId].tMainTaskId].tCurrentMode == MODE_BIKE_SCENE)
            BeginNormalPaletteFade(0x300, 0, 0, 16, COLOR_LIGHT_GREEN);
        else // MODE_SHOW_MONS
            BeginNormalPaletteFade(0x300, 0, 0, 16, COLOR_DARK_GREEN);
        return;
    case 5:
        if (!gPaletteFade.active)
        {
            // Still more Credits pages to show, return to state 2 to print
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            CopyWindowToVram(0, 2);
            gTasks[taskId].tState = 2;
        }
        return;
    case 10:
        gTasks[gTasks[taskId].tMainTaskId].tEndCredits = TRUE;
        DestroyTask(taskId);
        FreeCreditsBgsAndWindows();
        FREE_AND_SET_NULL(sCreditsData);
        return;
    }
}

#undef tDelay

#define PAGE_INTERVAL (PAGE_COUNT / 9) // 9 scenes (5 bike scenes, 4 Pokémon interludes)

static u8 CheckChangeScene(u8 page, u8 taskId)
{
    // Starts with bike + ocean + morning (SCENE_OCEAN_MORNING)

    if (page == PAGE_INTERVAL * 1)
    {
        // Pokémon interlude
        gTasks[taskId].tNextMode = MODE_SHOW_MONS;
    }

    if (page == PAGE_INTERVAL * 2)
    {
        // Bike + ocean + sunset
        gTasks[taskId].tSceneNum = SCENE_OCEAN_SUNSET;
        gTasks[taskId].tNextMode = MODE_BIKE_SCENE;
    }

    if (page == PAGE_INTERVAL * 3)
    {
        // Pokémon interlude
        gTasks[taskId].tNextMode = MODE_SHOW_MONS;
    }

    if (page == PAGE_INTERVAL * 4)
    {
        // Bike + forest + sunset
        gTasks[taskId].tSceneNum = SCENE_FOREST_RIVAL_ARRIVE;
        gTasks[taskId].tNextMode = MODE_BIKE_SCENE;
    }

    if (page == PAGE_INTERVAL * 5)
    {
        // Pokémon interlude
        gTasks[taskId].tNextMode = MODE_SHOW_MONS;
    }

    if (page == PAGE_INTERVAL * 6)
    {
        // Bike + forest + sunset
        gTasks[taskId].tSceneNum = SCENE_FOREST_CATCH_RIVAL;
        gTasks[taskId].tNextMode = MODE_BIKE_SCENE;
    }

    if (page == PAGE_INTERVAL * 7)
    {
        // Pokémon interlude
        gTasks[taskId].tNextMode = MODE_SHOW_MONS;
    }

    if (page == PAGE_INTERVAL * 8)
    {
        // Bike + town + night
        gTasks[taskId].tSceneNum = SCENE_CITY_NIGHT;
        gTasks[taskId].tNextMode = MODE_BIKE_SCENE;
    }

    if (gTasks[taskId].tNextMode != MODE_NONE)
    {
        // Returns true if changed
        return TRUE;
    }

    return FALSE;
}

#define tDelay data[3]

static void Task_ShowMons(u8 taskId)
{
    u8 spriteId;

    switch (gTasks[taskId].tState)
    {
    case 0:
        break;
    case 1:
        if (sCreditsData->nextImgPos == POS_LEFT && gTasks[gTasks[taskId].tMainTaskId].tPrintedPage == FALSE)
            break;
        gTasks[taskId].tState++;
        break;
    case 2:
        if (sCreditsData->imgCounter == NUM_MON_SLIDES || gTasks[gTasks[taskId].tMainTaskId].func != Task_CreditsMain)
            break;
        spriteId = CreateCreditsMonSprite(sCreditsData->monToShow[sCreditsData->currShownMon], 
                                    sMonSpritePos[sCreditsData->nextImgPos][0], 
                                    sMonSpritePos[sCreditsData->nextImgPos][1], 
                                    sCreditsData->nextImgPos);
        if (sCreditsData->currShownMon < sCreditsData->numMonToShow - 1)
        {
            sCreditsData->currShownMon++;
            gSprites[spriteId].data[3] = 50;
        }
        else
        {
            sCreditsData->currShownMon = 0;
            gSprites[spriteId].data[3] = 512;
        }
        sCreditsData->imgCounter++;

        if (sCreditsData->nextImgPos == POS_RIGHT)
            sCreditsData->nextImgPos = POS_LEFT;
        else
            sCreditsData->nextImgPos++;

        gTasks[taskId].tDelay = 50;
        gTasks[taskId].tState++;
        break;
    case 3:
        if (gTasks[taskId].tDelay != 0)
            gTasks[taskId].tDelay--;
        else
            gTasks[taskId].tState = 1;
        break;
    }
}

#undef tMainTaskId
#undef tDelay

#define tPlayer data[2]
#define tRival  data[3]
#define tDelay  data[4]
#define tSinIdx data[5]

static void Task_BikeScene(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        gIntroCredits_MovingSceneryVOffset = Sin((gTasks[taskId].tSinIdx >> 1) & 0x7F, 12);
        gTasks[taskId].tSinIdx++;
        break;
    case 1:
        if (gIntroCredits_MovingSceneryVOffset != 0)
        {
            gIntroCredits_MovingSceneryVOffset = Sin((gTasks[taskId].tSinIdx >> 1) & 0x7F, 12);
            gTasks[taskId].tSinIdx++;
        }
        else
        {
            gSprites[gTasks[taskId].tPlayer].data[0] = 2;
            gTasks[taskId].tSinIdx = 0;
            gTasks[taskId].tState++;
        }
        break;
    case 2:
        if (gTasks[taskId].tSinIdx < 64)
        {
            gTasks[taskId].tSinIdx++;
            gIntroCredits_MovingSceneryVOffset = Sin(gTasks[taskId].tSinIdx & 0x7F, 20);
        }
        else
        {
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        gSprites[gTasks[taskId].tPlayer].data[0] = 3;
        gSprites[gTasks[taskId].tRival].data[0] = 1;
        gTasks[taskId].tDelay = 120;
        gTasks[taskId].tState++;
        break;
    case 4:
        if (gTasks[taskId].tDelay != 0)
        {
            gTasks[taskId].tDelay--;
        }
        else
        {
            gTasks[taskId].tSinIdx = 64;
            gTasks[taskId].tState++;
        }
        break;
    case 5:
        if (gTasks[taskId].tSinIdx > 0)
        {
            gTasks[taskId].tSinIdx--;
            gIntroCredits_MovingSceneryVOffset = Sin(gTasks[taskId].tSinIdx & 0x7F, 20);
        }
        else
        {
            gSprites[gTasks[taskId].tPlayer].data[0] = 1;
            gTasks[taskId].tState++;
        }
        break;
    case 6:
        gTasks[taskId].tState = 50;
        break;
    case 10:
        gSprites[gTasks[taskId].tRival].data[0] = 2;
        gTasks[taskId].tState = 50;
        break;
    case 20:
        gSprites[gTasks[taskId].tPlayer].data[0] = 4;
        gTasks[taskId].tState = 50;
        break;
    case 30:
        gSprites[gTasks[taskId].tPlayer].data[0] = 5;
        gSprites[gTasks[taskId].tRival].data[0] = 3;
        gTasks[taskId].tState = 50;
        break;
    case 50:
        gTasks[taskId].tState = 0;
        break;
    }
}

#define TIMER_STOP  0x7FFF
#define tTimer      data[1]
#define tMainTaskId data[2]

static void Task_CycleSceneryPalette(u8 taskId)
{
    s16 bikeTaskId;

    switch (gTasks[taskId].tState)
    {
    default:
    case SCENE_OCEAN_MORNING:
        if (gTasks[taskId].tTimer != TIMER_STOP)
        {
            if (gTasks[gTasks[gTasks[taskId].tMainTaskId].tTaskId_UpdatePage].tCurrentPage == 2)
            {
                gTasks[gTasks[gTasks[taskId].tMainTaskId].tTaskId_BikeScene].tState = 20;
                gTasks[taskId].tTimer = TIMER_STOP;
            }
        }
        CycleSceneryPalette(0);
        break;
    case SCENE_OCEAN_SUNSET:
        CycleSceneryPalette(0);
        break;
    case SCENE_FOREST_RIVAL_ARRIVE:
        if (gTasks[taskId].tTimer != TIMER_STOP)
        {
            bikeTaskId = gTasks[gTasks[taskId].tMainTaskId].tTaskId_BikeScene;

            // Floor to multiple of 128
            if ((gTasks[bikeTaskId].tSinIdx & -128) == 640)
            {
                gTasks[bikeTaskId].tState = 1;
                gTasks[taskId].tTimer = TIMER_STOP;
            }
        }
        CycleSceneryPalette(1);
        break;
    case SCENE_FOREST_CATCH_RIVAL:
        if (gTasks[taskId].tTimer != TIMER_STOP)
        {

            if (gTasks[taskId].tTimer == 584)
            {
                gTasks[gTasks[gTasks[taskId].tMainTaskId].tTaskId_BikeScene].tState = 10;
                gTasks[taskId].tTimer = TIMER_STOP;
            }
            else
            {
                gTasks[taskId].tTimer++;
            }
        }
        CycleSceneryPalette(1);
        break;
    case SCENE_CITY_NIGHT:
        CycleSceneryPalette(2);
        break;
    }
}

static void SetBikeScene(u8 scene, u8 taskId)
{
    switch (scene)
    {
    case SCENE_OCEAN_MORNING:
        gSprites[gTasks[taskId].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tPlayerSpriteId].x = DISPLAY_WIDTH + 32;
        gSprites[gTasks[taskId].tRivalSpriteId].x = DISPLAY_WIDTH + 32;
        gSprites[gTasks[taskId].tPlayerSpriteId].y = 46;
        gSprites[gTasks[taskId].tRivalSpriteId].y = 46;
        gSprites[gTasks[taskId].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskId].tRivalSpriteId].data[0] = 0;
        gTasks[taskId].tTaskId_BgScenery = CreateBicycleBgAnimationTask(0, 0x2000, 0x20, 8);
        break;
    case SCENE_OCEAN_SUNSET:
        gSprites[gTasks[taskId].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tPlayerSpriteId].x = 120;
        gSprites[gTasks[taskId].tRivalSpriteId].x = DISPLAY_WIDTH + 32;
        gSprites[gTasks[taskId].tPlayerSpriteId].y = 46;
        gSprites[gTasks[taskId].tRivalSpriteId].y = 46;
        gSprites[gTasks[taskId].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskId].tRivalSpriteId].data[0] = 0;
        gTasks[taskId].tTaskId_BgScenery = CreateBicycleBgAnimationTask(0, 0x2000, 0x20, 8);
        break;
    case SCENE_FOREST_RIVAL_ARRIVE:
        gSprites[gTasks[taskId].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tPlayerSpriteId].x = 120;
        gSprites[gTasks[taskId].tRivalSpriteId].x = DISPLAY_WIDTH + 32;
        gSprites[gTasks[taskId].tPlayerSpriteId].y = 46;
        gSprites[gTasks[taskId].tRivalSpriteId].y = 46;
        gSprites[gTasks[taskId].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskId].tRivalSpriteId].data[0] = 0;
        gTasks[taskId].tTaskId_BgScenery = CreateBicycleBgAnimationTask(1, 0x2000, 0x200, 8);
        break;
    case SCENE_FOREST_CATCH_RIVAL:
        gSprites[gTasks[taskId].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tPlayerSpriteId].x = 120;
        gSprites[gTasks[taskId].tRivalSpriteId].x = -32;
        gSprites[gTasks[taskId].tPlayerSpriteId].y = 46;
        gSprites[gTasks[taskId].tRivalSpriteId].y = 46;
        gSprites[gTasks[taskId].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskId].tRivalSpriteId].data[0] = 0;
        gTasks[taskId].tTaskId_BgScenery = CreateBicycleBgAnimationTask(1, 0x2000, 0x200, 8);
        break;
    case SCENE_CITY_NIGHT:
        gSprites[gTasks[taskId].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskId].tPlayerSpriteId].x = 88;
        gSprites[gTasks[taskId].tRivalSpriteId].x = 152;
        gSprites[gTasks[taskId].tPlayerSpriteId].y = 46;
        gSprites[gTasks[taskId].tRivalSpriteId].y = 46;
        gSprites[gTasks[taskId].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskId].tRivalSpriteId].data[0] = 0;
        gTasks[taskId].tTaskId_BgScenery = CreateBicycleBgAnimationTask(2, 0x2000, 0x200, 8);
        break;
    }

    gTasks[taskId].tTaskId_SceneryPal = CreateTask(Task_CycleSceneryPalette, 0);
    gTasks[gTasks[taskId].tTaskId_SceneryPal].tState = scene;
    gTasks[gTasks[taskId].tTaskId_SceneryPal].tTimer = 0;
    gTasks[gTasks[taskId].tTaskId_SceneryPal].tMainTaskId = taskId;

    gTasks[taskId].tTaskId_BikeScene = CreateTask(Task_BikeScene, 0);
    gTasks[gTasks[taskId].tTaskId_BikeScene].tState = 0;
    gTasks[gTasks[taskId].tTaskId_BikeScene].data[1] = taskId; // data[1] is never read
    gTasks[gTasks[taskId].tTaskId_BikeScene].tPlayer = gTasks[taskId].tPlayerSpriteId;
    gTasks[gTasks[taskId].tTaskId_BikeScene].tRival = gTasks[taskId].tRivalSpriteId;
    gTasks[gTasks[taskId].tTaskId_BikeScene].tDelay = 0;

    if (scene == SCENE_FOREST_RIVAL_ARRIVE)
        gTasks[gTasks[taskId].tTaskId_BikeScene].tSinIdx = 69;
}

#undef tTimer
#undef tDelay
#undef tSinIdx
#undef tRival
#undef tPlayer

static bool8 LoadBikeScene(u8 scene, u8 taskId)
{
    u8 spriteId;

    switch (gMain.state)
    {
    default:
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 8);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state = 1;
        break;
    case 1:
        gIntroCredits_MovingSceneryVBase = 34;
        gIntroCredits_MovingSceneryVOffset = 0;
        LoadCreditsSceneGraphics(scene);
        gMain.state++;
        break;
    case 2:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBrendan);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsRivalMay);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBicycle);
            LoadSpritePalettes(gSpritePalettes_Credits);

            spriteId = CreateIntroBrendanSprite(120, 46);
            gTasks[taskId].tPlayerSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_Player;
            gSprites[spriteId].anims = sAnims_Player;

            spriteId = CreateIntroMaySprite(DISPLAY_WIDTH + 32, 46);
            gTasks[taskId].tRivalSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_Rival;
            gSprites[spriteId].anims = sAnims_Rival;
        }
        else
        {
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsMay);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsRivalBrendan);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBicycle);
            LoadSpritePalettes(gSpritePalettes_Credits);

            spriteId = CreateIntroMaySprite(120, 46);
            gTasks[taskId].tPlayerSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_Player;
            gSprites[spriteId].anims = sAnims_Player;

            spriteId = CreateIntroBrendanSprite(DISPLAY_WIDTH + 32, 46);
            gTasks[taskId].tRivalSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_Rival;
            gSprites[spriteId].anims = sAnims_Rival;
        };
        gMain.state++;
        break;
    case 3:
        SetBikeScene(scene, taskId);
        SetCreditsSceneBgCnt(scene);
        gMain.state = 0;
        return TRUE;
    }
    return FALSE;
}

static void ResetCreditsTasks(u8 taskId)
{
    // Destroy Task_BicycleBgAnimation, if running
    if (gTasks[taskId].tTaskId_BgScenery != 0)
    {
        DestroyTask(gTasks[taskId].tTaskId_BgScenery);
        gTasks[taskId].tTaskId_BgScenery = 0;
    }

    // Destroy Task_BikeScene, if running
    if (gTasks[taskId].tTaskId_BikeScene != 0)
    {
        DestroyTask(gTasks[taskId].tTaskId_BikeScene);
        gTasks[taskId].tTaskId_BikeScene = 0;
    }

    // Destroy Task_CycleSceneryPalette, if running
    if (gTasks[taskId].tTaskId_SceneryPal != 0)
    {
        DestroyTask(gTasks[taskId].tTaskId_SceneryPal);
        gTasks[taskId].tTaskId_SceneryPal = 0;
    }

    // Destroy Task_ShowMons, if running
    if (gTasks[taskId].tTaskId_ShowMons != 0)
    {
        DestroyTask(gTasks[taskId].tTaskId_ShowMons);
        gTasks[taskId].tTaskId_ShowMons = 0;
    }

    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_DESTROY;
}

static void LoadTheEndScreen(u16 arg0, u16 arg1, u16 palOffset)
{
    u16 baseTile;
    u16 i;

    LZ77UnCompVram(sCreditsCopyrightEnd_Gfx, (void *)(VRAM + arg0));
    LoadPalette(gIntroCopyright_Pal, palOffset, sizeof(gIntroCopyright_Pal));

    baseTile = (palOffset / 16) << 12;

    for (i = 0; i < 32 * 32; i++)
        ((u16 *) (VRAM + arg1))[i] = baseTile + 1;
}

static u16 GetLetterMapTile(u8 baseTiles)
{
    u16 out = (baseTiles & 0x3F) + 80;

    if (baseTiles == 0xFF)
        return 1;

    if (baseTiles & (1 << 7))
        out |= 1 << 11;
    if (baseTiles & (1 << 6))
        out |= 1 << 10;

    return out;
}

static void DrawLetterMapTiles(const u8 baseTiles[], u8 baseX, u8 baseY, u16 offset, u16 palette)
{
    u8 y, x;
    const u16 tileOffset = (palette / 16) << 12;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 3; x++)
            ((u16 *) (VRAM + offset + (baseY + y) * 64))[baseX + x] = tileOffset + GetLetterMapTile(baseTiles[y * 3 + x]);
    }
}

static void DrawTheEnd(u16 offset, u16 palette)
{
    u16 pos;
    u16 baseTile = (palette / 16) << 12;

    for (pos = 0; pos < 32 * 32; pos++)
        ((u16 *) (VRAM + offset))[pos] = baseTile + 1;

    DrawLetterMapTiles(sTheEnd_LetterMap_T, 3, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_H, 7, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_E, 11, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_E, 16, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_N, 20, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_D, 24, 7, offset, palette);
}

#define sState data[0]

static void SpriteCB_Player(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->sState)
    {
    case 0:
        StartSpriteAnimIfDifferent(sprite, 0);
        break;
    case 1:
        StartSpriteAnimIfDifferent(sprite, 1);
        if (sprite->x > -32)
            sprite->x--;
        break;
    case 2:
        StartSpriteAnimIfDifferent(sprite, 2);
        break;
    case 3:
        StartSpriteAnimIfDifferent(sprite, 3);
        break;
    case 4:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->x > 120)
            sprite->x--;
        break;
    case 5:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->x > -32)
            sprite->x--;
        break;
    }
}

static void SpriteCB_Rival(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->sState)
    {
    case 0:
        sprite->y2 = 0;
        StartSpriteAnimIfDifferent(sprite, 0);
        break;
    case 1:
        if (sprite->x > 200)
            StartSpriteAnimIfDifferent(sprite, 1);
        else
            StartSpriteAnimIfDifferent(sprite, 2);
        if (sprite->x > -32)
            sprite->x -= 2;
        sprite->y2 = -gIntroCredits_MovingSceneryVOffset;
        break;
    case 2:
        sprite->data[7]++;
        StartSpriteAnimIfDifferent(sprite, 0);
        if ((sprite->data[7] & 3) == 0)
            sprite->x++;
        break;
    case 3:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->x > -32)
            sprite->x--;
        break;
    }
}

#define sPosition data[1]
#define sSpriteId data[6]

static void SpriteCB_CreditsMon(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        FreeAndDestroyMonPicSprite(sprite->sSpriteId);
        return;
    }

    sprite->data[7]++;
    switch (sprite->sState)
    {
    case 0:
    default:
        sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        sprite->oam.matrixNum = sprite->sPosition;
        sprite->data[2] = 16;
        SetOamMatrix(sprite->sPosition, 0x10000 / sprite->data[2], 0, 0, 0x10000 / sprite->data[2]);
        sprite->invisible = FALSE;
        sprite->sState = 1;
        break;
    case 1:
        if (sprite->data[2] < 256)
        {
            sprite->data[2] += 8;
            SetOamMatrix(sprite->sPosition, 0x10000 / sprite->data[2], 0, 0, 0x10000 / sprite->data[2]);
        }
        else
        {
            sprite->sState++;
        }
        switch (sprite->sPosition)
        {
        case POS_LEFT + 1:
            if ((sprite->data[7] & 3) == 0)
                sprite->y++;
            sprite->x -= 2;
            break;
        case POS_CENTER + 1:
            break;
        case POS_RIGHT + 1:
            if ((sprite->data[7] & 3) == 0)
                sprite->y++;
            sprite->x += 2;
            break;
        }
        break;
    case 2:
        if (sprite->data[3] != 0)
        {
            sprite->data[3]--;
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
            sprite->oam.objMode = ST_OAM_OBJ_BLEND;
            sprite->data[3] = 16;
            sprite->sState++;
        }
        break;
    case 3:
        if (sprite->data[3] != 0)
        {
            int data3;

            sprite->data[3]--;

            data3 = 16 - sprite->data[3];
            SetGpuReg(REG_OFFSET_BLDALPHA, (data3 << 8) + sprite->data[3]);
        }
        else
        {
            sprite->invisible = TRUE;
            sprite->sState = 9;
        }
        break;
    case 9:
        sprite->sState++;
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        FreeAndDestroyMonPicSprite(sprite->data[6]);
        break;
    }
}

#define sMonSpriteId data[0]

static u8 CreateCreditsMonSprite(u16 nationalDexNum, s16 x, s16 y, u16 position)
{
    u8 monSpriteId;
    u8 bgSpriteId;

    monSpriteId = CreateMonSpriteFromNationalDexNumber(nationalDexNum, x, y, position);
    gSprites[monSpriteId].oam.priority = 1;
    gSprites[monSpriteId].sPosition = position + 1;
    gSprites[monSpriteId].invisible = TRUE;
    gSprites[monSpriteId].callback = SpriteCB_CreditsMon;
    gSprites[monSpriteId].sSpriteId = monSpriteId;

    bgSpriteId = CreateSprite(&sSpriteTemplate_CreditsMonBg, gSprites[monSpriteId].x, gSprites[monSpriteId].y, 1);
    gSprites[bgSpriteId].sMonSpriteId = monSpriteId;

    StartSpriteAnimIfDifferent(&gSprites[bgSpriteId], position);

    return monSpriteId;
}

static void SpriteCB_CreditsMonBg(struct Sprite *sprite)
{
    if (gSprites[sprite->sMonSpriteId].data[0] == 10 
     || gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        DestroySprite(sprite);
        return;
    }

    // Copy sprite data from the associated Pokémon
    sprite->invisible = gSprites[sprite->sMonSpriteId].invisible;
    sprite->oam.objMode = gSprites[sprite->sMonSpriteId].oam.objMode;
    sprite->oam.affineMode = gSprites[sprite->sMonSpriteId].oam.affineMode;
    sprite->oam.matrixNum = gSprites[sprite->sMonSpriteId].oam.matrixNum;
    sprite->x = gSprites[sprite->sMonSpriteId].x;
    sprite->y = gSprites[sprite->sMonSpriteId].y;
}

static void DeterminePokemonToShow(void)
{
    u16 starter = SpeciesToNationalPokedexNum(GetStarterPokemon(VarGet(VAR_STARTER_MON)));
    u16 page;
    u16 dexNum;
    u16 j;
    
    // Go through the Pokedex, and anything that has gotten caught we put into our massive array.
    // This basically packs all of the caught pokemon into the front of the array
    for (dexNum = 1, j = 0; dexNum < NATIONAL_DEX_COUNT; dexNum++)
    {
        if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
        {
            sCreditsData->caughtMonIds[j] = dexNum;
            j++;
        }
    }

    // Fill the rest of the array with zeroes
    for (dexNum = j; dexNum < NATIONAL_DEX_COUNT; dexNum++)
        sCreditsData->caughtMonIds[dexNum] = NATIONAL_DEX_NONE;

    // Cap the number of pokemon we care about to NUM_MON_SLIDES, the max we show in the credits scene (-1 for the starter)
    sCreditsData->numCaughtMon = j;
    if (sCreditsData->numCaughtMon < NUM_MON_SLIDES)
        sCreditsData->numMonToShow = j;
    else
        sCreditsData->numMonToShow = NUM_MON_SLIDES;

    // Loop through our list of caught pokemon and select randomly from it to fill the images to show
    j = 0;
    do
    {
        // Select a random mon, insert into array
        page = Random() % sCreditsData->numCaughtMon;
        sCreditsData->monToShow[j] = sCreditsData->caughtMonIds[page];
        
        // Remove the select mon from the array, and condense array entries
        j++;
        sCreditsData->caughtMonIds[page] = 0;
        sCreditsData->numCaughtMon--;
        if (page != sCreditsData->numCaughtMon)
        {
            // Instead of looping through and moving everything down, just take from the end. Order doesn't matter after all.
            sCreditsData->caughtMonIds[page] = sCreditsData->caughtMonIds[sCreditsData->numCaughtMon];
            sCreditsData->caughtMonIds[sCreditsData->numCaughtMon] = 0;
        }
    }
    while (sCreditsData->numCaughtMon != 0 && j < NUM_MON_SLIDES);

    // If we don't have enough pokemon in the dex to fill everything, copy the selected mon into the end of the array, so it loops
    if (sCreditsData->numMonToShow < NUM_MON_SLIDES)
    {
        for (j = sCreditsData->numMonToShow, page = 0; j < NUM_MON_SLIDES; j++)
        {
            sCreditsData->monToShow[j] = sCreditsData->monToShow[page];

            page++;
            if (page == sCreditsData->numMonToShow)
                page = 0;
        }
        // Ensure the last pokemon is our starter
        sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
    }
    else
    {
        // Check to see if our starter has already appeared in this list, break if it has
        for (dexNum = 0; sCreditsData->monToShow[dexNum] != starter && dexNum < NUM_MON_SLIDES; dexNum++);

        // If it has, swap it with the last pokemon, to ensure our starter is the last image
        if (dexNum < sCreditsData->numMonToShow - 1)
        {
            sCreditsData->monToShow[dexNum] = sCreditsData->monToShow[NUM_MON_SLIDES-1];
            sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
        }
        else
        {
            // Ensure the last pokemon is our starter
            sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
        }
    }
    sCreditsData->numMonToShow = NUM_MON_SLIDES;
}
