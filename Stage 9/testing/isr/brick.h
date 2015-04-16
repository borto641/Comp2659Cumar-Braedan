#ifndef BALL_H
#define BALL_H
#include "types.h"
#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "render.h"
#include "input.h"
#include "splash.h"
#include "music.h"
#include "psg.h"
#include "vector.h"

#define SCREEN_LENGTH 32000
#define SCREEN_CLOCK 0x462

UINT32 checkScreenClock();
void swapScreenBuffers(UINT8** a, UINT8** b);
extern long vbFlag;
void vbl_isr();

#endif
