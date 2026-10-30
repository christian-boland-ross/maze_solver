#include "render2d.h"
#include "config.h"
#include "graphics.h"

void drawGrid(void)
{
    //Grid is always 200x200 pixels, displayed in top left corner of window
    const int CELL_SIZE = 200/GRID_SIZE;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            int x = j * CELL_SIZE;
            int y = i * CELL_SIZE;

            drawRect(x, y, CELL_SIZE, CELL_SIZE);
        }
    }
}