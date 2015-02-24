#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "raster.h"


int main(){
    void  *base = Physbase();  
	int choice;
	Paddle paddle;
	Brick brick;
	LifeCounter lifeCounter;
    Ball ball;
    ScoreNum scoreNum;
    ScoreLabel scoreLabel;
    paddle.x = 200;
    paddle.y = 300;
    paddle.width = 20;
    paddle.height = 20;
    
    clrScrn(base);
    plot_rectangle(base, paddle.x, paddle.y, paddle.width, paddle.height);
	key_press(paddle);
	
	printf("HELL YAA*************************************");
	scanf(" %c", &choice);


return 0;
}