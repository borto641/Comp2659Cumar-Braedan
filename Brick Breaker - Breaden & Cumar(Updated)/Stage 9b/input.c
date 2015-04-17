#include "input.h"

bool checkInputBuffer()
{
    int i;
    long old_ssp;
    bool key_pressed = FALSE;
    UINT8 s,p;
    SINT8 x,y;
    old_ssp = Super(0);
    *IKBD_control = DISABLE; 
    
    s = *IKBD_RDR;
    p = *IKBD_RDR;
     
    if (s != p){
      
            key_pressed = TRUE;
               
            if(s >= 0xF8){
                x = *IKBD_RDR;
                y = *IKBD_RDR;
            }
            else{
              /*  p = *IKBD_RDR;*/
                ikbd_bfr[tail] = s;
                tail += 1 ;
                if(tail >= 256)
                    tail = 0;
            }
        }
       
    *IKBD_control = ENABLE;
    Super(old_ssp);
    
	return key_pressed;
}

long getInput()
{
    UINT8 key;
    
    key = ikbd_bfr[head];
    if(head < tail)
        head += 1;
    
	return key;
}

SCANCODE read_scancode(){
    while (!(*IKBD_status & RDR_FULL))
        ;
	return *IKBD_RDR;
}