CraggyCoastUnderwaterCave_MapScripts::
	.byte 0

CraggyCoast_Repel::
	lockall
	goto_if_set FLAG_HIDDEN_CRAGGY_COAST_REPEL, FrostyForestEnd
	giveitem ITEM_REPEL
	setflag FLAG_HIDDEN_CRAGGY_COAST_REPEL
	release
	end

CraggyCoast_RareBone::
	lockall
	goto_if_set FLAG_HIDDEN_CRAGGY_COAST_RARE_BONE, FrostyForestEnd
	giveitem ITEM_RARE_BONE
	setflag FLAG_HIDDEN_CRAGGY_COAST_RARE_BONE
	release
	end

CraggyCoast_GreatBall::
	lockall
	goto_if_set FLAG_HIDDEN_CRAGGY_COAST_GREAT_BALL, FrostyForestEnd
	giveitem ITEM_GREAT_BALL
	setflag FLAG_HIDDEN_CRAGGY_COAST_GREAT_BALL
	release
	end

CraggyCoast_DiveBall::
	lockall
	goto_if_set FLAG_HIDDEN_CRAGGY_COAST_DIVE_BALL, FrostyForestEnd
	giveitem ITEM_DIVE_BALL
	setflag FLAG_HIDDEN_CRAGGY_COAST_DIVE_BALL
	release
	end

CraggyCoast_HardStone::
	lockall
	goto_if_set FLAG_HIDDEN_CRAGGY_COAST_HARD_STONE, FrostyForestEnd
	giveitem ITEM_HARD_STONE
	setflag FLAG_HIDDEN_CRAGGY_COAST_HARD_STONE
	release
	end

CraggyCoast_NetBall::
	lockall
	goto_if_set FLAG_HIDDEN_CRAGGY_COAST_NET_BALL, FrostyForestEnd
	giveitem ITEM_NET_BALL
	setflag FLAG_HIDDEN_CRAGGY_COAST_NET_BALL
	release
	end
