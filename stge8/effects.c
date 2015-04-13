#include "effects.h"
#include "brick.h"
#include "psg.h"

/*

*/
void ballHitsPaddleSound(){
    UINT32 timeThen;
    timeThen = checkScreenClock(); 
    
    while((checkScreenClock() - timeThen )< 2){
        set_noise(0x1F);
        set_tone(2, 70);
        set_volume(2,0x10);
        set_envelope(0x09,0x02);
    }
    stop_sound();
}
/*


*/
void ballHitsWallSound(){
    UINT32 timeThen;
    timeThen  =  checkScreenClock(); 
   
    while((checkScreenClock() - timeThen ) < 2){
        set_noise(0x1F);
        set_tone(2, 150);
        set_volume(2,0x10);
        set_envelope(0x09,0x05);
    }
    stop_sound();
}
/*


*/
void ballHitsBrickSound(){
    UINT32 timeThen;
    timeThen  =  checkScreenClock(); 
    while((checkScreenClock() - timeThen )< 4){
        set_noise(0x1F);
        set_tone(2, 0);
        set_volume(2,0x10);
        set_envelope(0x09,0x38);
    }
    stop_sound();
}

