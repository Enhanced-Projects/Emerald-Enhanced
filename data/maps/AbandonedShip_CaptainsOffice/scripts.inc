AbandonedShip_CaptainsOffice_MapScripts:: @ 82387E1
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide:: @ 82387E2
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner:: @ 8238810
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus:: @ 823881A
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner: @ 8238824
	.string "I'm investigating this ship on behalf\n"
	.string "of CAPT. STERN.\p"
	.string "He also asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner: @ 823889D
	.string "Oh! That's a SCANNER!\p"
	.string "Listen, can I get you to deliver that\n"
	.string "to CAPT. STERN?\p"
	.string "I want to investigate this ship a\n"
	.string "little more.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus: @ 8238918
	.string "This ship is called S.S. CACTUS.\n"
	.string "It seems to be from an earlier era.$"
	
@==================================================================================================LANA AbandonedShip_CaptainsOffice_EventScript_2387E2
AS_Leaf_Event::
	msgbox AS_LeafMsg1 MSGBOX_DEFAULT
	closemessage
	msgbox AS_LeafMsg12 MSGBOX_DEFAULT
	applymovement 3, AS_PushingDown
	applymovement OBJ_EVENT_ID_PLAYER, AS_PushedDown
	waitmovement 3
	removeobject 3
	playse SE_DOOR
	waitse
	msgbox AS_PlayerMsg1 MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox AS_PlayerMsg2 MSGBOX_DEFAULT
	@setflag FLAG_LANA_EVENT_4
	setflag FLAG_HIDE_ABN_SHIP_LANA
	setvar VAR_RYU_DS_LANA_STAGE, 25
	clearflag FLAG_HIDE_PCF_TOWN_LANA
	release
	end
	
AS_LeafMsg1:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ...$"
	
AS_LeafMsg12:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (She seems upset by something.)\p{COLOR LIGHT_BLUE}{SHADOW BLUE}Hey, are you-$"

AS_PlayerMsg1:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}... ... ... ...\pWhat just...happened?$"
	
AS_PlayerMsg2:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Oh! Another note.\p {COLOR LIGHT_GREEN}{SHADOW GREEN}(This town was built atop a\n colony of Corsola, and functioned\l as a floating storehouse.)\p{COLOR LIGHT_RED}{SHADOW RED}... ... ... ...\p"
	.string "This can't be real...why's this\nhappening? First, the Power Plant,\lnow, the S.S. Anne...it's all\lcoming back to haunt me...!\p... ... ... ...\p{COLOR LIGHT_BLUE}{SHADOW BLUE}What in the world...?\pLana...what happened to you?$"
	
AS_PushedDown:
	walk_fastest_down
	walk_fastest_left
	walk_in_place_fastest_up
	step_end
	
AS_PushingDown:
	walk_in_place_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_down
	step_end

@==================================================================================================END OF EVENT

