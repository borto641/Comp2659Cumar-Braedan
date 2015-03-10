#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "raster.h"
#include "render.h"
 

int main(){
    Screen screen;
	void *base = Physbase();  
	int i;
	
	screen.ball.x = 100;
	screen.ball.y = 290;
	screen.ball.dX = 1;
	screen.ball.dY = 2;
	screen.scoreNum.score = 666;
	screen.scoreNum.x = 610;
	screen.scoreNum.y = 4;
	screen.scoreLabel.x = 550;
	screen.scoreLabel.y = 4;
	screen.paddle.x = 100;
	screen.paddle.y = 370;
	screen.lifeCounter.x = 4;
	screen.lifeCounter.y = 4;
	screen.lifeCounter.numLives = 3;
	for (i = 25; i >= 0; i--)
	{
		screen.bricks[i] = true;
	}
	
    clrScrn(base);
	printScreen(screen);
	/* SUPER SLOW
	for (i = 0; i < 300; i++)
	{
		clrScrn(base);
		moveBall(&screen.ball, &screen.bricks);
		printScreen(screen);
	}
	*/

return 0;
}