#include "model.h"
#include "events.h"

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
		
	}
}

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

void checkBallCollision(Screen *screen)
{
	if (screen->ball.y < 125)/*bricks may be hit*/
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
	else if (screen->ball.y > 360)
	{
		paddleCollDetect(screen);
	}		
	else /*cannot hit bricks or the paddle*/
	{
		if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1 >= 639) 
		|| (screen->ball.x + screen->ball.dX < 0))
		{
			ballHitHor(&screen->ball);
		}	
	}
}

void upCollDetect(Screen *screen)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ( screen->ball.x + 15 >= screen->bricks[i].x 
				&& screen->ball.x < screen->bricks[i].x + 64) /* within the valid x range of brick*/
			{
				if (screen->ball.y + screen->ball.dY < (screen->bricks[i].y + 24) 
					&& (screen->ball.y + screen->ball.dY) >= (screen->bricks[i].y))
				{
					brickSmashed(&screen->bricks[i]);
					ballHitVert(&screen->ball);
				}						
			}					
		}		
	}
	if ((screen->ball.y + screen->ball.dY) < 12)	/*checks for roof hits*/
		ballHitVert(&screen->ball);
}


void downCollDetect(Screen *screen)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ( screen->ball.x + 15 >= screen->bricks[i].x && screen->ball.x < screen->bricks[i].x + 64) /* within the valid x range of brick*/
			{
				if (screen->ball.y + screen->ball.dY >= (screen->bricks[i].y) && (screen->ball.y + screen->ball.dY) <= (screen->bricks[i].y + 24))
				{
					brickSmashed(&screen->bricks[i]);
					ballHitVert(&screen->ball);
				}						
			}					
		}		
	}
	if (screen->ball.x + screen->ball.dX <= 0 || screen->ball.x + screen->ball.dX >= 639) /*checks for wall hits*/
			ballHitHor(&screen->ball);
}

void dRCollDetect(Screen *screen)
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->bricks[i].x 
				&& (screen->ball.x + screen->ball.dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y)
					&& (screen->ball.y + screen->ball.dY) <= (screen->bricks[i].y + BRICK_HEIGHT))/* in Y range*/
				{
					if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) - screen->bricks[i].x 
						> 
					   (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) - screen->bricks[i].y) /*ball entered from top*/
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
	if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1 >= 639) 
		|| (screen->ball.x + screen->ball.dX < 0))
	{
		ballHitHor(&screen->ball);
	}		
}				
			

void dLCollDetect(Screen *screen)
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].alive == TRUE)
		{
			if ((screen->ball.x + screen->ball.dX + BALL_WIDTH - 1) >= screen->bricks[i].x 
				&& (screen->ball.x + screen->ball.dX) <= (screen->bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) >= (screen->bricks[i].y)
					&& (screen->ball.y + screen->ball.dY) <= (screen->bricks[i].y + BRICK_HEIGHT) - 1)/* in Y range*/
				{
					if ((screen->bricks[i].x + BRICK_WIDTH - 1) - (screen->ball.x + screen->ball.dX)
						> 
					   (screen->ball.y + screen->ball.dY + BALL_HEIGHT - 1) - screen->bricks[i].y) /*ball entered from top*/
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
}	
	
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