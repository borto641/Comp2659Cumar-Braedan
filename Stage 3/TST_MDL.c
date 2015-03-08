#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "raster.h"
 
 

int main(){
    Screen screen;
	void *base = Physbase();  
	int i;
	
	screen.ball.x = 160;
	screen.ball.y = 300;
	screen.scoreNum.score = 666;
	screen.scoreNum.x = 5;
	screen.scoreNum.y = 350;
	screen.scoreLabel.x = 5;
	screen.scoreLabel.y = 370;
	screen.paddle.x = 200;
	screen.paddle.y = 600;
	for (i = 25; i >= 0; i--)
	{
		screen.bricks[i] = true;
	}
	
    clrScrn(base);
    printScreen(screen);
	


return 0;
}