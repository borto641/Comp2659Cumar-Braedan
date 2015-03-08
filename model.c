#include "model.h"
#include "ballBitmap.h"

/*
moveBall will move the ball on it's respective path.
Collision detection will be preformed by the event handler
*/

void moveBall(Ball *ball, bool bricks[])
{
	/*if ((ball.x + dX) <= 120)
	{
		check for collisions
	}*/

	ball.x += ball.dX; 
	ball.y += ball.dY;
}

/*
ballHitV will change the path of the ball, flipping the vertical direction, and
	preserving the horizontal direction
*/
void ballHitVert(Ball ball)
{
	ball.dY -= (ball.dY * 2);
}

/*
ballHitH will change the path of the ball, flipping the horizontal direction, and
	preserving the vertical direction
*/
void ballHitSide(Ball ball)
{
	ball.dX -= (ball.dX * 2);
}

/*
ballHitB will change the path of the ball, flipping both horizontal and vertical
	directions
*/
void ballHitBoth(Ball ball)
{
	ball.dX -= (ball.dX * 2);
	ball.dY -= (ball.dY * 2);
}

/*
addScore will increase the numerical score value by a given amount
*/
void addScore(ScoreNum score, int amount)
{
	score += amount;
}

/*
remScore will decrease the numerical score value by a given amount
*/
void remScore(ScoreNum score, int amount)
{
	score -= amount;
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

void printScreen (Screen screen)
{
	UINT16 *base  = Physbase();
	UINT8  *base8 = Physbase();
	plot_bitmap_16(base, screen.ball.x, screen.ball.y, ballBitmap, 16);
	for (int i = 0; i < 25; i++)
	{
		if (screen.brick[i] == TRUE)
		{
			/*if (block y % 2 != 0)
				{
					x += 64
				}
			*/
			if (((i / 5) % 2) != 0)
			{
				plot_rectangle(base8, (i * 128) + 64, ((i % 5) * 24), 64, 24);
			}
			else 
			{
				plot_rectangle(base8, ( i * 128), (i % 5) * 24, 64, 24);
			}
		}
	}
}