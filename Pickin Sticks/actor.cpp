#include "actor.h"

//-------------------------
/* Public access members */
//-------------------------

Actor::Actor() {
	//
}

Actor::~Actor() {
	//
}

void Actor::LoadImage(const char* fname, int framecount, time_t interval) {
	//load the sprite
	spr.LoadSurface(fname);

	//Animator can handle a 0 framecount, but setting the width below can't
	if (!framecount)
		framecount = 1;

	//assuming a horizontal spritesheet, but that isn't a necessity
	spr.SetClipW( spr.GetSurface()->w / framecount );

	//set the animator
	ani.SetFrameCount( framecount );
	ani.SetInterval( interval );

	//set the BBox
	box.w = spr.GetClipW();
	box.h = spr.GetClipH();
}

void Actor::DrawTo(SDL_Surface* const pDest) {
	//set the current frame
	spr.SetClipX( ani.GetFrame() * spr.GetClipW() );

	//draw to the correct pos
	spr.DrawTo(pDest, (int)pos.x, (int)pos.y);
}

void Actor::Update(int delta) {
	//this updates the position smoothly
	pos += mot * delta;

	//update the frame
	//Animator does not care how many frames have passed, only how many milliseconds
	ani.Update();
}

BBox Actor::GetRealBox(int16_t x, int16_t y, uint16_t w, uint16_t h) {
	return BBox(box.x + (int16_t)pos.x + x, box.y + (int16_t)pos.y + y, box.w + w, box.h + h);
}