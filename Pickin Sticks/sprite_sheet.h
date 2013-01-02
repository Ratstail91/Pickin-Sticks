#ifndef KR_SPRITESHEET_H_
#define KR_SPRITESHEET_H_

#include "SDL.h"

#include "Codebase/image.h"
#include "Codebase/animator.h"

class SpriteSheet : public Image {
public:
	/* Public access members */
	SpriteSheet();
	virtual ~SpriteSheet();

	void Update();

	void LoadSurface(const char* fname, Uint16 width = 0, Uint16 height = 0);
	void SetSurface(SDL_Surface* surface, Uint16 width = 0, Uint16 height = 0);

	virtual void DrawTo(SDL_Surface* const, Sint16 x, Sint16 y);

	Uint16 SetWidth(Uint16);
	Uint16 SetHeight(Uint16);
	Uint16 GetWidth();
	Uint16 GetHeight();

	/* Animation control */
	Uint16 SetIndex(Uint16);
	Uint16 SetFrame(Uint16);
	Uint16 SetDelay(Uint16);
	Uint16 SetIndex();
	Uint16 SetFrame();
	Uint16 SetDelay();

	bool SetActive(bool);
	bool GetActive();

private:
	/* Private access members */
	Animator animator;

	/* Disallow these members */
	Image::LoadSurface;
	Image::SetSurface;

	Image::SetClip;
	Image::GetClip;

	Image::SetClipX;
	Image::SetClipY;
	Image::SetClipW;
	Image::SetClipH;

	Image::GetClipX;
	Image::GetClipY;
//	Image::GetClipW;
//	Image::GetClipH;
};

#endif
