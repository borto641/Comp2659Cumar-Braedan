#ifndef INPUT_H
#define INPUT_H
#include <osbind.h>
#include "types.h"

typedef signed char SINT8;
typedef UINT8 SCANCODE;

#define RDR_FULL ((UINT8)0x01)
#define ENABLE 0x96
#define DISABLE 0x16

#define ESC_MAKE     ((SCANCODE) 0x01)
#define ESC_BREAK    ((SCANCODE) 0x81)
#define RGHT_MAKE    ((SCANCODE) 0x4D)
#define RGHT_BREAK   ((SCANCODE) 0xCD)
#define LFT_MAKE     ((SCANCODE) 0x4B)
#define LFT_BREAK    ((SCANCODE) 0xCB)
#define SPACE_MAKE   ((SCANCODE) 0x39)
#define SPACE_BREAK  ((SCANCODE) 0xB9)
#define UP_MAKE      ((SCANCODE) 0x48)
#define UP_BREAK     ((SCANCODE) 0xC8)
#define DOWN_MAKE    ((SCANCODE) 0x50)
#define DOWN_BREAK   ((SCANCODE) 0xD0)
#define ENTER_MAKE   ((SCANCODE) 0x72)
#define ENTER_BREAK  ((SCANCODE) 0xf2)
#define RETURN_MAKE  ((SCANCODE) 0x1C)
#define RETURN_BREAK ((SCANCODE) 0x9C)

SCANCODE read_scancode();
volatile        UINT8 * const IKBD_control = 0xFFFFFC00;
volatile  const	UINT8 * const IKBD_status =  0xFFFFFC00;
volatile  const SCANCODE * const IKBD_RDR =  0xFFFFFC02;
UINT8 ikbd_bfr[255];
int head = 0, tail = 0;
bool checkInputBuffer();
long getInput();

#endif