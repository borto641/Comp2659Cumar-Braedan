#include "model.h"
#include "types.h"
#include "font.c"

const int ballBitmap[16] = 
	{ 
    0x07E0,
	0x1FF8,
	0x3FFC,
	0x7FFE,
	0x7FFE,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x7FFE,
	0x7FFE,
	0x3FFC,
	0x1FF8,
	0x07E0
    };  
    
const int fontS[8] = {0x00,0x78,0x80,0x78,0x04,0x84,0x78,0x00};  /* S */
const int fontC[8] = {0x00,0x00,0x1C,0x20,0x20,0x20,0x1C,0x00};
const int fontO[8] = {0x00,0x00,0x38,0x44,0x44,0x44,0x38,0x00};
const int fontR[8] = {0x00,0x00,0x1C,0x20,0x20,0x20,0x20,0x00};
const int fontE[8] = {0x00,0x00,0x38,0x44,0x78,0x40,0x3C,0x00};
const int fontZero[8] = {0x00,0x78,0x8C,0x94,0xA4,0xC4,0x78,0x00};
const int fontColon[8] = {0x00,0x00,0x00,0x10,0x00,0x00,0x10,0x00};
                      
/*
moveBall will move the ball on it's respective path.
Collision detection will be preformed by the event handler
*/
void moveBall(Ball ball, bool bricks[])
{
/* ADD COLLISION DETECTION*/
	ball.x += ball.dX; 
	ball.y += ball.dY;
}

/*
ballHitV will change the path of the ball, flipping the vertical direction, and
	preserving the horizontal direction
*/
void ballHitV(Ball ball)
{
	ball.dY -= (ball.dY + ball.dY);
}

/*
ballHitH will change the path of the ball, flipping the horizontal direction, and
	preserving the vertical direction
*/
void ballHitH(Ball ball)
{
	ball.dX -= (ball.dX + ball.dX);
}

/*
ballHitB will change the path of the ball, flipping both horizontal and vertical
	directions
*/
void ballHitB(Ball ball)
{
	ball.dX -= (ball.dX + ball.dX);
	ball.dY -= (ball.dY + ball.dY);
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
void paddleRight(Screen *screen){
     if ((screen->paddle.x + 72 + 30) <= 639 ){
	screen->paddle.x += 30;
    }
}
/*

*/
void paddleLeft(Screen *screen){
     if ((screen->paddle.x - 30) >= 0 ){
            screen->paddle.x -= 30;
    }
}
/*

*/
void paddle_launch_ball(Screen *screen){
	/* release the ball */

}
/*

*/
int get_life(LifeCounter lifeCounter){
	return lifeCounter.numLives;
}
/*

*/
void remove_life(LifeCounter lifeCounter){
	lifeCounter.numLives -= 1;
}

void printScreen (Screen *screen)
{
	UINT16 *base = Physbase();
	UINT8 *base8 = Physbase();
	int i;
     
    plot_hor_line(base8, 0, 20, 640);
	plot_bitmap_16(base, screen->ball.x, screen->ball.y, ballBitmap, 16);
    plot_bitmap_16(base, 0, 0, ballBitmap, 16);
    plot_bitmap_16(base, 16,0, ballBitmap, 16);
    plot_bitmap_16(base, 32,0, ballBitmap, 16);
    plot_bitmap_8(base8, 500, 5, fontS, 8, 0);
    plot_bitmap_8(base8, 508, 5, fontC, 8, 0) ;
    plot_bitmap_8(base8, 516, 5, fontO, 8, 0);
    plot_bitmap_8(base8, 524, 5, fontR, 8 , 0);
    plot_bitmap_8(base8, 532, 5, fontE, 8,   0);
    plot_bitmap_8(base8, 540, 5, fontColon, 8, 0);
    plot_bitmap_8(base8, 548, 5, fontZero, 8, 0);
    plot_bitmap_8(base8, 556, 5, fontZero, 8, 0);
    plot_bitmap_8(base8, 564, 5, fontZero, 8, 0);
    plot_bitmap_8(base8, 572, 5, fontZero, 8, 0);
	plot_rectangle(base8, screen->paddle.x, screen->paddle.y, 72, 10);
 
    for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i] == true)
		{
			if (((i / 5) % 2) != 0)
			{
				plot_rectangle(base8, ((i % 5) << 7) + 64, ( 20 + ((i / 5) * 24) ), 64, 24);
			}
			else 
			{
				plot_rectangle(base8, ( (i % 5) << 7), (20 + (i / 5) * 24), 64, 24);
			}
		}
	}
}
