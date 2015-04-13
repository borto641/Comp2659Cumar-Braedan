#include <osbind.h>
#include <stdio.h>
#include "music.h"
#include "psg.h"
#define SCREEN_CLOCK 0x462

/*even index holds tone odd index holds duration
    {43, 20, 0, 20, 44, 20, 0 , 20, 43 , 20, 0 , 20 ,42 , 10, 41 ,10 , 0 , 20};  */
    
const int song[] =  
                {
                    200,  10, 180 , 10, 240 , 10, 
                    200,  10, 180 , 10, 240 , 10,
                    200,  10, 180 , 10,
                     
                    200,  10, 180 , 10, 240 , 10, 
                    200,  10, 180 , 10, 240 , 10,
                    200,  10, 180 , 10,
                     
                    170 , 10, 160 , 10 , 150 , 10,
                     
                    200,  10, 180 , 10, 240 , 10, 
                    200,  10, 180 , 10, 240 , 10,
                    200,  10, 180 , 10,
                     
                    170, 10, 0 , 10, 160, 10, 0, 10, 150, 10 ,0 , 10,
                     
                    200,  10, 180 , 10, 240 , 10, 
                    200,  10, 180 , 10, 240 , 10,
                    200,  10, 180 , 10,
                     
                    150, 10, 0 , 10, 160, 10, 0, 10, 170, 10 ,0 , 10,
                                          
                    100, 10, 120, 10 , 150 , 10 , 125 , 20,
                     
                    100, 10, 120, 10 , 150 , 10 , 125 , 20,
                    
                    140 , 10, 135, 20
                                      
                };                                                  
int index;

void start_music(){
    index = 0;
    set_tone(0, song[index]);
    enable_channel(0, 0, 1);
    set_volume(0,13);
  
    set_noise(0x00);
    set_tone(1, 180);
    set_volume(1,0x10);
    set_envelope(0x0B, 30); 
}
int update_music(UINT32 time_elapsed){
    if(time_elapsed > song[index + 1] && time_elapsed < 50){
        if(index == 112)
            index = 0;
        else    
            index = index + 2;
    
        set_tone(0, song[index]);
        enable_channel (0, 0, 1);
        set_volume(0, 13);        
      
        return 1;
    }
    else if(time_elapsed > 50 ){
        set_noise(0x00);
        set_tone(1, 180);
        set_volume(1,0x10);
        set_envelope(0x0B, 30);
    }
    return 0;
} 
