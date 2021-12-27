#include "architect.h"

void architectTest(void){
    cout << "architect lib test func" << endl;
}

void App :: init(void){
	cout << "app initialized." << endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);

	}  

    appName = "enivicivokki" ;
    screenWidth = 0;
    screenHeight = 0;
    windowFlags = 0;
    rendererFlags = 0;
};
	
void  App :: presentScene(){    
	// SDL_RenderPresent takes just one parameter - once again the renderer that we are using.
    SDL_RenderPresent(renderer);
};

void App :: prepareScene(){
	// In prepareScene, we set the colour of SDL renderer using SDL_SetRenderDrawColor. 
	// This function takes five parameters: 
	//     - the pointer to the renderer that we created in init.cpp
	//     - the R channel of the colour that we want to use (from 0 to 255, 0 being darkest and 255 being full)
	//     - the G channel of the colour that we want to use (from 0 to 255, 0 being darkest and 255 being full)
	//     - the B channel of the colour that we want to use (from 0 to 255, 0 being darkest and 255 being full)
	//     - the alpha value (0 is fully transparent whereas 255 is opaque) 
	SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
	SDL_RenderClear(renderer);
};

void App :: build(void){
	cout << "app builded." << endl;
	// create our window using SDL_CreateWindow
	window = SDL_CreateWindow(
		appName,
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		screenWidth, 
		screenHeight, 
		SDL_WINDOW_SHOWN
	);
	if (window == NULL){
		cout << "Failed to open " << screenWidth <<" x " << screenHeight << " window: " << SDL_GetError() << endl;
		SDL_Quit();
	}
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// next create the main renderer by calling SDL_CreateRenderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL){
		cout << "Failed to create renderer: " << SDL_GetError() << endl;
		exit(1);
	};
};

void App ::  kill(){
	//Destroy the renderer created above
	SDL_DestroyRenderer(renderer);

	//Destroy the window created above
	SDL_DestroyWindow(window);

	//Close all the systems of SDL initialized at the top
	SDL_Quit();
	cout << " app killed." << endl;
};

void Entity :: init(void){
	cout  << " entity initialized" << endl;
	// initialize SLD_IMG
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	entityName = "enivicivokki";
	imgPath = "enivicivokki";
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	dy = 0;
	dx = 0;
	fire = 0;
	health = 0;
	texture = NULL;
};

void Entity :: kill(void){
	// quit SDL_Image
	cout << " entity killed." << endl;
	IMG_Quit();
};
