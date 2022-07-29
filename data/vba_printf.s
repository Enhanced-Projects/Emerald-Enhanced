.arm
.global vbaprint
.type   vbaprint STT_FUNC
.text
vbaprint:
	swi 0xFF0000
	bx lr