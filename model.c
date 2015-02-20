#include "model.h"


/*
moveBall will move the ball on it's respective path.
Collision detection will be preformed by the event handler
*/
void moveBall(Ball ball)
{
	ball.x += ball.dX; 
	ball.y += ball.dY;
}

/*
ballHitV will change the path of the ball, flipping the vertical direction, and
	preserving the horizontal direction
*/
void ballHitV(Ball ball)
{
	ball.dY -= (ball.dY * 2);
	moveBall(ball);
}

/*
ballHitH will change the path of the ball, flipping the horizontal direction, and
	preserving the vertical direction
*/
void ballHitH(Ball ball)
{
	ball.dX -= (ball.dX * 2);
	moveBall(ball);
}

/*
ballHitB will change the path of the ball, flipping both horizontal and vertical
	directions
*/
void ballHitB(Ball ball)
{
	ball.dX -= (ball.dX * 2);
	ball.dY -= (ball.dY * 2);
	moveBall(ball);
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

