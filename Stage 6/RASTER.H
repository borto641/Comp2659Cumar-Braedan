#ifndef RASTER_H
#define RASTER_H

#include "TYPES.H"
#include <osbind.h>
void bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
void plot_hor_line(UINT32 *base, int x, int y, int width, int lshift, int rshift);
void plot_rectangle(UINT32 *base, int x, int y, int width, int height);						/*Replaced horiz*/
void plot_pixel(UINT8 *base, int x, int y);
void clrScrn(UINT16 *base);
void plotVertLine(UINT8 *base, int x, int y, int length); 									/*Renamed from vert*/
void plotPoints(UINT8 *base ,int cx, int cy, int x, int y);	
void plotCircle(UINT8 *base, int cx, int cy, int r);
void clearRectangle(UINT32 *base, int x, int y, int width, int height);
void clrHorLine(UINT32 *base, int x, int y, int width);
#endif
