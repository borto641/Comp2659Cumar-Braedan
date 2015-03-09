#ifndef MODEL_H
#define MODEL_H
#define true 1
#define false 0

#include "raster.h"

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
	char score[6];
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

void moveBall(Ball ball, bool bricks[]);
void addScore(ScoreNum score, int amount);
void remScore(ScoreNum score, int amount);
void scoreLPosition (ScoreLabel label, int x, int y);
void paddleLeft(Screen *screen);
void paddleRight(Screen *screen);
void launchBall(Screen *screen);
void destroyBrick(int brick);
void removeLife(LifeCounter lifeCounter);
int  getLife(LifeCounter lifeCounter);
int  getScore (ScoreNum score);
void ballHitVert(Ball ball);
void ballHitHor(Ball ball);
void printScreen(Screen *screen);

#endif