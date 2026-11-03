#include "graphics.h"
#include "render2d.h"
#include "render3d.h"
#include "config.h"
#include "maze.h"
#include "robot.h"

int main(void)
{
    setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    initialiseMaze();
    initialiseRobot();
    
    //main game loop
    while(true)
    {
        draw3DWorld();
        draw2DWorld();
        drawRobot();
        //updateRobot();
        sleep(100);
    }

    return 0;
}