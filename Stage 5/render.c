#include "render.h"

/*
*	Function: printScreen
*
*	Purpose: Prints a representation of the Screen structure, without the ball or paddle, to the screen
*
*	Input: A Screen structure representing the state of the game
*		   A UINT16 pointer representing the physical base of the screen buffer
*/
void printScreen(Screen screen, UINT16 *base)
{
	UINT8 *base8 = (UINT8*)(base)
	int i;
	
	plot_hor_line(base8, 0, TOP_BAR_HEIGHT, 640);
	for (i = 0; i < 25; i++)
	{
		if (screen.bricks[i].alive == TRUE)
		{
			plot_rectangle(base8, screen.bricks[i].x, screen.bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	/*prints the score to the screen*/
	printString(base8, screen.scoreNum.x, screen.scoreNum.y, 3, scoreToChars(screen.scoreNum.score));
	/*prints the score label to the screen*/
	printString(base8, screen.scoreLabel.x, screen.scoreLabel.y, 6, screen.scoreLabel.label);
	/*prints the life counter label to the screen*/
	printString(base8, screen.lifeCounterLabel.x, screen.lifeCounterLabel.y, 6, screen.lifeCounterLabel.label);
	/*prints the remaining lives to the screen*/
	bitmap8(base8, screen.lifeCounterNumber.x, screen.lifeCounterNumber.y, GLYPH_START((char)((screen.lifeCounterNumb.lives) + ZERO)));
	
}

/*
*	Function: printChars
*
*	Purpose: To print a given array of characters to a location in the screen buffer
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   An integer representing the beggining x location of the string
*		   An integer representing the y location of the string
*		   An integer representing the length of the array
*		   A character array
*/
void printChars(UINT8 *base, int x, int y, int length, char[] string)
{
	for (i = 0; i < 6; i++)
	{
		bitmap8(base8, (x + (i * 8)), y, GLYPH_START(string[i]), FONT_HEIGHT);
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
void saveChunk (UINT32 *base, int x, int y, UINT32 *saved, int height)
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
*	Function: drwBall
*
*	Purpose: To draw the current location of the Ball to the screen buffer
*
*	Input: A UINT16 representing the physical base of the screen buffer
*		   A Ball object
*/
void drwBall(Ball ball, UINT16 *base)
{
	bitmap16(base, ball.x, ball.y, ballBitmap, 16);
}

/*
*	Function: clrPaddle
*
*	Purpose: To clear the Paddle from the given location on the screen buffer
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   A Paddle object
*/
void clrPaddle(UINT8 *base, Paddle paddle)
{
	clearRectangle(base, paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

/*
*	Function: drwPaddle
*
*	Purpose: To draw the current location of the Paddle to the screen buffer
*
*	Input: A UINT8 representing the physical base of the screen buffer
*		   A Paddle object
*/
void drwPaddle(UINT8 *base, Paddle paddle)
{
	plot_rectangle(base, paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

/*
*	Function: clrBrick
*
*	Purpose: To clear a brick from the screen buffer
*
*	Input: A Brick object
*/
void clrBrick(Brick brick)
{
	UINT8 *base = Physbase();
	clearRectangle(base, brick->x, brick->y, BRICK_WIDTH, BRICK_HEIGHT);
}




