#include "effects.h"
#include "brick.h"
#include "psg.h"

/*

*/
void ballHitsPaddleSound()
{    
	set_noise(0x1F);
	set_envelope(0xFF,0x80);
}
/*


*/
void ballHitsWallSound()
{
     set_noise(0x1F);
     set_volume(2,0x10);
     set_envelope(0x09,0x10);
 }
/*


*/
void ballHitsBrickSound()
{	
        set_noise(0x1F);
        set_volume(2,0x10);
        set_envelope(0x09,0x38);
}

