#include "events.h"



/****************************************************************************
Paddle:
- right key: 		move paddle right
- left  key: 		move paddle left
- space bar key:    launch ball if beginning of level
****************************************************************************/
void key_press(Paddle *paddle)
{
/*do appropriate actions corresponding to key pressed*/
	/*Cconis(); check status of standard input*/
	/*Cnecin(); read char from standard input no echo*/
	/*                       
		4B00 - Left arrow
		4D00 - Right arrow
		3920 - Space key
	*/
	int choice;
	long key_pressed = Cnecin();
		if(key_pressed == left_arrow){
			move_paddle_left(paddle);
		}
		else if(key_pressed == right_arrow){
			move_paddle_right(paddle);
		}
		else if(key_pressed == spacebar){
			/*paddle_launch_ball(paddle);*/
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

