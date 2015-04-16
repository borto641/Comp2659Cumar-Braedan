#include <stdio.h>
#include <osbind.h>
#include "types.h"

typedef void (*Vector)();

void vbl_isr();

Vector install_vector(int num, Vector vector);

bool vbFlag;

int main()
{
	int i = 0;
	Vector orig_vector = install_vector(7, vbl_isr);
	vbFlag = FALSE;
	while ( i < 99999)
	{
		i++;
	}
	install_vector(7, orig_vector);
	printf("%i \n", vbFlag);
	
	return 0;
}

Vector install_vector(int num, Vector vector)
{
	Vector orig;
	Vector *vectp = (Vector *)((long)num << 2);
	long old_ssp = Super(0);

	orig = *vectp;
	*vectp = vector;

	Super(old_ssp);
	return orig;
}