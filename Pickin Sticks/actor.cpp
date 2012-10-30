#include "actor.h"

//-------------------------
//Public access members
//-------------------------

Actor::Actor() {
	//
}

Actor::~Actor() {
	//
}

void Actor::Update(int delta) {
	//move
	position += motion * delta;
	animator.Update(); //animation is independant of delta
}

//-------------------------
//Sprite management
//-------------------------

void Actor::LoadSprite(const char* fname, Uint16 width, Uint16 height) {
	//load the file
	image.LoadSurface(fname);

	/* Note: This used to be similar to the zeroing system in UnloadSprite(),
	 * but I changed it for simplicity.
	*/
	SetWidth( width );
	SetHeight( height );
}

void Actor::SetSprite(SDL_Surface* surface, Uint16 width, Uint16 height) {
	//load the file
	image.SetSurface(surface);

	/* Note: This used to be similar to the zeroing system in UnloadSprite(),
	 * but I changed it for simplicity.
	*/
	SetWidth( width );
	SetHeight( height );
}

void Actor::UnloadSprite() {
	image.UnloadSurface();

	//zero the values of the actor
	SDL_Rect zeroclip = {0, 0, 0, 0};

	image.SetClip(zeroclip);
	*reinterpret_cast<SDL_Rect*>(&bbox) = zeroclip;

	animator.SetFrameCount( 0 );
}

Uint16 Actor::SetWidth(Uint16 w) {
	//set the values
	image.SetClipW( w ? w : image.GetSurface()->w );
	bbox.w = w ? w : image.GetSurface()->w;

	//adjust the spritesheet
	animator.SetFrameCount( w ? image.GetSurface()->w / w : 0 );

	return image.GetClipW();
}

Uint16 Actor::SetHeight(Uint16 h) {
	//set the values
	image.SetClipH( h ? h : image.GetSurface()->h );
	bbox.h = h ? h : image.GetSurface()->h;

	//reset the sprite index (lazy)
	image.SetClipY( 0 );

	return image.GetClipH();
}

Uint16 Actor::GetWidth() {
	return image.GetClipW();
}

Uint16 Actor::GetHeight() {
	return image.GetClipH();
}

Uint16 Actor::SetSpriteIndex(Uint16 index) {
	//zero the frame
	image.SetClipX( 0 );
	animator.SetFrame( 0 );

	//set the index
	image.SetClipY( index * image.GetClipH() );

	return GetSpriteIndex();
}

Uint16 Actor::GetSpriteIndex() {
	return (image.GetClipH() > 0) ? image.GetClipY() / image.GetClipH() : 0;
}

Uint16 Actor::SetSpriteSpeed(Uint16 fps) {
	animator.SetInterval( (fps > 0) ? 1000 / fps : 0 );

	return GetSpriteSpeed();
}

Uint16 Actor::GetSpriteSpeed() {
	return (animator.GetInterval() > 0) ? 1000 / (Uint16)animator.GetInterval() : 0;
}

void Actor::DrawTo(SDL_Surface* dest, int camX, int camY) {
	//set the current frame
	image.SetClipX( animator.GetFrame() * image.GetClipW() );

	//draw to the correct pos, and hook the camera
	image.DrawTo(dest, (int)position.x + camX, (int)position.y + camY);
}

//-------------------------
//Bounding Box Management
//-------------------------

BBox Actor::GetWorldBBox() {
	return bbox.Tweak( (int16_t)position.x, (int16_t)position.y, 0, 0);
}

BBox Actor::SetRawBBox(BBox b) {
	return bbox = b;
}

BBox Actor::GetRawBBox() {
	return bbox;
}

//-------------------------
//Position management
//-------------------------

Vector2 Actor::SetPosition(Vector2 v) {
	return position = v;
}

Vector2 Actor::SetPosition(double x, double y) {
	position.x = x;
	position.y = y;

	return position;
}

double Actor::SetX(double x) {
	return position.x = x;
}

double Actor::SetY(double y) {
	return position.y = y;
}

double Actor::ShiftX(double x) {
	return position.x += x;
}

double Actor::ShiftY(double y) {
	return position.y += y;
}

double Actor::GetX() {
	return position.x;
}

double Actor::GetY() {
	return position.y;
}

//-------------------------
//Motion management
//-------------------------

Vector2 Actor::SetMotion(Vector2 v) {
	return motion = v;
}

Vector2 Actor::SetMotion(double x, double y) {
	motion.x = x;
	motion.y = y;

	return motion;
}

double Actor::SetMotionX(double x) {
	return motion.x = x;
}

double Actor::SetMotionY(double y) {
	return motion.y = y;
}

double Actor::ShiftMotionX(double x) {
	return motion.x += x;
}

double Actor::ShiftMotionY(double y) {
	return motion.y += y;
}

double Actor::GetMotionX() {
	return motion.x;
}

double Actor::GetMotionY() {
	return motion.y;
}
