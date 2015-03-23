#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "render.h"

int main()
{
	Screen screen;
	const UINT32 *base = Physbase();
	bool quit = FALSE;
	long input;
	
	printf("\033E\033f\n");
	initialize(&screen);
	printScreen(screen, base);
	
	while (!quit)
	{
		
		
		if (Cconis())
		{
			input = Cnecin();
			if (input == ESC)
				quit = TRUE;
			else
			keyPress(&screen, input);
		}
		/*refreshScreen(&screen, base);*/
		Vsync();
	}
	return 0;
}