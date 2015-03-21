#ifndef RENDER_H
#define RENDER_H

#define BRICK_HEIGHT 24
#define BRICK_WIDTH 64
#define TOP_BAR_HEIGHT 12
#define PADDLE_HEIGHT 16
#define PADDLE_WIDTH  72
#define BALL_HEIGHT 16

#include "model.h"
#include "font.h"
#include "balBit.h"

void printScreen(Screen screen);
void clrBall(Ball ball, UINT16 *base);
void drwBall(Ball ball, UINT16 *base);
void clrPaddle(UINT8 *base, Paddle paddle);
void drwPaddle(UINT8 *base, Paddle paddle);
void drawChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void saveChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void clrBrick(Brick *brick, UINT8 *base);
#endif