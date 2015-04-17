#include "splash.h"
/*
*   Function: splashScreenLoop
*   
*	Purpose: This function sets up the splash screen by calling
                the initialize method and detects the which selected
                box has been pressed.
*                           
*	Input:	N/A 
*
*	Output: int - returns which box has been pressed
                - 0 - One player
                - 1 - Two player
                - 2 - Quit
*
*/
int splashScreenLoop(){
    char playerOneLabel[11] = {'O','n','e',' ','P','l','a','y','e','r', '\0'};
    char playerTwoLabel[11] = {'T','w','o',' ','P','l','a','y','e','r', '\0'};
    char quitLabel[5]       = {'Q','u','i','t','\0'};
    long input;
    int i = 0;
    int result = 0;
    void *defaultScreen  = getScreenBase();
    
    
    bool quit = FALSE;
    
    printf("\033E\033f\n");       
    initializeSplashScreen(defaultScreen,playerOneLabel,playerTwoLabel,quitLabel);
    
    while(!quit){ 
        if (checkInputBuffer())
        {
            input = getInput();
            if (input == ENTER  && i == 2){
                    result = 2;
                    quit = TRUE;
            }
            else if (input == ENTER && i == 1){
                    result = 1;
                    quit = TRUE;
            }
            else if (input == ENTER  && i == 0){
                    result = 0;
                    quit = TRUE;
            }
            else if(input == UP_ARROW){
                if(i == 2){
                    up_key_press(defaultScreen, 280, 300,  200, 10 , 4 , playerTwoLabel, quitLabel);
                    i--;
                }
                else if(i == 1){
                    up_key_press(defaultScreen, 280, 280, 100, 10, 10 , playerOneLabel, playerTwoLabel);
                    i--;
                }
            }
            else if(input == DOWN_ARROW){
                if(i == 0){
                    down_key_press(defaultScreen, 280, 280, 100, 10, 10, playerOneLabel, playerTwoLabel);
                    i++;
                }
                else if (i == 1){
                    down_key_press(defaultScreen, 280, 300, 200, 10, 4, playerTwoLabel, quitLabel);
                    i++;
                }
            }
        }
    }
    return result;
}
/*
*   Function: initializeSplashScreen
*   
*	Purpose: This function checks if a keyboard key
*            has been pressed.               
*	Input:	UINT8  defaultScreen       
            UINT32 defaultScreen      
            char playerOneLabel
            char playerOneLabel
            char quitLabel
*
*	Output: N/A 
            
*
*/
void initializeSplashScreen(void *defaultScreen, char playerOneLabel[], char playerTwoLabel[], char quitLabel[]){
    plotRectangleLines(defaultScreen, 220, 80, 180, 50);
    plotRectangleLines(defaultScreen, 220, 180, 180, 50);
    plotRectangleLines(defaultScreen, 220, 280, 180, 50);   
    
    bitmap32(defaultScreen, 120, 0, letterB, 32);
    bitmap32(defaultScreen, 150, 0, letterR, 32);
    bitmap32(defaultScreen, 180, 0, letterI, 32);
    bitmap32(defaultScreen, 210, 0, letterC, 32);
    bitmap32(defaultScreen, 240, 0, letterK, 32);
        
    bitmap32(defaultScreen, 300, 0, letterB, 32);
    bitmap32(defaultScreen, 330, 0, letterR, 32);
    bitmap32(defaultScreen, 360, 0, letterE, 32);
    bitmap32(defaultScreen, 390, 0, letterA, 32);
    bitmap32(defaultScreen, 420, 0, letterK, 32);
    bitmap32(defaultScreen, 450, 0, letterE, 32);
    bitmap32(defaultScreen, 480, 0, letterR, 32);
 
    printCharsV2(defaultScreen, 280, 100, 10, playerOneLabel);
    printChars(defaultScreen, 280, 200, 10, playerTwoLabel);
    printChars(defaultScreen, 300, 300, 4, quitLabel);
}
/*
*   Function: down_key_press
*   
*	Purpose: This function handles the down key press and drops
             down to the bottom displayed select box
*                      
*	Input:	UINT8 defaultScreen
            int x1
            int x2
            int y
            int width1
            int width2
            char label1
            char label2
*
*	Output: N/A
*
*/
void down_key_press(UINT8 *defaultScreen, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]){
    clearRectangle8(defaultScreen, x1, y, 80 , 16);
    clearRectangle8(defaultScreen, x2, (y + 100), 80 , 16);
    printChars(defaultScreen, x1, y, width1, label1);
    printCharsV2(defaultScreen, x2, (y + 100), width2, label2);
}
/*
*   Function: up_key_press
*   
*	Purpose: This function handles the when the up key has been
            pressed and chooses the next selected box
*                          
*	Input:	N/A
*
*	Output: UINT8 defaultScreen
            int x1
            int x2
            int y
            int width1
            int width2
            int label1
            int label2
*
*/
void up_key_press(UINT8 *defaultScreen, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]){
    clearRectangle8(defaultScreen, x1, y, 80 , 16);
    clearRectangle8(defaultScreen, x2, (y + 100), 80 , 16);
    printCharsV2(defaultScreen, x1, y, width1, label1);
    printChars(defaultScreen, x2, (y + 100), width2, label2);
}

