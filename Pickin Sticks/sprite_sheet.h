#ifndef KR_SPRITESHEET_H_
#define KR_SPRITESHEET_H_

#include "SDL.h"

#include "Codebase/image.h"

class SpriteSheet : public Image {
public:
	/* Public access members */
	SpriteSheet();
	~SpriteSheet();

	void LoadSurface(const char* fname, Uint16 width = 0, Uint16 height = 0);
	void SetSurface(SDL_Surface* surface, Uint16 width = 0, Uint16 height = 0);

	virtual void DrawTo(SDL_Surface* const, Sint16 x, Sint16 y);

private:
	/* Private access members */
	//...

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
	Image::GetClipW;
	Image::GetClipH;
};

#endif
