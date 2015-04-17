#include "model.h"
#include "events.h"

/*
*	Function: moveBall
*
*	Purpose: This function changes properties of the screen's Ball structure, 
* 			then attempts to change it's coordinates if possible.
*
*	Input:	A Screen by reference representing the current game state
*
*	Output: The input Screen pointer modified to represent the game state after 
*				attempting to more the Ball
*
*/
void moveBall(Screen *screen)
{	
	int dX = screen->ball.dX * screen->ball.speed;
	int dY = screen->ball.dY * screen->ball.speed;
	
	checkBounces(&screen->ball);
	checkBallCollision(screen, dX, dY);
	
	if (!screen->gameOver && !screen->holdBall)
	{
		screen->ball.x += dX;
		screen->ball.y += dY;
	}
}

/*
*	Function: checkBounces
*
*	Purpose: changes the Ball's speed if a certain threshold has been reached
*
*	Input:	A Ball by reference
*
*	Output: The input Ball, representing the state after checking for speed increases
*
*/
void checkBounces(Ball *ball)
{
	if (ball->totalBounces > 25)
	{
		ball->speed = 2;
	}
	else
	{
		ball->speed = 1;
	}
}

/*
*	Function: checkBallCollision
*
*	Purpose: To choose which form of collision detection is appropriate, and then calling functions
				to perform actions upon the Screen structure
*
*	Input:	A Screen by reference representing the current game state
*
*	Output: The above Screen modified to represent one Ball movement
*
*/
void checkBallCollision(Screen *screen, int dX, int dY)
{
	if (screen->ball.y < 130)/*bricks, or the roof may be hit*/
	{
		if (dX > 0) /*moving right*/
		{
			if (dY < 0) /*moving up*/
			{
				uRCollDetect(screen, dX, dY);
			}
			else /*moving down*/
			{
				dRCollDetect(screen, dX, dY);
			}
		}
		else if (dX < 0) /*left*/
		{
			if (dY < 0) /*moving up*/
			{
				uLCollDetect(screen, dX, dY);
			}
			else /*down*/
			{
				dLCollDetect(screen, dX, dY);
			}
		}
		else /*vertical*/
		{
			if (dY > 0) /*down*/
			{
				downCollDetect(screen, dX, dY);
			}
			else /*up*/
			{
				upCollDetect(screen, dX, dY);
			}
		}			
	}
	else if ((screen->ball.y + (dY) + BALL_HEIGHT + 1) > 369) /*Ball is in range of the paddle*/
	{
		paddleCollDetect(screen, dX, dY);
	}		
	else /*cannot hit bricks or the paddle*/
	{
		if ((screen->ball.x + (dX) + BALL_WIDTH - 1 >= 639) /*wall detection*/
		|| (screen->ball.x + (dX) < 0))
		{
			ballHitHor(&screen->ball);
		}	
	}
}

/*
*	Function: upCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with an object, redirect the Ball,
				perform appropriate actions upon objects hit
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*/
void upCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ( screen->ball.x + 15 >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& screen->ball.x < screen->bricks[i].x + 64) /*leftmost x of ball is before rightmost x of brick*/
			{
				if (screen->ball.y + dY < (screen->bricks[i].y + 24) /*topmost y of ball is after bottommost y of brick*/
					&& (screen->ball.y + dY) >= (screen->bricks[i].y)) /*bottommost y of ball is after topmost y of brick*/
				{
					brickSmashed(screen, i);
                    ballHitVert(&screen->ball);
                   
				}						
			}					
		}		
	}
	if ((screen->ball.y + (dY)) < 12)/* topmost y of ball is past roof level*/
		ballHitVert(&screen->ball);
}

/*
*	Function: downCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with an object, redirect the Ball,
				perform appropriate actions upon objects hit
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*
*/
void downCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].alive)
		{
			if (screen->ball.x + 15 >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& screen->ball.x < screen->bricks[i].x + 64) /*leftmost x of ball is before rightmost x of brick*/
			{
				if (screen->ball.y + dY + BALL_HEIGHT - 1 >= (screen->bricks[i].y) /*bottommost y of ball is after topmost y of brick*/
					&& (screen->ball.y + dY) <= (screen->bricks[i].y + 24)) /*topmost y of ball is after bottommost y of brick*/
				{
					brickSmashed(screen, i);
					ballHitVert(&screen->ball);
				}						
			}					
		}		
	}
}

/*
*	Function: dRCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with an object, redirect the Ball,
				perform appropriate actions upon objects hit
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*
*/
void dRCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + BALL_WIDTH - 1) >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*leftmost x of ball is before rightmost x of brick*/
			{
				if ((screen->ball.y + dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y) /*bottommost y of ball is after topmost y of brick*/
					&& (screen->ball.y + dY) <= (screen->bricks[i].y + BRICK_HEIGHT))/*topmost y of ball is after bottommost y of brick*/
				{
					if ((screen->ball.x + dX + BALL_WIDTH - 1) - screen->bricks[i].x /*(rightmost x of ball) - (leftmost x of brick)*/
						> 
					   (screen->ball.y + dY + BALL_HEIGHT - 1) - screen->bricks[i].y) /*(bottommost y of ball) - (topmost y of brick)*/
					{/*ball entered from the top*/
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else 
					{/*ball entered from side*/
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}	
	if ((screen->ball.x +  (dX) + BALL_WIDTH - 1 >= 639) /*rightmost ball x past right bounds*/
		|| (screen->ball.x + (dX) < 0)) /*leftmost ball x before left bounds*/
	{
		ballHitHor(&screen->ball);
	}		
}				
			
/*
*	Function: dLCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with an object, redirect the Ball,
				perform appropriate actions upon objects hit
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*
*/
void dLCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + BALL_WIDTH - 1) >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*leftmost x of ball is before rightmost x of brick*/
			{
				if ((screen->ball.y + dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y) /*bottommost y of ball is after topmost y of brick*/
					&& (screen->ball.y + dY) <= (screen->bricks[i].y + BRICK_HEIGHT) - 1)/*topmost y of ball is after bottommost y of brick*/
				{
					if ((screen->bricks[i].x + BRICK_WIDTH - 1) - (screen->ball.x + dX) /*(leftmost x of ball) - (rightmost x of brick)*/
						> 
					   (screen->ball.y + dY + BALL_HEIGHT - 1) - screen->bricks[i].y) /*(bottommost y of ball) - (topmost y of brick)*/
					{/*ball entered from the top*/
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else 
					{/*ball entered from side*/
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}	
	if ((screen->ball.x +  (dX) + BALL_WIDTH - 1) >= 639 /*rightmost ball x past right bounds*/
		|| (screen->ball.x +  (dX)) < 0) /*leftmost ball x before left bounds*/
	{
		ballHitHor(&screen->ball);
	}		
}	

/*
*	Function: uLCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with an object, redirect the Ball,
				perform appropriate actions upon objects hit
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*
*/
void uLCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + BALL_WIDTH - 1) >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*leftmost x of ball is before rightmost x of brick*/
			{
				if ((screen->ball.y + dY) < (screen->bricks[i].y + 24) /*topmost y of ball is after bottommost y of brick*/
						&& (screen->ball.y + dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y))/*bottommost y of ball is after topmost y of brick*/
				{
					if ((screen->bricks[i].x + BRICK_WIDTH  - 1) - (screen->ball.x + dX) /*(rightmost x of brick) - (leftmost x of ball)*/ 
						> 
					   ((screen->bricks[i].y + BRICK_HEIGHT - 1) - screen->ball.y + dY)) /*(bottommost y of brick) - (topmost y of ball)*/
					{/*ball entered from the top*/
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else 
					{/*ball entered from side*/
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}	
	if ((screen->ball.x +  (dX) + BALL_WIDTH - 1) >= 639 /*rightmost ball x past right bounds*/
		|| (screen->ball.x + dX) < 0) /*leftmost ball x before left bounds*/
	{
		ballHitHor(&screen->ball);
	}	
	if ((screen->ball.y + dY) <= 12) /* topmost y of ball is past roof level*/
	{
		ballHitVert(&screen->ball);
	}
}

/*
*	Function: uRCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with an object, redirect the Ball,
				perform appropriate actions upon objects hit
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*
*/
void uRCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + BALL_WIDTH - 1) >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*leftmost x of ball is before rightmost x of brick*/
			{
				if ((screen->ball.y + dY) < (screen->bricks[i].y + 24) /*topmost y of ball is after bottommost y of brick*/
						&& (screen->ball.y + dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y))/*bottommost y of ball is after topmost y of brick*/
				{
					if ((screen->ball.x + dX + BALL_WIDTH - 1) - screen->bricks[i].x /*(rightmost x of ball) - (leftmost x of brick)*/
						> 
					   ((screen->bricks[i].y + BRICK_HEIGHT - 1) - screen->ball.y + dY)) /*(bottommost y of brick) - (topmost y of ball)*/
					{/*ball entered from the top*/
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else 
					{/*ball entered from side*/
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}	
	if ((screen->ball.x + (dX) + BALL_WIDTH - 1) >= 639 /*rightmost ball x past right bounds*/
		|| (screen->ball.x + (dX)) < 0) /*leftmost ball x before left bounds*/
	{
		ballHitHor(&screen->ball);
	}
	if ((screen->ball.y + dY) <= 12) /* topmost y of ball is past roof level*/
	{
		ballHitVert(&screen->ball);
	}	
}

/*
*	Function: paddleCollDetect
*
*	Purpose: To check if the next movement of the Ball would collide with the paddle, and redirect the Ball at the correct angle
*
*	Input:	A Screen by reference representing the current game state.
*
*	Output: The input Screen modified to represent the state after a Ball movement
*
*/
void paddleCollDetect(Screen *screen, int dX, int dY)
{
	if ((screen->ball.x + dX + BALL_WIDTH - 1) >= screen->paddle.x /*rightmost x of ball is past leftmost x of paddle*/
		&& (screen->ball.x + dX) <= (screen->paddle.x + PADDLE_WIDTH - 1)) /*leftmost x of ball is before rightmost x of paddle*/
	{
		if ((screen->ball.y + dY + BALL_HEIGHT - 1) >= (screen->paddle.y) /*bottommost y of ball is after topmost y of paddle*/
			&& (screen->ball.y + dY) <= screen->paddle.y + PADDLE_WIDTH - 1)/*topmost y of ball is after bottommost y of paddle*/
		{
			if (dX <= 0)
			{
				if ((screen->paddle.x + PADDLE_WIDTH - 1) - (screen->ball.x + dX) /*(rightmost x of paddle) - (leftmost x of ball)*/
					 > 
					(screen->ball.y + dY + BALL_HEIGHT - 1) - screen->paddle.y) /*(bottommost y of ball) - (topmost y of paddle)*/
				 {/*ball entered from the top*/
					ballHitPaddle(screen, dX, dY);
				}
				else 
				{/*ball entered from side*/
					ballHitHor(&screen->ball);
					screen->paddle.lock = TRUE;
				}
			}
			else
			{
				if ((screen->ball.x + dX + BALL_WIDTH - 1) - screen->paddle.x /*(rightmost x of ball) - (leftmost x of paddle)*/
					 > 
			  	    (screen->ball.y + dY + BALL_HEIGHT - 1) - screen->paddle.y) /*(bottommost y of ball) - (topmost y of brick)*/
				{/*ball entered from the top*/
					ballHitPaddle(screen, dX, dY);
				}
				else 
				{/*ball entered from side*/
					ballHitHor(&screen->ball);
					screen->paddle.lock = TRUE;
				}
			}
		}
	}
	if ((screen->ball.y + (dY) + BALL_HEIGHT - 1) >= 399)
	{
		ballHitBottom(screen);
	}
	if ((screen->ball.x + (dX) + BALL_WIDTH - 1) >= 639 /*rightmost ball x past right bounds*/
		|| (screen->ball.x + (dX)) < 0) /*leftmost ball x before left bounds*/
	{
		ballHitHor(&screen->ball);
	}
}
void ballHitPaddle(Screen *screen, int dX, int dY)
{
	int paddleHitPosition;
	
	paddleHitPosition = screen->paddle.x - (screen->ball.x + dX + BALL_WIDTH);
	if (paddleHitPosition > -26)
	{/*ball hit far left of paddle*/
		farLeftPaddleHit(&screen->ball);
	}
	else if (paddleHitPosition > -51)
	{/*ball hit mid left of paddle*/
		midLeftPaddleHit(&screen->ball);
	}
	else if (paddleHitPosition > -77)
	{/*ball hit centre of paddle*/
		centrePaddleHit(&screen->ball);
	}
	else if (paddleHitPosition > -103)
	{/*ball hit mid right of paddle*/
		midRightPaddleHit(&screen->ball);
	}
	else
	{/*ball hit far right of paddle*/
		farRightPaddleHit(&screen->ball);
	}		
}	

/*
*	Function: scoreToChars
*
*	Purpose: To convert the numerical value of a ScoreNum's score field to an array of characters
*
*	Input:	A ScoreNum representing the current score
*
*	Return: An array characters representing the numerical score of the current game
*/
void scoreToChars (ScoreNum score, char scoreChars[3])
{
	scoreChars[0] = ((score.score % 1000) / 100) + ZERO; 	/*hundreds*/
	scoreChars[1] = ((score.score % 100)  / 10)  + ZERO;  	/*tens*/
	scoreChars[2] = (score.score % 10)           + ZERO;    /*ones*/
}

/*
*	Function: paddleLeft
*
*	Purpose: Attempts to move the paddle's x value up to 20 left, stopping if it hits the wall
*
*	Input:	A Paddle structure by reference
*
*	Output: A Paddle structure by reference
*
*/
void paddleLeft(Paddle *paddle){
	if ((paddle->x) >= 20 ){
            paddle->x -= 20;
    }
	else{
		paddle->x = 0;
	}
}

/*
*	Function: paddleRight
*
*	Purpose: Attempts to move the paddle's x value up to 20 right, stopping if it hits the wall
*
*	Input:	A Paddle structure by reference
*
*	Output: A Paddle structure by reference
*
*/
void paddleRight(Paddle *paddle){
	if ((paddle->x + PADDLE_WIDTH) <= 620 ){
		paddle->x += 20;
    }
	else{
		paddle->x = 512;
	}
}

/*
*	Function: launchBall
*
*	Purpose: Allows the ball to move on game cycles
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*
*/
void launchBall(Screen *screen)
{
	 screen->holdBall = FALSE;
}

/*
*	Function: initialize
*
*	Purpose: loads the default values to the fields of the Screen structure, with all bricks unsmashed,
*			  the paddle and ball centred, and the score and life counters at correct values
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*
*/
void initialize(Screen *screen)
{
	int i;
	screen->ball.x = 314;
	screen->ball.y = 354;
	screen->ball.oldX = 314;
	screen->ball.oldY = 354;
	screen->ball.olderY = 354;
	screen->ball.olderX = 314;
	screen->ball.dX = 0;
	screen->ball.dY = -3;
	screen->ball.speed = 1;
	screen->ball.totalBounces = 0;
	screen->ball.ballOut = FALSE;
	
	screen->scoreNum.score = 0;
	screen->scoreNum.x = 608;
	screen->scoreNum.y = 2;
	
	screen->scoreLabel.x = 559;
	screen->scoreLabel.y = 2;
	screen->scoreLabel.label[0] = 'S';
	screen->scoreLabel.label[1] = 'c';
	screen->scoreLabel.label[2] = 'o';
	screen->scoreLabel.label[3] = 'r';
	screen->scoreLabel.label[4] = 'e';
	screen->scoreLabel.label[5] = ':';
	
	screen->lifeLabel.x = 16;
	screen->lifeLabel.y = 2;
	screen->lifeLabel.label[0] = 'L';
	screen->lifeLabel.label[1] = 'i';
	screen->lifeLabel.label[2] = 'v';
	screen->lifeLabel.label[3] = 'e';
	screen->lifeLabel.label[4] = 's';
	screen->lifeLabel.label[5] = ':';
	
	screen->paddle.x = 256;
	screen->paddle.y = 370;
	screen->paddle.oldX = 256;
	screen->paddle.oldY = 370;
	screen->paddle.olderX = 256;
	screen->paddle.olderY = 370;
	screen->paddle.lock = FALSE;
	
	screen->lifeCount.lives = 3;
	screen->lifeCount.x = 64;
	screen->lifeCount.y = 2;

	screen->holdBall = TRUE;
	screen->gameOver = FALSE;
	for (i = 0; i < NUM_BRICKS; i++)
	{
		screen->bricks[i].alive = TRUE;
		screen->bricks[i].y = (i / 5) * 24 + 13;
		
		if ((i / 5) % 2 == 0)
			screen->bricks[i].x = (i % 5) * 128;
		else 
			screen->bricks[i].x = (i % 5) * 128 + 64;
	}
	screen->bricksLeft = NUM_BRICKS;
	for (i = 0; i < 32; i++)
	{
		screen->ballChunk[i] = 0;
	}
	for (i = 0; i < 32; i++)
	{
		screen->oldBallChunk[i] = 0;
	}
}

/*
*	Function: resetBall
*
*	Purpose: Resets the ball and paddle to the centre of the screen, and resets the speed of the ball
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*
*/
void resetBall(Screen *screen)
{
	screen->ball.x = 314;
	screen->ball.y = 354;
	screen->ball.dX = 0;
	screen->ball.dY = -3;
	screen->ball.speed = 1;
	screen->ball.totalBounces = 0;
	
	screen->paddle.x = 256;
	screen->paddle.lock = FALSE;
	
	screen->holdBall = TRUE;
}

/*
*	Function: resetLevel
*
*	Purpose: Sets all bricks to unsmashed, centres the ball and paddle, increments the lives, but does not affect the score
*
*	Input:	A Screen structure by reference
*
*	Output: A Screen structure by reference
*
*/
void resetLevel(Screen *screen)
{
	int i;
	screen->bricksLeft = NUM_BRICKS;
	screen->ball.x = 314;
	screen->ball.y = 354;
	screen->ball.oldX = 314;
	screen->ball.oldY = 354;
	screen->ball.olderY = 354;
	screen->ball.olderX = 314;
	screen->ball.dX = 0;
	screen->ball.dY = -3;
	screen->ball.ballOut = FALSE;
	
	screen->paddle.x = 256;
	screen->paddle.y = 370;
	screen->paddle.oldX = 256;
	screen->paddle.oldY = 370;
	screen->paddle.olderX = 256;
	screen->paddle.olderY = 370;
	screen->paddle.lock = FALSE;

	screen->holdBall = TRUE;
	screen->gameOver = FALSE;
	screen->lifeCount.lives++;
	for (i = 0; i < NUM_BRICKS; i++)
	{
		screen->bricks[i].alive = TRUE;
		screen->bricks[i].firstUndraw = FALSE;
		screen->bricks[i].secondUndraw = FALSE;
		screen->bricks[i].y = (i / 5) * 24 + 13;
		
		if ((i / 5) % 2 == 0)
			screen->bricks[i].x = (i % 5) * 128;
		else 
			screen->bricks[i].x = (i % 5) * 128 + 64;
	}
	for (i = 0; i < 32; i++)
	{
		screen->ballChunk[i] = 0;
	}
	for (i = 0; i < 32; i++)
	{
		screen->oldBallChunk[i] = 0;
	}
}