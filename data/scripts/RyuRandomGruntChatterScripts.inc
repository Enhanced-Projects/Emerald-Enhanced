@Magma

MH_RandomGruntSpeak::
	random 7
	switch VAR_RESULT
	case 0, MH_RandomGruntChatter1
	case 1, MH_RandomGruntChatter2
	case 2, MH_RandomGruntChatter3
	case 3, MH_RandomGruntChatter4
	case 4, MH_RandomGruntChatter5
	case 5, MH_RandomGruntChatter6
	case 6, MH_RandomGruntChatter7
	goto MH_RandomGruntChatter1
	
MH_RandomGruntChatter1::
	msgbox MH_GruntChatter1
	release
	end
	
MH_RandomGruntChatter2::
	msgbox MH_GruntChatter2
	release
	end
	
MH_RandomGruntChatter3::
	msgbox MH_GruntChatter3
	release
	end

MH_RandomGruntChatter4::
	msgbox MH_GruntChatter4
	release
	end

MH_RandomGruntChatter5::
	msgbox MH_GruntChatter5
	release
	end

MH_RandomGruntChatter6::
	msgbox MH_GruntChatter6
	release
	end

MH_RandomGruntChatter7::
	msgbox MH_GruntChatter7
	release
	end
	
MH_GruntChatter1:
	.string "I really need a raise.$"
	
MH_GruntChatter2:
	.string "I heard that Courtney's Mightyena\neats people. That's crazy!$"
	
MH_GruntChatter3:
	.string "You really don't wanna get on\nMaxie's bad side.\pBut Courtney is way harsher.\nBest to do what you're told.$"
	
MH_GruntChatter4:
	.string "Why did I join Magma...\n it's way too hot here!$"
	
MH_GruntChatter5:
	.string "Blaise is kinda the cool\nguy. I much prefer getting\lassignments from him.$"
	
MH_GruntChatter6:
	.string "Don't ever make fun of Tabitha's\nname. He gets really upset.$"
	
MH_GruntChatter7:
	.string "I think Courtney's cute\nbut I am not into crazy.\lThat girl is All crazy.$"


@Aqua hideout
AH_RandomGruntSpeak::
	random 7
	switch VAR_RESULT
	case 0, AH_RandomGruntChatter1
	case 1, AH_RandomGruntChatter2
	case 2, AH_RandomGruntChatter3
	case 3, AH_RandomGruntChatter4
	case 4, AH_RandomGruntChatter5
	case 5, AH_RandomGruntChatter6
	case 6, AH_RandomGruntChatter7
	goto AH_RandomGruntChatter1


AH_RandomGruntChatter1::
	msgbox AH_GruntChatter1
	release
	end

AH_RandomGruntChatter2::
	msgbox AH_GruntChatter2
	release
	end

AH_RandomGruntChatter3::
	msgbox AH_GruntChatter3
	release
	end

AH_RandomGruntChatter4::
	msgbox AH_GruntChatter4
	release
	end

AH_RandomGruntChatter5::
	msgbox AH_GruntChatter5
	release
	end

AH_RandomGruntChatter6::
	msgbox AH_GruntChatter6
	release
	end

AH_RandomGruntChatter7::
	msgbox AH_GruntChatter7
	release
	end

AH_GruntChatter1:
	.string "I feel like going out for a swim.$"

AH_GruntChatter2:
	.string "If we can get the oceans to\nexpand, that means longer beaches!$"

AH_GruntChatter3:
	.string "There's rumors going around that\nsay Archie is off his rocker.$"

AH_GruntChatter4:
	.string "Shelly is so hot, You're a\nlucky person, you know?\pLots of grunts are jealous...$"

AH_GruntChatter5:
	.string "Big things are about to happen!$"

AH_GruntChatter6:
	.string "I'd like to use a Mantine.\nThey're really strong.\pBut I want to fit in with everyone\nso I use the regular stuff.$"

AH_GruntChatter7:
	.string "How do those magma members\nstand wearing so much clothing?\pI would suffocate in minutes.$"
