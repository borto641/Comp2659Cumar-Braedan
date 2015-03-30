# 1 "tst_rndr.c" 1
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
# 1 "tst_rndr.c" 2
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
# 2 "tst_rndr.c" 2
# 1 "./model.h" 1
# 1 "./raster.h" 1
# 1 "./TYPES.H" 1





typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef int bool;
# 4 "./raster.h" 2
# 1 "C:/c68/include/osbind.h" 1
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
	bool resetBall;
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
	char[] label;
} ScoreLabel;

typedef struct {
	int x;
	int y;

}Paddle;

typedef struct{
	int x;
	int y;
	char[] label;
}LifeCounterLabel;

typedef struct{
	int x;
	int y;
	int amount;
}LifeCount

typedef struct{
	Ball ball;
	ScoreNum scoreNum;
    ScoreLabel scoreLabel;
    Paddle paddle;
    Brick bricks[25];
    LifeCounterLabel lifeCounter;
	LifeCount lifeCount;
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
void initialize(Screen *screen);
void resetBall(Screen *screen);
# 3 "tst_rndr.c" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
# 3 "./events.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 4 "./events.h" 2
# 1 "C:/c68/include/stdio.h" 1
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
void ballHitBottom(Screen *screen);
# 4 "tst_rndr.c" 2
# 1 "./raster.h" 1
# 5 "tst_rndr.c" 2
# 1 "./render.h" 1
# 1 "./model.h" 1
# 11 "./render.h" 2
# 1 "./font.h" 1
# 1 "./types.h" 1
# 4 "./font.h" 2


extern const UINT8 font[];
# 12 "./render.h" 2
# 1 "./balBit.h" 1
# 1 "./types.h" 1
# 4 "./balBit.h" 2


extern const UINT16 ballBitmap[16];
# 13 "./render.h" 2


void printScreen(Screen screen);
void clrBall(Ball ball, UINT16 *base);
void drwBall(Ball ball, UINT16 *base);
void clrPaddle(UINT8 *base, Paddle paddle);
void drwPaddle(UINT8 *base, Paddle paddle);
void drawChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void saveChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void clrBrick(Brick *brick, UINT8 *base);
# 6 "tst_rndr.c" 2


int main(){

    Screen screen;
	int i;
	long key_pressed;
	long *timer = 0x462;
	long c_time;
	long old_ssp;
	UINT8 *base8 = (void*)_trap_14_w((short)0x2) ;
	UINT16 *base16 = (void*)_trap_14_w((short)0x2) ;
	UINT32 *base32 = (void*)_trap_14_w((short)0x2) ;
	UINT32 savedBallChunk[32];
	UINT32 savedPaddleChunk[32];

	screen.ball.x = 314;
	screen.ball.y =  355;
	screen.ball.dX = 1;
	screen.ball.dY = -8;

	screen.scoreNum.score = 666;
	screen.scoreNum.x = 610;
	screen.scoreNum.y = 4;
	screen.scoreLabel.x = 550;
	screen.scoreLabel.y = 4;
	screen.paddle.x = 284;
	screen.paddle.y = 370;
	screen.lifeCounter.x = 4;
	screen.lifeCounter.y = 4;
	screen.lifeCount = 3;


	for (i = 0; i <= 19; i++)
	{
		screen.bricks[i].alive = 1 ;
		screen.bricks[i].undraw = 0 ;
	}
	for (i = 20; i < 25; i++)
	{
		screen.bricks[i].alive = 1 ;
		screen.bricks[i].undraw = 0 ;
	}

	for (i = 0; i < 25; i++)
	{
		screen.bricks[i].y = (i / 5) * 24 + 13;

		if ((i / 5) % 2 == 0)
			screen.bricks[i].x = (i % 5) * 128;
		else
			screen.bricks[i].x = (i % 5) * 128 + 64;
	}

	printf("\033E\033f\n");
	printScreen(screen);
	saveChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, 16 );
	saveChunk(base32, screen.paddle.x, screen.paddle.y, savedPaddleChunk, 16 );
	drwBall(screen.ball, base16);
	drwPaddle(base8, screen.paddle);
	key_pressed = _trap_1_w((short)0x08) ;
	old_ssp = _trap_1_wl((short)0x20,(long)(0)) ;
	c_time = *timer;

	  while (1 )
	  {
		for (i = 0; i < 25; i++)
		{
			if (screen.bricks[i].undraw)
			{
				(void)_trap_14_w((short)0x25) ;
				clrBrick(&screen.bricks[i], base8);
				screen.bricks[i].undraw = 0 ;
			}
		}
		drawChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, 16 );
		moveBall(&screen);
		saveChunk(base32, screen.ball.x, screen.ball.y, savedBallChunk, 16 );
		drwBall(screen.ball, base16);
		if ((short)_trap_1_w((short)0x0B) )
		{
			clrPaddle(base8, screen.paddle);
			key_press(&screen.paddle);
			drwPaddle(base8, screen.paddle);
		}
		(void)_trap_14_w((short)0x25) ;
	  }

  _trap_1_wl((short)0x20,(long)(old_ssp)) ;


return 0;
}
