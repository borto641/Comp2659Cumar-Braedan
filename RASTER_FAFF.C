#include "raster.h"

void plot_hor_line(UINT8 *base, int x, int y, int length)
{
	UINT8 *draw;
	int i = 0;
	int part = (y % 8);
	 
	if ( x < 640 && y < 400)
	{
		draw = base + (x * 80) + (y / 8);
		if (part > 0)
		{
			//for (int i = part; i < 0; part--)
			//{				
			*draw = *draw | (255 / 2 * part);
			draw + 1;
		}
		for (int l = length % 8; l % 8 == 0; l - 8;)
		{
			*draw == 0xff
			draw++;
		}
		if (part > 0)
		{
			for (i = 1; i < part; i++)
			{
				*draw = *draw | 128 + (127 / 2^part)
			}
				//*draw = *draw | 256 - (128/part) (128, 192, 224 240, 248, 252, 254, 255 PATTERNS ARE COOOOL!)
				
		}
	}
	else
	//Cry
	
	/*
		if (y % 8 == 1)
		{
			*draw = *draw | 0x7f; //127	
			draw + 1;
		}
		else if ( y % 8 == 2)
		{
			*draw = *draw | 0x3f; //63
			draw + 1;
		{
		else if (y % 8 == 3)
		{
			*draw = *draw | 0x1f; //31
		}
		else if (y % 8 == 4)
		{
			*draw = *draw | 0x0f; //15
		}
		else if (y % 8 == 5) //7
		*/
	}
	else
	{
		throw Exception;
	}
}


void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
{
	
}
