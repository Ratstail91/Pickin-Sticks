#ifndef KR_ACTOR_H_
#define KR_ACTOR_H_

#include "SDL.h"

#include "image.h"
#include "animator.h"
#include "bbox.h"
#include "vector2.h"

class Actor {
	Image		spr;
	Animator	ani;
	BBox		box;
	Vector2		pos;
	Vector2		mot;

public:
	Actor();
	//...?
	~Actor();

	//this updates the various elements of the actor
	//this should be called ONCE per loop
	//delta is for synced motion between different actors
	void Update(int delta);

	//sprite manipulation
	//also handles the bounding box, and resets the animator?
	//returns 0 on success, 1 on error
	int LoadSprite		(const char* fname, Uint16 width = 0, Uint16 height = 0);
	int SetSprite		(Image*); //direct copy: not local, set clip, compensate BBox
	int SetSprite		(SDL_Surface*, Uint16 width = 0, Uint16 height = 0);
	void UnloadSprite	();

	//handles the width & height of the actor, and adjusts the bounding box
	Uint16 SetWidth		(Uint16 w);
	Uint16 SetHeight	(Uint16 h);
	Uint16 GetWidth		();
	Uint16 GetHeight	();

	//assume this system:
	//    animation along the X of the spritesheet
	//    different sprites (up,down,left,right) along the Y of the spritesheet
	Uint16 SetSpriteIndex	(Uint16 i); //can use macros
	Uint16 SetSpriteSpeed	(Uint16 s);
	Uint16 GetSpriteIndex	();
	Uint16 GetSpriteSpeed	();

	//draw to the screen, and compensate for any camera input
	void DrawTo(SDL_Surface* dest, int camX, int camY);

	//this handles minor tweaks to the edges of the bounding box
	//these are signed, and passed into the box's tweak function
	BBox GetRealBBox(Sint16 x, Sint16 y, Sint16 w, Sint16 h);

	//the positon is handled by a 2D vector
	Vector2 SetPosition		(double x, double y);
	Vector2 SetPosition		(Vector2 newpos);
	double SetX				(double x);
	double SetY				(double y);
	Vector2 ShiftPosition	(double xdir, double ydir);
	Vector2 ShiftPosition	(Vector2 dir);
	double ShiftX			(double xdir);
	double ShiftY			(double ydir);
	Vector2 GetPosition		();
	double GetX				();
	double GetY				();

	//the motion is handled by a 2D vector
	Vector2 SetMotion		(double x, double y);
	Vector2 SetMotion		(Vector2 newpos);
	double SetMotionX		(double x);
	double SetMotionY		(double y);
	Vector2 ShiftMotion		(double xdir, double ydir);
	Vector2 ShiftMotion		(Vector2 dir);
	double ShiftMotionX		(double xdir);
	double ShiftMotionY		(double ydir);
	Vector2 GetMotion		();
	double GetMotionX		();
	double GetMotionY		();

	//OO breaker (deprecated) get pointers to the members
//	Image*		GetSpr() { return &spr; }
//	Animator*	GetAni() { return &ani; }
//	BBox*		GetBox() { return &box; }
//	Vector2*	GetPos() { return &pos; }
//	Vector2*	GetMot() { return &mot; }
};

#endif
