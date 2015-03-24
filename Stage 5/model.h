#ifndef MODEL_H
#define MODEL_H
#include "raster.h"
#include "types.h"

#define BALL_HEIGHT 16
#define BALL_WIDTH 16
#define BRICK_WIDTH 64
#define BRICK_HEIGHT 24
#define ZERO 48

typedef struct
{
	int oldX;
	int oldY;
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
	char label[6];
} ScoreLabel;

typedef struct {
	int x;
	int y;
	int oldX;
	int oldY;
	/*PADDLE IS HARD CODED TO 72x16*/
}Paddle;

typedef struct{
	int x;
	int y;
	char label[6];
}LifeLabel;

typedef struct{
	int x;
	int y;
	int lives;
}LifeCount;

typedef struct{
	Ball ball;
	ScoreNum scoreNum;
    ScoreLabel scoreLabel;
    Paddle paddle;
	LifeLabel lifeLabel;
	LifeCount lifeCount;
    Brick bricks[25];
	UINT32 ballChunk[32];
	bool holdBall;
	bool gameOver;
}Screen;

void moveBall(Screen *screen);
void resetBall(Screen *screen);
void addScore(ScoreNum score, int amount);
void remScore(ScoreNum score, int amount);
void scoreLPosition (ScoreLabel label, int x, int y);
void paddleLeft(Paddle *paddle);
void paddleRight(Paddle *paddle);
void launchBall(Screen *screen);
void destroyBrick(int brick);
int  getScore (ScoreNum score);
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
void scoreToChars (ScoreNum score, char scoreChars[]);
void initialize(Screen *screen);

#endif