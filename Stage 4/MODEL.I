# 1 "model.c" 1
# 1 "./model.h" 1
# 1 "./raster.h" 1
# 1 "./TYPES.H" 1





typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef int bool;
# 4 "./raster.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/osbind.h" 2
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 5 "./raster.h" 2

void bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
void plot_hor_line(UINT8 *base, int x, int y, int width);
void plot_rectangle(UINT8 *base, int x, int y, int width, int height);
void plot_pixel(UINT8 *base, int x, int y);
void clrScrn(UINT16 *base);
void plotVertLine(UINT8 *base, int x, int y, int length);
void plotPoints(UINT8 *base ,int cx, int cy, int x, int y);
void plotCircle(UINT8 *base, int cx, int cy, int r);
void clearRectangle(UINT8 *base, int x, int y, int width, int height);
void clrHorLine(UINT8 *base, int x, int y, int width);
# 3 "./model.h" 2
# 1 "./types.h" 1
# 4 "./model.h" 2
# 11 "./model.h"
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
# 1 "model.c" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
# 3 "./events.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 4 "./events.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 20 "C:/c68/include/stdio.h"
typedef unsigned long  size_t;
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 5 "./events.h" 2
# 12 "./events.h"
void key_press(Paddle *paddle);
void level_lost();
void brickSmashed(Brick *brick);
void ballHitVert(Ball *ball);
void ballHitHor(Ball *ball);
void farRightPaddleHit(Ball *ball);
void midRightPaddleHit(Ball *ball);
void centrePaddleHit(Ball *ball);
void midLeftPaddleHit(Ball *ball);
void farLeftPaddleHit(Ball *ball);
# 2 "model.c" 2


void moveBall(Ball *ball, Brick *bricks, Paddle paddle)
{
	checkBounces(ball);
	checkBallCollision(ball, bricks, paddle);
	ball->x += (ball->dX * ball->speed);
	ball->y += (ball->dY * ball->speed);
}

void checkBounces(Ball *ball)
{
	if (ball->totalBounces > 100)
	{
		ball->speed = 5;
	}
	else if (ball->totalBounces > 75)
	{
		ball->speed = 4;
	}
	else if (ball->totalBounces > 50)
	{
		ball->speed = 3;
	}
	else if (ball->totalBounces > 15)
	{
		ball->speed = 2;
	}
	else
	{
		ball->speed = 1;
	}
}

void checkBallCollision(Ball *ball, Brick bricks[], Paddle paddle)
{
	if (ball->y < 125)
	{

			if (ball->dX > 0)
			{
				if (ball-> dY < 0)
				{
					uRCollDetect(ball, bricks);
				}
				else
				{
					dRCollDetect(ball, bricks);
				}
			}
			else if (ball->dX < 0)
			{
				if (ball->dY < 0)
				{
					uLCollDetect(ball,bricks);
				}
				else
				{
					dLCollDetect(ball,bricks);
				}
			}
			else
			{
				if (ball->dY > 0)
				{
					downCollDetect(ball, bricks);
				}
				else
				{
					upCollDetect(ball, bricks);
				}
			}

	}
	else if (ball->y > 360)
	{
		paddleCollDetect(ball, paddle);
	}
	else
	{
		if ((ball->x + ball->dX + 16  - 1 >= 639)
		|| (ball->x + ball->dX < 0))
		{
			ballHitHor(ball);
		}
	}
}

void upCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == 1 )
		{
			if ( ball->x + 15 >= bricks[i].x
				&& ball->x < bricks[i].x + 64)
				{
					if (ball->y + ball->dY < (bricks[i].y + 24)
						&& (ball->y + ball->dY) >= (bricks[i].y))
					{
						brickSmashed(&bricks[i]);
						ballHitVert(ball);
					}
				}
		}
	}
	if ((ball->y + ball->dY) < 12)
		ballHitVert(ball);
}


void downCollDetect(Ball *ball, Brick bricks[])
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == 1 )
		{
			if ( ball->x + 15 >= bricks[i].x && ball->x < bricks[i].x + 64)
			{
				if (ball->y + ball->dY >= (bricks[i].y) && (ball->y + ball->dY) <= (bricks[i].y + 24))
				{
					brickSmashed(&bricks[i]);
					ballHitVert(ball);
				}
			}
		}
	}
	if (ball->x + ball->dX <= 0 || ball->x + ball->dX >= 639)
			ballHitHor(ball);
}

void dRCollDetect(Ball *ball, Brick bricks[])
{
	int i;

	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == 1 )
		{
			if ((ball->x + ball->dX + 16  - 1) >= bricks[i].x
				&& (ball->x + ball->dX) <= (bricks[i].x + 64  - 1))
			{
				if ((ball->y + ball->dY + 16  - 1) >= (bricks[i].y)
					&& (ball->y + ball->dY) <= (bricks[i].y + 24 ))
				{
					if ((ball->x + ball->dX + 16  - 1) - bricks[i].x
						>
					   (ball->y + ball->dY + 16  - 1) - bricks[i].y)
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}
	if ((ball->x + ball->dX + 16  - 1 >= 639)
		|| (ball->x + ball->dX < 0))
	{
		ballHitHor(ball);
	}
}


void dLCollDetect(Ball *ball, Brick bricks[])
{
	int i;

	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == 1 )
		{
			if ((ball->x + ball->dX + 16  - 1) >= bricks[i].x
				&& (ball->x + ball->dX) <= (bricks[i].x + 64  - 1))
			{
				if ((ball->y + ball->dY + 16  - 1) >= (bricks[i].y)
					&& (ball->y + ball->dY) <= (bricks[i].y + 24 ) - 1)
				{
					if ((bricks[i].x + 64  - 1) - (ball->x + ball->dX)
						>
					   (ball->y + ball->dY + 16  - 1) - bricks[i].y)
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}
	if ((ball->x + ball->dX + 16  - 1) >= 639
		|| (ball->x + ball->dX) < 0)
	{
		ballHitHor(ball);
	}
}

void uLCollDetect(Ball *ball, Brick bricks[])
{
	int i;

	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == 1 )
		{
			if ((ball->x + ball->dX + 16  - 1) >= bricks[i].x
				&& (ball->x + ball->dX) <= (bricks[i].x + 64  - 1))
			{
				if ((ball->y + ball->dY) < (bricks[i].y + 24)
						&& (ball->y + ball->dY + 16  - 1) >= (bricks[i].y))
				{
					if ((bricks[i].x + 64   - 1) - (ball->x + ball->dX)
						>
					   ((bricks[i].y + 24  - 1) - ball->y + ball->dY))
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}
	if ((ball->x + ball->dX + 16  - 1) >= 639
		|| (ball->x + ball->dX) < 0)
	{
		ballHitHor(ball);
	}
	if ((ball->y + ball->dY) <= 12)
	{
		ballHitVert(ball);
	}
}

void uRCollDetect(Ball *ball, Brick bricks[])
{
	int i;

	for (i = 0; i < 25; i++)
	{
		if (bricks[i].alive == 1 )
		{
			if ((ball->x + ball->dX + 16  - 1) >= bricks[i].x
				&& (ball->x + ball->dX) <= (bricks[i].x + 64  - 1))
			{
				if ((ball->y + ball->dY) < (bricks[i].y + 24)
						&& (ball->y + ball->dY + 16  - 1) >= (bricks[i].y))
				{
					if ((ball->x + ball->dX + 16  - 1) - bricks[i].x
						>
					   ((bricks[i].y + 24  - 1) - ball->y + ball->dY))
					{
						ballHitVert(ball);
						brickSmashed(&bricks[i]);
					}
					else
					{
						ballHitHor(ball);
						brickSmashed(&bricks[i]);
					}
				}
			}
		}
	}
	if ((ball->x + ball->dX + 16  - 1) >= 639
		|| (ball->x + ball->dX) < 0)
	{
		ballHitHor(ball);
	}
	if ((ball->y + ball->dY) <= 12)
	{
		ballHitVert(ball);
	}
}


void paddleCollDetect(Ball *ball, Paddle paddle)
{

	int paddleHitPosition;
	if ((ball->x + ball->dX + 16  - 1) >= paddle.x
				&& (ball->x + ball->dX) <= (paddle.x + 71))
				{
					if ((ball->y + ball->dY + 16  - 1) >= paddle.y)
						{
							paddleHitPosition = paddle.x - (ball->x + ball->dX);
							if (paddleHitPosition > 0)
							{

								farLeftPaddleHit(ball);
							}
							else if (paddleHitPosition > -14)
							{

								midLeftPaddleHit(ball);
							}
							else if (paddleHitPosition > -29)
							{

								centrePaddleHit(ball);
							}
							else if (paddleHitPosition > 43)
							{

								midRightPaddleHit(ball);
							}
							else
							{

								farRightPaddleHit(ball);
							}
						}
				}
}





void addScore(ScoreNum score, int amount)
{
	score.score += amount;
}




void remScore(ScoreNum score, int amount)
{
	score.score -= amount;
}
# 355 "model.c"
int getScore (ScoreNum score)
{
	return score.score;
}




void scoreLPosition (ScoreLabel label, int x, int y)
{
	label.x = x;
	label.y = y;
}



void paddleLeft(Paddle *paddle){
	  if ((paddle->x - 5) >= 0 ){
            paddle->x -= 20;
    }
}



void paddleRight(Paddle *paddle){
	 if ((paddle->x + 72) <= 640 ){
		paddle->x += 20;
    }
}



void launch_ball(Paddle *paddle){


}



int getLife(LifeCounter *lifeCounter){
	return lifeCounter->numLives;
}



void removeLife(LifeCounter *lifeCounter){
	lifeCounter->numLives -= 1;
}
