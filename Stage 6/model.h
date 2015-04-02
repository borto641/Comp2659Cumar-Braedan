#ifndef MODEL_H
#define MODEL_H
#include "raster.h"
#include "types.h"

#define BALL_HEIGHT 16
#define BALL_WIDTH 16
#define BRICK_WIDTH 64
#define BRICK_HEIGHT 24
#define PADDLE_WIDTH 128
#define PADDLE_HEIGHT 8
#define NUM_BRICKS 25
#define ZERO 48

typedef struct
{
	int olderX;
	int olderY;
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
	bool firstUndraw;
	bool secondUndraw;
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
	int olderX;
	int olderY;
	bool lock;
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
    Brick bricks[NUM_BRICKS];
	int bricksLeft;
	UINT32 ballChunk[32];
	UINT32 oldBallChunk[32];
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
void checkBallCollision(Screen *screen, int dX, int dY);
void upCollDetect(Screen *screen, int dX, int dY);
void downCollDetect(Screen *screen, int dX, int dY);
void dRCollDetect(Screen *screen, int dX, int dY);
void dLCollDetect(Screen *screen, int dX, int dY);
void uLCollDetect(Screen *screen, int dX, int dY);
void uRCollDetect(Screen *screen, int dX, int dY);
void paddleCollDetect(Screen *screen, int dX, int dY);
void checkBounces(Ball *ball);
void scoreToChars (ScoreNum score, char scoreChars[]);
void initialize(Screen *screen);
void ballHitPaddle(Screen *screen, int dX, int dY);
void resetLevel(Screen *screen);

#endif