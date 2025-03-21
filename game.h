
#ifndef GRID_H
#define GRID_H

#include "raylib.h"

typedef struct game_inst {

    unsigned short values[4][4];
    unsigned int highscore;

} game_inst;



void draw_grid(game_inst* instance);

void move(KeyboardKey key, game_inst* instance);

void handle_up(game_inst* instance, unsigned short current, int x, int y);



#endif
