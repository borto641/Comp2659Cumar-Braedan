#include <stdio.h>
#include <osbind.h>

#define TRAP_0 32

typedef void (*Vector)();

void trap0();
Vector install_vector(int num, Vector vector);
void trap0_isr();

int main(){

	Vector orig_vector = install_vector(TRAP_0, trap0_isr);
	
	trap0();
	install_vector(TRAP_0, orig_vector);
	printf("got here\n");
     
	return 0;
}

Vector install_vector(int num, Vector vector){
	Vector orig;
	Vector *vectp = (Vector *) ((long)num <<2);
	long old_ssp = Super(0);
	
	orig   =  *vectp;
	*vectp = vector;

	Super(old_ssp);

	return orig;
}