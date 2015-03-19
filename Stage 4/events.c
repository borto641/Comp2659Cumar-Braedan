#include "events.h"



/****************************************************************************
Paddle:
- right key: 		move paddle right
- left  key: 		move paddle left
- space bar key:    launch ball if beginning of level
****************************************************************************/
void key_press(Paddle *paddle)
{
/*do appropriate actions corresponding to key pressed*/
	/*Cconis(); check status of standard input*/
	/*Cnecin(); read char from standard input no echo*/
	/*                       
		4B00 - Left arrow
		4D00 - Right arrow
		3920 - Space key
	*/
	int choice;
	long key_pressed = Cnecin();
		if(key_pressed == left_arrow){
			paddleLeft(paddle);
		}
		else if(key_pressed == right_arrow){
			paddleRight(paddle);
		}
		else if(key_pressed == spacebar){
			/*paddle_launch_ball(paddle);*/
		}
}

/* *****************************************************************************
Brick
- when the ball touches the brick from any side
- up,down, left side and right side
******************************************************************************/

void brickSmashed(Brick *brick){
/*If ball touches the brick remove the brick from the level*/
	brick->alive = FALSE;
	brick->undraw = TRUE;
	} 

/*
ballHitV will change the path of the ball, flipping the vertical direction, and
	preserving the horizontal direction
*/
void ballHitVert(Ball *ball)
{
	ball->totalBounces++;
	ball->dY -= (ball->dY + ball->dY);
}

/*
ballHitH will change the path of the ball, flipping the horizontal direction, and
	preserving the vertical direction
*/
void ballHitHor(Ball *ball)
{
	ball->totalBounces++;
	ball->dX -= (ball->dX + ball->dX);
}

void farLeftPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = -3;
	ball->dY = -1;
}

void midLeftPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = -1;
	ball->dY = -3;
}

void centrePaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = 0;
	ball->dY = -4;
}

void midRightPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = 1;
	ball->dY = -3;
}

void farRightPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = 3;
	ball->dY = -1;
}