#include "events.h"



/****************************************************************************
Paddle:
- right key: 		move paddle right
- left  key: 		move paddle left
- space bar key:    launch ball if beginning of level
****************************************************************************/
void keyPress(Screen *screen, long choice)
{
/*do appropriate actions corresponding to key pressed*/
	/*Cconis(); check status of standard input*/
	/*Cnecin(); read char from standard input no echo*/
	/*                       
		4B00 - Left arrow
		4D00 - Right arrow
		3920 - Space key
	*/
		if(choice == LEFT_ARROW && screen->holdBall == FALSE){
			paddleLeft(&(screen->paddle));
		}
		else if(choice == RIGHT_ARROW && screen->holdBall == FALSE){
			paddleRight(&(screen->paddle));
		}
		else if(choice == SPACEBAR && screen->holdBall == TRUE){
			launchBall(screen);
		}
}

/* *****************************************************************************
Brick
- when the ball touches the brick from any side
- up,down, left side and right side
******************************************************************************/

void brickSmashed(Screen *screen, int i){
/*If ball touches the brick remove the brick from the level*/
	screen->bricks[i].alive = FALSE;
	screen->bricks[i].undraw = TRUE;
	screen->scoreNum.score += 10;
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

void ballHitBottom(Screen *screen)
{
	screen->lifeCount.lives--;
	if (screen->lifeCount.lives > 0)
	{
		resetBall(screen);
	}
	else
	{
		screen->gameOver = TRUE;
	}
}