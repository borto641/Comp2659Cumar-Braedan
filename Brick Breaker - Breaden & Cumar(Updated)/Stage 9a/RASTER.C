#include "RASTER.H"

/*
*	Function: plotHorLine
*
*	Purpose: To plot a horizontal line to the given screen buffer
*
*	Input:	 A UINT32 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the line
*			 An integer representing the shift on the left side of the line
*			 An integer representing the shift on the right side of the line
*
*/
void plotHorLine(UINT32 *base, int x, int y, int width, int lshift, int rshift)
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

/*
*	Function: plotRectangle
*
*	Purpose: To plot a rectangle to the given screen buffer by repeatedly plottng lines
*
*	Input:	 A UINT32 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*			 An integer representing the height of the rectangle
*
*/
void plotRectangle(UINT32 *base, int x, int y, int width, int height)
{
	UINT32 *draw = base;
	int i = 0;
	int lshift = (x % 32);              				    /*amount of shift required on left side of line*/
	int rshift = (32 - ((width - (32 - lshift)) % 32)); 	/*amount of shift required on right side of line*/

	for (i = 0; i < height; i++)
	{
		plotHorLine(draw, x, y, width, lshift, rshift);
		draw += 20;
	}

	return;	
}

/*
*	Function: clearRectangle
*
*	Purpose: To choose the correct function for clearing a rectangle from a given screen buffer
*
*	Input:	 A UINT32 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*			 An integer representing the height of the rectangle
*
*/
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

/*
*	Function: clearRectangle32
*
*	Purpose: To clear a rectangle from the given screen buffer
*
*	Input:	 A UINT32 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*			 An integer representing the height of the rectangle
*
*/
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

/*
*	Function: clearRectangle16
*
*	Purpose: To clear a rectangle from the given screen buffer
*
*	Input:	 A UINT16 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*			 An integer representing the height of the rectangle
*
*/
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

/*
*	Function: clearRectangle8
*
*	Purpose: To clear a rectangle from the given screen buffer
*
*	Input:	 A UINT8 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*			 An integer representing the height of the rectangle
*
*/
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

/*
*	Function: clearHorLine32
*
*	Purpose: To clear a line from the given screen buffer
*
*	Input:	 A UINT32 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*
*/
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

/*
*	Function: clearHorLine16
*
*	Purpose: To clear a line from the given screen buffer
*
*	Input:	 A UINT16 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*
*/
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

/*
*	Function: clearHorLine8
*
*	Purpose: To clear a line from the given screen buffer
*
*	Input:	 A UINT8 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the rectangle
*
*/
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
*	Function: bitmap32
*
*	Purpose: To plot a 32 bit wide bitmap to a given screen buffer
*
*	Input:	 A UINT16 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 A constant UINT16 pointer to a given bitmap
*			 An integer representing the height of the bitmap
*
*/
void bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height)
{
	UINT32 *draw = base + y * 20 + (x / 32);
	int shift = x % 32; /*amount of shift required*/
	unsigned int i;
	
	if (x <= 640 && y <= 400)
	{
		for (i = 0; i < height && draw < base + 8000; i++)
		{
            *draw |= (bitmap[i] >> shift);
			draw += 20;
            *draw |= (bitmap[i] >> shift);
			draw += 20;
		}
		draw = draw - (20 * height*2) + 1;
		if (shift > 0)
		{
			for (i = 0; i < height && draw < base + 8000; i++)
			{
                *draw |= (bitmap[i] << 32 - shift);
				draw += 20;
                *draw |= (bitmap[i] << 32 - shift);
				draw += 20;
			}
		}
	}
	return;
}

/*
*	Function: bitmap16
*
*	Purpose: To plot a 16 bit wide bitmap to a given screen buffer
*
*	Input:	 A UINT16 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 A constant UINT16 pointer to a given bitmap
*			 An integer representing the height of the bitmap
*
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

/*
*	Function: bitmap8
*
*	Purpose: To plot a 8 bit wide bitmap to a given screen buffer
*
*	Input:	 A UINT8 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 A constant UINT8 pointer to a given bitmap
*			 An integer representing the height of the bitmap
*
*/
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
*	Function: bitmap8V2
*
*	Purpose: To plot a 8 bit wide bitmap with the font white
            and back ground black, to a given screen buffer
*            
*
*	Input:	 A UINT8 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 A constant UINT8 pointer to a given bitmap
*			 An integer representing the height of the bitmap
*
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
*	Function: clrScrn
*
*	Purpose: To clear a 32000 byte long screen buffer
*
*	Input:	 A UINT16 pointer to the beginning of a screen buffer
*			 
*/
void clrScrn(UINT16 *base){
	int x, y;
	for(x = 0; x < 40; x++){
			for(y = 0; y < 399 ; y++){
				*(base + y * 40 + x) = 0x0000;
			}
		}
}

/*
*	Function: plotVertLine
*
*	Purpose: Plots a byte aligned vertical line to the screen buffer
*
*	Input:	 A UINT8 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the height of the line
*			 
*/
void plotVertLine(UINT8 *base, int startX, int startY, int height){
	int i;
	for(i = 0; i < height; i++){
		*(base + (startY + i) * 80 + (startX >> 3)) |= 1 << 7 -((startX & 7));
	}
}

/*
*	Function: plotHorizLine
*
*	Purpose: Plots a byte aligned horizontal line to the screen buffer
*
*	Input:	 A UINT8 pointer to the beginning of a screen buffer
*			 An integer representing the starting x value
*			 An integer representing the starting y value
*			 An integer representing the width of the line
*			 An integer representing the height of the line
*/
void plotHorizLine(UINT8 *base, int startX, int startY, int width){
	int i;
	for(i = 0; i < width; i++){
		*(base + startY * 80 + ((startX + i) >> 3)) |= 1 << 7 -(((startX + i) & 7));
	}
}


/*
*	Function: plot_rectangleLines
*
*	Purpose: Draws a hollow rectangle to the screen buffer
*
*	Input:	 A UINT8 pointer to the base of the screen buffer
*			 An integer containing the starting X value
*			 An integer containing the starting Y value
*			 An integer containing the total width
*			 An integer containing the total height
*/
void plotRectangleLines(UINT8 *base, int startX, int startY, int width, int height){
    plotHorizLine(base, startX, startY, width);
    plotHorizLine(base, startX, (startY + height), width);
    plotVertLine (base, startX, startY, height);
    plotVertLine (base, (startX + width), startY, (height + 1));
}

/*
*	Function: getScreenBase
*
*	Purpose: Retrieves the current screen buffer base
*
*	Return: A UINT8 pointer containing the current base			 
*/
UINT8* getScreenBase()
{
	UINT8 *highByte = 0xFFFF8201L;
	UINT8 *loByte = 0xFFFF8203L;
	long address;
	long oldSSP;
	
	oldSSP = Super(0);
	
	address = (long)(*highByte);
	address = address << 8;
	address += (long)(*loByte);
	address = address << 8;
	
	Super(oldSSP);
	
	return (UINT8*)(address);
}


/*
*	Function: swapScreenBuffers
*
*	Purpose: Swaps the phystical base of the system with a new buffer
*
*	Input:	 A UINT8* pointer to a screen buffer
*			 A UINT8* pointer to a screen buffer
*			 
*/
void swapScreenBuffers(UINT8** front, UINT8** back)
{
	long old_ssp;
	UINT8* swap = *front;
	*front = *back;
	*back = swap;
	old_ssp = Super(0);
	setScrn(*front);
	Super(old_ssp);
}
