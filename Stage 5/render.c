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
	plot_hor_line((UINT8*)(base), 0, TOP_BAR_HEIGHT, 640);
	for (i = 0; i < 25; i++)
	{
		if (screen.bricks[i].alive == TRUE)
		{
			plot_rectangle((UINT8*)(base), screen.bricks[i].x, screen.bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	drawScore(screen.scoreNum, (UINT8*)(base));
	drawLives(screen.lifeCount, (UINT8*)(base));
	printScoreLabel(screen.scoreLabel, (UINT8*)(base));
	printLifeLabel(screen.lifeLabel, (UINT8*)(base));
	
	/*saves the contents of the buffer where the ball will be printed to an array, as well as it's location*/
	saveChunk(base, screen.ball.x, screen.ball.y, screen.ballChunk, BALL_HEIGHT);
	screen.ball.oldX = screen.ball.x;
	screen.ball.oldY = screen.ball.y;
	drawBall(screen.ball, (UINT16*)(base));
	/*saves the contents of the buffer where the paddle will be printed to an array, as well as it's location*/
	saveChunk(base, screen.paddle.x, screen.paddle.y, screen.paddleChunk, PADDLE_HEIGHT);
	screen.paddle.oldX = screen.paddle.x;
	screen.paddle.oldY = screen.paddle.y;
	drawPaddle(screen.paddle, (UINT8*)(base));
}

void refreshScreen(Screen *screen, UINT32 *base)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (screen->bricks[i].undraw)
		{ /*if any bricks have been hit since the last refresh, clear them from the buffer*/
			screen->bricks[i].undraw = FALSE;
			clearRectangle((UINT8*)(base), screen->bricks[i].x, screen->bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	
	/*Ball and paddle refresh*/
	drawChunk(base, screen->ball.oldX, screen->ball.oldY, screen->ballChunk, BALL_HEIGHT); /*erase ball*/
	saveChunk(base, screen->ball.x, screen->ball.y, screen->ballChunk, BALL_HEIGHT); /*save ball's new background*/
	screen->ball.oldX = screen->ball.x;
	screen->ball.oldY = screen->ball.y;
	drawBall(screen->ball, (UINT16*)(base));
	
	if (screen->paddle.oldX != screen->paddle.x)
	{
		drawChunk(base, screen->paddle.oldX, screen->paddle.oldY, screen->ballChunk, BALL_HEIGHT); /*erase paddle*/
		saveChunk(base, screen->paddle.x, screen->paddle.y, screen->paddleChunk, PADDLE_HEIGHT); /*save paddle's new background*/
		screen->paddle.oldX = screen->paddle.x;
		screen->paddle.oldY = screen->paddle.y;
		drawPaddle(screen->paddle, (UINT8*)(base));
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
void drawPaddle(Paddle paddle, UINT8 *base)
{
	plot_rectangle(base, paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void drawScore(ScoreNum scoreNum, UINT8 *base)
{
	char score[3];
	scoreToChars(scoreNum, score);
	clearRectangle(base, scoreNum.x, scoreNum.y, SCORE_WIDTH, SCORE_HEIGHT);
	printChars(base, scoreNum.x, scoreNum.y, 3, score);
}

void drawLives(LifeCount lives, UINT8 *base)
{
	clearRectangle(base, lives.x, lives.y, 8, FONT_HEIGHT);
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




