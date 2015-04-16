#include "types.h"
#include "vector.h"
#include <stdio.h>
#include <osbind.h>

typedef void (*Vector)();
Vector installVector(int num, Vector vector);
void vbl_isr();
bool vbFlag;

int main()
{
	long old_ssp = Super(0);
	vbFlag = FALSE;
	Vector orig_vbl = installVector(VBL_VECT, vbl_isr);
	printf("SURE?\n");
	installVector(VBL_VECT, orig_vbl);
	
	return 0;
	
}