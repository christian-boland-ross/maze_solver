#include "robot.h"
#include "graphics.h"
#include "config.h"
#include "maze.h"

static int x = 0;
static int y = 0;

static int orientation = 1;
// 0 = north, 1 = east, 2 = south, 3 = west

int getRobotX(void)
{
    return x;
}

int getRobotY(void)
{
    return y;
}

int getRobotOrientation(void)
{
    return orientation;
}

void forward(void)
{
    if(canMoveForward()) 
    {
        switch (orientation)
        {
            case 0: y++; break;
            case 1: x++; break;
            case 2: y--; break;
            case 3: x--; break;
        }
    }
}

void left(void)
{
    orientation = (orientation + 3) % 4;
}

void right(void)
{
    orientation = (orientation + 1) % 4;
}

bool atMarker(void)
{
    return true;
} // return true if the robot is on the exit marker, otherwise false.

bool canMoveForward(void) 
{
    int nextX = x;
    int nextY = y;

    switch (orientation)
    {
        case 0: nextY++; break;
        case 1: nextX++; break;
        case 2: nextY--; break;
        case 3: nextX--; break;
    }

    if (nextX < 0 || nextX >= GRID_SIZE || nextY < 0 || nextY >= GRID_SIZE)
    {
        return false;
    }

    return !isWall(nextY, nextX);
}