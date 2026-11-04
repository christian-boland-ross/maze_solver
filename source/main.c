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
    
    //main game loop
    while(true)
    {
        clear();

        draw3DWorld();

        draw2DWorld();
        drawRobot();

        sleep(100);

        if(atMarker())
        {
            break;
        }
        updateRobot();
    }

    drawString("Maze Solved.", WINDOW_WIDTH/2 - 30, WINDOW_HEIGHT/2);

    return 0;
}