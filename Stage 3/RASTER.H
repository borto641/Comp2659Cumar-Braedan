#ifndef RASTER_H
#define RASTER_H

#include "TYPES.H"
#include <osbind.h>
void plot_bitmap_16(UINT16 *base, int x, int y, const int *bitmap, unsigned int height);
void plot_hor_line(UINT8 *base, int x, int y, int width);
void plot_rectangle(UINT8 *base, int x, int y, int width, int height);						/*Replaced horiz*/
void plot_pixel(UINT8 *base, int x, int y);
void clrScrn(UINT16 *base);
void plotVertLine(); 																		/*Renamed from vert*/
void plotPoints(UINT8 *base ,int cx, int cy, int x, int y);	
void plotCircle(UINT8 *base, int cx, int cy, int r);
#endif
