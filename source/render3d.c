#include "render3d.h"
#include "graphics.h"
#include "config.h"

static void drawWalls(void);
static void drawSky(void);
static void drawGround(void);

void draw3DWorld(void)
{
    drawSky();
    drawGround();
    drawWalls();
}

static void drawWalls(void)
{
    //TODO
}

static void drawSky(void)
{
    setColour(blue);
    fillRect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT/2);
}

static void drawGround(void)
{
    setColour(green);
    fillRect(0,WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT/2);
}