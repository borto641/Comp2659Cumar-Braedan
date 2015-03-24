#ifndef RENDER_H
#define RENDER_H

#define BRICK_HEIGHT 24
#define BRICK_WIDTH 64
#define TOP_BAR_HEIGHT 12
#define PADDLE_HEIGHT 16
#define PADDLE_WIDTH  72
#define BALL_HEIGHT 16
#define SCORE_WIDTH 24
#define SCORE_HEIGHT 8

#include "model.h"
#include "font.h"
#include "balBit.h"

void printScreen(Screen screen, UINT32 *base);
void refreshScreen(Screen *screen, UINT32 *base);
void drawChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void saveChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void clrBrick(Brick *brick, UINT8 *base);
void printLifeLabel(LifeLabel lifeCounterLabel, UINT8 *base);
void printScoreLabel(ScoreLabel scoreLabel, UINT8 *base);
void drawLives(LifeCount lives, UINT8 *base);
void drawScore(ScoreNum scoreNum, UINT8 *base);
void drawPaddle(UINT8 *base, Paddle paddle);
void clearPaddle(UINT8 *base, Paddle paddle);
void drawBall(Ball ball, UINT16 *base);
void printChars(UINT8 *base, int x, int y, int length, char string[]);
#endif