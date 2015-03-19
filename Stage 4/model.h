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
	int numLives;
	int x;
	int y;
}LifeCounter;

typedef struct{
	Ball ball;
	ScoreNum scoreNum;
    ScoreLabel scoreLabel;
    Paddle paddle;
    Brick bricks[25];
    LifeCounter lifeCounter;
}Screen;

void moveBall(Ball *ball, Brick bricks[], Paddle paddle);
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
void printScreen(Screen screen);
void ballDirection(Ball *ball, Paddle *paddle);
void checkBallCollision(Ball *ball, Brick bricks[], Paddle paddle);
void upCollDetect(Ball *ball, Brick bricks[]);
void downCollDetect(Ball *ball, Brick bricks[]);
void dRCollDetect(Ball *ball, Brick bricks[]);
void dLCollDetect(Ball *ball, Brick bricks[]);
void uLCollDetect(Ball *ball, Brick bricks[]);
void uRCollDetect(Ball *ball, Brick bricks[]);
void paddleCollDetect(Ball *ball, Paddle paddle);
void checkBounces(Ball *ball);

#endif