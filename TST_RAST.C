#include <osbind.h>
#include "raster.h"

#define INVADER_HEIGHT 16



int main()
{
const int invader_bitmap[INVADER_HEIGHT] =
{
0x0000,
0x0810,
0x0810,
0x0420,
0x0240,
0x1FF8,
0x2004,
0x4662,
0x4002,
0x43C2,
0x2424,
0x1008,
0x0FF0,
0x0FF0,
0x0FF0,
0x0FF0};

	UINT16 *base = Physbase();
	UINT8 *base8 = Physbase();


	clrScrn(base);
	plotCircle(base8, 100, 100, 30);
	plotCircle(base8, 100, 100, 40);
	plotCircle(base8, 100, 100, 50);
	plotCircle(base8, 100, 100, 60);
	plot_bitmap_16(base, 200, 200, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 600, 200, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 100, 100, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 300, 300, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 500, 10, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 250, 250, invader_bitmap, INVADER_HEIGHT);
	
	plot_rectangle(base8, 100, 250, 500, 10);
	return 0;
}
