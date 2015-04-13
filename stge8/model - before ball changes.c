#include "model.h"

void checkCollision(Ball *ball, bool bricks[])
{
	
	if (ball.Y > 120)/*bricks may be hit*/
	{

			if (ball->dX > 0) /*moving right*/
			{
				if (ball-> dY < 0) /*moving up*/
				{
				/*	uRCollDetect(ball, bricks);*/
				}
				else /*moving down*/
				{
					dRCollDetect(ball, bricks);
				}
			}
			else if (ball->dX < 0) /*left*/
			{
				if (ball->dY > 0) /*moving up*/
				{
				/*	uLCollDetect(ball,bricks);*/
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
					upCollDetect(ball,bricks);
				}
			}
			
	}
	else /*cannot hit bricks*/
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
			if (((i / 5) % 2) == 0) /*Even row*/
			{
				if ( ball->x + 15 >= ((i % 5) * 128) && ball->x < (((i % 5) * 128) + 64) /* within the valid x range of brick*/
				{
					if (ball->y + ball->dY < (((i / 5) * 24) + 24) && (ball->y + ball->dY) >= ((i / 5) * 24))
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}					
			}
			else /*odd row*/
			{
				if ( ball->x + 15 >= ((i % 5) * 128) + 64 && ball->x < (((i % 5) * 128) + 128) /* within the valid x range of brick*/
				{
					if (ball->y + ball->dY <= (((i / 5) * 24) + 24) && (ball->y + ball->dY) >= ((i / 5) * 24))
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}		
			}
		}		
	}
	if ((ball->y + ball->dY) < 20)	/*checks for roof hits*/
		ballHitV(ball);
	if (ball->x + ball->dX <= 0 || ball->x + ball->dX >= 639) /*checks for wall hits*/
			ballHitH(ball);
}


void downCollDetect(Ball ball, Brick bricks[])
{
	int i;
	int pixel;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i] == true)
		{
			if (((i / 5) % 2) == 0) /*Even row*/
			{
				if ( ball->x + 15 >= ((i % 5) * 128) && ball->x < (((i % 5) * 128) + 64) /* within the valid x range of brick*/
				{
					if (ball->y + BALL_HEIGHT - 1 >= ((i / 5) * 24) && (ball->y + ball->dY + BALL_HEIGHT - 1) <= ((i / 5) * 24)
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}					
			}
			else /*odd row*/
			{
				if ( ball->x + 15 >= ((i % 5) * 128) + 64 && ball->x < (((i % 5) * 128) + 128) /* within the valid x range of brick*/
				{
					if (ball->y + BALL_HEIGHT - 1 >= (((i / 5) * 24) + 24) && (ball->y + ball->dY - BALL_HEIGHT) <= (((i / 5) * 24) + 24)
					{
						destroyBrick(bricks[i]);
						ballHitV(ball);
					}						
				}		
			}
		}		
	}
	if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= 639)	/*checks for roof hits*/
		ballHitBottom(ball);
	if (ball->x + ball->dX <= 0 || ball->x + ball->dX >= 639) /*checks for wall hits*/
		ballHitH(ball);
}

void dRCollDetect(Ball, Brick bricks[])
{
	int i;
	int pixel;
	bool flippedH = false;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i] == true)
		{
			if (((i / 5) % 2) == 0) /*Even row*/
			{
				if ((ball->x + ball->dX + 15) >= ((i % 5) * 128) && (ball->x + ball->dX) <= (((i % 5) * 128) + 64)) /*In x range*/
				{
					if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= ((i / 5) * 24) && (ball->y + ball->dY + BALL_HEIGHT - 1) <= ((i / 5) * 24) + 23) 
						/* in Y range*/
					{
						if ((ball->x + ball-dX + 15) - ((i % 5) * 128) > (ball->x + ball-dY + 15) - ((i / 5) * 24) + 23 /*ball entered from top*/
						{
							if (!flippedV)
							{
								ballHitV(ball);
								bricks[i] = false;
							}
							else /*ball entered from side*/
							{
								flippedH = TRUE;
								ballHitH(ball);
								bricks[i] = false;
							}
						}
					}
				}
				else 
				{
					if ((ball->x + ball->dX + 15) >= ((i % 5) * 128 + 64) && (ball->x + ball->dX) <= (((i % 5) * 128) + 128))
					{
						if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= ((i / 5) * 24) && (ball->y + ball->dY + BALL_HEIGHT - 1) <= ((i / 5) * 24) + 23)
						{
							if ((ball->x + ball-dX + 15) - ((i % 5) * 128) > (ball->x + ball-dY + 15) - ((i / 5) * 24) + 23
							{
								ballHitV(ball);
								bricks[i] = false;
							}
							else
							{
								flippedH = TRUE;
								ballHitH(ball);
								bricks[i] = false;
							}	
						}
					}
				}
			}
		}	
		if ((ball->x + ball->dX + BALL_WIDTH >= 639 
			|| ball->x + ball->dX + BALL_WIDTH < 0)
			&& !flippedH)
		{
			ballHitH(ball);
		}		
	}		
}		
			

void dLCollDetect(Ball, Brick bricks[])
{
	int i;
	int pixel;
	bool flippedH = false;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i] == true)
		{
			if (((i / 5) % 2) == 0) /*Even row*/
			{
				if ((ball->x + ball->dX + 15) >= ((i % 5) * 128) && (ball->x + ball->dX) <= (((i % 5) * 128) + 64)) /*In x range*/
				{
					if ((ball->y + ball->dY + BALL_HEIGHT - 1) >= ((i / 5) * 24) && (ball->y + ball->dY + BALL_HEIGHT - 1) <= ((i / 5) * 24) + 23) 
						/* in Y range*/
					{
						if (((i % 5) * 128 + 64) - (ball->x + ball-dX) > (ball->x + ball-dY + 15) - ((i / 5) * 24) + 23 /*ball entered from top*/
						{
							ballHitV(ball);
							bricks[i] = false;
						}
						else /*ball entered from side*/
						{
							flippedH = TRUE;
							ballHitH(ball);
							bricks[i] = false;
						}
					}
				}
			}
		}
		else 
		{
			if ((ball->x + ball->dX + 15) >= ((i % 5) * 128 + 64) && (ball->x + ball->dX) <= (((i % 5) * 128) + 128))
			{
				if ((ball->y + ball->dY + BALL_HEIGHT - 1) <= ((i / 5) * 24) && (ball->y + ball->dY + BALL_HEIGHT - 1) >= ((i / 5) * 24) + 23)
				{
					if ((ball->x + ball-dX + 15) - ((i % 5) * 128) > (ball->x + ball-dY + 15) - ((i / 5) * 24) + 23
					{
						ballHitV(ball);
						bricks[i] = false;
					}
					else
					{
						flippedH = TRUE;
						ballHitH(ball);
						bricks[i] = false;
					}	
				}
			}
		}
	}	
	if ((ball->x + ball->dX + BALL_WIDTH >= 639 
		|| ball->x + ball->dX + BALL_WIDTH < 0)
		&& !flippedH)
	{
		ballHitH(ball);
	}		
}		




*/
void moveBall(Ball *ball, bool bricks[], Paddle * paddle)
{
/* ADD COLLISION DETECTION */
	ballDirection(ball,  paddle);
	if(ball->ballMovingUp == true){
		if(ball->ballMovingRight == true){
			ball->x += ball->dX;
			ball->y -= ball->dY;
		}
		else {
			ball->x -= ball->dX;
			ball->y -= ball->dY;
		}
	}
	else if(ball->ballMovingUp == false){
		if(ball->ballMovingLeft == true){
			ball->x -= ball->dX;
			ball->y += ball->dY;
		}
		else {
			ball->x += ball->dX;
			ball->y += ball->dY;
		}
	}
	
	
		
}
void ballDirection(Ball *ball, Paddle *paddle){
	int x = ball->x;
	int y = ball->y;
	int dx = ball->dX;
	int dy = ball->dY;
	
	if(((ball->ballMovingUp) == true)&&((y -= dy) <= 0)){
		ball->ballMovingUp = false;	
	}
	else if(((ball->ballMovingUp) == false)  && (((y += dy) +16) >= 399)
	||
		((((ball->ballMovingUp) == false) 
						&& ((((y += dy)+16) >= (paddle->y) ) 
						&&  ((((x += dx)+16) >=(paddle->x)) 
						&& (((x += dx)) <=(paddle->x + 72))))))){
	
	
		ball->ballMovingUp = true;	 
	}
	else if((((ball->ballMovingUp) == true) && ((ball->ballMovingLeft) == true)) && ((x -= dx) <= 0)){
		ball->ballMovingRight = true;
		ball->ballMovingLeft = false;
	}
	else if ((((ball->ballMovingUp) == true) && ((ball->ballMovingRight) == true)) && (((x += dx) + 16) >= 639)){
		ball->ballMovingRight = false;
		ball->ballMovingLeft =true;
	}
	else if((((ball->ballMovingUp) == false) && ((ball->ballMovingLeft) == true)) && (((x -= dx)) <= 1)){
		ball->ballMovingRight = true;
		ball->ballMovingLeft = false;
	}
	else if ((((ball->ballMovingUp) == false) && ((ball->ballMovingRight) == true)) && (((x += dx) + 16) >= 639)){
		ball->ballMovingRight = false;
		ball->ballMovingLeft = true;
	}
	
	
	
	
	
	/*
	if(((ball->ballMovingUp) == true)&&((ball->y -= ball->dY) <= 0)){
		ball->ballMovingUp = false;	
	}
	else if(((ball->ballMovingUp) == false)  && (((ball->y += ball->dY)+16) >= 400)){ 
	/*
	||
		((((ball->ballMovingUp) == false) 
						&& ((((ball->y += ball->dY)+16) >= (paddle->y) ) 
						&&  ((((ball->x += ball->dX)+16) >=(paddle->x)) 
						&& (((ball->x += ball->dX)+16) <=(paddle->x + 72))))))){
		
	
		ball->ballMovingUp = true;
		 
			
	}
	
	
	else if((((ball->ballMovingUp) == true) && ((ball->ballMovingLeft) == true)) && ((ball->x -= ball->dX) <= 0)){
		ball->ballMovingRight = true;
		ball->ballMovingLeft = false;
	}
	else if ((((ball->ballMovingUp) == true) && ((ball->ballMovingRight) == true)) && (((ball->x += ball->dX) + 16) >= 639)){
		ball->ballMovingRight = false;
		ball->ballMovingLeft =true;
	}
	else if((((ball->ballMovingUp) == false) && ((ball->ballMovingLeft) == true)) && (((ball->x -= ball->dX)) <= 0)){
		ball->ballMovingRight = true;
		ball->ballMovingLeft = false;
	}
	else if ((((ball->ballMovingUp) == false) && ((ball->ballMovingRight) == true)) && (((ball->x += ball->dX) + 16) >= 639)){
		ball->ballMovingRight = false;
		ball->ballMovingLeft = true;
	}
	*/
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


