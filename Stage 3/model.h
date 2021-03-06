#ifndef MODEL_H
#define MODEL_H
#define true 1
#define false 0
#define BRICK_HEIGHT 24
#define BRICK_WIDTH 64
#define TOP_BAR_HEIGHT 12
#define PADDLE_HEIGHT 16
#define PADDLE_WIDTH  72

#include "raster.h"
#include "types.h"
#include "font.h"
#include "balBit.h"
typedef int bool;

typedef struct
{
	int x;
	int y;
	int dX;
	int dY;
	int size;
} Ball;

typedef struct 
{
	int score;
	int x;
	int y;
} ScoreNum;

typedef struct 
{
	int x;
	int y;
} ScoreLabel;

typedef struct {
	int x;
	int y;
}Paddle;

typedef struct{
	int numLives;
	int x;
	int y;
}LifeCounter;

typedef struct{
	Ball ball;
	ScoreNum scoreNum;
    ScoreLabel scoreLabel;
    Paddle paddle;
    bool bricks[25];
    LifeCounter lifeCounter;
}Screen;

void moveBall(Ball *ball, bool bricks[]);
void addScore(ScoreNum score, int amount);
void remScore(ScoreNum score, int amount);
void scoreLPosition (ScoreLabel label, int x, int y);
void paddleLeft(Paddle *paddle);
void paddleRight(Paddle *paddle);
void launchBall(Paddle *paddle);
void destroyBrick(int brick);
void removeLife(LifeCounter *lifeCounter);
int  getLife(LifeCounter *lifeCounter);
int  getScore (ScoreNum score);
void printScreen(Screen screen);
void ballHitVert(Ball *ball);
void ballHitHor(Ball *ball);
void printScreen(Screen screen);

#endif