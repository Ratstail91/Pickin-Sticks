#include "stick.h"
#include <stdlib.h>

Stick::Stick() {
	//
}

Stick::~Stick() {
	//
}

Image* Stick::GetImage() {
	return &image;
}

BBox* Stick::GetBBox() {
	return &bbox;
}

Vector2* Stick::GetPosition() {
	return &position;
}

void Stick::RandomizePosition(int w, int h) {
	position.x = rand() % (w - image.GetClipW());
	position.y = rand() % (h - image.GetClipH());
}
