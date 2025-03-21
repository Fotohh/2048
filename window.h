#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"

typedef struct windowattr{

    int width;
    int height;
    const int fps;
    const char* title;
    bool active;

} windowattr;

windowattr create_window(int width, int height, const char* title, int fps);

#endif