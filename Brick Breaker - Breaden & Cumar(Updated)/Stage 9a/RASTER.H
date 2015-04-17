#ifndef RASTER_H
#define RASTER_H

#include "TYPES.H"
#include <osbind.h>
void bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
void bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
void plotHorLine(UINT32 *base, int x, int y, int width, int lshift, int rshift);
void plotRectangle(UINT32 *base, int x, int y, int width, int height);						/*Replaced horiz*/
void plot_pixel(UINT8 *base, int x, int y);
void clrScrn(UINT16 *base);
void plotVertLine(UINT8 *base, int x, int y, int length); 									/*Renamed from vert*/
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
void plotRectangleLines(UINT8 *base, int startX, int startY, int width, int height);
void bitmap8V2(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
UINT8* getScreenBase();
void setScrn(UINT8* newBase);
#endif
