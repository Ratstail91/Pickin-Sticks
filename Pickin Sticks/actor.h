#ifndef KR_ACTOR_H_
#define KR_ACTOR_H_

/* This Actor class can have anything at all; this is an example of how to use
 * as much of cb as possible.
*/

#include "SDL.h"

#include "image.h"
#include "animator.h"
#include "bbox.h"
#include "vector2.h"

class Actor {
public:
	/* Public access members */
	Actor();
	virtual ~Actor();

	//handle the graphical side of things
	void LoadImage(const char* fname, int framecount = 0, time_t interval = 0);
	void DrawTo(SDL_Surface* const pDest); //this can have hooks for a camera

	//update the Actor's position, based on time passed
	void Update(int delta);

	//get the bbox + world pos
	BBox GetRealBox(int16_t x = 0, int16_t y = 0, uint16_t w = 0, uint16_t h = 0);

	/* Cheap Accessors */
	Image* GetSprite()		{ return &spr; }
	Animator* GetAnimator()	{ return &ani; }
	BBox* GetBBox()			{ return &box; }
	Vector2* GetPosition()	{ return &pos; }
	Vector2* GetMotion()	{ return &mot; }

private:
	/* Private access members */
	Image spr;
	Animator ani;
	BBox box;
	Vector2 pos; //positon
	Vector2 mot; //motion
};

#endif
