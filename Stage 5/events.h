#ifndef EVENTS_H
#define EVENTS_H
#include "model.h"
#include <osbind.h>
#include <stdio.h>

#define LEFT_ARROW 0x004B0000L
#define RIGHT_ARROW 0x004D0000L
#define SPACEBAR    0x00390020L 
#define ESC         0x0001001BL 

void keyPress(Screen *screen, long choice);
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

#endif

