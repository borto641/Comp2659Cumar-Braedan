			xdef    _ikbd_isr
            xref    _ikbdFlag
			
_ikbd_isr 	movem.l		d0-d7/a0-a6,-(sp)
            lea			_ikbdFlag,a0
			move.l		#1,(a0)	 			
			movem.l		(sp)+,d0-d7/a0-a6
			rte								