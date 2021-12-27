#include <iostream>
#include <architect/architect.h>
#include <inputHandler/inputHandler.h>
#include <renderer/renderer.h>

using namespace std;

int main(){

    architectTest();
    App app;
    app.init();
    app.appName = "test";
    app.screenWidth = 1280;
    app.screenHeight = 720;
    app.windowFlags = SDL_WINDOW_SHOWN;
    app.rendererFlags = SDL_RENDERER_ACCELERATED;
    app.build();

    Entity player;
    player.init();
    player.entityName = "player";
    player.imgPath = "./gfx/player.png";
    player.x = 100;
    player.y = 100;
    player.w = 100;
    player.h = 100;
    player.texture = loadTexture(&player, &app);


    Entity bullet;
    bullet.init();
    bullet.health = 0;
    bullet.w = 30;
    bullet.h = 30;
    bullet.entityName = "bullet";
    bullet.imgPath = "./gfx/playerBullet.png";
    bullet.texture = loadTexture(&bullet, &app);


    InputHandler handler;

    
    
    while(1){
        app.prepareScene();
        handler.doInput();
        
        player.x += player.dx;
		player.y += player.dy;

        if (handler.keyboard[SDL_SCANCODE_UP]){
            player.y -= 4;
            cout << "up" << endl;
        }

        if (handler.keyboard[SDL_SCANCODE_DOWN]){
            player.y += 4;
            cout << "down" << endl;
        };

        if (handler.keyboard[SDL_SCANCODE_LEFT]){
            player.x -= 4;
            cout << "left" << endl;
        };

        if (handler.keyboard[SDL_SCANCODE_RIGHT]){
            player.x += 4;
            cout << "right" << endl;
        };

        if (handler.keyboard[SDL_SCANCODE_Q] && bullet.health == 0 ){
            cout << "fire" << endl;
            player.fire=1;
        }
        else
            player.fire=0;

        if (player.fire && bullet.health == 0){
			bullet.x = player.x;
			bullet.y = player.y;
			bullet.dx = 16;
			bullet.dy = 0;
			bullet.health = 1;
		}

		bullet.x += bullet.dx;
		bullet.y += bullet.dy;

		if (bullet.x > app.screenWidth){
			bullet.health = 0;
		}

        blit(&player, &app);
    	
        if (bullet.health > 0){
			blit(&bullet, &app);
		}
        app.presentScene();

        SDL_Delay(16);
    }
    app.kill();
    return 0;
}