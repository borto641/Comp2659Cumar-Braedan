#include <stdio.h>
#include <osbind.h>
#include "RASTER.H"

int main()
{
	char *vidBaseReg;
	long old_ssp;
	UINT8* address = getScreenBase();
	old_ssp = Super(0);
	
	printf("%p \n", address);
	printf("%p \n", Physbase());

	Super(old_ssp);

	return 0;
}
