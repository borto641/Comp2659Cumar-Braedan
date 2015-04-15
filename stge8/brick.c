#include "brick.h"

const UINT8 secondBuffer[32256];


int main()
{
	UINT8 *defaultScreen = getScreenBase();
	UINT8 *frontScreen = defaultScreen;
	UINT8 *backScreen = secondBuffer;
	long tempUINT8 = (long)(backScreen);
	Screen screen;
	bool quit = FALSE;
	long input;
    int result;
	UINT32 timeThen, timeNow, timeElapsed;
    UINT32 timeThen2, timeNow2, timeElapsed2;
    UINT32 timeThen3, timeNow3, timeElapsed3;
	
    result = splashScreenLoop();
	
    if(result == 0){
        while ((tempUINT8 % 256) != 0)
        {
            tempUINT8++;
        }
        backScreen = (UINT8*)(tempUINT8);
            
        printf("\033E\033f\n"); 
        initialize(&screen);
        printScreen(screen, (UINT32*)(frontScreen));
        printScreen(screen, (UINT32*)(backScreen));
        start_music();
        timeThen  =  checkScreenClock();
        timeThen2 =  checkScreenClock();
        timeThen3 =  checkScreenClock();
	}
    else if (result == 3)
        quit = TRUE;
    
	while (!quit && !screen.gameOver)
	{	
		if (checkInputBuffer())
		{
			input = getInput();
			if (input == ESC)
				quit = TRUE;
			else
				keyPress(&screen, input);
		}
        timeNow       = checkScreenClock();
        timeNow2      = timeNow;
        timeElapsed2  = timeNow2 - timeThen2;    
        timeElapsed3  = timeNow2 - timeThen3;
        
        if(update_music(timeElapsed2) == 1){
            timeThen2 = timeNow2;
        }
        else if(timeElapsed3 > 50){
            timeThen3 = timeNow2;
            update_music(timeElapsed3);
        }
        
		if (timeNow - timeThen > 0 && !screen.holdBall)
		{
			timeNow = checkScreenClock();
			timeThen = timeNow;
			moveBall(&screen);
			if(screen.bricksLeft == 0)
			{
				levelCleared(&screen, frontScreen, backScreen);
                start_music();
                timeThen2 =  checkScreenClock();
                timeThen3 =  checkScreenClock();
			}
			else
			{
				Vsync();	 
				refreshScreen(&screen, (UINT32*)(backScreen));
				swapScreenBuffers(&frontScreen, &backScreen);
			}
		}
	}
	Setscreen(-1, defaultScreen, -1);
    stop_sound();
    printf("\033E\033f\n"); 
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




