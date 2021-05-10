const u8 sQuestStage0[] = _("HELLO\nWORLD\n3RD LINE\n4TH LINE");
const u8 sAquaQuestStage5Desc[] = _("Player chose Run For It in Rusturf.\nTake goods to the Aqueus Corp.\noffice in Lilycove.");

struct QuestStageDesc
{
  const u8 * description;
  u16 questStage;
};

const static struct QuestStageDesc gAquaQuestStages[] = {
  {
    .description = sQuestStage0,
    .questStage = 0,
  },
  {
    .description = sAquaQuestStage5Desc,
    .questStage = 5,
  },
};