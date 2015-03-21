#ifndef EVENTS_H
#define EVENTS_H
#include "model.h"
#include <osbind.h>
#include <stdio.h>

#define left_arrow  0x004B0000L
#define right_arrow 0x004D0000L
#define spacebar    0x00390020L 
#define ESC         0x0001001BL 

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

#endif

