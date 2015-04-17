#include "vector.h"
#include <osbind.h>
#include "types.h"

/*
*	Function: installVector
*
*	Purpose: Moves the address of a new isr into the vector table of the system
*
*	Input:	An integer holding the vector number to replace
*			A Vector pointing to the new isr
*
*	Output: An old Vector containing the old isr
*
*/
Vector installVector(int num, Vector vector)
{
	Vector orig;
	Vector *vectp = (Vector *)((long)num << 2);
	long old_ssp = Super(0);

	orig = *vectp;
	*vectp = vector;

	Super(old_ssp);
	return orig;
}