#include "RASTER.H"

/*
Plots a horizontal line to the screen buffer
*/
void plot_hor_line(UINT32 *base, int x, int y, int width, int lshift, int rshift)
{
	UINT32 *draw = base + (y * 20) + (x >> 5);
	int i = 0;
	
	if (x < 640 && y < 400) /* in bounds */
	{		
		if (lshift > 0) /*if left shift needed*/
		{
			*draw |= (0xFFFFFFFF >> lshift);
			draw++;
		}
		for (i = 0; i < ((width - lshift) >> 5) && (draw < (base + ((y + 1) * 20))); i++) /* for each four bytes draw FF */
		{
			*draw |= (0xFFFFFFFF);
			draw++;
		}		
		if ((draw < base + ((y + 1) * 20)) && rshift > 0) /*if right shift needed*/
			*draw |= (0xFFFFFFFF << rshift);
	}
	return;
}
				
/*Plots a rectangle by calling plot_hor_line "height" times*/
void plot_rectangle(UINT32 *base, int x, int y, int width, int height)
{
	UINT32 *draw = base;
	int i = 0;
	int lshift = (x % 32);              				    /*amount of shift required on left side of line*/
	int rshift = (32 - ((width - (32 - lshift)) % 32)); 	/*amount of shift required on right side of line*/

	for (i = 0; i < height; i++)
	{
		plot_hor_line(draw, x, y, width, lshift, rshift);
		draw += 20;
	}

	return;	
}
void clearRectangle(UINT32 *base, int x, int y, int width, int height)
{
	if (width <= 8)
	{
		clearRectangle8((UINT8*)(base), x, y, width, height);
	}
	else if ( width <= 32)
	{
		clearRectangle16((UINT16*)(base), x, y, width, height);
	}
	else
	{
		clearRectangle32((UINT32*)(base), x, y, width, height);
	}
	return;	
}

void clearRectangle32(UINT32 *base, int x, int y, int width, int height)
{
	UINT32 *draw = base;
	int i = 0;
	
	for (i = 0; i < height; i++)
	{
		clrHorLine32(draw, x, y, width);
		draw += 20;
	}

	return;	
}

void clearRectangle16(UINT16 *base, int x, int y, int width, int height)
{
	UINT16 *draw = base;
	int i = 0;
	
	for (i = 0; i < height; i++)
	{
		clrHorLine16(draw, x, y, width);
		draw += 40;
	}

	return;	
}

void clearRectangle8(UINT8 *base, int x, int y, int width, int height)
{
	UINT8 *draw = base;
	int i = 0;
	
	for (i = 0; i < height; i++)
	{
		clrHorLine8(draw, x, y, width);
		draw += 80;
	}

	return;	
}

/*May need to address clearing only part of a byte if required
  by more than clear paddle*/
void clrHorLine32(UINT32 *base, int x, int y, int width)
{
	UINT32 *draw = base + (y * 20) + (x >> 5);
	int i = 0;
	for (i = 0; i < (width >> 5) + 1 && (draw < (base + ((y + 1) * 20))); i++) /* for each full byte draw 00 */
		{
			*draw = (0x00000000);
			draw++;
		}		
	return;
}

void clrHorLine16(UINT16 *base, int x, int y, int width)
{
	UINT16 *draw = base + (y * 40) + (x >> 4);
	int i = 0;
	for (i = 0; i < (width >> 4) + 1 && (draw < (base + ((y + 1) * 40))); i++) /* for each full byte draw 00 */
	{
		*draw = (0x0000);
		draw++;
	}		
	return;
}

void clrHorLine8(UINT8 *base, int x, int y, int width)
{
	UINT8 *draw = base + (y * 80) + (x >> 3);
	int i = 0;
	for (i = 0; i < (width >> 3) + 1 && (draw < (base + ((y + 1) * 80))); i++) /* for each full byte draw 00 */
		{
			*draw = (0x00);
			draw++;
		}		
	return;
}
/*
plots a single pixel to the correct location
Formula supplied by Paul Pospisil
*/
void plot_pixel(UINT8 *base, int x, int y)
{
	if (((x >= 0) && (x < 640)) && ((y >= 0) && (y < 400))) /*within screen bounds*/
		*(base + (y * 80) + (x >> 3)) |= (1 << (7 - (x & 7)));
	
	return;
}

/*
Plots a 16 bit wide bitmap to a specific location on the screen
*/
void bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
	UINT16 *draw = base + y * 40 + (x / 16);
	int shift = x % 16; /*amount of shift required*/
	unsigned int i;
	
	if (x <= 640 && y <= 400)
	{
		for (i = 0; i < height && draw < base + 16000; i++)
		{
			*draw |= (bitmap[i] >> shift);
			draw += 40;
		}
		draw = draw - (40 * height) + 1;
		if (shift > 0)
		{
			for (i = 0; i < height && draw < base + 16000; i++)
			{
				*draw |= (bitmap[i] << 16 - shift);
				draw += 40;
			}
		}
	}
	return;
}

void bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height)
{
	UINT8 *draw = base + y * 80 + (x / 8);
	int shift = x % 8; /*amount of shift required*/
	unsigned int i;
	
	if (x <= 640 && y <= 400)
	{
		for (i = 0; i < height && draw < base + 32000; i++)
		{
			*draw |= (bitmap[i] >> shift);
			draw += 80;
		}
		draw = draw - (80 * height) + 1;
		if (shift > 0)
		{
			for (i = 0; i < height && draw < base + 32000; i++)
			{
				*draw |= (bitmap[i] << 8 - shift);
				draw += 80;
			}
		}
	}
	return;
}
/*


*/
void bitmap8V2(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height)
{
	UINT8 *draw = base + y * 80 + (x / 8);
	int shift = x % 8; /*amount of shift required*/
	unsigned int i;
	
	if (x <= 640 && y <= 400)
	{
		for (i = 0; i < height && draw < base + 32000; i++)
		{
			*draw |= ((0xFF - bitmap[i]) >> shift);
			draw += 80;
		}
		draw = draw - (80 * height) + 1;
		if (shift > 0)
		{
			for (i = 0; i < height && draw < base + 32000; i++)
			{
				*draw |= ((0xFF - bitmap[i]) << 8 - shift);
				draw += 80;
			}
		}
	}
	return;
}
/*
 *	Clears the screen.
 */
void clrScrn(UINT16 *base){
	int x, y;
	for(x = 0; x < 40; x++){
			for(y = 0; y < 399 ; y++){
				*(base + y * 40 + x) = 0x0000;
			}
		}
}


/* Purpose: Draws a circle to the screen
 *
 * Method:  Bresenhams circle algorithm is used to locate where to plot
			the shape of a circle. This is done by plotting pixels in each
			of the 8 octants of the circle, since a circle is symmetric
			about the x-axis.
	Input:  UINT8 *base    - the starting point of the frame buffer
			Int    centerX - the x-axis of the center of the circle
			Int    centerY - the y-axis of the center of the circle
			Int    radius  - how big the circle will be
	
	Output: NO OUTPUT
 *
 */
void plotCircle(UINT8 *base, int centerX, int centerY, int radius){
	int y, decisionParam, x = 0;  /*600 + 39 = 639 and 344 + 39 != 400 but that's the max height*/
	y = radius;
	decisionParam =  1 - radius; 
 
	plotPoints(base, centerX, centerY, x, y);	
	while (x < y){
		x++;
		if (decisionParam < 0){
			decisionParam = decisionParam + 4 * x + 6;
		}
		else{
			y--;
			decisionParam = decisionParam + 4 * (x - y) + 10;
		}
		plotPoints(base, centerX, centerY, x, y);
	}
}

void plotPoints(UINT8 *base, int cx, int cy, int x, int y){ 	
	*(base + (cy - x) * 80 + ((cx - y) >> 3)) |= 1 << 7 -((cx - y) & 7);
	*(base + (cy - x) * 80 + ((cx + y) >> 3)) |= 1 << 7 -((cx + y) & 7);
	*(base + (cy + x) * 80 + ((cx - y) >> 3)) |= 1 << 7 -((cx - y) & 7);
	*(base + (cy + x) * 80 + ((cx + y) >> 3)) |= 1 << 7 -((cx + y) & 7);
	*(base + (cy - y) * 80 + ((cx - x) >> 3)) |= 1 << 7 -((cx - x) & 7);
	*(base + (cy - y) * 80 + ((cx + x) >> 3)) |= 1 << 7 -((cx + x) & 7);
	*(base + (cy + y) * 80 + ((cx - x) >> 3)) |= 1 << 7 -((cx - x) & 7);
	*(base + (cy + y) * 80 + ((cx + x) >> 3)) |= 1 << 7 -((cx + x) & 7);
}
void plotVertLine(UINT8 *base, int startX, int startY, int height){
	int i;
	for(i = 0; i < height; i++){
		*(base + (startY + i) * 80 + (startX >> 3)) |= 1 << 7 -((startX & 7));
	}
}
void plotHorizLine(UINT8 *base, int startX, int startY, int width){
	int i;
	for(i = 0; i < width; i++){
		*(base + startY * 80 + ((startX + i) >> 3)) |= 1 << 7 -(((startX + i) & 7));
	}
}

void plot_rectangleLines(UINT8 *base, int startX, int startY, int width, int height){
    plotHorizLine(base, startX, startY, width);
    plotHorizLine(base, startX, (startY + height), width);
    plotVertLine (base, startX, startY, height);
    plotVertLine (base, (startX + width), startY, (height + 1));
}