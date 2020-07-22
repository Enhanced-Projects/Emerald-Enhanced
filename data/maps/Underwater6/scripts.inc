Underwater6_MapScripts:: @ 81F773D
	map_script ON_RESUME, Underwater6_OnResume
	.byte 0

Underwater6_OnResume: @ 81F7743
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end

