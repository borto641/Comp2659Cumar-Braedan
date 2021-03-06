#include "events.h"
#include "render.h"
#include "effects.h"



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
		if(choice == LEFT_ARROW && !screen->holdBall && !screen->paddle.lock){
			paddleLeft(&(screen->paddle));
		}
		else if(choice == RIGHT_ARROW && !screen->holdBall && !screen->paddle.lock){
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

void brickSmashed(Screen *screen, int i)
{
   
	screen->bricks[i].alive = FALSE;
	screen->bricks[i].firstUndraw = TRUE;
	screen->bricks[i].secondUndraw = TRUE;
	screen->scoreNum.score += 10;
	screen->bricksLeft--;
    ballHitsBrickSound();
} 

/*
ballHitV will change the path of the ball, flipping the vertical direction, and
	preserving the horizontal direction
*/
void ballHitVert(Ball *ball)
{
    if(ball->y <= 20 ){
        ballHitsWallSound();
    }
	ball->totalBounces++;
	ball->dY -= (ball->dY + ball->dY);
}

/*
ballHitH will change the path of the ball, flipping the horizontal direction, and
	preserving the vertical direction
*/
void ballHitHor(Ball *ball)
{
    
    if((ball->x) + ball->dX <= 0 || (ball->x) + ball->dX >= 620){
        ballHitsWallSound();
    }
	ball->totalBounces++;
	ball->dX -= (ball->dX + ball->dX);
}

void farLeftPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = -3;
	ball->dY = -1;
}

void midLeftPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = -1;
	ball->dY = -3;
}

void centrePaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = 0;
	ball->dY = -4;
}

void midRightPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = 1;
	ball->dY = -3;
}

void farRightPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
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

void levelCleared(Screen *screen, UINT8* front, UINT8* back)
{
	resetLevel(screen);
	clrScrn((UINT16*)(front));
	clrScrn((UINT16*)(back));
	printScreen(*screen, (UINT32*)(front));
	printScreen(*screen, (UINT32*)(back));
}