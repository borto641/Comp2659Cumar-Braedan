#include <osbind.h>
#include <stdio.h>
#include "psg.h"
#include "music.h"
#include "effects.h"
#define SCREEN_CLOCK 0x462

UINT32 checkScreenClock();

int main()
{
    int i,w,x,y,z;
    UINT32 timeThen, timeNow, timeElapsed;
    
    start_music();
    timeThen =  checkScreenClock();
    
    while(!Cconis()){
        timeNow      = checkScreenClock();
        timeElapsed  = timeNow - timeThen;
        
        if(update_music(timeElapsed) == 1)
            timeThen = timeNow;
            
    }
    stop_sound();
    Cnecin();

	return 0;
}

UINT32 checkScreenClock()
{
		UINT32 time;
		long old_ssp;
		long *clock = SCREEN_CLOCK;
		old_ssp = Super(0);
		time = *clock;
		Super(old_ssp);
		return time;
}