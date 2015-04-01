#include "brick.h"
#include <stdio.h>
const UINT8 secondBuffer[32256];



int main()
{
	UINT8 *defaultScreen = Physbase();
	UINT8 *frontScreen = defaultScreen;
	UINT8 *backScreen = secondBuffer;
	long tempUINT8 = (long)(backScreen);
	Screen screen;
	bool quit = FALSE;
	long input;
	UINT32 timeThen, timeNow, timeElapsed;
	
	while ((tempUINT8 % 256) != 0)
	{
		tempUINT8++;
	}
	backScreen = (UINT8*)(tempUINT8);
		
	printf("\033E\033f\n");
	initialize(&screen);
	printScreen(screen, (UINT32*)(frontScreen));
	printScreen(screen, (UINT32*)(backScreen));
	timeThen = checkScreenClock();
	
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
		timeNow = checkScreenClock();
		if (timeNow - timeThen > 0)
		{
			timeNow = checkScreenClock();
			timeThen = timeNow;
			if (screen.holdBall == FALSE)
			{	
				moveBall(&screen);
			}
			Vsync();	
			refreshScreen(&screen, (UINT32*)(backScreen));
			swapScreenBuffers(&frontScreen, &backScreen);
		}
	}
	Setscreen(-1, defaultScreen, -1);
	return 0;
}
void swapScreenBuffers(UINT8** front, UINT8** back)
{
	UINT8* swap = *front;
	*front = *back;
	*back = swap;
	Setscreen(-1, *front, -1);
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




