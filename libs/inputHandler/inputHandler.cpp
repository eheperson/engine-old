#include "inputHandler.h"

void InputHandler :: doKeyUp(SDL_KeyboardEvent *event_){
	if(event_->repeat == 0 && event_->keysym.scancode < MAX_KEYBOARD_KEYS)
		keyboard[event_->keysym.scancode] = 0;
}

void InputHandler :: doKeyDown(SDL_KeyboardEvent *event_){
	if(event_->repeat == 0 && event_->keysym.scancode < MAX_KEYBOARD_KEYS)
		keyboard[event_->keysym.scancode] = 1;
}

void InputHandler :: doInput(void){
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{	
		switch (event.type)
		{
			case SDL_QUIT:
				cout << " quit " << endl; 

				exit(0);
				break;

			case SDL_KEYDOWN:
				doKeyDown(&event.key);
				break;

			case SDL_KEYUP:
				doKeyUp(&event.key);
				break;

			default:
				break;
		}
	}

}