#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "window.h"


void update(windowattr* win, game_inst* g) {


    if(win->active) return;
    while(!WindowShouldClose()) {

        switch (GetKeyPressed()) {
            case KEY_UP:
                printf("UP\n");
                move_up(g);
                break;
            case KEY_DOWN:
                printf("DOWN\n");
                move_down(g);
                break;
            case KEY_LEFT:
                printf("LEFT\n");
                move_left(g);
                break;
            case KEY_RIGHT:

                break;
            default:
                break;
        }

        BeginDrawing();
        win->active = true;

        ClearBackground(RAYWHITE);
        draw_grid(g);

        EndDrawing();
    }
    win->active = false;

}

void print_board(const game_inst* instance) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            printf("%4d ", instance->values[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    windowattr win = create_window(700, 700, "Hello World", 60);
    game_inst g = {
        .values = {
            {2, 0, 2, 2},
            {2, 2, 2, 0},
            {0, 0, 2, 2},
            {2, 2, 0, 0}
        }
    };

    /*printf("Before move_up:\n");
    print_board(&g);

    move_up(&g);

    printf("After move_up:\n");
    print_board(&g);*/

    update(&win, &g);

    return 0;
}


