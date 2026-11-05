#include "render3d.h"
#include "graphics.h"
#include "config.h"
#include "robot.h"
#include "maze.h"
#include "math.h"

static void drawWalls(void);
static void drawSky(void);
static void drawGround(void);
static void drawColumn(double distance, int x, bool side);

void draw3DWorld(void)
{
    drawSky();
    drawGround();
    drawWalls();
}

static void drawWalls(void)
{
    double angleIncrement = FOV * PI/180 / WINDOW_WIDTH;
    double robotAngle = getRobotOrientation() * PI / 2.0 - PI/2.0;
    double rayAngle = robotAngle - FOV * PI/180 / 2.0;

    double robotX = getRobotX() + 0.5; // the + 0.5 starts ray at the center of the robot's square
    double robotY = getRobotY() + 0.5;

    int x = -1;
    while(x < WINDOW_WIDTH)
    {
        x++;
        
        double rayDirX = cos(rayAngle);
        double rayDirY = sin(rayAngle);

        double deltaDistX = (rayDirX == 0) ? 1e30 : absolute(1.0 / rayDirX); // avoid division by zero
        double deltaDistY = (rayDirY == 0) ? 1e30 : absolute(1.0 / rayDirY);

        int stepX = (rayDirX < 0) ? -1 : 1;
        int stepY = (rayDirY < 0) ? -1 : 1;

        int mapX = getRobotX();
        int mapY = getRobotY();

        double sideDistX;
        double sideDistY;

        if(stepX < 0)
            sideDistX = (robotX - mapX) * deltaDistX;
        else
            sideDistX = (mapX + 1.0 - robotX) * deltaDistX;

        if(stepY < 0)
            sideDistY = (robotY - mapY) * deltaDistY;
        else
            sideDistY = (mapY + 1.0 - robotY) * deltaDistY;

        bool side; // 0 for vertical, 1 for horizontal

        // DDA algorithm: https://lodev.org/cgtutor/raycasting.html
        while(!isWall(mapY, mapX))
        {
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
        }

        double distance;
        if(side == 0)
            distance = sideDistX - deltaDistX;
        else
            distance = sideDistY - deltaDistY;

        //correct the distance for the fish-eye effect
        distance *= cos(rayAngle - robotAngle);

        drawColumn(distance, x, side);

        rayAngle += angleIncrement;
    }
}

static void drawColumn(double distance, int x, bool side)
{
    if(distance < 0.01)
        distance = 0.01;

    //calculate brightness based on distance
    double brightness = 255.0 / (1.0 + distance * 0.5);

    if(side == 1)
        brightness *= 0.7;

    int r = (int)(brightness);
    int g = (int)(brightness * 0.5);
    int b = (int)(brightness * 0.5);
    setRGBColour(r, g, b);

    int wallHeight = (int)(WINDOW_HEIGHT / distance);
    int wallTop = (WINDOW_HEIGHT - wallHeight) / 2;
    int wallBottom = (WINDOW_HEIGHT + wallHeight) / 2;
    drawLine(x, wallTop, x, wallBottom);
}

static void drawSky(void)
{
    for(int i = 0; i < WINDOW_HEIGHT/2; i++)
    {
        int r = 135 + (120 * i / (WINDOW_HEIGHT/2));
        int g = 205 + (50 * i / (WINDOW_HEIGHT/2));
        int b = 235 + (20 * i / (WINDOW_HEIGHT/2));
        setRGBColour(r, g, b);
        drawLine(0, i, WINDOW_WIDTH, i);
    }
}

static void drawGround(void)
{
    for(int i = WINDOW_HEIGHT/2; i < WINDOW_HEIGHT; i++)
    {
        int shade = 20 + (80 * (i - WINDOW_HEIGHT/2) / (WINDOW_HEIGHT/2));

        setRGBColour(shade, shade, shade);
        drawLine(0, i, WINDOW_WIDTH, i);
    }
}