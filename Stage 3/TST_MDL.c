#include <osbind.h>
#include <stdio.h>
#include <linea.h>
#include "model.h"
#include "events.h"
#include "raster.h"

 

int main(){
    Screen *screen;
    Screen screen2;
	void *base = Physbase();  
	int i;


    linea1();
	
	screen->ball.x = 286;
	screen->ball.y = 300;
	screen->scoreNum.score = 666;
	screen->scoreNum.x = 5;
	screen->scoreNum.y = 350;
	screen->scoreLabel.x = 5;
	screen->scoreLabel.y = 370;
	screen->paddle.x = 250;
	screen->paddle.y = 359;
    
	for (i = 25; i >= 0; i--)
	{
		screen->bricks[i] = true;
	}
    
    /*clrScrn(base);*/
    
    printf("\033E\033f\n");      /*blank the screen */
    printScreen(screen);
    key_press(screen);
    
   
   
   
    
	


return 0;
}