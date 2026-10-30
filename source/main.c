#include "graphics.h"
#include "render2d.h"
#include "config.h"

int main(void)
{
    setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    drawGrid();

    return 0;
}