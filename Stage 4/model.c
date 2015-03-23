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
	checkBounces(&screen->ball);
	checkBallCollision(screen);
	if (!screen->resetBall)
	{
		screen->ball.x += (screen->ball.dX * screen->ball.speed);
		screen->ball.y += (screen->ball.dY * screen->ball.speed);
	}
	else 
	{
		/*Reset ball when it hits the bottom of the screen*/
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
	if (ball->totalBounces > 100)
	{
		ball->speed = 5;
	}
	else if (ball->totalBounces > 75)
	{
		ball->speed = 4;
	}
	else if (ball->totalBounces > 50)
	{
		ball->speed = 3;
	}
	else if (ball->totalBounces > 15)
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
void checkBallCollision(Screen *screen)
{
	if (screen->ball.y < 125)/*bricks, or the roof may be hit*/
	{

			if (screen->ball.dX > 0) /*moving right*/
			{
				if (screen->ball. dY < 0) /*moving up*/
				{
					uRCollDetect(screen);
				}
				else /*moving down*/
				{
					dRCollDetect(screen);
				}
			}
			else if (screen->ball.dX < 0) /*left*/
			{
				if (screen->ball.dY < 0) /*moving up*/
				{
					uLCollDetect(screen);
				}
				else /*down*/
				{
					dLCollDetect(screen);
				}
			}
			else /*vertical*/
			{
				if (screen->ball.dY > 0) /*down*/
				{
					downCollDetect(screen);
				}
				else /*up*/
				{
					upCollDetect(screen);
				}
			}
			
	}
	else if (screen->ball.y > 360) /*Ball is in range of the paddle*/
	{
		paddleCollDetect(screen);
	}		
	else /*cannot hit bricks or the paddle*/
	{
		if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1 >= 639) /*wall detection*/
		|| (screen->ball.x + screen->ball.dX < 0))
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
void upCollDetect(Screen *screen)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ( screen->ball.x + 15 >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& screen->ball.x < screen->bricks[i].x + 64) /*leftmost x of ball is before rightmost x of brick*/
			{
				if (screen->ball.y + screen->ball.dY < (screen->bricks[i].y + 24) /*topmost y of ball is after bottommost y of brick*/
					&& (screen->ball.y + screen->ball.dY) >= (screen->bricks[i].y)) /*bottommost y of ball is after topmost y of brick*/
				{
					brickSmashed(&screen->bricks[i]);
					ballHitVert(&screen->ball);
				}						
			}					
		}		
	}
	if ((screen->ball.y + screen->ball.dY) < 12)/* topmost y of ball is past roof level*/
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

void downCollDetect(Screen *screen)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if (screen->ball.x + 15 >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& screen->ball.x < screen->bricks[i].x + 64) /*leftmost x of ball is before rightmost x of brick*/
			{
				if (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1 >= (screen->bricks[i].y) /*bottommost y of ball is after topmost y of brick*/
					&& (screen->ball.y + screen->ball.dY) <= (screen->bricks[i].y + 24)) /*topmost y of ball is after bottommost y of brick*/
				{
					brickSmashed(&screen->bricks[i]);
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

void dRCollDetect(Screen *screen)
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& (screen->ball.x + screen->ball.dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*leftmost x of ball is before rightmost x of brick*/
			{
				if ((screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y) /*bottommost y of ball is after topmost y of brick*/
					&& (screen->ball.y + screen->ball.dY) <= (screen->bricks[i].y + BRICK_HEIGHT))/*topmost y of ball is after bottommost y of brick*/
				{
					if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) - screen->bricks[i].x /*(rightmost x of ball) - (leftmost x of brick)*/
						> 
					   (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) - screen->bricks[i].y) /*(bottommost y of ball) - (topmost y of brick)*/
					{
						/*ball entered from the top*/
						ballHitVert(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
					else 
					{
						/*ball entered from side*/
						ballHitHor(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
				}
			}
		}
	}	
	if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1 >= 639) /*rightmost ball x past right bounds*/
		|| (screen->ball.x + screen->ball.dX < 0)) /*leftmost ball x before left bounds*/
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
			
void dLCollDetect(Screen *screen)
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->bricks[i].x /*rightmost x of ball is past leftmost x of brick*/
				&& (screen->ball.x + screen->ball.dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*leftmost x of ball is before rightmost x of brick*/
			{
				if ((screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y) /*bottommost y of ball is after topmost y of brick*/
					&& (screen->ball.y + screen->ball.dY) <= (screen->bricks[i].y + BRICK_HEIGHT) - 1)/*topmost y of ball is after bottommost y of brick*/
				{
					if ((screen->bricks[i].x + BRICK_WIDTH - 1) - (screen->ball.x + screen->ball.dX) /*(rightmost x of ball) - (leftmost x of brick)*/
						> 
					   (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) - screen->bricks[i].y) /*(bottommost y of ball) - (topmost y of brick)*/
					{
						/*ball entered from the top*/
						ballHitVert(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
					else 
					{
						/*ball entered from side*/
						ballHitHor(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
				}
			}
		}
	}	
	if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= 639 /*rightmost ball x past right bounds*/
		|| (screen->ball.x + screen->ball.dX) < 0) /*leftmost ball x before left bounds*/
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
void uLCollDetect(Screen *screen)
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->bricks[i].x 
				&& (screen->ball.x + screen->ball.dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((screen->ball.y + screen->ball.dY) < (screen->bricks[i].y + 24) 
						&& (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y))/* in Y range*/
				{
					if ((screen->bricks[i].x + BRICK_WIDTH  - 1) - (screen->ball.x + screen->ball.dX)
						> 
					   ((screen->bricks[i].y + BRICK_HEIGHT - 1) - screen->ball.y + screen->ball.dY)) /*ball entered from bottom*/
					{
						ballHitVert(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
					else /*ball entered from side*/
					{
						ballHitHor(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
				}
			}
		}
	}	
	if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= 639 
		|| (screen->ball.x + screen->ball.dX) < 0)
	{
		ballHitHor(&screen->ball);
	}	
	if ((screen->ball.y + screen->ball.dY) <= 12)
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

void uRCollDetect(Screen *screen)
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->bricks[i].x 
				&& (screen->ball.x + screen->ball.dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((screen->ball.y + screen->ball.dY) < (screen->bricks[i].y + 24) 
						&& (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y))/* in Y range*/
				{
					if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) - screen->bricks[i].x
						> 
					   ((screen->bricks[i].y + BRICK_HEIGHT - 1) - screen->ball.y + screen->ball.dY)) /*ball entered from bottom*/
					{
						ballHitVert(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
					else /*ball entered from side*/
					{
						ballHitHor(&screen->ball);
						brickSmashed(&screen->bricks[i]);
					}
				}
			}
		}
	}	
	if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= 639 
		|| (screen->ball.x + screen->ball.dX) < 0)
	{
		ballHitHor(&screen->ball);
	}
	if ((screen->ball.y + screen->ball.dY) <= 12)
	{
		ballHitVert(&screen->ball);
	}	
}

/*BASIC paddle collision with no angle change. IMPROVE*/
void paddleCollDetect(Screen *screen)
{
	int paddleHitPosition;
	if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->paddle.x 
				&& (screen->ball.x + screen->ball.dX) <= (screen->paddle.x + 71))
				{			
					if ((screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= screen->paddle.y)
						{
							paddleHitPosition = screen->paddle.x - (screen->ball.x + screen->ball.dX);
							if (paddleHitPosition > 0)
							{
								/*far left*/
								farLeftPaddleHit(&screen->ball);
							}
							else if (paddleHitPosition > -14)
							{
								/*mid left*/
								midLeftPaddleHit(&screen->ball);
							}
							else if (paddleHitPosition > -29)
							{
								/*centre*/
								centrePaddleHit(&screen->ball);
							}
							else if (paddleHitPosition > 43)
							{
								/*mid right*/
								midRightPaddleHit(&screen->ball);
							}
							else
							{
								/*far right*/
								farRightPaddleHit(&screen->ball);
							}
						}
				}
				else if (screen->ball.x + screen->ball.dX >= 399)
				{
					ballHitBottom(screen);
				}
}	


/*
addScore will increase the numerical score value by a given amount
*/
void addScore(ScoreNum score, int amount)
{
	score.score += amount;
}

/*
remScore will decrease the numerical score value by a given amount
*/
void remScore(ScoreNum score, int amount)
{
	score.score -= amount;
}

/*
getScore will retrieve the numerical score value of a given ScoreNum object

** Not needed? **

*/
int getScore (ScoreNum score)
{
	return score.score;
}

/* 
ScoreLPosition sets the X:Y position of the given ScoreLabel
*/
void scoreLPosition (ScoreLabel label, int x, int y)
{
	label.x = x;
	label.y = y;
}
/*

*/
void paddleLeft(Paddle *paddle){
	  if ((paddle->x - 5) >= 0 ){
            paddle->x -= 20;
    }
}
/*

*/
void paddleRight(Paddle *paddle){
	 if ((paddle->x + 72) <= 640 ){
		paddle->x += 20;
    }
}
/*

*/
void launch_ball(Paddle *paddle){
	/* release the ball */

}

void initialize(Screen *screen);
{
	screen->ball.x = 314;
	screen->ball.y = 355;
	screen->ball.dX = 0;
	screen->ball.dY = 3;
	screen->ball.speed = 1;
	screen->ball.totalBounces = 0;
	screen->ball.ballOut = FALSE;
	
	screen->scoreNum.score = 666;
	screen->scoreNum.x = 610;
	screen->scoreNum.y = 4;
	
	screen->scoreLabel.x = 550;
	screen->scoreLabel.y = 4;
	screen->scoreLabel.label = "Score:";
	
	screen->paddle.x = 284;
	screen->paddle.y = 370;
	
	screen->lifeCounter.x = 4;
	screen->lifeCounter.y = 4;
	screen->lifeCounter.label = "Lives: ";
	
	screen->lifeCount.amount = 3;
	screen->lifeCount.x = 52;
	screen->lifeCount.y = 4;

	bool holdBall = TRUE;
	
	for (i = 0; i <= 25; i++)
	{
		screen.bricks[i].alive = TRUE;
		screen.bricks[i].undraw = FALSE;
		screen.bricks[i].y = (i / 5) * 24 + 13;
		
		if ((i / 5) % 2 == 0)
			screen.bricks[i].x = (i % 5) * 128;
		else 
			screen.bricks[i].x = (i % 5) * 128 + 64;
	}
}

void resetBall(Screen *screen)
{
	screen->ball.x = 314;
	screen->ball.y = 355;
	screen->ball.dX = 0;
	screen->ball.dY = 3;
	screen->ball.speed = 1;
	screen->ball.totalBounces = 0;
	
	screen->paddle.x = 284;
	screen->paddle.y = 370;
	
	screen->holdBall = TRUE;
}