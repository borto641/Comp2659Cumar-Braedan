#include "effects.h"
#include "brick.h"
#include "psg.h"

/*
*	Function: ballHitsBrickSound
*
*	Purpose: This function creates a sound effect when the ball hits
*             the paddle.
* 			
*	Input:	N/A
*
*	Output: N/A
*
*/
void ballHitsPaddleSound()
{    
	long oldSSP = Super(0);
	set_noise(0x1F);
	set_volume(2,0x10);
	set_envelope(0x09,0x10);
	Super(oldSSP);
}
/*
*	Function: ballHitsWallSound
*
*	Purpose: This function creates a sound effect when the ball hits
*            the wall.
* 			
*	Input:	N/A
*
*	Output: N/A
*
*/
void ballHitsWallSound()
{
	long oldSSP = Super(0);
	set_noise(0x1F);
	set_volume(2,0x10);
	set_envelope(0x09,0x8);
	Super(oldSSP);
 }
/*
*	Function: ballHitsBrickSound
*
*	Purpose: This function creates a sound effect when the ball hits
*             a brick.
*
*	Input:	N/A
*
*	Output: N/A
*
*/
void ballHitsBrickSound()
{	
	long oldSSP = Super(0);
	set_noise(0x1F);
	set_volume(2,0x10);
	set_envelope(0x09,0x38);
	Super(oldSSP);
}

