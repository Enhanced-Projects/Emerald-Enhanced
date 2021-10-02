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
    call RyuBufferPartyMonNames
    multichoice 1, 1, MULTI_DYNAMIC_6, 0
    specialvar VAR_TEMP_A, CheckIfSelectedSlotIsValid
	compare VAR_TEMP_A, FALSE
	goto_if_eq ryu_end
	special RyuFillStatsBuffers
	delay 30
    drawinfobox INFOBOXPOKEMONDATA
    bufferpartymonnick 6, VAR_RESULT
	msgbox RyuAP_StatMsg
	removeinfobox
    release
    end

RyuAP_StatsFailed::
    msgbox RyuAP_ErrorMsg
    release
    end

RyuAP_StatMsg:
    .string "Viewing {RYU_STR_4}'s stats.$"

RyuAP_ErrorMsg:
    .string "There was an error attempting\nto read stats.$"
