#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

#include "SDL_image.h"

#define MAX_KEYBOARD_KEYS 350

typedef struct{
    // SDL_Event event;
    int keyboard[MAX_KEYBOARD_KEYS];
    void doKeyUp(SDL_KeyboardEvent *event_);
    void doKeyDown(SDL_KeyboardEvent *event_);
    void doInput(void);
} InputHandler;



#endif