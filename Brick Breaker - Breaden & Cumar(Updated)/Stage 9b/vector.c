#include "vector.h"
#include <osbind.h>
#include "types.h"

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