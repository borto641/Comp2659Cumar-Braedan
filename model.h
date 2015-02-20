#ifnotdef
#define model_h

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
	char[] = "Score"; 
} ScoreLabel;

void moveBall(Ball ball);
void ballHitV(Ball ball);
void ballHitH(Ball ball);
void ballHitB(Ball ball);
void addScore(ScoreNum score, int amount);
void remScore(ScoreNum score, int amount);
int getScore (ScoreNum score);
void scoreLPosition (ScoreLabel label, int x, int y);

#endif