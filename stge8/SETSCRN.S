;-----SUBROUTINE: _setScrn
;
; PURPOSE: Sets the physical base of the screen to the given address
;
;
; INPUT: A longword passed by the stack
;
; OUTPUT: none
;
; NOTES: Must be in supervisor mode, or cause a bus error

						xdef		_setScrn
				
				
NEWBASE					equ			8				;The offset of the new address on the stack
HIBASE					equ			$FFFF8201		;The address of the high byte of the current base

_setScrn:				link a6,#0
					movem.l d1/a1,-(sp)
					
					moveq	#0,d1				;Clear d1
					move.l	#HIBASE,a1			;Move Screen base's high address into a1
						
					move.l	NEWBASE(a6),d1		;Move the new base's address into d1
					lsr.l	#8,d1				;Shift right to put the bytes into the d1's low word
					movep.w d1,0(a1)			;Move both bytes, with a 1 byte gap into high byte and low byte
						
					movem.l (sp)+,d1/a1
					unlk 	a6
					rts