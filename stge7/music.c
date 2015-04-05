#include <osbind.h>
#include <stdio.h>
#include "music.h"
#include "psg.h"
#define SCREEN_CLOCK 0x462

/*even index holds tone odd index holds duration
    {43, 20, 0, 20, 44, 20, 0 , 20, 43 , 20, 0 , 20 ,42 , 10, 41 ,10 , 0 , 20};  */
    
const int song[] =  {43, 20, 0, 20, 44, 20, 0 , 20, 43 , 20, 0 , 20 ,42 , 10, 41 ,10 , 0 , 20};                                              
int index;

void start_music(){
    int i;
    index = 0;
    /*
    set_tone(0, song[index]);
    enable_channel(0, 0, 1);
    set_volume(0,11);
    */
    i = 0;
    while(i < 255 ){
         set_tone(1,100);
        set_tone(0,i);
       
        enable_channel(0, 0, 1);
        enable_channel(1, 0, 1);
        set_volume(1,0);
        set_volume(0,11);
       
         printf ("%d\n", i);
        while(!Cconis()){
            ;
        }
       Cnecin();
       set_volume(1,11);
       i++;
    }
    
    
}

int update_music(UINT32 time_elapsed){
    if(time_elapsed > song[index + 1]){
        if(index == 16)
            index = 0;
        else    
            index = index + 2;
        
        set_tone(0, song[index]);
        enable_channel (0, 0, 1);
        set_volume(0, 11);  

      
        return 1;
    }
    return 0;
} 

