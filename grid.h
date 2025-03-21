
#ifndef GRID_H
#define GRID_H

#include "raylib.h"

typedef struct grid {

    unsigned short values[4][4];
    unsigned int highscore;

} grid;



void draw_grid(grid* g);



#endif
