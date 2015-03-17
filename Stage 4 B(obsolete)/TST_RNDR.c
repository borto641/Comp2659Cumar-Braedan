#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "raster.h"
#include "render.h"
 

int main(){
    Screen screen;
	UINT8 *base = Physbase();
	UINT16 *base16 = Physbase();
	UINT32 *base32 = Physbase();
	int i;
	UINT32 savedChunk[32];
	
	screen.ball.x = 100;
	screen.ball.y = 300;
	screen.ball.dX = -2;
	screen.ball.dY = -2;
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
	
    clrScrn(base16);
	printScreen(screen);
	saveChunk(base32, screen.ball.x, screen.ball.y, savedChunk, BALL_HEIGHT);
	drwBall(screen.ball, base16);
	
	for (i = 0; i < 150; i++)
	{
		drawChunk(base32, screen.ball.x, screen.ball.y, savedChunk, BALL_HEIGHT);
		moveBall(&screen.ball, &screen.bricks);
		saveChunk(base32, screen.ball.x, screen.ball.y, savedChunk, BALL_HEIGHT);
		drwBall(screen.ball, base16);
		Vsync();
	}

return 0;
}