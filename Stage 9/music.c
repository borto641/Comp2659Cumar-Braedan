#include <osbind.h>
#include <stdio.h>
#include "music.h"
#include "psg.h"
#define SCREEN_CLOCK 0x462

/*even index holds tone odd index holds duration
    {43, 20, 0, 20, 44, 20, 0 , 20, 43 , 20, 0 , 20 ,42 , 70, 41 ,70 , 0 , 20};  */
    
const int song[] =  
                {
                    200,  17, 180 , 17, 240 , 17, 
                    200,  17, 180 , 17, 240 , 17,
                    200,  17, 180 , 17,
                     
                    200,  17, 180 , 17, 240 , 17, 
                    200,  17, 180 , 17, 240 , 17,
                    200,  17, 180 , 17,
                     
                    170 , 17, 160 , 17 , 150 , 17,
                     
                    200,  17, 180 , 17, 240 , 17, 
                    200,  17, 180 , 17, 240 , 17,
                    200,  17, 180 , 17,
                     
                    170, 17, 0 , 17, 160, 17, 0, 17, 150, 17 ,0 , 17,
                     
                    200,  17, 180 , 17, 240 , 17, 
                    200,  17, 180 , 17, 240 , 17,
                    200,  17, 180 , 17,
                     
                    150, 17, 0 , 17, 160 , 17, 0 , 17, 170 , 17 , 0 , 17,
                                          
                    100, 17, 120, 17 , 150 , 17 , 125 , 35,
                     
                    100, 17, 120, 17 , 150 , 17 , 125 , 35,
                    
                    200 , 17, 240, 17
                                      
                };                                                  

int musicIndex;
int musicCounter;
bool musicStarted = FALSE;

void start_music()
{
	long oldSSP = Super(0);
    musicIndex = 0;
    set_tone(0, song[musicIndex]);
    enable_channel(0, 0, 1);
    set_volume(0,13);
	musicStarted = TRUE;
	Super(oldSSP);
}

void update_music()
{
	if (musicStarted == TRUE)
	{
		if(musicCounter > song[musicIndex + 1])
		{
			if(musicIndex == 112)
				musicIndex = 0;
			else    
				musicIndex = musicIndex + 2;
	 
			set_tone(0, song[musicIndex]);		  
			musicCounter = 0;
		}
		else
		{	
			musicCounter += 1;
		}
	}
    return;
} 
