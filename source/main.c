#include "graphics.h"
#include "render2d.h"
#include "config.h"
#include "maze.h"

int main(void)
{
    setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    drawGrid();

    initialiseMaze();
    drawMaze();

    return 0;
}