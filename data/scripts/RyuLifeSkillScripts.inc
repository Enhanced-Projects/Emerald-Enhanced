@@Life Skills scripts

@@Mining General

Ryu_MineOutsideRock::
    playse SE_W088
    waitse
    playse SE_W088
    waitse
    playse SE_W088
    delay 20
    dominingcheck
    compare VAR_TEMP_B, 0
    goto_if_eq Ryu_MineFailed
    additem VAR_TEMP_B, VAR_TEMP_C
    bufferitemname 1, VAR_TEMP_B
    buffernumberstring 0, VAR_TEMP_C
    return

Ryu_MineFailed::
    msgbox Ryu_FailedToMine
    release
    end

Ryu_NoOresHere::
    msgbox Ryu_NothingHere
    release
    end

Ryu_FailedToMine:
    .string "You failed to mine anything.$"

Ryu_YouMinedA:
    .string "{PLAYER} mined {STR_VAR_1} {STR_VAR_2}(s)\nfrom the rock!$"

Ryu_NothingHere:
    .string "There doesn't seem to be\nanything of interest here.$"

@overworld mining scripts

r101_MiningRock1::
    goto_if_set FLAG_TEMP_2, Ryu_NoOresHere
    setflag FLAG_TEMP_2
    call Ryu_MineOutsideRock
    playfanfare MUS_FANFA1
    msgbox Ryu_YouMinedA
    waitfanfare
    release
    end

r101_MiningRock2::
    goto_if_set FLAG_TEMP_3, Ryu_NoOresHere
    setflag FLAG_TEMP_3
    call Ryu_MineOutsideRock
    playfanfare MUS_FANFA1
    msgbox Ryu_YouMinedA
    waitfanfare
    release
    end

