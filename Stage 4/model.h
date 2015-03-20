#ifndef MODEL_H
#define MODEL_H
#include "raster.h"
#include "types.h"

#define BALL_HEIGHT 16
#define BALL_WIDTH 16
#define BRICK_WIDTH 64
#define BRICK_HEIGHT 24

typedef struct
{
	int x;
	int y;
	int dX;
	int dY;
	int totalBounces;
	int speed;
	bool ballOut;
	
} Ball;

typedef struct
{
	int x;
	int y;
	bool alive;
	bool undraw;
} Brick;

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
	/*PADDLE IS HARD CODED TO 72x16*/
}Paddle;

typedef struct{
	int x;
	int y;
}LifeCounterLabel;

typedef struct{
	Ball ball;
	ScoreNum scoreNum;
    ScoreLabel scoreLabel;
    Paddle paddle;
    Brick bricks[25];
    LifeCounterLabel lifeCounter;
	int lifeCount;
	bool resetBall;
}Screen;

void moveBall(Screen *screen);
void addScore(ScoreNum score, int amount);
void remScore(ScoreNum score, int amount);
void scoreLPosition (ScoreLabel label, int x, int y);
void paddleLeft(Paddle *paddle);
void paddleRight(Paddle *paddle);
void launchBall(Paddle *paddle);
void destroyBrick(int brick);
int  getScore (ScoreNum score);
void printScreen(Screen screen);
void printScreen(Screen screen);
void ballDirection(Ball *ball, Paddle *paddle);
void checkBallCollision(Screen *screen);
void upCollDetect(Screen *screen);
void downCollDetect(Screen *screen);
void dRCollDetect(Screen *screen);
void dLCollDetect(Screen *screen);
void uLCollDetect(Screen *screen);
void uRCollDetect(Screen *screen);
void paddleCollDetect(Screen *screen);
void checkBounces(Ball *ball);

#endif