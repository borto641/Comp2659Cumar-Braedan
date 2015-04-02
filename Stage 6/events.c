#include "events.h"
#include "render.h"


/****************************************************************************
Paddle:
- right key: 		move paddle right
- left  key: 		move paddle left
- space bar key:    launch ball if beginning of level
****************************************************************************/
/*
*	Function: keyPress
*
*	Purpose: To interpret the key pressed, and call an appropriate function
*
*	Input:	A Screen structure representing the game state by reference
*			A longword representing the key pressed
*
*	Output: A Screen structure representing the game state
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
*	Purpose: To change the game state to show a brick being smashed by the ball
*
*	Input:	A Screen structure representing the game state by reference
*			An integer representing the brick being smashed
*
*	Output: A Screen structure representing the game state 
*
*/
void brickSmashed(Screen *screen, int i)
{
	screen->bricks[i].alive = FALSE;
	screen->bricks[i].firstUndraw = TRUE;
	screen->bricks[i].secondUndraw = TRUE;
	screen->scoreNum.score += 10;
	screen->bricksLeft--;
} 

/*
*	Function: ballHitVert
*
*	Purpose: To change the game state to show the ball hitting an object
*			 on the side by reversing it's horizontal trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void ballHitVert(Ball *ball)
{
	ball->totalBounces++;
	ball->dY -= (ball->dY + ball->dY);
}

/*
*	Function: ballHitVert
*
*	Purpose: To change the game state to show the ball hitting an object
*			 on the top or bottom by reversing it's vertical trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void ballHitHor(Ball *ball)
{
	ball->totalBounces++;
	ball->dX -= (ball->dX + ball->dX);
}

/*
*	Function: farLeftPaddleHit
*
*	Purpose: To change the game state to show the ball hitting the paddle
*			 on the the far left by adjusting it's trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void farLeftPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = -3;
	ball->dY = -1;
}

/*
*	Function: midLeftPaddleHit
*
*	Purpose: To change the game state to show the ball hitting the paddle
*			 on the the middle left by adjusting it's trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void midLeftPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = -1;
	ball->dY = -3;
}

/*
*	Function: centrePaddleHit
*
*	Purpose: To change the game state to show the ball hitting the paddle
*			 in the centre by adjusting it's trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void centrePaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = 0;
	ball->dY = -4;
}

/*
*	Function: midRightPaddleHit
*
*	Purpose: To change the game state to show the ball hitting the paddle
*			 on the the middle right by adjusting it's trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void midRightPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = 1;
	ball->dY = -3;
}

/*
*	Function: farRightPaddleHit
*
*	Purpose: To change the game state to show the ball hitting the paddle
*			 on the the far right by adjusting it's trajectory
*
*	Input:	A Ball structure by reference
*
*	Output: A Ball structure by reference
*
*/
void farRightPaddleHit(Ball *ball)
{
	ball->totalBounces++;
	ball->dX = 3;
	ball->dY = -1;
}

/*
*	Function: ballHitBottom
*
*	Purpose: To change the game state to show the ball hitting the bottom of the 
*			 screen by calling a function to reset the ball and lose a life
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*
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
*	Purpose: To call functions to reset the screen to a state where all the bricks
*			 exist and the ball and paddle are reset
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*
*/
void levelCleared(Screen *screen, UINT8* front, UINT8* back)
{
	resetLevel(screen);
	clrScrn((UINT16*)(front));
	clrScrn((UINT16*)(back));
	printScreen(*screen, (UINT32*)(front));
	printScreen(*screen, (UINT32*)(back));
}