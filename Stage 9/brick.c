#include "brick.h"

const UINT8 secondBuffer[32256];

long vbFlag = FALSE;

int main()
{
	Vector orig_vector = installVector(VBL_VECT, vbl_isr);

	UINT8 *defaultScreen = getScreenBase();
	UINT8 *frontScreen = defaultScreen;
	UINT8 *backScreen = secondBuffer;
	long tempUINT8 = (long)(backScreen);
	Screen screen;
	bool quit = FALSE;
	long input;
	long oldSSP;
    int result;
    unsigned int musicCounter = 0;

	
    result = splashScreenLoop();
	
    if(result == 0)
	{
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
        
		if (vbFlag == TRUE && !screen.holdBall)
		{		
			moveBall(&screen);
			if(screen.bricksLeft == 0)
			{
				levelCleared(&screen, frontScreen, backScreen);
				start_music();
			}
			else
			{
				refreshScreen(&screen, (UINT32*)(backScreen));
				swapScreenBuffers(&frontScreen, &backScreen);
			}
			vbFlag = FALSE;
		}
	}
	Setscreen(-1, defaultScreen, -1);
    stop_sound();
	installVector(VBL_VECT, orig_vector);
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




