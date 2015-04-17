#ifndef SPLASH_H
#define SPLASH_H

#include "types.h"
#include "render.h"
#include "raster.h"
#include "input.h"
#include <osbind.h>
#include <stdio.h>

#define UP_ARROW   0x00480000L
#define DOWN_ARROW 0x00500000L
#define ENTER      0x0072000DL

void down_key_press(UINT8 *base8, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]);
void up_key_press(UINT8 *base, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]);
void initializeSplashScreen(UINT8 *base8, char playerOneLabel[], char playerTwoLabel[], char quitLabel[]);
int splashScreenLoop();

#endif
