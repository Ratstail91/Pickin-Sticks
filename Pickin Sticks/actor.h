#ifndef KR_ACTOR_H_
#define KR_ACTOR_H_

#include "SDL.h"

#include "Codebase/image.h"
#include "Codebase/animator.h"
#include "Codebase/bbox.h"
#include "Codebase/vector2.h"

class Actor {
public:
	/* Public access members */
	Actor();
	~Actor();

	void Update(int delta);

	/* Sprite management */
	void LoadSprite			(const char* fname, Uint16 width = 0, Uint16 height = 0);
	void SetSprite			(SDL_Surface* surface, Uint16 width = 0, Uint16 height = 0);
	void UnloadSprite		();

	Uint16 SetWidth			(Uint16);
	Uint16 SetHeight		(Uint16);
	Uint16 GetWidth			();
	Uint16 GetHeight		();

	Uint16 SetSpriteIndex	(Uint16 index);
	Uint16 GetSpriteIndex	();

	Uint16 SetSpriteSpeed	(Uint16 fps);
	Uint16 GetSpriteSpeed	();

	Uint16 SetSpriteFrame	(Uint16 frame);
	Uint16 GetSpriteFrame	();

	bool SetAnimationActive	(bool);
	bool GetAnimationActive	();

	void DrawTo				(SDL_Surface* dest, int camX = 0, int camY = 0);

	/* Bounding Box Management */
	BBox GetWorldBBox();
//	BBox GetTweakedBBox(Sint16 x, Sint16 y, Sint16 w, Sint16 h);

	//dirty modifier
	BBox SetRawBBox(BBox);
	BBox GetRawBBox();

	/* Position management */
	Vector2 SetPosition(Vector2);
	Vector2 SetPosition(double, double);
	double SetX(double);
	double SetY(double);

//	ShiftPosition();
	double ShiftX(double);
	double ShiftY(double);

	Vector2 GetPosition();
	double GetX();
	double GetY();

	/* Motion management */
	Vector2 SetMotion(Vector2);
	Vector2 SetMotion(double, double);
	double SetMotionX(double);
	double SetMotionY(double);

	double ShiftMotionX(double);
	double ShiftMotionY(double);

	Vector2 GetMotion();
	double GetMotionX();
	double GetMotionY();

private:
	/* Private access members */
	Image  image;
	Animator animator;
	BBox bbox;
	Vector2 position;
	Vector2 motion;
};

#endif
