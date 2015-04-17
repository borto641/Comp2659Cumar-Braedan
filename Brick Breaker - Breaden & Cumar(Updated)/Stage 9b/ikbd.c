#include "ikbd.h"

long ikbdFlag = 0; 
UINT8 ikbd_bfr[255];
int head = 0, tail = 0;
int main(){

Vector orig_vector = installVector(IKBD_VECT, ikbd_isr);
long old_ssp;
int i;
UINT8 s;
SINT8 x,y;

ikbdFlag = 0;

/*
old_ssp = Super(0);
*IKBD_control = DISABLE;


    i = 0;
    while(i != 10){
        if (RDR_FULL){
            s = read_scancode();
            if(s >= 0xf8){
                x = read_scancode();
                y = read_scancode();
                printf("%s\n", "mouse");
            }
            else{
                ikbd_bfr[tail] = s;
                ikbd_bfr[tail + 1] = read_scancode();
                tail += 2 ;
                if(tail >= 256)
                    tail = 0;
            }
            i++;
        }
    }
   
        printf("%x\n", ikbd_bfr[0]);
        printf("%x\n", ikbd_bfr[1]);
   
    
    *IKBD_control = ENABLE;
    Super(old_ssp);
*/
    
    
    while(Cnecin() != ESC){
        if(ikbdFlag == 1){
            printf("%s\n", "innnnn");
        }
    }
    installVector(IKBD_VECT, orig_vector);
    
    return 0;
}
SCANCODE read_scancode(){
    while (!(*IKBD_status & RDR_FULL))
        ;
	return *IKBD_RDR;
}