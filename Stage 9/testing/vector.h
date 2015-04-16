#ifndef EVENTS_H
#define EVENTS_H
#define VBL_VECT 7

typedef void (*Vector)();

Vector installVector(int num, Vector vector);
void vbl_isr();

#endif