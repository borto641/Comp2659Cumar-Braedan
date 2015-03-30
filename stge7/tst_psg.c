#include <osbind.h>
#include <stdio.h>
#include "psg.h"

int main()
{
    int i,w,x,y,z;
	long old_ssp = Super(0);
    /*
    w = 0;
    while(w < 1){
        ball_hits_paddle_sound();
        music (0, 111, 5000);
        music (0, 100, 5000);
        music (0, 74,  5000);
        music (0, 100, 5000);
        ball_hits_wall_sound();
        music (1, 148, 5000);
        music (1, 137, 5000);
        music (1, 122, 5000);
        music (1, 137, 5000);
        ball_hits_paddle_sound();
        w++;
    }
    */
    i = 0;
    while(i < 16){
        write_psg(i, 0);
        i++;
    }
    
     write_psg(0, 100);
     write_psg(1, 0);
     write_psg(7, 0x3E);
     write_psg(8, 11);
     
     while(i < 16){
        write_psg(i, 0);
        i++;
    }
    
    write_psg(13, 150);
    write_psg(14, 150);
    write_psg(15, 10);
   
    stop_sound();
	Super(old_ssp);
	return 0;
}