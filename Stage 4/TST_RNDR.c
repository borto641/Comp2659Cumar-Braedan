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
	long key_pressed = Cnecin();
	long *timer = 0x462;
	long c_time;
	long old_ssp;
	
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
	/*
	for (i = 25; i >= 0; i--)
	{
		screen.bricks[i] = true;
	}
	*/
	
	printf("\033E\033f\n");
	old_ssp = Super(0);
	c_time = *timer;
 
  while (key_pressed != spacebar){
	  while (!Cconis()){
		while (c_time == *timer)
		;
		moveBall(&screen.ball, &screen.bricks, &screen.paddle);
		printf("\033E\033f\n");
		printScreen(screen);
		c_time = *timer;
	  }  
	key_press(&screen.paddle);
	printf("\033E\033f\n");
	printScreen(screen);
  }

  Super(old_ssp);
	/* SUPER SLOW */
	/*
	for (i = 0; i < 2000; i++)
	{	
		printf("\033E\033f\n");
		moveBall(&screen.ball, &screen.bricks, &screen.paddle);
		printScreen(screen);
	}
	*/


return 0;
}