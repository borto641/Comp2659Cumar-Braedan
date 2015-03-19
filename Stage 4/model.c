#include "model.h"
#include "events.h"

void moveBall(Ball *ball, Brick *bricks, Paddle paddle)
{	
	checkBounces(ball);
	checkBallCollision(ball, bricks, paddle);
	ball->x += (ball->dX * ball->speed);
	ball->y += (ball->dY * ball->speed);
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

void checkBallCollision(Ball *ball, Brick bricks[], Paddle paddle)
{
	if (ball->y < 125)/*bricks may be hit*/
	{

			if (ball->dX > 0) /*moving right*/
			{
				if (ball-> dY < 0) /*moving up*/
				{
					uRCollDetect(ball, bricks);
				}
				else /*moving down*/
				{
					dRCollDetect(ball, bricks);
				}
			}
			else if (ball->dX < 0) /*left*/
			{
				if (ball->dY < 0) /*moving up*/
				{
					uLCollDetect(ball,bricks);
				}
				else /*down*/
				{
					dLCollDetect(ball,bricks);
				}
			}
			else /*vertical*/
			{
				if (ball->dY > 0) /*down*/
				{
					downCollDetect(ball, bricks);
				}
				else /*up*/
				{
					upCollDetect(ball, bricks);
				}
			}
			
	}
	else if (ball->y > 360)
	{
		paddleCollDetect(ball, paddle);
	}		
	else /*cannot hit bricks or the paddle*/
	{
		if ((ball->x + ball->dX + BALL_WIDTH - 1 >= 639) 
		|| (ball->x + ball->dX < 0))
		{
			ballHitHor(ball);
		}	
	}
}

void upCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == TRUE)
		{
			if ( ball->x + 15 >= bricks[i].x 
				&& ball->x < bricks[i].x + 64) /* within the valid x range of brick*/
				{
					if (ball->y + ball->dY < (bricks[i].y + 24) 
						&& (ball->y + ball->dY) >= (bricks[i].y))
					{
						brickSmashed(&bricks[i]);
						ballHitVert(ball);
					}						
				}					
		}		
	}
	if ((ball->y + ball->dY) < 12)	/*checks for roof hits*/
		ballHitVert(ball);
}


void downCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == TRUE)
		{
			if ( ball->x + 15 >= bricks[i].x && ball->x < bricks[i].x + 64) /* within the valid x range of brick*/
			{
				if (ball->y + ball->dY >= (bricks[i].y) && (ball->y + ball->dY) <= (bricks[i].y + 24))
				{
					brickSmashed(&bricks[i]);
					ballHitVert(ball);
				}						
			}					
		}		
	}
	if (ball->x + ball->dX <= 0 || ball->x + ball->dX >= 639) /*checks for wall hits*/
			ballHitHor(ball);
}

void dRCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == TRUE)
		{
			if ((ball->x + ball->dX + BALL_WIDTH - 1) >= bricks[i].x 
				&& (ball->x + ball->dX) <= (bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= (bricks[i].y)
					&& (ball->y + ball->dY) <= (bricks[i].y + BRICK_HEIGHT))/* in Y range*/
				{
					if ((ball->x + ball->dX + BALL_WIDTH - 1) - bricks[i].x 
						> 
					   (ball->y + ball->dY + BALL_HEIGHT - 1) - bricks[i].y) /*ball entered from top*/
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else /*ball entered from side*/
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}	
	if ((ball->x + ball->dX + BALL_WIDTH - 1 >= 639) 
		|| (ball->x + ball->dX < 0))
	{
		ballHitHor(ball);
	}		
}				
			

void dLCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == TRUE)
		{
			if ((ball->x + ball->dX + BALL_WIDTH - 1) >= bricks[i].x 
				&& (ball->x + ball->dX) <= (bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= (bricks[i].y)
					&& (ball->y + ball->dY) <= (bricks[i].y + BRICK_HEIGHT) - 1)/* in Y range*/
				{
					if ((bricks[i].x + BRICK_WIDTH - 1) - (ball->x + ball->dX)
						> 
					   (ball->y + ball->dY + BALL_HEIGHT - 1) - bricks[i].y) /*ball entered from top*/
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else /*ball entered from side*/
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}	
	if ((ball->x + ball->dX + BALL_WIDTH - 1) >= 639 
		|| (ball->x + ball->dX) < 0)
	{
		ballHitHor(ball);
	}		
}	
	
void uLCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == TRUE)
		{
			if ((ball->x + ball->dX + BALL_WIDTH - 1) >= bricks[i].x 
				&& (ball->x + ball->dX) <= (bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((ball->y + ball->dY) < (bricks[i].y + 24) 
						&& (ball->y + ball->dY + BALL_HEIGHT - 1) >= (bricks[i].y))/* in Y range*/
				{
					if ((bricks[i].x + BRICK_WIDTH  - 1) - (ball->x + ball->dX)
						> 
					   ((bricks[i].y + BRICK_HEIGHT - 1) - ball->y + ball->dY)) /*ball entered from bottom*/
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else /*ball entered from side*/
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}	
	if ((ball->x + ball->dX + BALL_WIDTH - 1) >= 639 
		|| (ball->x + ball->dX) < 0)
	{
		ballHitHor(ball);
	}	
	if ((ball->y + ball->dY) <= 12)
	{
		ballHitVert(ball);
	}
}

void uRCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == TRUE)
		{
			if ((ball->x + ball->dX + BALL_WIDTH - 1) >= bricks[i].x 
				&& (ball->x + ball->dX) <= (bricks[i].x + BRICK_WIDTH - 1)) /*In x range*/
			{
				if ((ball->y + ball->dY) < (bricks[i].y + 24) 
						&& (ball->y + ball->dY + BALL_HEIGHT - 1) >= (bricks[i].y))/* in Y range*/
				{
					if ((ball->x + ball->dX + BALL_WIDTH - 1) - bricks[i].x
						> 
					   ((bricks[i].y + BRICK_HEIGHT - 1) - ball->y + ball->dY)) /*ball entered from bottom*/
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else /*ball entered from side*/
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}	
	if ((ball->x + ball->dX + BALL_WIDTH - 1) >= 639 
		|| (ball->x + ball->dX) < 0)
	{
		ballHitHor(ball);
	}
	if ((ball->y + ball->dY) <= 12)
	{
		ballHitVert(ball);
	}	
}

/*BASIC paddle collision with no angle change. IMPROVE*/
void paddleCollDetect(Ball *ball, Paddle paddle)
{

	int paddleHitPosition;
	if ((ball->x + ball->dX + BALL_WIDTH - 1) >= paddle.x 
				&& (ball->x + ball->dX) <= (paddle.x + 71))
				{			
					if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= paddle.y)
						{
							paddleHitPosition = paddle.x - (ball->x + ball->dX);
							if (paddleHitPosition > 0)
							{
								/*far left*/
								farLeftPaddleHit(ball);
							}
							else if (paddleHitPosition > -14)
							{
								/*mid left*/
								midLeftPaddleHit(ball);
							}
							else if (paddleHitPosition > -29)
							{
								/*centre*/
								centrePaddleHit(ball);
							}
							else if (paddleHitPosition > 43)
							{
								/*mid right*/
								midRightPaddleHit(ball);
							}
							else
							{
								/*far right*/
								farRightPaddleHit(ball);
							}
						}
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
/*

*/
int getLife(LifeCounter *lifeCounter){
	return lifeCounter->numLives;
}
/*

*/
void removeLife(LifeCounter *lifeCounter){
	lifeCounter->numLives -= 1;
}


