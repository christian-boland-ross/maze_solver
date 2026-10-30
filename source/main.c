#include "graphics.h"
#include "render2d.h"
#include "render3d.h"
#include "config.h"
#include "maze.h"

int main(void)
{
    setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    initialiseMaze();

    draw3DWorld();
    draw2DWorld();

    return 0;
}