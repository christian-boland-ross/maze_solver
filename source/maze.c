#include "maze.h"
#include "config.h"
#include "graphics.h"

static bool maze[GRID_SIZE][GRID_SIZE];

void initialiseMaze(void)
{
    // TODO: implement a maze generation algorithm
    //temporarily use a preset a 10x10 maze
    bool placeholder[10][10] = {
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,0,1,1,0,1,1,1,0},
        {0,1,0,1,0,0,0,1,0,0},
        {1,1,0,0,0,1,0,1,0,1},
        {0,1,1,1,0,1,0,1,0,0},
        {0,0,0,1,1,1,0,1,1,0},
        {0,1,0,1,0,0,0,1,0,0},
        {1,1,0,0,0,1,0,0,0,0},
        {0,1,0,1,1,1,0,1,1,0},
        {0,0,0,0,0,1,0,1,0,0}
    };

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            maze[row][col] = placeholder[row][col];
        }
    }
}

bool isWall(int row, int col)
{
    if(maze[row][col] || row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}