#include <osbind.h>
#include <stdio.h>
#include "psg.h"

void music (int channel, int tuning, int duration){
    int i = 0;
    while(i < duration){
        set_tone(channel, tuning);
        enable_channel(channel, 0, 1);
        set_volume(channel, 11);
        i++;
    }
}
void ball_hits_paddle_sound(){
    int i = 0;
    while(i < 255){
         set_tone(0, i);
         enable_channel(0, 0, 1);
         set_volume(0, 11);
         i = i + 1;
    }
}

void ball_hits_wall_sound(){
    int i = 255;
    while(i > 0){
         set_tone(0, i);
         enable_channel(0, 0, 1);
         set_volume(0, 11);
         i = i - 1 ;
    }
}
/*

*/
void write_psg(int reg, UINT8 val){
    volatile char *PSG_reg_select = 0xFF8800;
    volatile char *PSG_reg_write  = 0xFF8802;
    long old_ssp;
		
    old_ssp = Super(0);
		
		
    
    *PSG_reg_select = reg;
    *PSG_reg_write  = val;
    Super(old_ssp);
}
/*

*/
void set_tone(int channel, int tuning){  
    if(channel == 0){
        write_psg(0, tuning);
        write_psg(1, 0);
    }
   else if (channel == 1){
        write_psg(2, tuning);
        write_psg(3, 0);
    }
   else if (channel == 2){
        write_psg(4, tuning);
        write_psg(5, 0);
    }
}
/*
Volume Registers:
    8 = A
    9 = B
    A = C
*/
void set_volume(int channel, int volume){
   if(channel == 0)
          write_psg(8, volume);
   else if (channel == 1)
          write_psg(9, volume);
   else if (channel == 2)
          write_psg(10, volume);
}
/*
Channel A :
36 - Noise  on  tone on
3F - Noise  off tone off
37 - Noise  on 
**3E - Tone on

Channel B:
2D - Noise  on  tone on
3F - Noise  off tone off
2F - Noise  on 
**3D - Tone on

Channel C :
1B - Noise  on  tone on
3F - Noise  off tone off
1F - Noise  on 
**3B - Tone on
*/
void enable_channel(int channel, int tone_on, int noise_on){    
    if(channel == 0){
        if(tone_on == 0 && noise_on == 1)
            write_psg(7, 0x3E);
        else if(tone_on == 1 && noise_on == 0)
            write_psg(7, 0x37);
        else if(tone_on == 0 && noise_on == 0)
            write_psg(7, 0x36);
    }
    else if (channel == 1){
        if(tone_on == 0 && noise_on == 1)
             write_psg(7, 0x3D);  
        else if(tone_on == 1 && noise_on == 0)
            write_psg(7, 0x2F);
        else if(tone_on == 0 && noise_on == 0)
            write_psg(7, 0x2D);
    }
    else if (channel == 2){
        if(tone_on == 0 && noise_on == 1)
            write_psg(7, 0x3B);
        else if(tone_on == 1 && noise_on == 0)
            write_psg(7, 0x1F);
        else if(tone_on == 0 && noise_on == 0)
            write_psg(7, 0x1B);
    }
}
/*

*/
void stop_sound(){    
    write_psg(8, 0);		/* set channel A volume = 0 */
    write_psg(9, 0);		/* set channel B volume = 0 */
    write_psg(10, 0);		/* set channel C volume = 0 */
}
/*

*/
void set_noise(int tuning){
    write_psg(6, tuning);
} 
/*

*/
void set_envelope(int shape, unsigned int sustain){
    write_psg(11, sustain);
    write_psg(12, sustain);
    write_psg(13, shape);
}