#include "robot.h"
#include "graphics.h"
#include "config.h"
#include "maze.h"

static int x = 0;
static int y = 0;

static int orientation = 1;
// 0 = north, 1 = east, 2 = south, 3 = west

void drawRobot(void)
{
    int pixelX = x * CELL_SIZE;
    int pixelY = y * CELL_SIZE;

    int margin = CELL_SIZE / 10;

    int left = pixelX + margin;
    int right = pixelX + CELL_SIZE - margin;
    int top = pixelY + margin;
    int bottom = pixelY + CELL_SIZE - margin;

    int centreX = pixelX + CELL_SIZE / 2;
    int centreY = pixelY + CELL_SIZE / 2;

    int px[3];
    int py[3];

    switch (orientation)
    {
        case 0: // North
            px[0] = centreX;
            py[0] = top;
            px[1] = right;
            py[1] = bottom;
            px[2] = left;
            py[2] = bottom;
            break;

        case 1: // East
            px[0] = right;
            py[0] = centreY;
            px[1] = left;
            py[1] = top;
            px[2] = left;
            py[2] = bottom;
            break;

        case 2: // South
            px[0] = centreX;
            py[0] = bottom;
            px[1] = left;
            py[1] = top;
            px[2] = right;
            py[2] = top;
            break;

        case 3: // West
            px[0] = left;
            py[0] = centreY;
            px[1] = right;
            py[1] = bottom;
            px[2] = right;
            py[2] = top;
            break;

        default:
            return;
    }

    setColour(red);
    fillPolygon(3, px, py);
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