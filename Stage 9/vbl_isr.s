				xdef		_vbl_isr
				xref		_vbFlag

_vbl_isr:		movem.l		d0-d7/a0-a6,-(sp)
				lea			_vbFlag,a0
				move.b		#1,(a0)				;Set a flag to true
				movem.l		(sp)+,d0-d7/a0-a6
				rte								;return