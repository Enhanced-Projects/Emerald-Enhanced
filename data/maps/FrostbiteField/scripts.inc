FrostbiteField_MapScripts::
	.byte 0


FrostbiteField_TestBattle::
	cleartrainerflag TRAINER_OVERLORD_RYU
	trainerbattle_no_intro TRAINER_OVERLORD_RYU, RCR_RYU_DefeatText
	release
	end
	