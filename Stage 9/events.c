#include "events.h"
#include "render.h"
#include "effects.h"



/****************************************************************************
Paddle:
- right key: 		move paddle right
- left  key: 		move paddle left
- space bar key:    launch ball if beginning of level
****************************************************************************/



/*
*	Function: keyPress
*
*	Purpose: Interprets a given key to take to correct action
*
*	Input:	The Screen structure by reference
*			A longword holding the scan code of the key pressed
*
*/
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

/*
*	Function: brickSmashed
*
*	Purpose: Sets the state of the brick to a smashed state, and sets flags signalling the renderer to undraw the
*				brick from buffers
*
*	Input:	The Screen Structure by reference
*			An integer holding the brick number to smash
*
*	Output: The Screen Structure by reference
*
*/
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
*	Function: ballHitVert
*
*	Purpose: Changes the state of the ball to deflect vertically
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
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
*	Function: ballHitHor
*
*	Purpose: Changes the state of the ball to deflect horizontally
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*/
void ballHitHor(Ball *ball)
{
    
    if((ball->x) + ball->dX <= 0 || (ball->x) + ball->dX >= 620){
        ballHitsWallSound();
    }
	ball->totalBounces++;
	ball->dX -= (ball->dX + ball->dX);
}

/*
*	Function: farLeftPaddleHit
*
*	Purpose: Changes the state of the ball to deflect of the far left portion of the paddle
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*/
void farLeftPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = -2;
	ball->dY = -2;
}

/*
*	Function: midLeftPaddleHit
*
*	Purpose: Changes the state of the ball to deflect of the mid left portion of the paddle
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*/
void midLeftPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = -1;
	ball->dY = -3;
}

/*
*	Function: centrePaddleHit
*
*	Purpose: Changes the state of the ball to deflect of the centre portion of the paddle
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*/
void centrePaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = 0;
	ball->dY = -3;
}

/*
*	Function: midRightPaddleHit
*
*	Purpose: Changes the state of the ball to deflect of the middle right portion of the paddle
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*/
void midRightPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = 1;
	ball->dY = -3;
}

/*
*	Function: farRightPaddleHit
*
*	Purpose: Changes the state of the ball to deflect of the far right portion of the paddle
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*/
void farRightPaddleHit(Ball *ball)
{
    ballHitsPaddleSound();
	ball->totalBounces++;
	ball->dX = 2;
	ball->dY = -2;
}

/*
*	Function: ballHitBottom
*
*	Purpose: Modifies the state of the Screen structure to show the user has allowed the ball to strike
*			 the bottom of the screen by resetting the paddle, the ball, and reducing the life count
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*/
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

/*
*	Function: levelCleared
*
*	Purpose: Clears the screen, and calls the function to reset the model to the correct state after
*			 smashing all bricks from the screen
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*/
void levelCleared(Screen *screen, UINT8* front, UINT8* back)
{
	resetLevel(screen);
	clrScrn((UINT16*)(front));
	clrScrn((UINT16*)(back));
	printScreen(*screen, (UINT32*)(front));
	printScreen(*screen, (UINT32*)(back));
}