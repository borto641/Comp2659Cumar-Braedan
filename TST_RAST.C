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
/*	plotCircle(base8, 100, 100, 30);
	plotCircle(base8, 100, 100, 40);
	plotCircle(base8, 100, 100, 50);
	plotCircle(base8, 100, 100, 60);
	plot_bitmap_16(base, 200, 200, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 600, 200, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 100, 100, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 300, 300, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 500, 10, invader_bitmap, INVADER_HEIGHT);
	plot_bitmap_16(base, 250, 250, invader_bitmap, INVADER_HEIGHT);
*/	
	plot_rectangle(base8, 620, 400, 64, 24);
	/*Row 1*/
	plot_rectangle(base8, 0, 0, 64, 24);
	plot_rectangle(base8, 128, 0, 64, 24);
	plot_rectangle(base8, 256, 0, 64, 24);
	plot_rectangle(base8, 384, 0, 64, 24);
	plot_rectangle(base8, 512, 0, 64, 24);
	/*Row 2*/
	plot_rectangle(base8, 64, 24, 64, 24);
	plot_rectangle(base8, 192, 24, 64, 24);
	plot_rectangle(base8, 320, 24, 64, 24);
	plot_rectangle(base8, 448, 24, 64, 24);
	plot_rectangle(base8, 576, 24, 64, 24);
	/*Row 3*/
	plot_rectangle(base8, 0, 48, 64, 24);
	plot_rectangle(base8, 128, 48, 64, 24);
	plot_rectangle(base8, 256, 48, 64, 24);
	plot_rectangle(base8, 384, 48, 64, 24);
	plot_rectangle(base8, 512, 48, 64, 24);
	/*Row 4*/
	plot_rectangle(base8, 64, 72, 64, 24);
	plot_rectangle(base8, 192, 72, 64, 24);
	plot_rectangle(base8, 320, 72, 64, 24);
	plot_rectangle(base8, 448, 72, 64, 24);
	plot_rectangle(base8, 576, 72, 64, 24);
	/*Row 5*/
	plot_rectangle(base8, 0, 96, 64, 24);
	plot_rectangle(base8, 128, 96, 64, 24);
	plot_rectangle(base8, 256, 96, 64, 24);
	plot_rectangle(base8, 384, 96, 64, 24);
	plot_rectangle(base8, 512, 96, 64, 24);
	
	plot_rectangle(base8, 400, 300, 16, 16);
	return 0;
}
