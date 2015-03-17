#include "model.h"

void moveBall(Ball *ball, bool bricks[])
{
	
	ball->x += ball->dX;
	ball->y += ball->dY;
}
/*
void checkCollision(Ball *ball, bool bricks[])
{
	
	if (ballY > 120)/*bricks may be hit
	{

			if (ball->dX > 0) /*moving right
			{
				if (ball-> dY < 0) /*moving up
				{
					uRCollDetect(ball, bricks);
				}
				else /*moving down
				{
					dRCollDetect(ball, bricks);
				}
			}
			else if (ball->dX < 0) /*left
			{
				if (ball->dY > 0) /*moving up
				{
					uLCollDetect(ball,bricks);
				}
				else /*down
				{
					dLCollDetect(ball,bricks);
				}
			}
			else /*vertical
			{
				if (ball->dY > 0) /*down
				{
					downCollDetect(ball, bricks);
				}
				else /*up
				{
					upCollDetect(ball,bricks);
				}
			}
			
	}
	else /*cannot hit bricks
	{
		if (ball->x == 0 || ballY == 639)
			ballHitH(ball);
	}
}

void upCollDetect (Ball *ball, bool bricks[])
{
	int i;
	int pixel;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i] == true)
		{
			if (((i / 5) 2) == 0) /*Even row
			{
				if ( ball->x >= ((i % 5) * 128) && ball->x < (((i%5) * 128) + 64) /* within the valid x range of brick
				{
					if (ball->y < (((i / 5) * 24) + 24) && (ball->y + ball->dY) > (((i / 5) * 24) + 24)
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}					
			}
			else /*odd row
			{
				if ( ball->x >= ((i % 5) * 128) + 64 && ball->x < (((i%5) * 128) + 128) /* within the valid x range of brick
				{
					if (ball->y < (((i / 5) * 24) + 24) && (ball->y + ball->dY) > (((i / 5) * 24) + 24)
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}		
			}
		}		
	}
	if ((ball->y + ball->dY) < 20)
	{
		
		ballHitV(ball);
	}
}

void downCollDetect (Ball *ball, bool bricks[])
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i] == true)
		{
			if (((i / 5) 2) == 0) /*Even row
			{ 
				if ((ball->x + 16) >= ((i % 5) * 128) && ball->x < (((i%5) * 128) + 64) /* within the valid x range of brick
				{
					if ((ball->x + ball->dX + 16) - ((i % 5) * 128) > 0)
					{
						if ((ball->x + ball->dX + 16) - ((i % 5) * 128) < dX && ball->y + 1) - )
						{
							
					}
					if (ball->y < (((i / 5) * 24)) && (ball->y + ball->dY) > (((i / 5) * 24))
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}					
			}
			else /*odd row
			{
				if ((ball->x + 16) >= ((i % 5) * 128) + 64 && ball->x < (((i%5) * 128) + 128) /* within the valid x range of brick
				{
					if (ball->y < (((i / 5) * 24)) && (ball->y + ball->dY) > (((i / 5) * 24))
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}		
			}
		}		
	}
	if ((ball->y + ball->dY) < 20)
	{
		
		ballHitV(ball);
	}
}



dRCollDetect(Ball *ball, bool bricks[])
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i] == true)
		{
			if (((i / 5) 2) == 0) /*Even row
			{
				if ((ball->x + ball->dX + ) >= ((i % 5) * 128) && (ball->x + ball->dX) < (((i%5) * 128) + 64) /* within the valid x range of brick
				{
					
					if (ball->y < (((i / 5) * 24)) && (ball->y + ball->dY) > (((i / 5) * 24))
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}					
			}
			else /*odd row
			{
				if ( ball->x >= ((i % 5) * 128) + 64 && ball->x < (((i%5) * 128) + 128) /* within the valid x range of brick
				{
					if (ball->y < (((i / 5) * 24)) && (ball->y + ball->dY) > (((i / 5) * 24))
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}		
			}
		}		
	}
	if ((ball->y + ball->dY) < 20)
	{
		
		ballHitV(ball);
	}
}

/*
ballHitV will change the path of the ball, flipping the vertical direction, and
	preserving the horizontal direction
*/
void ballHitV(Ball *ball)
{
	ball->dY -= (ball->dY + ball->dY);
}

/*
ballHitH will change the path of the ball, flipping the horizontal direction, and
	preserving the vertical direction
*/
void ballHitH(Ball *ball)
{
	ball->dX -= (ball->dX + ball->dX);
}

/*
ballHitB will change the path of the ball, flipping both horizontal and vertical
	directions
*/
void ballHitB(Ball *ball)
{
	ball->dX -= (ball->dX + ball->dX);
	ball->dY -= (ball->dY + ball->dY);
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
void move_paddle_left(Paddle *paddle){
	paddle->x += 1;
}
/*

*/
void move_paddle_right(Paddle *paddle){
	paddle->x -= 1;
}
/*

*/
void paddle_launch_ball(Paddle *paddle){
	/* release the ball */

}
/*

*/
int get_life(LifeCounter *lifeCounter){
	return lifeCounter->numLives;
}
/*

*/
void remove_life(LifeCounter *lifeCounter){
	lifeCounter->numLives -= 1;
}


