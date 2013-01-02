#include "sprite_sheet.h"

//-------------------------
/* Public access members */
//-------------------------

SpriteSheet::SpriteSheet() {
	//
}

SpriteSheet::~SpriteSheet() {
	//
}

void SpriteSheet::Update() {
	animator.Update();
}

void SpriteSheet::LoadSurface(const char* fname, Uint16 width, Uint16 height) {
	//This was ripped from Actor
	Image::LoadSurface(fname);

	SetWidth(width);
	SetHeight(height);
}

void SpriteSheet::SetSurface(SDL_Surface* surface, Uint16 width, Uint16 height) {
	//This was ripped from Actor
	Image::SetSurface(surface);

	SetWidth(width);
	SetHeight(height);
}

void SpriteSheet::DrawTo(SDL_Surface* const dest, Sint16 x, Sint16 y) {
	//This was ripped from Actor
	//set the current frame
	Image::SetClipX(animator.GetFrame() * Image::GetClipW());

	//draw to the correct pos, and hook the camera
	Image::DrawTo(dest, x, y);
}

Uint16 SpriteSheet::SetWidth(Uint16 w) {
	//This was ripped from Actor
	//set the values
	Image::SetClipW( w ? w : Image::GetSurface()->w );

	//adjust the spritesheet
	animator.SetFrameCount( w ? Image::GetSurface()->w / w : 0 );

	return Image::GetClipW();
}

Uint16 SpriteSheet::SetHeight(Uint16 h) {
	//This was ripped from Actor
	//set the values
	Image::SetClipH( h ? h : Image::GetSurface()->h );

	//reset the sprite index (lazy)
	Image::SetClipY( 0 );

	return Image::GetClipH();
}

Uint16 SpriteSheet::GetWidth() {
	return Image::GetClipW();
}

Uint16 SpriteSheet::GetHeight() {
	return Image::GetClipY();
}

//-------------------------
//Animation control
//-------------------------

Uint16 SpriteSheet::SetIndex(Uint16) {
	//
}

Uint16 SpriteSheet::SetFrame(Uint16) {
	//
}

Uint16 SpriteSheet::SetDelay(Uint16) {
	//
}

Uint16 SpriteSheet::SetIndex() {
	//
}

Uint16 SpriteSheet::SetFrame() {
	//
}

Uint16 SpriteSheet::SetDelay() {
	//
}

bool SpriteSheet::SetActive(bool) {
	//
}

bool SpriteSheet::GetActive() {
	//
}
