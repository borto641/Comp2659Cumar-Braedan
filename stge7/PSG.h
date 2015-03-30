#ifndef PSG_H
#define PSG_H
#include <osbind.h>
#include <stdio.h>
#include "types.h"

void write_psg(int reg, UINT8 val);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
void ball_hits_paddle_sound();
void ball_hits_wall_sound();
void music (int channel, int tuning, int duration);


#endif
