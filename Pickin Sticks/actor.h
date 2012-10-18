#ifndef KR_ACTOR_H_
#define KR_ACTOR_H_

#include "SDL.h"

#include "image.h"
#include "animator.h"
#include "bbox.h"
#include "vector2.h"

class Actor {
public:
	/* Public access members */
	Actor();
	~Actor();

	void Update(int delta);

	/* Sprite management */
	void LoadSprite			(const char* fname, Uint16 width, Uint16 height);
	void SetSprite			(SDL_Surface* surface, Uint16 width, Uint16 height);
	void UnloadSprite		();

	Uint16 SetWidth			(Uint16);
	Uint16 SetHeight		(Uint16);
	Uint16 GetWidth			();
	Uint16 GetHeight		();

	Uint16 SetSpriteIndex	(Uint16 index);
	Uint16 GetSpriteIndex	();

	Uint16 SetSpriteSpeed	(Uint16 fps);
	Uint16 GetSpriteSpeed	();

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

	double GetX();
	double GetY();

	/* Motion management */
	Vector2 SetMotion(Vector2);
	Vector2 SetMotion(double, double);
	double SetMotionX(double);
	double SetMotionY(double);

	double ShiftMotionX(double);
	double ShiftMotionY(double);

	double GetMotionX();
	double GetMotionY();

	//debugging
//	Image*		GetImage()		{ return &m_image; }
//	Animator*	GetAnimator()	{ return &m_animator; }
//	BBox*		GetBBox()		{ return &m_bbox; }
//	Vector2*	GetPosition()	{ return &m_position; }
//	Vector2*	GetMotion()		{ return &m_motion; }

private:
	/* Private access members */
	Image  m_image;
	Animator m_animator;
	BBox m_bbox;
	Vector2 m_position;
	Vector2 m_motion;
};

#endif
