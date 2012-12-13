/* File Name: pickin_sticks.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): ...
 * Copyright: ...
 * Description: ...
*/
#ifndef KR_PICKINSTICKS_H_
#define KR_PICKINSTICKS_H_

#include "scene.h"

#include "actor.h"
#include "stick.h"

#include "Codebase/image.h"

class PickinSticks : public Scene {
public:
	/* Public access members */
	PickinSticks();
	virtual ~PickinSticks();

protected:
	/* Frame loop */
	virtual void FrameStart();
	virtual void FrameEnd();
	virtual void Update();
	virtual void Render(SDL_Surface* const);

	/* Event handlers */
	virtual void MouseMotion		(SDL_MouseMotionEvent const&);
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&);
	virtual void KeyDown			(SDL_KeyboardEvent const&);
	virtual void KeyUp				(SDL_KeyboardEvent const&);

	/* Members */
	Actor player;
	Stick stick;

	Image grass;

	int score;
};

#endif
