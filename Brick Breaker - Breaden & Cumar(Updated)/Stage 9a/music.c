#include <osbind.h>
#include <stdio.h>
#include "music.h"
#include "psg.h"
#define SCREEN_CLOCK 0x462

/*
*	Purpose: This variable array contains the tone and duration of the tone
             for the music of the game. The even indices contains the tone 
             while the odd indices contains the duration. 
*                     
*	Input:	N/A
*
*	Output: N/A
*
*/  
    
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

/*
*   Function: start_music
*
*   Purpose:  This function starts up the music by reading/setting up the tone
              from the song array, enabling the channel used(Channel A) and
*             turns on the volume of the chosen channel.                          
*	Input:	N/A
*
*	Output: N/A
*
*/
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
/*
*   Function: update_music
*
*   Purpose:  This function updates the tone whenever the duration of
*              the current tone has elapsed. This is done by moving the  
*             index to the next tone(adding two to the index). When the
*              index has reached the size of the array index is set to
*             zero and plays back the music.
*	Input:	N/A
*
*	Output: N/A
*
*/
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
