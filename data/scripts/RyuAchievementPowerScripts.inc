@@Contains scripts for AP related items

RyuAP_PDA::
    msgbox RyuRCTS
    closemessage
    playbgm MUS_FRIENDLY
    pokemart 0
    fadedefaultbgm
    release
    end

RyuRCTS:
    .string "Now connecting to a shop...$"

RyuAP_StatAssist::
    setflag FLAG_TEMP_F
    multichoicedefault 0, 0, MULTI_SELECT_PARTY_SLOT, 0, 0
	specialvar VAR_TEMP_B, RyuFillStatsBuffers
	compare VAR_RESULT, TRUE
	goto_if_ne RyuAP_StatsFailed
	delay 30
    drawinfobox INFOBOXPOKEMONDATA
    bufferpartymonnick VAR_RESULT, 0
	msgbox Ryu_Stats
	removeinfobox
    release
    end

RyuAP_StatsFailed::
    msgbox RyuAP_ErrorMsg
    release
    end

RyuAP_ErrorMsg:
    .string "There was an error attempting\nto read stats.$"