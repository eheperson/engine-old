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
	memset(&player, 0, sizeof(Entity));
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
    bullet.health = 1;
    bullet.w = 30;
    bullet.h = 30;
    bullet.dx = 16;
    bullet.entityName = "bullet";
    bullet.imgPath = "./gfx/playerBullet.png";
    bullet.texture = loadTexture(&bullet, &app);


    InputHandler handler;
    long then;
    float remainder;
    
    
    // EntityList playerList;
    // memset(&playerList,0, sizeof(EntityList));
    // playerList.entity_ = &player;
    // playerList.init();

    EntityList bulletList;
    memset(&bulletList,0, sizeof(EntityList));
    bulletList.entity_ = &bullet;
    bulletList.init();

    while(1){
        app.prepareScene();
        handler.doInput();
        
        /* --------- DoPlayer() - Begin ------------ */
        player.dx = 0;
	    player.dy = 0;
        
        if(player.reload > 0)
		    player.reload--;

        if (handler.keyboard[SDL_SCANCODE_UP]){
            player.dy -= 4;
            cout << "up" << endl;
        }

        if (handler.keyboard[SDL_SCANCODE_DOWN]){
            player.dy += 4;
            cout << "down" << endl;
        };

        if (handler.keyboard[SDL_SCANCODE_LEFT]){
            player.dx -= 4;
            cout << "left" << endl;
        };

        if (handler.keyboard[SDL_SCANCODE_RIGHT]){
            player.dx += 4;
            cout << "right" << endl;
        };

        if (handler.keyboard[SDL_SCANCODE_Q] && player.reload == 0 ){
            cout << "fire" << endl;
            // player.fire=1;
            // fireBullets(&player, &bullet, &bulletList);

            int bullety = (player.h / 2) - (bullet.h / 2);
            int bulletx = player.x;
            int bulletw = bullet.w;
            int bulleth = bullet.h;

            bulletList.insert(bulletx, bullety, bulletw, bulleth);
            player.reload = 8;
        }
        // else
        //     player.fire=0;

        player.x += player.dx;
		player.y += player.dy;
        /* --------- DoPlayer() - End ------------ */
        doBullets(&bulletList);
        /* --------- DoBullets() - Begin ------------ */


        // if (player.fire && bullet.health == 0){
		// 	bullet.x = player.x;
		// 	bullet.y = player.y;
		// 	bullet.dx = 16;
		// 	bullet.dy = 0;
		// 	bullet.health = 1;
		// }

		// bullet.x += bullet.dx;
		// bullet.y += bullet.dy;

		// if (bullet.x > app.screenWidth){
		// 	bullet.health = 0;
		// }
        
        /* --------- DrawPlayer() - Begin ------------ */
        blit(&player, &app);
        /* --------- DrawPlayer() - End ------------ */


        /* --------- DrawBullets() - Begin ------------ */
        drawBullets(&bulletList, &app);
        /* --------- DrawBullets() - End ------------ */
    	
        // if (bullet.health > 0){
		// 	blit(&bullet, &app);
		// }
        app.presentScene();

        SDL_Delay(16);
    }
    player.kill();
    bullet.kill();
    app.kill();
    return 0;
}