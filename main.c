#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "window.h"


void update(windowattr* win, game_inst* g) {


    if(win->active) return;
    while(!WindowShouldClose()) {
        BeginDrawing();
        win->active = true;

        ClearBackground(RAYWHITE);
        draw_grid(g);

        EndDrawing();
    }
    win->active = false;

}

void on_exit() {
    printf("Exited 2048... Goodbye.");
}

int main(void) {
    windowattr win = create_window(500, 500, "Hello World", 60);
    game_inst g = {};
    update(&win, &g);
    return 0;
}


