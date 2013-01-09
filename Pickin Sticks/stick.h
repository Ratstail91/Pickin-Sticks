#ifndef KR_STICK_H_
#define KR_STICK_H_

#include "Codebase/image.h"
#include "Codebase/bbox.h"
#include "Codebase/vector2.h"

class Stick {
public:
	/* Public access members */
	Stick();
	~Stick();

	/* Sprite management */
	void LoadSprite(const char* fname);
	void UnloadSprite();

	void DrawTo(SDL_Surface* dest, Sint16 camX = 0, Sint16 camY = 0);

	/* Bonding box management */
	BBox GetWorldBBox();

	/* Position management */
	Vector2 SetPosition(Vector2 v);
	Vector2 SetPosition(double x, double y);
	double SetX(double x);
	double SetY(double y);

	void RandomizePosition(int screenW, int screenH);

private:
	Image image;
	BBox bbox;
	Vector2 position;
};

#endif
