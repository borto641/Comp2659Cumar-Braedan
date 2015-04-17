#include "effects.h"
#include "brick.h"
#include "psg.h"

/*

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


*/
void ballHitsBrickSound()
{	
	long oldSSP = Super(0);
	set_noise(0x1F);
	set_volume(2,0x10);
	set_envelope(0x09,0x38);
	Super(oldSSP);
}

