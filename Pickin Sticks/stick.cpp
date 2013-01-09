#include "stick.h"
#include <stdlib.h>

//-------------------------
/* Public access members */
//-------------------------

Stick::Stick() {
	//
}

Stick::~Stick() {
	//
}

//-------------------------
/* Sprite management */
//-------------------------

void Stick::LoadSprite(const char* fname) {
	image.LoadSurface(fname);

	bbox.w = image.GetClipW();
	bbox.h = image.GetClipH();
}

void Stick::UnloadSprite() {
	image.UnloadSurface();

	bbox.w = 0;
	bbox.h = 0;
}

void Stick::DrawTo(SDL_Surface* dest, Sint16 camX, Sint16 camY) {
	image.DrawTo(dest, (Sint16)position.x + camX, (Sint16)position.y + camY);
}

//-------------------------
/* Bonding box management */
//-------------------------

BBox Stick::GetWorldBBox() {
	return bbox.Tweak( (int16_t)position.x, (int16_t)position.y, 0, 0);
}

//-------------------------
/* Position management */
//-------------------------

Vector2 Stick::SetPosition(Vector2 v) {
	return position = v;
}

Vector2 Stick::SetPosition(double x, double y) {
	position.x = x;
	position.y = y;

	return position;
}

double Stick::SetX(double x) {
	return position.x = x;
}

double Stick::SetY(double y) {
	return position.y = y;
}

void Stick::RandomizePosition(int screenW, int screenH) {
	position.x = rand() % (screenW - image.GetClipW());
	position.y = rand() % (screenH - image.GetClipH());
}
