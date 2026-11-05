#include "render3d.h"
#include "graphics.h"
#include "config.h"
#include "robot.h"
#include "maze.h"
#include "math.h"

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
    double angleIncrement = FOV * PI/180 / WINDOW_WIDTH;
    double robotAngle = getRobotOrientation() * PI / 2.0 - PI/2.0;

    double robotX = getRobotX() + 0.5; // the + 0.5 starts ray at the center of the robot's square
    double robotY = getRobotY() + 0.5;

    int x = -1;
    while(x < WINDOW_WIDTH)
    {
        x++;
        double rayAngle = robotAngle - FOV * PI/180 / 2.0 + (x) * angleIncrement;
        
        double rayX = robotX;
        double rayY = robotY;

        while(true)
        {
            if(isWall((int)rayY, (int)rayX))
            {
                double distance = sqrt(
                    (rayX - robotX) * (rayX - robotX) +
                    (rayY - robotY) * (rayY - robotY)
                );
                if(distance < 0.01) distance = 0.01;

                //correct the distance for the fish-eye effect
                distance *= cos(rayAngle - robotAngle);

                //calculate brightness based on distance
                double brightness = 255.0 / (1.0 + distance * 0.5);
                int r = (int)(brightness);
                int g = (int)(brightness * 0.5);
                int b = (int)(brightness * 0.5);
                setRGBColour(r, g, b);

                int wallHeight = (int)(WINDOW_HEIGHT / distance);
                int wallTop = (WINDOW_HEIGHT - wallHeight) / 2;
                int wallBottom = (WINDOW_HEIGHT + wallHeight) / 2;
                drawLine(x, wallTop, x, wallBottom);

                break;
            }

            rayX += cos(rayAngle) * 0.01;
            rayY += sin(rayAngle) * 0.01;
        }
    }
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