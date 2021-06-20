Common_EventScript_PkmnCenterNurse:: @ 827195A
    call_if_set FLAG_RYU_USED_WIRELESSPC, PCN_RechargeWirelessPC
    incrementgamestat GAME_STAT_USED_POKECENTER
    readgamestat GAME_STAT_USED_POKECENTER
    compare VAR_RESULT, 256
    call_if_ge PkmnCenterNurse_MegaAudinite
    compare VAR_RESULT, 50
    call_if_ge RyuCheckIfQualifiesForNurseQuest
    call Ryu_CheckHealPermissions
    switch VAR_RYU_QUEST_NURSE
    case 1, PCN_Stage1HealMsg
    case 3, PCN_Stage2HealMsg
    case 5, PCN_Stage3HealMsg
    case 7, PCN_Stage4HealMsg
    case 10, PCN_Stage5HealMsg
    goto PCN_Stage1HealMsg

RyuCheckIfQualifiesForNurseQuest::
    compare VAR_RYU_QUEST_NURSE, 0
    call_if_eq RyuEnableNurseQuest
    return

RyuEnableNurseQuest::
    setflag FLAG_RYU_CAN_DO_NURSE_QUEST
    return

PCN_Stage1HealMsg::
    message gText_IllTakeYourPkmn
    goto PCN_HealMons

PCN_Stage2HealMsg::
    msgbox PCN_S2HealText
	goto PCN_HealMons

PCN_Stage3HealMsg::
    msgbox PCN_S3HealText
	goto PCN_HealMons

PCN_Stage4HealMsg::
    msgbox PCN_S4HealText
	goto PCN_HealMons

PCN_Stage5HealMsg::
    msgbox PCN_S5HealText
	goto PCN_HealMons
	
PCN_S2HealText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Oh! Hi!\nLet me heal you up real quick!$"

PCN_S3HealText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}It's nice to see you again!\nYou've been busy, I see!$"

PCN_S4HealText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}! Welcome back.\nLet me make you feel better...$"

PCN_S5HealText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}! I missed you!\nI'll make the kids all better...$"

PCN_HealMons::
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
    waitmovement 0
    dofieldeffect FLDEFF_POKECENTER_HEAL
    waitfieldeffect FLDEFF_POKECENTER_HEAL
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
    waitmovement 0
    special HealPlayerParty
	switch VAR_RYU_QUEST_NURSE
	case 3, PCN_HealOutroText2
	case 5, PCN_HealOutroText3
	case 7, PCN_HealOutroText4
	case 10, PCN_HealOutroText5
	goto PCN_HealOutroText1
	
PCN_HealOutroText1:
    msgbox HaveANiceDay
    closemessage
    releaseall
    end
	
PCN_HealOutroText2:
	msgbox S2OutroText
	goto ryu_end
	
PCN_HealOutroText3:
	msgbox S3OutroText
	goto ryu_end

PCN_HealOutroText4:
	msgbox S4OutroText
	goto ryu_end

PCN_HealOutroText5:
    msgbox S5OutroText
    goto ryu_end

	
S2OutroText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Nice seeing you again!$"
	
S3OutroText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I wish you would come visit\nme under other circumstances...$"
	
S4OutroText:
	.string "{COLOR LIGHT_RED}{SHADOW RED}It's always a pleasure to see\nyou.$"

S5OutroText:
    .string "{COLOR LIGHT_RED}{SHADOW RED}{PLAYER}, when will you come stay\nwith me again?$"

PCN_RechargeWirelessPC::
    msgbox PCN_RechargedWirelessPc
    clearflag FLAG_RYU_USED_WIRELESSPC
    playse SE_PC_ON
    return

PCN_RechargedWirelessPc:
    .string "Here, I'll charge your PC device\n"
    .string "as well...$"

PCN_CantUseThisHere::
    msgbox PCN_CantUseWPCHere
    closemessage
    release
    end

PCN_CantUseWPCHere:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Could not connect to uplink satellite.$"

PkmnCenterNurse_MegaAudinite::
    goto_if_set FLAG_RYU_GOT_AUDINITE, ryu_return
    setflag FLAG_RYU_GOT_AUDINITE
    givemon SPECIES_AUDINO, 50, ITEM_AUDINITE
    givepokedexflag SPECIES_AUDINO, TRUE
    msgbox PCN_AudiniteExplain
    closemessage
    return

PCN_AudiniteExplain:
    .string "Nurse: I sure see you a lot,\n"
    .string "{PLAYER}. If I didn't know better,\p"
    .string "I'd say you were {COLOR LIGHT_GREY}{SHADOW DARK_GREY} trying\n"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}to come visit me.\p"
    .string "Why don't you take this Audino\n"
    .string "and have it heal you while you're\p"
    .string "out adventuring? Audino love to\n"
    .string "support others. I think this one\l"
    .string "would be happy to help you!$"

Ryu_CheckHealPermissions::
    goto_if_set FLAG_RYU_HARDCORE_MODE, Ryu_NoPcUsesHardcore
    goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_CheckSetNuzlockPCUseVar
    return


PCN_NurseFollower::
    msgbox PCN_CanIComeWith, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq FollowerNurseSetup
    release
    end

PCN_CanIComeWith:
    .string "{COLOR LIGHT_RED}{SHADOW RED}Did you... by chance...\nwant a companion for your travels?$"

HaveANiceDay:
    .string "Have a nice day!$"

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom:: @ 82719B1
    specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
    compare VAR_RESULT, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    specialvar VAR_RESULT, BufferUnionRoomPlayerName
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    compare VAR_0x8008, 1
    goto_if_eq EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
    end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn:: @ 82719E2
    compare VAR_0x8004, 1
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn2
    message gText_RestoredPkmnToFullHealth
    waitmessage
    applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_ReturnPkmn2:: @ 8271A03
    message gText_ThankYouForWaiting
    waitmessage
    applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom:: @ 8271A19
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
    msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_CheckPokerus:: @ 8271A43
    specialvar VAR_RESULT, IsPokerusInParty
    compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_ExplainPokerus
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_ExplainPokerus:: @ 8271A5F
    message gText_PokerusExplanation
    setflag FLAG_POKERUS_EXPLAINED
    return

EventScript_PkmnCenterNurse_GoldCard:: @ 8271A68
    goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
    setflag FLAG_NURSE_MENTIONS_GOLD_CARD
    msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement VAR_0x800B, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement VAR_0x800B, Common_Movement_Delay48
    waitmovement 0
    msgbox gText_NoticesGoldCard, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_AskForUsual:: @ 8271AAC
    msgbox gText_YouWantTheUsual, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_GoldCardHealPkmn:: @ 8271AC5
    end

EventScript_PkmnCenterNurse_Bow: @ 8271AD0
    nurse_joy_bow
    delay_4
    step_end
