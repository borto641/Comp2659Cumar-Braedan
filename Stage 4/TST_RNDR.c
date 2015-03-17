#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "raster.h"
#include "render.h"

int main(){
    Screen screen;
	/*void *base = Physbase();  */
	int i;
	long key_pressed = Cnecin();
	long *timer = 0x462;
	long c_time;
	long old_ssp;
	UINT8 *base8 = Physbase();
	UINT16 *base16 = Physbase();
	UINT32 *base32 = Physbase();
	UINT32 savedBallChunk[32];
	UINT32 savedPaddleChunk[32];
	
	screen.ball.x = 85;
	screen.ball.y =  290;
	screen.ball.dX = 3;
	screen.ball.dY = 1;
	screen.ball.ballMovingUp = false;
	screen.ball.ballMovingRight = true;
	screen.ball.ballMovingLeft = false;

	
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
	
	printf("\033E\033f\n");
	printScreen(screen);
	saveChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, BALL_HEIGHT);
	saveChunk(base32, screen.paddle.x, screen.paddle.y, savedPaddleChunk, PADDLE_HEIGHT);
	drwBall(screen.ball, base16);
	drwPaddle(base8, screen.paddle);
	old_ssp = Super(0);
	c_time = *timer;
 
  while (key_pressed != spacebar){
	  while (!Cconis()){
		while (c_time == *timer)
		;
		drawChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, BALL_HEIGHT);
		moveBall(&screen.ball, &screen.bricks, &screen.paddle);
		saveChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, BALL_HEIGHT);
		drwBall(screen.ball, base16);
		Vsync();
		
		/*moveBall(&screen.ball, &screen.bricks, &screen.paddle);
		printf("\033E\033f\n");
		printScreen(screen);
		c_time = *timer;*/
	  }  
	clrPaddle(base8, screen.paddle);
	key_press(&screen.paddle);
	drwPaddle(base8, screen.paddle);
	/*printScreen(screen);*/
  }

  Super(old_ssp);
	

return 0;
}