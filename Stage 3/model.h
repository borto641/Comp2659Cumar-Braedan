#ifndef MODEL_H
#define MODEL_H
#define true 1
#define false 0

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
	int height;
	int width;
}Paddle;

typedef struct{
	bool bricks[5][5]; /*figure out how many bricks needed */
}Brick;

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
    Brick brick;
    LifeCounter lifeCounter;
}Screen;

void moveBall(Ball ball);
void ballHitV(Ball ball);
void ballHitH(Ball ball);
void ballHitB(Ball ball);
void addScore(ScoreNum score, int amount);
void remScore(ScoreNum score, int amount);
void scoreLPosition (ScoreLabel label, int x, int y);
void move_paddle_left(Paddle *paddle);
void move_paddle_right(Paddle *paddle);
void paddle_launch_ball(Paddle *paddle);
void destory_brick(Brick *brick, int x, int y);
void remove_life(LifeCounter *lifeCounter);
bool is_broken(Brick *brick, int x, int y);
int  get_life(LifeCounter *lifeCounter);
int getScore (ScoreNum score);

#endif