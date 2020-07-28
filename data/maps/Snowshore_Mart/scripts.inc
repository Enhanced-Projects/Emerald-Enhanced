Snowshore_Mart_MapScripts::
	.byte 0

Snowshore_Mart_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
