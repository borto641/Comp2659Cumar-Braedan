    #include "events.h"

    /****************************************************************************
    Paddle:
    - right key: 		move paddle right
    - left  key: 		move paddle left
    - space bar key:    launch ball if beginning of level
    ****************************************************************************/

    void key_press(Screen  * screen){
    /*do appropriate actions corresponding to key pressed*/
        /*Cconis(); check status of standard input*/
        /*Cnecin(); read char from standard input no echo*/
        /*                       
            4B00 - Left arrow
            4D00 - Right arrow
            3920 - Space key
        */
        int choice;
        void *base = Physbase();
        long key_pressed = Cnecin();
        while (key_pressed != spacebar){
            if(key_pressed == left_arrow){
             /*user presses left key*/
                    paddleLeft(screen);
            }
            else if(key_pressed == right_arrow){
            /*user presses right key*/
              paddleRight(screen);
             
            }
            else if(key_pressed == spacebar){
                /*user presses spacebar key*/
                /*paddle_launch_ball(paddle);*/	
                }
                printf("\033E\033f\n");     /* blank the screen */
            /*clrScrn(base);*/
            printScreen(screen);
            key_pressed = Cnecin();    
                
            }
            
        }

    /* *****************************************************************************
    Brick
    - when the ball touches the brick from any side
    - up,down, left side and right side
    ******************************************************************************/

    void ball_hits_brick(Screen screen, int brick){
    /*If ball touches the brick remove the brick from the level*/
        screen.bricks[brick] = false;
    } 

