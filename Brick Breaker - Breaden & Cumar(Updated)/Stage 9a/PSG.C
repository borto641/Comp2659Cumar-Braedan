#include <osbind.h>
#include <stdio.h>
#include "psg.h"

/*
*   Function: write_psg
*
*   Purpose:  This function communicates with the requested register
*             and writes a value to it. 
*                                       
*	Input:	int   reg - used to access the registers 0 - F
*           UINT8 val - used to write a value to the register that has been chosen
*
*	Output: N/A
*
*/
void write_psg(int reg, UINT8 val){
    volatile char *PSG_reg_select = 0xFF8800;
    volatile char *PSG_reg_write  = 0xFF8802;
    long old_ssp;
	
    *PSG_reg_select = reg;
    *PSG_reg_write  = val;
   
}
/*
*   Function: set_tone
*
*   Purpose:  This function sets a tone for the requested channel
              
*                                       
*	Input:	int channel -  selects one of the channels for A - C
*                       -  A = 0, B = 1, C = 2
*           int tuning  - 
*
*	Output: N/A
*
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
/*
*   Function: set_volume
*
*   Purpose:  This function sets the volume of the chosen channel
                                       
*	Input:	int channel - selects on the channels A - C
*           int volume  - sets the volume of the channel from 0 - 11
*
*	Output: N/A
*
    Volume Registers:
    8 = A
    9 = B
    10 = C
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
*   Function: enable_channel
*
*   Purpose:  This function enables either the tone or noise for
               the chosen channel.
                                   
*	Input:	int channel  - selects one of the channels from A - C
*           int tone_on  - 0 = set tone on  1 = set tone off 
*           int noise_on - 0 = set noise on 1 = set noise off
*
*	Output: N/A
*
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
            write_psg(7, 0x08);/* opens channel a and b */
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
*   Function: stop_sound
*
*   Purpose:  This function stops the sound for all the channels A - C
                                    
*	Input:	N/A
*
*	Output: N/A
*
*/
void stop_sound()
{    
	long oldSSP = Super(0);
    write_psg(8, 0);		/* set channel A volume = 0 */
    write_psg(9, 0);		/* set channel B volume = 0 */
    write_psg(10, 0);		/* set channel C volume = 0 */
	Super(oldSSP);
}
/*
*   Function: start_noise
*
*   Purpose:  This function sets a the noise frequency when a noise
*             has been set.                      
*	Input: int tuning 
*
*	Output: N/A
*
*/
void set_noise(int tuning){
    write_psg(6, tuning);
} 
/*
*   Function: set_envelope
*
*   Purpose:  This function sets the envelope for the given noise
                                   
*	Input:	int shape   - chooses a shape from 00 - 0F
*           int sustain - chooses a fine or rough frequency from 0 - 255 
*
*	Output: N/A
*
*/
void set_envelope(int shape, unsigned int sustain){
    write_psg(11, sustain);
    write_psg(12, sustain);
    write_psg(13, shape);
}