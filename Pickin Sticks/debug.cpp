#include <exception>
#include <iostream>
#include "SDL.h"
using namespace std;

#include "delta.h"

#include "actor.h"

#define SPRITE_UP 1
#define SPRITE_DOWN 0
#define SPRITE_LEFT 2
#define SPRITE_RIGHT 3

#define SPEED 0.14
#define FRAME_SPEED 30

int main(int, char**) {
	SDL_Surface* screen = NULL;

	if (SDL_Init(0) || ( screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE) ) == NULL) {
		cerr << "Failed to init SDL" << endl;
	}

	//test the actor
	Actor actor;

	try {
		cout << "Running debug output" << endl;

		actor.LoadSprite("elliot2.bmp", 32, 48);
		actor.SetSpriteSpeed( 30 );

		cout << "Width: " << actor.GetWidth() << endl;
		cout << "Height: " << actor.GetHeight() << endl;

		cout << "Sprite Index: " << actor.GetSpriteIndex() << endl;
		cout << "Sprite Speed: " << actor.GetSpriteSpeed() << endl;

		cout << "X: " << actor.GetX() << endl;
		cout << "Y: " << actor.GetY() << endl;

		cout << "Motion X: " << actor.GetMotionX() << endl;
		cout << "Motion Y: " << actor.GetMotionY() << endl;
	}
	catch(exception& e) {
		cerr << "Error: " << e.what() << endl;
		cerr << "SDL: " << SDL_GetError() << endl;
		
		actor.UnloadSprite();

		return 1;
	}

	bool running = true;
	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					running = false;
					break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_ESCAPE:
							running = false;
							break;

						case SDLK_UP:
							if (actor.GetMotionY() - SPEED >= -SPEED) {
								actor.ShiftMotionY(-SPEED);
								actor.SetSpriteIndex(SPRITE_UP);
							}
							break;

						case SDLK_DOWN:
							if (actor.GetMotionY() + SPEED <= SPEED) {
								actor.ShiftMotionY(SPEED);
								actor.SetSpriteIndex(SPRITE_DOWN);
							}
							break;

						case SDLK_LEFT:
							if (actor.GetMotionX() - SPEED >= -SPEED) {
								actor.ShiftMotionX(-SPEED);
								actor.SetSpriteIndex(SPRITE_LEFT);
							}
							break;

						case SDLK_RIGHT:
							if (actor.GetMotionX() + SPEED <= SPEED) {
								actor.ShiftMotionX(SPEED);
								actor.SetSpriteIndex(SPRITE_RIGHT);
							}
							break;
					}
					break;

				case SDL_KEYUP:
					switch(event.key.keysym.sym) {
						case SDLK_UP:
							if (actor.GetMotionY() + SPEED <= 0)
								actor.ShiftMotionY(SPEED);
							else
								actor.SetMotionY(0);
							break;

						case SDLK_DOWN:
							if (actor.GetMotionY() - SPEED >= 0)
								actor.ShiftMotionY(-SPEED);
							else
								actor.SetMotionY(0);
							break;

						case SDLK_LEFT:
							if (actor.GetMotionX() + SPEED <= 0)
								actor.ShiftMotionX(SPEED);
							else
								actor.SetMotionX(0);
							break;

						case SDLK_RIGHT:
							if (actor.GetMotionX() - SPEED >= 0)
								actor.ShiftMotionX(-SPEED);
							else
								actor.SetMotionX(0);
							break;
					}
					break;
			}
		}

		//update all of the elements of the game
		Delta::CalcDelta();

		actor.Update(Delta::GetDelta());

		//render the game
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		actor.DrawTo(screen);
		SDL_Flip(screen);
	}

	actor.UnloadSprite();
	SDL_Quit();
	return 0;
}
