#include "render2d.h"
#include "config.h"
#include "graphics.h"
#include "maze.h"

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

void draw2DWorld(void)
{
    drawGrid();
    drawMaze();
}