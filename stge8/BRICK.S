; Generated by c68 v4.4.5, 25 Jan 95 (Jan 25 1995) from "brick.c"
	text
L1:
	dc.b	27,69,27,102,10,0
	even
_main:
	link	a6,#-640
	movem.l	d3/d4/d5/d6/d7/a3/a4/a5,-(a7)
	lea	_checkScreenClock,a3
	lea	-596(a6),a0
	move.l	a0,d7
	lea	-12(a6),a4
	lea	-8(a6),a5
	;line	20
	jsr	_getScreenBase
	move.l	d0,-4(a6)
	move.l	-4(a6),(a5)
	move.l	#_secondBuffer,(a4)
	move.l	(a4),-16(a6)
	clr.w	-598(a6)
	;line	20
	jsr	_splashScreenLoop
	move.w	d0,-604(a6)
	;line	22
	tst.w	-604(a6)
	bne	L2
	;line	23
	bra	L4
L3:
	;line	25
	addq.l	#1,-16(a6)
L4:
	pea	256
	move.l	-16(a6),-(a7)
	jsr	.Xlrem
	tst.l	d0
	bne	L3
L5:
	;line	27
	move.l	-16(a6),(a4)
	;line	29
	pea	L1
	jsr	_printf
	addq.l	#4,a7
	;line	30
	move.l	d7,-(a7)
	jsr	_initialize
	addq.l	#4,a7
	;line	31
	move.l	(a5),-(a7)
	lea	-580(a7),a7
	move.l	d7,a0
	move.l	a7,a1
	move.w	#144,d0
L6:
	move.l	(a0)+,(a1)+
	dbra	d0,L6
	jsr	_printScreen
	lea	584(a7),a7
	;line	32
	move.l	(a4),-(a7)
	lea	-580(a7),a7
	move.l	d7,a0
	move.l	a7,a1
	move.w	#144,d0
L7:
	move.l	(a0)+,(a1)+
	dbra	d0,L7
	jsr	_printScreen
	lea	584(a7),a7
	;line	33
	jsr	_start_music
	;line	34
	jsr	(a3)
	move.l	d0,-608(a6)
	;line	35
	jsr	(a3)
	move.l	d0,d6
	;line	36
	jsr	(a3)
	move.l	d0,d5
	bra	L8
L2:
	;line	38
	cmp.w	#3,-604(a6)
	bne	L9
	;line	39
	move.w	#1,-598(a6)
L9:
L8:
	;line	41
	bra	L11
L10:
	;line	43
	jsr	_checkInputBuffer
	tst.w	d0
	beq	L13
	;line	45
	jsr	_getInput
	move.l	d0,-602(a6)
	;line	46
	cmp.l	#65563,-602(a6)
	bne	L14
	;line	47
	move.w	#1,-598(a6)
	bra	L15
L14:
	;line	49
	move.l	-602(a6),-(a7)
	move.l	d7,-(a7)
	jsr	_keyPress
	addq.l	#8,a7
L15:
L13:
	;line	51
	jsr	(a3)
	move.l	d0,d4
	;line	52
	move.l	d4,d3
	;line	53
	move.l	d3,d0
	sub.l	d6,d0
	move.l	d0,-628(a6)
	;line	54
	move.l	d3,d0
	sub.l	d5,d0
	move.l	d0,-640(a6)
	;line	56
	move.l	-628(a6),-(a7)
	jsr	_update_music
	addq.l	#4,a7
	cmp.w	#1,d0
	bne	L16
	;line	57
	move.l	d3,d6
	bra	L17
L16:
	;line	59
	cmp.l	#50,-640(a6)
	bls	L18
	;line	60
	move.l	d3,d5
	;line	61
	move.l	-640(a6),-(a7)
	jsr	_update_music
	addq.l	#4,a7
L18:
L17:
	;line	64
	move.l	d4,d0
	sub.l	-608(a6),d0
	tst.l	d0
	bls	L19
	tst.w	-20(a6)
	bne	L19
	;line	66
	jsr	(a3)
	move.l	d0,d4
	;line	67
	move.l	d4,-608(a6)
	;line	68
	move.l	d7,-(a7)
	jsr	_moveBall
	addq.l	#4,a7
	;line	69
	tst.w	-278(a6)
	bne	L20
	;line	71
	move.l	(a4),-(a7)
	move.l	(a5),-(a7)
	move.l	d7,-(a7)
	jsr	_levelCleared
	lea	12(a7),a7
	;line	72
	jsr	_start_music
	;line	73
	jsr	(a3)
	move.l	d0,d6
	;line	74
	jsr	(a3)
	move.l	d0,d5
	bra	L21
L20:
	;line	78
	move.w	#37,-(a7)
	jsr	__trap_14_w
	addq.l	#2,a7
	;line	79
	move.l	(a4),-(a7)
	move.l	d7,-(a7)
	jsr	_refreshScreen
	addq.l	#8,a7
	;line	80
	move.l	a4,-(a7)
	move.l	a5,-(a7)
	jsr	_swapScreenBuffers
	addq.l	#8,a7
L21:
L19:
L11:
	tst.w	-598(a6)
	bne	L22
	tst.w	-18(a6)
	beq	L10
L22:
L12:
	;line	84
	move.w	#-1,-(a7)
	move.l	-4(a6),-(a7)
	pea	-1
	move.w	#5,-(a7)
	jsr	__trap_14_wllw
	lea	12(a7),a7
	;line	85
	jsr	_stop_sound
	;line	86
	pea	L1
	jsr	_printf
	;line	87
	moveq	#0,d0
L23:
	movem.l	-672(a6),d3/d4/d5/d6/d7/a3/a4/a5
	unlk	a6
	rts
_checkScreenClock:
	link	a6,#-12
	;line	95
	move.l	#1122,-12(a6)
	;line	95
	pea	0
	move.w	#32,-(a7)
	jsr	__trap_1_wl
	addq.l	#6,a7
	move.l	d0,-8(a6)
	;line	96
	move.l	-12(a6),a0
	move.l	(a0),-4(a6)
	;line	97
	move.l	-8(a6),-(a7)
	move.w	#32,-(a7)
	jsr	__trap_1_wl
	;line	98
	move.l	-4(a6),d0
L24:
	unlk	a6
	rts
	globl	_checkScreenClock
	bss
_secondBuffer:
	ds.b	32256
	globl	_secondBuffer
	globl	_main
