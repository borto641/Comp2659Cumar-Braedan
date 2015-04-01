#include <osbind.h>
#include <stdio.h>
#include "effects.h"
#include "psg.h"

void ballHitsPaddleSound(){
    set_noise(0x1F);
    enable_channel(2, 1, 0);
    set_volume(2,0x10);
    set_envelope(0x09,0x02);
}
void ballHitsWallSound(){
    set_noise(0x00);
    enable_channel(2, 1, 0);
    set_volume(2,0x10);
    set_envelope(0x00,0x02);

}
void ballHitsBrickSound(){
    set_noise(0x1F);
    enable_channel(2, 1, 0);
    set_volume(2,0x10);
    set_envelope(0x00,0x38);
}