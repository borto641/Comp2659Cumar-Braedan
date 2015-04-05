#include <osbind.h>
#include <stdio.h>
#include "effects.h"
#include "psg.h"
#include "brick.h"
#include <stdio.h>
/*

*/
void ballHitsPaddleSound(){
    long old_ssp = Super(0);
    int i = 0;
    set_noise(0x1F);
    set_tone(2, 70);
    enable_channel(2, 0, 0);
    set_volume(2,0x10);
    set_envelope(0x09,0x02);
    while(i <10000){
        i++;
    }
    stop_sound();
    Super(old_ssp);
}
/*


*/
void ballHitsWallSound(){
    long old_ssp = Super(0);
    int i = 0;
    set_noise(0x1F);
    set_tone(2, 150);
    enable_channel(2, 0, 0);
    set_volume(2,0x10);
    set_envelope(0x09,0x05);

    while(i <10000){
        i++;
    }
    stop_sound();
    Super(old_ssp);
}
/*


*/
void ballHitsBrickSound(){
    long old_ssp = Super(0);
    int i = 0;
    set_noise(0x1F);
    enable_channel(2, 1, 0);
    set_volume(2,0x10);
    set_envelope(0x00,0x38);

    while(i <= 30000){
        i++;
    }
   
    stop_sound();
    Super(old_ssp);
}