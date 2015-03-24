#include "brick.h"

int main()
{
	Screen screen;
	const UINT32 *base = Physbase();
	bool quit = FALSE;
	long input;
	UINT32 timeThen, timeNow, timeElapsed;
	
	printf("\033E\033f\n");
	initialize(&screen);
	printScreen(screen, base);
	
	timeThen = checkScreenClock();
	
	while (!quit && !screen.gameOver)
	{	
		timeNow = checkScreenClock();
		if (timeNow - timeThen > 0)
		{
			timeNow = checkScreenClock();
			timeThen = timeNow;
			if (screen.holdBall == FALSE)
			{	
				moveBall(&screen);
			}
			refreshScreen(&screen, base);
		}
		
		if (Cconis())
		{
			input = Cnecin();
			if (input == ESC)
				quit = TRUE;
			else
			keyPress(&screen, input);
		}
	}
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




