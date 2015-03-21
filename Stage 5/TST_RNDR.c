#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "raster.h"
#include "render.h"

int main(){
	
    Screen screen;
	int i;
	long key_pressed;
	long *timer = 0x462;
	long c_time;
	long old_ssp;
	UINT8 *base8 = Physbase();
	UINT16 *base16 = Physbase();
	UINT32 *base32 = Physbase();
	UINT32 savedBallChunk[32];
	UINT32 savedPaddleChunk[32];
	
	screen.ball.x = 314;
	screen.ball.y =  355;
	screen.ball.dX = 1;
	screen.ball.dY = -3;
	
	screen.scoreNum.score = 666;
	screen.scoreNum.x = 610;
	screen.scoreNum.y = 4;
	screen.scoreLabel.x = 550;
	screen.scoreLabel.y = 4;
	screen.paddle.x = 284;
	screen.paddle.y = 370;
	screen.lifeCounter.x = 4;
	screen.lifeCounter.y = 4;
	screen.lifeCount = 3;
	
	/*next two loops for testing purposes*/
	for (i = 0; i <= 19; i++)
	{
		screen.bricks[i].alive = TRUE;
		screen.bricks[i].undraw = FALSE;
	}
	for (i = 20; i < 25; i++)
	{
		screen.bricks[i].alive = TRUE;
		screen.bricks[i].undraw = FALSE;
	}
	
	for (i = 0; i < 25; i++)
	{
		screen.bricks[i].y = (i / 5) * 24 + 13;
		
		if ((i / 5) % 2 == 0)
			screen.bricks[i].x = (i % 5) * 128;
		else 
			screen.bricks[i].x = (i % 5) * 128 + 64;
	}
	
	printf("\033E\033f\n");
	printScreen(screen);
	saveChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, BALL_HEIGHT);
	saveChunk(base32, screen.paddle.x, screen.paddle.y, savedPaddleChunk, PADDLE_HEIGHT);
	drwBall(screen.ball, base16);
	drwPaddle(base8, screen.paddle);
	key_pressed = Cnecin();
	old_ssp = Super(0);
	c_time = *timer;
 
	  while (TRUE)
	  {		  
		for (i = 0; i < 25; i++)
		{
			if (screen.bricks[i].undraw)
			{
				Vsync();
				clrBrick(&screen.bricks[i], base8);
				screen.bricks[i].undraw = FALSE;
			}
		}
		drawChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, BALL_HEIGHT);
		moveBall(&screen);
		saveChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, BALL_HEIGHT);
		drwBall(screen.ball, base16);
		if (Cconis())
		{
			clrPaddle(base8, screen.paddle);
			key_press(&screen.paddle);
			drwPaddle(base8, screen.paddle);
		}
		Vsync();
	  }
  
  Super(old_ssp);
	

return 0;
}