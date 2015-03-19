#include "render.h"


void printScreen(Screen screen)
{
	UINT16 *base = Physbase();
	UINT8 *base8 = Physbase();
	int i;
	char label[] = "Score:";
	char lives[] = "Lives:";
	char score[] = "666";
	plot_hor_line(base8, 0, TOP_BAR_HEIGHT, 640);

	for (i = 0; i < 25; i++)
	{
		if (screen.bricks[i].alive == TRUE)
		{
			plot_rectangle(base8, screen.bricks[i].x, screen.bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT);
		}
	}
	
	for (i = 0; i < 6; i++)
	{
		bitmap8(base8, (screen.scoreLabel.x + (i * 8)), screen.scoreLabel.y, GLYPH_START(label[i]), FONT_HEIGHT);
	}
	
	for (i = 0; i < 3; i++)
	{
		bitmap8(base8, (screen.scoreNum.x + (i * 8)), screen.scoreNum.y, GLYPH_START(score[i]), FONT_HEIGHT);
	}
	
	for (i = 0; i < 6; i++)
	{
		bitmap8(base8, (screen.lifeCounter.x + (i * 8)), screen.lifeCounter.y, GLYPH_START(lives[i]), FONT_HEIGHT);
	}
	
	for (i = 0; i < 3; i++)
	{
		bitmap8(base8, (screen.lifeCounter.x + (i * 8) + 48), screen.lifeCounter.y, GLYPH_START(score[i]), FONT_HEIGHT);
	}
	
}

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

void drwBall(Ball ball, UINT16 *base)
{
	bitmap16(base, ball.x, ball.y, ballBitmap, 16);
}

void clrPaddle(UINT8 *base, Paddle paddle)
{
	clearRectangle(base, paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void drwPaddle(UINT8 *base, Paddle paddle)
{
	plot_rectangle(base, paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void clrBrick(Brick *brick, UINT8 *base)
{
	clearRectangle(base, brick->x, brick->y, BRICK_WIDTH, BRICK_HEIGHT);
}




