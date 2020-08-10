Common_EventScript_PkmnCenterNurse:: @ 827191E
    lock
    faceplayer
    goto_if_set FLAG_RYU_HARDCORE_MODE, Common_NurseDisabledHardcore
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

Common_NurseDisabledHardcore::
    msgbox HardcoreNurseDisabled
    release
    end

HardcoreNurseDisabled:
    .string "I'm sorry, but our machine isn't\nworking. You can purchase healing\litems at a mart.$"

EventScript_PkmnCenterNurse_Goodbye:: @ 8271954
    message gText_WeHopeToSeeYouAgain
    return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn:: @ 827195A
    call Ryu_CheckHealPermissions
    call_if_set FLAG_RYU_USED_WIRELESSPC, PCN_RechargeWirelessPC
    incrementgamestat GAME_STAT_USED_POKECENTER
    readgamestat GAME_STAT_USED_POKECENTER
    compare VAR_RESULT, 256
    call_if_eq PkmnCenterNurse_MegaAudinite
    compare VAR_0x8004, 0
    call_if_eq EventScript_PkmnCenterNurse_IllTakeYourPkmn
    compare VAR_0x8004, 1
    call_if_eq EventScript_PkmnCenterNurse_IllTakeYourPkmn2
    waitmessage
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn
    releaseall
    end

PCN_RechargeWirelessPC::
    msgbox PCN_RechargedWirelessPc
    clearflag FLAG_RYU_USED_WIRELESSPC
    playse SE_PC_ON
    return

PCN_RechargedWirelessPc:
    .string "Here, i'll charge your PC device\n"
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

EventScript_PkmnCenterNurse_IllTakeYourPkmn:: @ 8271987
    message gText_IllTakeYourPkmn
    return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2:: @ 827198D
    message gText_IllTakeYourPkmn2
    return

EventScript_PkmnCenterNurse_TakeAndHealPkmn:: @ 8271993
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
    waitmovement 0
    dofieldeffect FLDEFF_POKECENTER_HEAL
    waitfieldeffect FLDEFF_POKECENTER_HEAL
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
    waitmovement 0
    call_if_set FLAG_RYU_HIDE_MINNIE, CheckRestoreMinnie
    special HealPlayerParty
    msgbox HaveANiceDay
    closemessage
    return

CheckRestoreMinnie::
    goto_if_unset FLAG_RYU_HAS_FOLLOWER, ryu_return
    compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_TWIN
    goto_if_ne ryu_return
    clearflag FLAG_RYU_HIDE_MINNIE
    return

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
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

EventScript_PkmnCenterNurse_Bow: @ 8271AD0
    nurse_joy_bow
    delay_4
    step_end
