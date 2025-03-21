#include "grid.h"

#include <stdlib.h>


void draw_grid(grid* g) {

    float grid_x = 200, grid_y = 100;
    for(int i = 0; i < sizeof(g->values) / sizeof(g->values[0][0]) / 4; i++) {
        for(int x = 0; x < sizeof(g->values) / sizeof(g->values[0][0]) / 4; x++) {
            const Rectangle rec = {grid_x, grid_y, 20, 20};
            DrawRectangleRoundedLines(rec, 5.0f, 5, 10.0f, BLACK);
            grid_x += 40;
        }
        grid_y += 40;
        grid_x = 200;
    }

}
