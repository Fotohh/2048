
#ifndef GRID_H
#define GRID_H

constexpr int EMPTY_SQUARE = 0;
// constexpr int UP[2] = {0, -1};
// constexpr int DOWN[2] = {0, 1};
// constexpr int RIGHT[2] = {1, 0};
// constexpr int LEFT[2] = {-1, 0};

#include "raylib.h"

typedef struct game_inst {

    unsigned int values[4][4];
    unsigned int highscore;

} game_inst;

void draw_grid(const game_inst* instance);

void move(KeyboardKey key, game_inst* instance);

void move_up(game_inst* instance);

void move_down(game_inst* instance);

void move_left(game_inst* instance);

void move_right(game_inst* instance);

#endif
