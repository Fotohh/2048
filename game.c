#include "game.h"

#include <stdlib.h>

void draw_grid(const game_inst* instance) {

    float grid_x = 150, grid_y = 100;
    for(int i = 0; i < 4; i++) {
        for(int x = 0; x < 4; x++) {
            const Rectangle rec = {grid_x, grid_y, 80, 80};
            DrawRectangleRoundedLines(rec, 0.2f, 5, 2.0f, BLACK);
            const int value = instance->values[x][i];
            char str[5];
            itoa(value, str, 10);
            DrawText(str, grid_x + 20, grid_y + 10, 30, BLACK);
            grid_x += 90;

        }
        grid_y += 90;
        grid_x = 150;
    }

}

void move_down(game_inst* instance) {
    for(int x = 0; x < 4; x++) {
        int lower_bound = 3;
        int lower_value = instance->values[x][3];
        for(int y = 2; y >= 0; y--) {
            const int current_value = instance->values[x][y];
            if(current_value ==  EMPTY_SQUARE) continue;
            if(lower_bound <= 1) break;

            if(lower_value == EMPTY_SQUARE) {
                instance->values[x][lower_bound] = current_value;
                instance->values[x][y] = EMPTY_SQUARE;
                lower_value = current_value;
            }else if(lower_value == current_value) {
                instance->values[x][lower_bound] *= 2;
                instance->values[x][y] = EMPTY_SQUARE;
                lower_value *=2;
            }else if(lower_value != current_value){
                lower_bound--;
                instance->values[x][y] = EMPTY_SQUARE;
                instance->values[x][lower_bound] = current_value;
                lower_value = current_value;
            }
        }
    }
}

void move_up(game_inst* instance) {
    for(int x = 0; x < 4; x++) {
        int top_bound = 0;
        int top_value = instance->values[x][0];

        for(int y = 1; y < 4; y++) {
            const int current_value = instance->values[x][y];
            if(current_value == EMPTY_SQUARE) continue;
            if(top_bound >= 2) break;

            if(top_value == EMPTY_SQUARE) {
                instance->values[x][top_bound] = current_value;
                instance->values[x][y] = EMPTY_SQUARE;
                top_value = current_value;
            }else if(top_value == current_value) {
                instance->values[x][top_bound] *= 2;
                instance->values[x][y] = EMPTY_SQUARE;
                top_value *=2;
            }else if(top_value != current_value){
                top_bound++;
                instance->values[x][y] = EMPTY_SQUARE;
                instance->values[x][top_bound] = current_value;
                top_value = current_value;
            }
        }
    }
}

void move_left(game_inst* instance) {
    for(int y = 0; y < 4; y++) {
        int left_bound = 0;
        int left_value = instance->values[0, y];
        for(int x = 1; x < 4; x++) {

            const int current_value = instance->values[x][y];
            if(current_value == EMPTY_SQUARE) continue;
            if(left_bound >= 2) break;

            if(left_value == EMPTY_SQUARE) {
                instance->values[x][left_bound] = current_value;
                instance->values[x][y] = EMPTY_SQUARE;
                left_value = current_value;
            }else if(left_value == current_value) {
                instance->values[x][left_bound] *= 2;
                instance->values[x][y] = EMPTY_SQUARE;
                left_value *=2;
            }else if(left_value != current_value){
                left_bound++;
                instance->values[x][y] = EMPTY_SQUARE;
                instance->values[x][left_bound] = current_value;
                left_value = current_value;
            }

        }
    }
}

void move(const KeyboardKey key, game_inst* instance) {
    switch (key) {
        case KEY_UP:
            move_up(instance);
        break;
        case KEY_DOWN:
            //handle_mvmt(instance, DOWN);
        break;
        case KEY_LEFT:
            //handle_mvmt(instance, LEFT);
        break;
        case KEY_RIGHT:
            //handle_mvmt(instance, RIGHT);
        break;
        default:
            break;

    }
}


