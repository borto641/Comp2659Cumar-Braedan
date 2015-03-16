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
void ball_hits_brick(Screen screen, int brick);

#endif

