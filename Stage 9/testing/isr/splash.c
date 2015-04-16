#include "splash.h"

int splashScreenLoop(){

    char playerOneLabel[11] = {'O','n','e',' ','P','l','a','y','e','r', '\0'};
    char playerTwoLabel[11] = {'T','w','o',' ','P','l','a','y','e','r', '\0'};
    char quitLabel[5]       = {'Q','u','i','t','\0'};
    UINT8 *base8 = Physbase();
    bool quit = FALSE;
    long input;
    int i = 0;
    int result = 0;
   
    printf("\033E\033f\n");    
    initializeSplashScreen(base8,playerOneLabel,playerTwoLabel,quitLabel);
    
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
                    up_key_press(base8, 280, 300,  200, 10 , 4 , playerTwoLabel, quitLabel);
                    i--;
                }
                else if(i == 1){
                    up_key_press(base8, 280, 280, 100, 10, 10 , playerOneLabel, playerTwoLabel);
                    i--;
                }
            }
            else if(input == DOWN_ARROW){
                if(i == 0){
                    down_key_press(base8, 280, 280, 100, 10, 10, playerOneLabel, playerTwoLabel);
                    i++;
                }
                else if (i == 1){
                    down_key_press(base8, 280, 300, 200, 10, 4, playerTwoLabel, quitLabel);
                    i++;
                }
            }
        }
    }
    return result;
}
void initializeSplashScreen(UINT8 *base8, char playerOneLabel[], char playerTwoLabel[], char quitLabel[]){
    plot_rectangleLines(base8, 220, 80, 200, 50);
    plot_rectangleLines(base8, 220, 180, 200, 50);
    plot_rectangleLines(base8, 220, 280, 200, 50);   
 
    printCharsV2(base8, 280, 100, 10, playerOneLabel);
    printChars(base8, 280, 200, 10, playerTwoLabel);
    printChars(base8, 300, 300, 4, quitLabel);
}
void down_key_press(UINT8 *base8, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]){
    clearRectangle8(base8, x1, y, 80 , 16);
    clearRectangle8(base8, x2, (y + 100), 80 , 16);
    printChars(base8, x1, y, width1, label1);
    printCharsV2(base8, x2, (y + 100), width2, label2);
}
void up_key_press(UINT8 *base8, int x1, int x2, int y, int width1, int width2, char label1[], char label2[]){
    clearRectangle8(base8, x1, y, 80 , 16);
    clearRectangle8(base8, x2, (y + 100), 80 , 16);
    printCharsV2(base8, x1, y, width1, label1);
    printChars(base8, x2, (y + 100), width2, label2);
}

