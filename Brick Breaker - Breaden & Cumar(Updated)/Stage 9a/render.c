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
	plotHorLine(base, 0, TOP_BAR_HEIGHT, 640, 0, 0);
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen.bricks[i].alive == TRUE)
		{
			plotRectangle(base, screen.bricks[i].x, screen.bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	drawScore(screen.scoreNum, (UINT8*)(base));
	drawLives(screen.lifeCount, (UINT8*)(base));
	printScoreLabel(screen.scoreLabel, (UINT8*)(base));
	printLifeLabel(screen.lifeLabel, (UINT8*)(base));
	drawBall(&screen.ball, (UINT16*)(base));
	drawPaddle(base, &screen.paddle);
}
/*
*	Function: refreshScreen
*
*	Purpose: Redraws the ball, paddle, and score, as well as undrawing any smashed bricks
*
*	Input: A Screen structure by reference
*		   A UINT32 pointer to the screen buffer base
*/
void refreshScreen(Screen *screen, UINT32 *base)
{
	int i;	
	
	drawChunk(base, screen->ball.olderX, screen->ball.olderY, screen->oldBallChunk, BALL_HEIGHT); /*erase ball*/
	for (i = 0; i < NUM_BRICKS; i++)
	{
		if (screen->bricks[i].firstUndraw == TRUE)
		{ /*if any bricks have been hit since the last refresh, clear them from the buffer*/
			screen->bricks[i].firstUndraw = FALSE;
			clearRectangle((UINT32*)(base), screen->bricks[i].x, screen->bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		} else if (screen->bricks[i].secondUndraw == TRUE)
		{ /*if any bricks have been hit since the second last refresh, clear them from the buffer*/
			screen->bricks[i].secondUndraw = FALSE;
			clearRectangle((UINT32*)(base), screen->bricks[i].x, screen->bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	for (i = 0; i < 32; i++)
	{
		screen->oldBallChunk[i] = screen->ballChunk[i];
	}
	if(screen->paddle.olderX != screen->paddle.x)
		clearPaddle(base, screen->paddle);
	
	saveChunk(base, screen->ball.x, screen->ball.y, screen->ballChunk, BALL_HEIGHT); /*save ball's new background*/	
	drawBall(&screen->ball, (UINT16*)(base));
	
	drawPaddle(base, &screen->paddle);
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
*	Function: printCharsV2
*
*	Purpose: To print a given array of characters to a location in the screen buffer inverted in colour
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   An integer representing the beginning x location of the string
*		   An integer representing the y location of the string
*		   An integer representing the length of the array
*		   A character array
*/
void printCharsV2(UINT8 *base, int x, int y, int length, char string[])
{
	int i;
	for (i = 0; i < length; i++)
	{
		bitmap8V2(base, (x + (i * 8)), y, GLYPH_START(string[i]), FONT_HEIGHT);
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
	UINT32 *start =	base + (y * 20) + (x >> 5);
	
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
	UINT32 *start =	base + (y * 20) + (x >> 5);
	
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
void drawBall(Ball *ball, UINT16 *base)
{
	ball->olderX = ball->oldX;
	ball->olderY = ball->oldY;
	ball->oldX = ball->x;
	ball->oldY = ball->y;
	bitmap16(base, ball->x, ball->y, ballBitmap, 16);
}

/*
*	Function: drawPaddle
*
*	Purpose: To draw the current location of the Paddle to the screen buffer
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   A Paddle object
*/
void drawPaddle(UINT32 *base, Paddle *paddle)
{
	plotRectangle(base, paddle->x, paddle->y, PADDLE_WIDTH, PADDLE_HEIGHT);
	paddle->olderX = paddle->oldX;
	paddle->olderY = paddle->oldY;
	paddle->oldX = paddle->x;
	paddle->oldY = paddle->y;
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
	clearRectangle((UINT32*)(base), lives.x, lives.y, 9, FONT_HEIGHT);
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




