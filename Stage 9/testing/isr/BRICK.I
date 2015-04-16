# 1 "brick.c" 1
# 1 "./brick.h" 1
# 1 "./types.h" 1





typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef int bool;
# 3 "./brick.h" 2
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
# 4 "./brick.h" 2
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
# 5 "./brick.h" 2
# 1 "./model.h" 1
# 1 "./raster.h" 1
# 1 "./TYPES.H" 1
# 4 "./raster.h" 2
# 1 "C:/c68/include/osbind.h" 1
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
UINT8* getScreenBase();
void setScrn(UINT8* newBase);
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
# 6 "./brick.h" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
# 3 "./events.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 4 "./events.h" 2
# 1 "C:/c68/include/stdio.h" 1
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
# 7 "./brick.h" 2
# 1 "./render.h" 1
# 1 "./model.h" 1
# 10 "./render.h" 2
# 1 "./font.h" 1
# 1 "./types.h" 1
# 4 "./font.h" 2


extern const UINT8 font[];
# 11 "./render.h" 2
# 1 "./balBit.h" 1
# 1 "./types.h" 1
# 4 "./balBit.h" 2


extern const UINT16 ballBitmap[16];
# 12 "./render.h" 2


void printScreen(Screen screen, UINT32 *base);
void refreshScreen(Screen *screen, UINT32 *base);
void drawChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void saveChunk(UINT32 *base, int x, int y, UINT32 *saved, int height);
void clrBrick(Brick *brick, UINT8 *base);
void printLifeLabel(LifeLabel lifeCounterLabel, UINT8 *base);
void printScoreLabel(ScoreLabel scoreLabel, UINT8 *base);
void drawLives(LifeCount lives, UINT8 *base);
void drawScore(ScoreNum scoreNum, UINT8 *base);
void drawPaddle(UINT32 *base, Paddle *paddle);
void clearPaddle(UINT32 *base, Paddle paddle);
void drawBall(Ball *ball, UINT16 *base);
void printChars(UINT8 *base, int x, int y, int length, char string[]);
void printCharsV2(UINT8 *base, int x, int y, int length, char string[]);
# 8 "./brick.h" 2
# 1 "./input.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 3 "./input.h" 2
# 1 "./types.h" 1
# 4 "./input.h" 2


bool checkInputBuffer();
long getInput();
# 9 "./brick.h" 2
# 1 "./splash.h" 1
# 1 "./types.h" 1
# 4 "./splash.h" 2
# 1 "./render.h" 1
# 5 "./splash.h" 2
# 1 "./raster.h" 1
# 6 "./splash.h" 2
# 1 "./input.h" 1
# 7 "./splash.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 8 "./splash.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 9 "./splash.h" 2
# 15 "./splash.h"
void down_key_press(UINT8 *base8, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]);
void up_key_press(UINT8 *base, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]);
void initializeSplashScreen(UINT8 *base8, char playerOneLabel[], char playerTwoLabel[], char quitLabel[]);
int splashScreenLoop();
# 10 "./brick.h" 2
# 1 "./music.h" 1
# 1 "./types.h" 1
# 3 "./music.h" 2


void start_music();
int update_music(int musicCounter);
# 11 "./brick.h" 2
# 1 "./psg.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 3 "./psg.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 4 "./psg.h" 2
# 1 "./types.h" 1
# 5 "./psg.h" 2


void write_psg(int reg, UINT8 val);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
void ball_hits_paddle_sound();
void ball_hits_wall_sound();
void music (int channel, int tuning, int duration);
# 12 "./brick.h" 2
# 1 "./vector.h" 1




typedef void (*Vector)();
Vector installVector(int num, Vector vector);
# 13 "./brick.h" 2





UINT32 checkScreenClock();
void swapScreenBuffers(UINT8** a, UINT8** b);
extern long vbFlag;
void vbl_isr();
# 1 "brick.c" 2


const UINT8 secondBuffer[32256];

long vbFlag = 0 ;

int main()
{
	Vector orig_vector = installVector(28 , vbl_isr);

	UINT8 *defaultScreen = getScreenBase();
	UINT8 *frontScreen = defaultScreen;
	UINT8 *backScreen = secondBuffer;
	long tempUINT8 = (long)(backScreen);
	Screen screen;
	bool quit = 0 ;
	long input;
    int result;
	UINT32 timeThen, timeNow, timeElapsed;

	while (!quit)
	{

		if (vbFlag == 1  && !screen.holdBall || screen.holdBall)
		{
			printf("TRUE\n");
			vbFlag = 0 ;
			printf("%i", vbFlag);
		}
	}
	(void)_trap_14_wllw((short)0x5,(long)(-1),(long)defaultScreen,(short)(-1)) ;
	installVector(28 , orig_vector);
	return 0;
}

UINT32 checkScreenClock()
{
		UINT32 time;
		long old_ssp;
		long *clock = 0x462 ;
		old_ssp = _trap_1_wl((short)0x20,(long)(0)) ;
		time = *clock;
		_trap_1_wl((short)0x20,(long)(old_ssp)) ;
		return time;
}
