#include <osbind.h>
#include "types.h"

void setScrn(UINT8* screen);
int main()
{
	long old_ssp;
	UINT8* screen = Physbase();	
	old_ssp = Super(0);
	setScrn(screen);
	Super(old_ssp);
	return 0;
}