				xdef		_vbl_isr
				xref		_vbFlag

_vbl_isr:		movem.l		d0-d7/a0-a6,-(sp)
				lea			_vbFlag,a0
				move.l		#1,(a0)	 			;Set vbl flag to true
				movem.l		(sp)+,d0-d7/a0-a6
				rte								;return