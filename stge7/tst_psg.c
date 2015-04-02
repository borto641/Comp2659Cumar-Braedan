#include <osbind.h>
#include <stdio.h>
#include "psg.h"
#include "music.h"
#include "effects.h"

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
    while(i <255){
    /*
        ballHitsPaddleSound();
        ballHitsWallSound();
      
      ballHitsBrickSound();
      */
         ballHitsWallSound();
      
        while(!Cconis())
            ;
        Cnecin();
    
        i++;
    }
    stop_sound();
    Cnecin();
	Super(old_ssp);
	return 0;
}