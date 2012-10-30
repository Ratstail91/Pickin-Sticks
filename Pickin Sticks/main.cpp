#include <exception>
#include <iostream>
#include "SDL.h"
using namespace std;

#include "delta.h"
#include "actor.h"

int SDL_main(int, char**) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "Failed to init SDL" << endl;
		return 1;
	}

	SDL_Surface* screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);

	if (screen == NULL) {
		cerr << "Failed to init the screen" << endl;
		return 2;
	}

	Actor player, stick;
	Image grass;

	try {
		grass.LoadSurface("grass.bmp");
		stick.LoadImage("stick.bmp");
		player.LoadImage("elliot2.bmp", 4, 200);

//		player.GetSprite()->SetClipW( player.GetSprite()->GetClipW() / 4 );
//		player.GetSprite()->SetClipH( player.GetSprite()->GetClipH() / 4 );
	}
	catch(exception& e) {
		cerr << "Asset Error: " << e.what() << endl;
		return 3;
	}

	SDL_Event event;

	bool running = true;

	while(running) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					running = false;
					break;
			}
		}

		//update the actors
		Delta::CalcDelta();

		stick.Update(Delta::GetDelta());
		player.Update(Delta::GetDelta());

		//draw everything

//		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 0, 255));

		//draw the grass
		for (int i = 0; i <= screen->w / grass.GetClipW(); i++) {
			for (int j = 0; j <= screen->h / grass.GetClipH(); j++) {
				grass.DrawTo(screen, i * grass.GetClipW(), j * grass.GetClipH());
			}
		}

		stick.DrawTo(screen);
		player.DrawTo(screen);

		SDL_Flip(screen);
	}

	SDL_Quit();
	return 0;
}
