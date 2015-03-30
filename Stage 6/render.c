#include "render.h"

/*
*	Function: printScreen
*
*	Purpose: Prints a representation of the Screen structure, without the ball or paddle, to the screen
*
*	Input: A Screen structure representing the state of the game
*		   A UINT16 pointer representing the physical base of the screen buffer
*/
void printScreen(Screen screen, UINT32 *base)
{
	int i;
	plot_hor_line(base, 0, TOP_BAR_HEIGHT, 640, 0, 0);
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen.bricks[i].alive == TRUE)
		{
			plot_rectangle(base, screen.bricks[i].x, screen.bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	drawScore(screen.scoreNum, (UINT8*)(base));
	drawLives(screen.lifeCount, (UINT8*)(base));
	printScoreLabel(screen.scoreLabel, (UINT8*)(base));
	printLifeLabel(screen.lifeLabel, (UINT8*)(base));
	
	/*saves the contents of the buffer where the ball will be printed to an array, as well as it's location*/
	drawBall(screen.ball, (UINT16*)(base));
	/*saves the contents of the buffer where the paddle will be printed to an array, as well as it's location*/
	drawPaddle(base, screen.paddle);
}

void refreshScreen(Screen *screen, UINT32 *base)
{
	int i;	
	/*Ball and paddle refresh*/
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].firstUndraw == TRUE)
		{ /*if any bricks have been hit since the last refresh, clear them from the buffer*/
			screen->bricks[i].firstUndraw = FALSE;
			clearRectangle((UINT32*)(base), screen->bricks[i].x, screen->bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		} else if (screen->bricks[i].secondUndraw == TRUE)
		{ /*if any bricks have been hit since the last refresh, clear them from the buffer*/
			screen->bricks[i].secondUndraw = FALSE;
			clearRectangle((UINT32*)(base), screen->bricks[i].x, screen->bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	drawChunk(base, screen->ball.olderX, screen->ball.olderY, screen->oldBallChunk, BALL_HEIGHT); /*erase ball*/
	for (i = 0; i < 32; i++)
	{
		screen->oldBallChunk[i] = screen->ballChunk[i];
	}
	saveChunk(base, screen->ball.x, screen->ball.y, screen->ballChunk, BALL_HEIGHT); /*save ball's new background*/
	screen->ball.olderX = screen->ball.oldX;
	screen->ball.olderY = screen->ball.oldY;
	screen->ball.oldX = screen->ball.x;
	screen->ball.oldY = screen->ball.y;
	drawBall(screen->ball, (UINT16*)(base));
	
	if (screen->paddle.olderX != screen->paddle.x)
	{
		clearPaddle(base, screen->paddle);
		drawPaddle(base, screen->paddle);
		screen->paddle.olderX = screen->paddle.oldX;
		screen->paddle.olderY = screen->paddle.oldY;
		screen->paddle.oldX = screen->paddle.x;
		screen->paddle.oldY = screen->paddle.y;
		drawPaddle(base, screen->paddle);
	}
	
	drawScore(screen->scoreNum, (UINT8*)(base));
	drawLives(screen->lifeCount, (UINT8*)(base));
	
}
/*
*	Function: printChars
*
*	Purpose: To print a given array of characters to a location in the screen buffer
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   An integer representing the beginning x location of the string
*		   An integer representing the y location of the string
*		   An integer representing the length of the array
*		   A character array
*/
void printChars(UINT8 *base, int x, int y, int length, char string[])
{
	int i;
	for (i = 0; i < length; i++)
	{
		bitmap8(base, (x + (i * 8)), y, GLYPH_START(string[i]), FONT_HEIGHT);
	}
}

/*
*	Function: saveChunk
*
*	Purpose: To save a 32 bit wide portion of the screen butter to an array
*
*	Input: A UINT32 representing the physical base of the screen buffer
*		   A UINT32 array by reference
*	
*	Output: A UINT32 array by reference
*/
void saveChunk (UINT32 *base, int x, int y, UINT32 saved[], int height)
{
	int i;
	int arraySize = height *2;
	UINT32 *start =	base + (y * 20) + (x / 32);
	
	for (i = 0; i < arraySize; i++)
	{
		saved[i] = *start;
		i++;
		saved[i] = *(start + 1);
		start += 20;
	}
}

/*
*	Function: drawChunk
*
*	Purpose: To draw a 32 bit wide array to a given portion of the screen buffer
*
*	Input: A UINT32 representing the physical base of the screen buffer
*		   A UINT32 array by reference
*	
*	Output: A UINT32 array by reference
*/
void drawChunk (UINT32 *base, int x, int y, UINT32 *saved, int height)
{
	int i;
	int arraySize = height * 2;
	UINT32 *start =	base + (y * 20) + (x / 32);
	
	for (i = 0; i < arraySize; i++)
	{
		*start = saved[i];
		start++;
		i++;
		*start = saved[i];
		start += 19;
	}
}

/*
*	Function: drawBall
*
*	Purpose: To draw the current location of the Ball to the screen buffer
*
*	Input: A UINT16 representing the physical base of the screen buffer
*		   A Ball object
*/
void drawBall(Ball ball, UINT16 *base)
{
	bitmap16(base, ball.x, ball.y, ballBitmap, 16);
}

/*
*	Function: drawPaddle
*
*	Purpose: To draw the current location of the Paddle to the screen buffer
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   A Paddle object
*/
void drawPaddle(UINT32 *base, Paddle paddle)
{
	plot_rectangle(base, paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void clearPaddle(UINT32 *base, Paddle paddle)
{
	clearRectangle(base, paddle.olderX, paddle.olderY, PADDLE_WIDTH, PADDLE_HEIGHT);
}


void drawScore(ScoreNum scoreNum, UINT8 *base)
{
	char score[3];
	scoreToChars(scoreNum, score);
	clearRectangle((UINT32*)(base), scoreNum.x, scoreNum.y, SCORE_WIDTH, SCORE_HEIGHT);
	printChars(base, scoreNum.x, scoreNum.y, 3, score);
}

void drawLives(LifeCount lives, UINT8 *base)
{
	clearRectangle((UINT32*)(base), lives.x, lives.y, 8, FONT_HEIGHT);
	bitmap8(base, lives.x, lives.y, GLYPH_START((char)(lives.lives + ZERO)), FONT_HEIGHT);
}

void printScoreLabel(ScoreLabel scoreLabel, UINT8 *base)
{
	printChars(base, scoreLabel.x, scoreLabel.y, 6, scoreLabel.label);
}

void printLifeLabel(LifeLabel lifeLabel, UINT8 *base)
{
	printChars(base, lifeLabel.x, lifeLabel.y, 6, lifeLabel.label);
}




