;-----SUBROUTINE: _vbl_isr
;
; PURPOSE: Sets the vertical blank flag, and updates the music
;
;
; INPUT: none
;
; OUTPUT: none
;

				xdef		_vbl_isr
				xref		_update_music
				xref		_vbFlag
				xref		_musicCounter
				
				
_vbl_isr:		movem.l		d0-d7/a0-a6,-(sp)
				lea			_vbFlag,a0
				move.l		#1,(a0)	 				;Set vbl flag to true
				jsr			_update_music
				movem.l		(sp)+,d0-d7/a0-a6
				rte									;return