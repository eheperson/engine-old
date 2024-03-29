/*
    common game objects and common game structures definitions

	TODO  changes :
	app > essence or realm ????
	entity > esse ???

	TODO 
	the architecture will be spited to four:
		app <struct>
		world <struct>
		esse <struct> (entity)
		esseChain <struct>
*/
#ifndef _ARCHITECT_H
#define _ARCHITECT_H

#include <iostream>
#include <string>
#include <cstring>

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

#include "SDL_image.h"

using namespace std;

// #define SCREEN_WIDTH 1280
// #define SCREEN_HEIGHT 720
// #define PLAYER_IMG_PATH "./gfx/player.png"
// #define APP_NAME "testAPP"
// #define RENDERER_FLAGS SDL_RENDERER_ACCELERATED
// #define WINDOW_FLAGS SDL_WINDOW_SHOWN

void architectTest(void);

// The App struct will hold references to our renderer and window

typedef struct{
    char *appName; // shooter
	int screenWidth; // SCREEN_WIDTH
	int screenHeight; // SCREEN_HEIGHT
	int rendererFlags; //SDL_RENDERER_ACCELERATED
	int windowFlags; // SDL_WINDOW_SHOWN
	SDL_Renderer *renderer;
	SDL_Window *window;
	void init(void);
	void presentScene(void);
	void prepareScene(void);
	void build(void);
	void kill(void);
}App;

typedef struct Entity Entity;
struct Entity{
	char *entityName;
	char *imgPath;

	SDL_Texture *texture;

	int x;
	int y;
	int w;
	int h;

	int dy;
	int dx;

	int fire;
	int health;
	int reload;

	Entity *next;

	void init(void);
	void kill(void);
};

typedef struct EntityList EntityList;
struct EntityList{
	Entity *entity_;
	Entity head;
	Entity *tail;
	
	void init(void);
	void insert(int x_, int y_, int w_, int h_);
};

extern SDL_Texture *loadTexture(char *filename, App *app_);
extern void blit(Entity *entity_, App *app_);

void fireBullets(Entity *player_, Entity *bullet_, EntityList *blist_);
void doBullets(EntityList *blist_);

void drawBullets(EntityList *blist_, App *app_);


#endif