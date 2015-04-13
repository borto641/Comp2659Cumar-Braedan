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
void plot_hor_line(UINT32 *base, int x, int y, int width, int lshift, int rshift);
void plot_rectangle(UINT32 *base, int x, int y, int width, int height);
void plot_pixel(UINT8 *base, int x, int y);
void clrScrn(UINT16 *base);
void plotVertLine(UINT8 *base, int x, int y, int length);
void plotHorizLine(UINT8 *base, int x, int y, int length);
void plotPoints(UINT8 *base ,int cx, int cy, int x, int y);
void plotCircle(UINT8 *base, int cx, int cy, int r);
void clearRectangle(UINT32 *base, int x, int y, int width, int height);
void clearRectangle8(UINT8 *base, int x, int y, int width, int height);
void clearRectangle16(UINT16 *base, int x, int y, int width, int height);
void clearRectangle32(UINT32 *base, int x, int y, int width, int height);
void clrHorLine8(UINT8 *base, int x, int y, int width);
void clrHorLine16(UINT16 *base, int x, int y, int width);
void clrHorLine32(UINT32 *base, int x, int y, int width);
void plotHorizLine(UINT8 *base, int startX, int startY, int width);
void plot_rectangleLines(UINT8 *base, int startX, int startY, int width, int height);
void bitmap8V2(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
# 3 "./model.h" 2
# 1 "./types.h" 1
# 4 "./model.h" 2
# 15 "./model.h"
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
    Brick bricks[25 ];
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
void destroyBrick(int brick);
int  getScore (ScoreNum score);
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
void keyPress(Screen *screen, long choice);
void level_lost();
void brickSmashed(Screen *screen, int i);
void ballHitVert(Ball *ball);
void ballHitHor(Ball *ball);
void farRightPaddleHit(Ball *ball);
void midRightPaddleHit(Ball *ball);
void centrePaddleHit(Ball *ball);
void midLeftPaddleHit(Ball *ball);
void farLeftPaddleHit(Ball *ball);
void ballHitBottom(Screen *screen);
void levelCleared(Screen *screen, UINT8* front, UINT8* back);
# 2 "model.c" 2
# 16 "model.c"
void moveBall(Screen *screen)
{
	int dX = screen->ball.dX * screen->ball.speed;
	int dY = screen->ball.dY * screen->ball.speed;

	checkBounces(&screen->ball);
	checkBallCollision(screen, dX, dY);

	if (!screen->gameOver && !screen->holdBall)
	{
		screen->ball.x += dX;
		screen->ball.y += dY;
	}
}
# 41 "model.c"
void checkBounces(Ball *ball)
{
	if (ball->totalBounces > 50)
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
# 68 "model.c"
void checkBallCollision(Screen *screen, int dX, int dY)
{
	if (screen->ball.y < 130)
	{
		if (dX > 0)
		{
			if (dY < 0)
			{
				uRCollDetect(screen, dX, dY);
			}
			else
			{
				dRCollDetect(screen, dX, dY);
			}
		}
		else if (dX < 0)
		{
			if (dY < 0)
			{
				uLCollDetect(screen, dX, dY);
			}
			else
			{
				dLCollDetect(screen, dX, dY);
			}
		}
		else
		{
			if (dY > 0)
			{
				downCollDetect(screen, dX, dY);
			}
			else
			{
				upCollDetect(screen, dX, dY);
			}
		}
	}
	else if ((screen->ball.y + (dY) + 16  + 1) > 369)
	{
		paddleCollDetect(screen, dX, dY);
	}
	else
	{
		if ((screen->ball.x + (dX) + 16  - 1 >= 639)
		|| (screen->ball.x + (dX) < 0))
		{
			ballHitHor(&screen->ball);
		}
	}
}
# 130 "model.c"
void upCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	for (i = 0; i < 25 ; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ( screen->ball.x + 15 >= screen->bricks[i].x
				&& screen->ball.x < screen->bricks[i].x + 64)
			{
				if (screen->ball.y + dY < (screen->bricks[i].y + 24)
					&& (screen->ball.y + dY) >= (screen->bricks[i].y))
				{
					brickSmashed(screen, i);
                    ballHitVert(&screen->ball);

				}
			}
		}
	}
	if ((screen->ball.y + (dY)) < 12)
		ballHitVert(&screen->ball);
}
# 165 "model.c"
void downCollDetect(Screen *screen, int dX, int dY)
{
	int i;
	for (i = 0; i < 25 ; i++)
	{
		if (screen->bricks[i].alive)
		{
			if (screen->ball.x + 15 >= screen->bricks[i].x
				&& screen->ball.x < screen->bricks[i].x + 64)
			{
				if (screen->ball.y + dY + 16  - 1 >= (screen->bricks[i].y)
					&& (screen->ball.y + dY) <= (screen->bricks[i].y + 24))
				{
					brickSmashed(screen, i);
					ballHitVert(&screen->ball);
				}
			}
		}
	}
}
# 197 "model.c"
void dRCollDetect(Screen *screen, int dX, int dY)
{
	int i;

	for (i = 0; i < 25 ; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + 16  - 1) >= screen->bricks[i].x
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + 64  - 1))
			{
				if ((screen->ball.y + dY + 16  - 1) >= (screen->bricks[i].y)
					&& (screen->ball.y + dY) <= (screen->bricks[i].y + 24 ))
				{
					if ((screen->ball.x + dX + 16  - 1) - screen->bricks[i].x
						>
					   (screen->ball.y + dY + 16  - 1) - screen->bricks[i].y)
					{
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else
					{
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}
	if ((screen->ball.x +  (dX) + 16  - 1 >= 639)
		|| (screen->ball.x + (dX) < 0))
	{
		ballHitHor(&screen->ball);
	}
}
# 245 "model.c"
void dLCollDetect(Screen *screen, int dX, int dY)
{
	int i;

	for (i = 0; i < 25 ; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + 16  - 1) >= screen->bricks[i].x
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + 64  - 1))
			{
				if ((screen->ball.y + dY + 16  - 1) >= (screen->bricks[i].y)
					&& (screen->ball.y + dY) <= (screen->bricks[i].y + 24 ) - 1)
				{
					if ((screen->bricks[i].x + 64  - 1) - (screen->ball.x + dX)
						>
					   (screen->ball.y + dY + 16  - 1) - screen->bricks[i].y)
					{
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else
					{
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}
	if ((screen->ball.x +  (dX) + 16  - 1) >= 639
		|| (screen->ball.x +  (dX)) < 0)
	{
		ballHitHor(&screen->ball);
	}
}
# 293 "model.c"
void uLCollDetect(Screen *screen, int dX, int dY)
{
	int i;

	for (i = 0; i < 25 ; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + 16  - 1) >= screen->bricks[i].x
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + 64  - 1))
			{
				if ((screen->ball.y + dY) < (screen->bricks[i].y + 24)
						&& (screen->ball.y + dY + 16  - 1) >= (screen->bricks[i].y))
				{
					if ((screen->bricks[i].x + 64   - 1) - (screen->ball.x + dX)
						>
					   ((screen->bricks[i].y + 24  - 1) - screen->ball.y + dY))
					{
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else
					{
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}
	if ((screen->ball.x +  (dX) + 16  - 1) >= 639
		|| (screen->ball.x + dX) < 0)
	{
		ballHitHor(&screen->ball);
	}
	if ((screen->ball.y + dY) <= 12)
	{
		ballHitVert(&screen->ball);
	}
}
# 345 "model.c"
void uRCollDetect(Screen *screen, int dX, int dY)
{
	int i;

	for (i = 0; i < 25 ; i++)
	{
		if (screen->bricks[i].alive)
		{
			if ((screen->ball.x + dX + 16  - 1) >= screen->bricks[i].x
				&& (screen->ball.x + dX) <= (screen->bricks[i].x + 64  - 1))
			{
				if ((screen->ball.y + dY) < (screen->bricks[i].y + 24)
						&& (screen->ball.y + dY + 16  - 1) >= (screen->bricks[i].y))
				{
					if ((screen->ball.x + dX + 16  - 1) - screen->bricks[i].x
						>
					   ((screen->bricks[i].y + 24  - 1) - screen->ball.y + dY))
					{
						ballHitVert(&screen->ball);
						brickSmashed(screen, i);
					}
					else
					{
						ballHitHor(&screen->ball);
						brickSmashed(screen, i);
					}
				}
			}
		}
	}
	if ((screen->ball.x + (dX) + 16  - 1) >= 639
		|| (screen->ball.x + (dX)) < 0)
	{
		ballHitHor(&screen->ball);
	}
	if ((screen->ball.y + dY) <= 12)
	{
		ballHitVert(&screen->ball);
	}
}
# 396 "model.c"
void paddleCollDetect(Screen *screen, int dX, int dY)
{
	if ((screen->ball.x + dX + 16  - 1) >= screen->paddle.x
		&& (screen->ball.x + dX) <= (screen->paddle.x + 128  - 1))
	{
		if ((screen->ball.y + dY + 16  - 1) >= (screen->paddle.y)
			&& (screen->ball.y + dY) <= screen->paddle.y + 128  - 1)
		{
			if (dX <= 0)
			{
				if ((screen->paddle.x + 128  - 1) - (screen->ball.x + dX)
					 >
					(screen->ball.y + dY + 16  - 1) - screen->paddle.y)
				 {
					ballHitPaddle(screen, dX, dY);
				}
				else
				{
					ballHitHor(&screen->ball);
					screen->paddle.lock = 1 ;
				}
			}
			else
			{
				if ((screen->ball.x + dX + 16  - 1) - screen->paddle.x
					 >
			  	    (screen->ball.y + dY + 16  - 1) - screen->paddle.y)
				{
					ballHitPaddle(screen, dX, dY);
				}
				else
				{
					ballHitHor(&screen->ball);
					screen->paddle.lock = 1 ;
				}
			}
		}
	}
	if ((screen->ball.y + (dY) + 16  - 1) >= 399)
	{
		ballHitBottom(screen);
	}
	if ((screen->ball.x + (dX) + 16  - 1) >= 639
		|| (screen->ball.x + (dX)) < 0)
	{
		ballHitHor(&screen->ball);
	}
}
void ballHitPaddle(Screen *screen, int dX, int dY)
{
	int paddleHitPosition;

	paddleHitPosition = screen->paddle.x - (screen->ball.x + dX + 16 );
	if (paddleHitPosition > -26)
	{
		farLeftPaddleHit(&screen->ball);
	}
	else if (paddleHitPosition > -51)
	{
		midLeftPaddleHit(&screen->ball);
	}
	else if (paddleHitPosition > -77)
	{
		centrePaddleHit(&screen->ball);
	}
	else if (paddleHitPosition > -103)
	{
		midRightPaddleHit(&screen->ball);
	}
	else
	{
		farRightPaddleHit(&screen->ball);
	}
}
# 480 "model.c"
void scoreToChars (ScoreNum score, char scoreChars[3])
{
	scoreChars[0] = ((score.score % 1000) / 100) + 48 ;
	scoreChars[1] = ((score.score % 100)  / 10)  + 48 ;
	scoreChars[2] = (score.score % 10)           + 48 ;
}




void scoreLPosition (ScoreLabel label, int x, int y)
{
	label.x = x;
	label.y = y;
}



void paddleLeft(Paddle *paddle){
	if ((paddle->x) >= 20 ){
            paddle->x -= 20;
    }
	else{
		paddle->x = 0;
	}
}



void paddleRight(Paddle *paddle){
	if ((paddle->x + 128 ) <= 620 ){
		paddle->x += 20;
    }
	else{
		paddle->x = 512;
	}
}




void launchBall(Screen *screen)
{
	 screen->holdBall = 0 ;
}

void initialize(Screen *screen)
{
	int i;
	screen->ball.x = 314;
	screen->ball.y = 354;
	screen->ball.oldX = 314;
	screen->ball.oldY = 354;
	screen->ball.olderY = 354;
	screen->ball.olderX = 314;
	screen->ball.dX = 0;
	screen->ball.dY = -3;
	screen->ball.speed = 1;
	screen->ball.totalBounces = 0;
	screen->ball.ballOut = 0 ;

	screen->scoreNum.score = 0;
	screen->scoreNum.x = 608;
	screen->scoreNum.y = 2;

	screen->scoreLabel.x = 559;
	screen->scoreLabel.y = 2;
	screen->scoreLabel.label[0] = 'S';
	screen->scoreLabel.label[1] = 'c';
	screen->scoreLabel.label[2] = 'o';
	screen->scoreLabel.label[3] = 'r';
	screen->scoreLabel.label[4] = 'e';
	screen->scoreLabel.label[5] = ':';

	screen->lifeLabel.x = 16;
	screen->lifeLabel.y = 2;
	screen->lifeLabel.label[0] = 'L';
	screen->lifeLabel.label[1] = 'i';
	screen->lifeLabel.label[2] = 'v';
	screen->lifeLabel.label[3] = 'e';
	screen->lifeLabel.label[4] = 's';
	screen->lifeLabel.label[5] = ':';

	screen->paddle.x = 256;
	screen->paddle.y = 370;
	screen->paddle.oldX = 256;
	screen->paddle.oldY = 370;
	screen->paddle.olderX = 256;
	screen->paddle.olderY = 370;
	screen->paddle.lock = 0 ;

	screen->lifeCount.lives = 3;
	screen->lifeCount.x = 64;
	screen->lifeCount.y = 2;

	screen->holdBall = 1 ;
	screen->gameOver = 0 ;
	for (i = 0; i < 25 ; i++)
	{
		screen->bricks[i].alive = 1 ;
		screen->bricks[i].y = (i / 5) * 24 + 13;

		if ((i / 5) % 2 == 0)
			screen->bricks[i].x = (i % 5) * 128;
		else
			screen->bricks[i].x = (i % 5) * 128 + 64;
	}
	screen->bricksLeft = 25 ;
	for (i = 0; i < 32; i++)
	{
		screen->ballChunk[i] = 0;
	}
	for (i = 0; i < 32; i++)
	{
		screen->oldBallChunk[i] = 0;
	}
}

void resetBall(Screen *screen)
{
	screen->ball.x = 314;
	screen->ball.y = 354;
	screen->ball.dX = 0;
	screen->ball.dY = -3;
	screen->ball.speed = 1;
	screen->ball.totalBounces = 0;

	screen->paddle.x = 256;
	screen->paddle.lock = 0 ;

	screen->holdBall = 1 ;
}

void resetLevel(Screen *screen)
{
	int i;
	screen->bricksLeft = 25 ;
	screen->ball.x = 314;
	screen->ball.y = 354;
	screen->ball.oldX = 314;
	screen->ball.oldY = 354;
	screen->ball.olderY = 354;
	screen->ball.olderX = 314;
	screen->ball.dX = 0;
	screen->ball.dY = -3;
	screen->ball.ballOut = 0 ;

	screen->paddle.x = 256;
	screen->paddle.y = 370;
	screen->paddle.oldX = 256;
	screen->paddle.oldY = 370;
	screen->paddle.olderX = 256;
	screen->paddle.olderY = 370;
	screen->paddle.lock = 0 ;

	screen->holdBall = 1 ;
	screen->gameOver = 0 ;
	screen->lifeCount.lives++;
	for (i = 0; i < 25 ; i++)
	{
		screen->bricks[i].alive = 1 ;
		screen->bricks[i].firstUndraw = 0 ;
		screen->bricks[i].secondUndraw = 0 ;
		screen->bricks[i].y = (i / 5) * 24 + 13;

		if ((i / 5) % 2 == 0)
			screen->bricks[i].x = (i % 5) * 128;
		else
			screen->bricks[i].x = (i % 5) * 128 + 64;
	}
	for (i = 0; i < 32; i++)
	{
		screen->ballChunk[i] = 0;
	}
	for (i = 0; i < 32; i++)
	{
		screen->oldBallChunk[i] = 0;
	}
}
