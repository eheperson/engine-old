#ifndef _RENDERER_H
#define _RENDERER_H

#include <iostream>
#include <cstring>
#include <string>

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

#include "SDL_image.h"

#include <architect/architect.h>



SDL_Texture *loadTexture(Entity *entity_, App *app_);

void blit(Entity *entity_, App *app_);

#endif