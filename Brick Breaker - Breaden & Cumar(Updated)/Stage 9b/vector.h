#ifndef VECTOR_H
#define VECTOR_H
#define VBL_VECT 28
#define IKBD_VECT 28

typedef void (*Vector)();
Vector installVector(int num, Vector vector);

#endif