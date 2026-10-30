#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>

void initialiseMaze(void);
void drawMaze(void);
bool isWall(int row, int col);

#endif