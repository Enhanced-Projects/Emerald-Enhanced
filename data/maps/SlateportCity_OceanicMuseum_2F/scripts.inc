SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1:: @ 820BD0A
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2:: @ 820BD13
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment:: @ 820BD1C
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel:: @ 820BD25
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay:: @ 820BD2E
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay:: @ 820BD37
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica:: @ 820BD40
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica:: @ 820BD49
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica:: @ 820BD52
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica:: @ 820BD5B
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1:: @ 820BD64
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2:: @ 820BD6D
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3:: @ 820BD76
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip: @ 820C43F
	.string "I saw a model of a ship here.\p"
	.string "It reminded me of the Abandoned Ship\n"
	.string "near Dewford Town…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum: @ 820C495
	.string "Don't you dare run around inside\n"
	.string "the Museum!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine: @ 820C4C2
	.string "Wow, the submarine's awesome!\n"
	.string "I want to go for a ride!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1: @ 820C4F9
	.string "“WATER Quality Sample 1,” the\n"
	.string "label says.\p"
	.string "The sea is all connected, but the\n"
	.string "water seems to differ by region.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2: @ 820C566
	.string "“WATER Quality Sample 2,” the\n"
	.string "label says.\p"
	.string "Does the saltiness of seawater differ\n"
	.string "by region, too?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment: @ 820C5C6
	.string "A rubber ball is expanding and\n"
	.string "shrinking.\p"
	.string "“In the sea, the weight of water itself\n"
	.string "exerts pressure.\p"
	.string "“In shallow water, the pressure is not\n"
	.string "very heavy.\p"
	.string "“However, in extremely deep water,\n"
	.string "the pressure can reach even tens of\l"
	.string "thousands of tons on a small area.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel: @ 820C6C7
	.string "“MODEL OF Hoenn REGION”\p"
	.string "It's a miniature diorama of the\n"
	.string "Hoenn region.\p"
	.string "Where is Littleroot Town on this?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay: @ 820C72F
	.string "It's a display on the flow of seawater.\p"
	.string "“Near the bottom of the sea, water\n"
	.string "flows due to differences in such\l"
	.string "factors as temperature and salinity.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay: @ 820C7C1
	.string "It's a display on the flow of seawater.\p"
	.string "“Toward the surface, seawater flows\n"
	.string "as currents driven by the winds.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica: @ 820C82F
	.string "“THE Ferry S.S. Tidal\p"
	.string "“A scale replica of the ship under\n"
	.string "construction at Stern's Shipyard.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica: @ 820C88B
	.string "“SUBMARINE Explorer 1\p"
	.string "“A replica of the high-performance\n"
	.string "ocean floor exploration submarine.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica: @ 820C8E8
	.string "“SUBMERSIBLE Pod\p"
	.string "“A replica of a compact, unmanned\n"
	.string "pod for seafloor exploration.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica: @ 820C93A
	.string "“S.S. Anne\p"
	.string "“A replica of the luxury liner that\n"
	.string "circles the globe.”$"

