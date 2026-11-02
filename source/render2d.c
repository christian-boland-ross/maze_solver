#include "render2d.h"
#include "config.h"
#include "graphics.h"
#include "maze.h"
#include "robot.h"

static void drawGrid(void)
{
    //Grid is always 200x200 pixels, displayed in top left corner of window
    setColour(white);
    fillRect(0, 0, GRID_PIXELS, GRID_PIXELS);
    setColour(black);
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            int x = j * CELL_SIZE;
            int y = i * CELL_SIZE;

            drawRect(x, y, CELL_SIZE, CELL_SIZE);
        }
    }
}

static void drawMaze(void)
{
    setColour(black);
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(isWall(i, j))
            {
                int x = j * CELL_SIZE;
                int y = i * CELL_SIZE;

                fillRect(x, y, CELL_SIZE, CELL_SIZE);
            }
        }
    }

    //top left is always start, bottom right is always finish
    setColour(green);
    fillRect(0, 0, CELL_SIZE, CELL_SIZE);
    fillRect((GRID_SIZE - 1) * CELL_SIZE, (GRID_SIZE - 1) * CELL_SIZE, CELL_SIZE, CELL_SIZE);
}


static void drawRobot(void)
{
    int pixelX = getRobotX() * CELL_SIZE;
    int pixelY = getRobotY() * CELL_SIZE;

    int margin = CELL_SIZE / 10;

    int left = pixelX + margin;
    int right = pixelX + CELL_SIZE - margin;
    int top = pixelY + margin;
    int bottom = pixelY + CELL_SIZE - margin;

    int centreX = pixelX + CELL_SIZE / 2;
    int centreY = pixelY + CELL_SIZE / 2;

    int px[3];
    int py[3];

    switch (getRobotOrientation())
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

void draw2DWorld(void)
{
    drawGrid();
    drawMaze();
    drawRobot();
}