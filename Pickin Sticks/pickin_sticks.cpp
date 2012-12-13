/* File Name: pickin_sticks.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): ...
 * Copyright: ...
 * Description: ...
*/
#include "pickin_sticks.h"

#include "Codebase/delta.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define CHAR_SPEED 0.14

//-------------------------
//Public access members
//-------------------------

PickinSticks::PickinSticks() {
	grass.LoadSurface("grass.bmp");
	player.LoadSprite("elliot2.bmp", 32, 48);
	stick.GetImage()->LoadSurface("stick.bmp");

	player.SetSpriteSpeed(20);
	player.SetAnimationActive(true);

	score = 0;

	srand((int)time(NULL));

	stick.RandomizePosition(GetScreen()->w, GetScreen()->h);
	stick.RandomizePosition(GetScreen()->w, GetScreen()->h);
	stick.RandomizePosition(GetScreen()->w, GetScreen()->h);
}

PickinSticks::~PickinSticks() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void PickinSticks::FrameStart() {
	//
}

void PickinSticks::FrameEnd() {
	//
}

void PickinSticks::Update() {
	Delta::CalcDelta();

	//update all actors
	player.Update(Delta::GetDelta());

	/* The following code should not be typed by anyone.
	 * If you find yourself with the urge to program like this, please
	 * insert the nearest available boot into your rear end
	 * (application of force is recommended).
	*/

	//collision check
	if (CheckCollision(
		player.GetWorldBBox(),
		//world BBox of the stick
		stick.GetBBox()->Tweak(
			stick.GetPosition()->x,
			stick.GetPosition()->y,
			stick.GetImage()->GetClipW(),
			stick.GetImage()->GetClipH())
		)
	) {
		//score
		stick.RandomizePosition(GetScreen()->w, GetScreen()->h);
		cout << "Score: " << (++score) << endl;
	}
}

void PickinSticks::Render(SDL_Surface* const screen) {
	//draw the grass everywhere
	for (int i = 0; i < screen->w; i += grass.GetClipW()) {
		for (int j = 0; j < screen->h; j += grass.GetClipH()) {
			grass.DrawTo(screen, i, j);
		}
	}

	player.DrawTo(screen);
	stick.GetImage()->DrawTo(screen, stick.GetPosition()->x, stick.GetPosition()->y);
}

//-------------------------
//Event handlers
//-------------------------

void PickinSticks::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void PickinSticks::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	//
}

void PickinSticks::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void PickinSticks::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;

		//character motion
		case SDLK_UP:
			player.ShiftMotionY(-CHAR_SPEED);
			break;

		case SDLK_DOWN:
			player.ShiftMotionY(CHAR_SPEED);
			break;

		case SDLK_LEFT:
			player.ShiftMotionX(-CHAR_SPEED);
			break;

		case SDLK_RIGHT:
			player.ShiftMotionX(CHAR_SPEED);
			break;
	}
}

void PickinSticks::KeyUp(SDL_KeyboardEvent const& key) {
	//character motion
	switch(key.keysym.sym) {
		case SDLK_UP:
			if (player.GetMotionY() + CHAR_SPEED <= CHAR_SPEED)
				player.ShiftMotionY(CHAR_SPEED);
			break;

		case SDLK_DOWN:
			if (player.GetMotionY() - CHAR_SPEED >= -CHAR_SPEED)
				player.ShiftMotionY(-CHAR_SPEED);
			break;

		case SDLK_LEFT:
			if (player.GetMotionX() + CHAR_SPEED <= CHAR_SPEED)
				player.ShiftMotionX(CHAR_SPEED);
			break;

		case SDLK_RIGHT:
			if (player.GetMotionX() - CHAR_SPEED >= -CHAR_SPEED)
				player.ShiftMotionX(-CHAR_SPEED);
			break;
	}
}
