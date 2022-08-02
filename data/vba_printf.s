.arm
.global vbaprint
.type   vbaprint STT_FUNC
.text
vbaprint:
	swi 0xFF0000
	bx lr


.arm
.global StdMsgBox
.type StdMsgBox STT_FUNC
.text
StdMsgBox:
	swi 0x091100
	bx lr