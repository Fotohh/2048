#include "game.h"

void draw_grid(game_inst* instance) {

    float grid_x = 150, grid_y = 100;
    for(int i = 0; i < 4; i++) {
        for(int x = 0; x < 4; x++) {
            const Rectangle rec = {grid_x, grid_y, 50, 50};
            DrawRectangleRoundedLines(rec, 0.4f, 5, 5.0f, BLACK);
            grid_x += 60;
        }
        grid_y += 60;
        grid_x = 150;
    }

}

void handle_up(game_inst* instance, unsigned short current, const int x, const int y) {

    if(y <= 0) return;

    const unsigned short upper = instance->values[x][y-1];

    if(upper == current) {
        instance->values[x][y] = 0;
        instance->values[x][y-1] = current*2;
    }

}

void move(KeyboardKey key, game_inst* instance) {
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {

            unsigned short value = instance->values[x][y];

            switch (key) {
                case KEY_UP:

                    handle_up(instance, value, x, y);

                    break;
                default:
                    break;

            }

        }
    }
}


