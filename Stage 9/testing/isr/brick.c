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
    int result;
	UINT32 timeThen, timeNow, timeElapsed;
   
	while (!quit)
	{	
        
		if (vbFlag == TRUE && !screen.holdBall || screen.holdBall)
		{
			printf("TRUE\n");
			vbFlag = FALSE;
			printf("%i", vbFlag);
		}
	}
	Setscreen(-1, defaultScreen, -1);
	installVector(VBL_VECT, orig_vector);
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




