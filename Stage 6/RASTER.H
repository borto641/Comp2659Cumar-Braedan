#ifndef RASTER_H
#define RASTER_H

#include "TYPES.H"
#include <osbind.h>
void bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
void plotHorLine(UINT32 *base, int x, int y, int width, int lshift, int rshift);
void plotRectangle(UINT32 *base, int x, int y, int width, int height);						
void clrScrn(UINT16 *base);
void clearRectangle(UINT32 *base, int x, int y, int width, int height);
void clearRectangle8(UINT8 *base, int x, int y, int width, int height);
void clearRectangle16(UINT16 *base, int x, int y, int width, int height);
void clearRectangle32(UINT32 *base, int x, int y, int width, int height);
void clrHorLine8(UINT8 *base, int x, int y, int width);
void clrHorLine16(UINT16 *base, int x, int y, int width);
void clrHorLine32(UINT32 *base, int x, int y, int width);
#endif
