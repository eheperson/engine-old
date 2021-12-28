
#include "renderer.h"


SDL_Texture *loadTexture(Entity *entity_, App *app_){
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", entity_->imgPath);

	texture = IMG_LoadTexture(app_->renderer, entity_->imgPath);

	return texture;
}

void blit(Entity *entity_, App *app_){

    SDL_Rect dest;

    dest.x = entity_->x;
	dest.y = entity_->y;
    
    SDL_QueryTexture(entity_->texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app_->renderer, entity_->texture, NULL, &dest);
};