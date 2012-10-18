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
	//TODO animator needs to be revised in codebase to use the delta

	//if motion is zero (TODO this is temporary, see Pseudocode.txt for details)
	if (m_motion.x == 0 && m_motion.y == 0) {
		//stop the sprite animation
		m_animator.SetInterval( 0 );
		m_animator.SetFrame( 0 );
	}

	//move
	m_position += m_motion * delta;
	m_animator.Update();
}

//-------------------------
//Sprite management
//-------------------------

void Actor::LoadSprite(const char* fname, Uint16 width, Uint16 height) {
	//load the file
	m_image.LoadSurface(fname);

	/* Note: This used to be similar to the zeroing system in UnloadSprite(),
	 * but I changed it for simplicity.
	*/
	SetWidth( width );
	SetHeight( height );
}

void Actor::SetSprite(SDL_Surface* surface, Uint16 width, Uint16 height) {
	//load the file
	m_image.SetSurface(surface);

	/* Note: This used to be similar to the zeroing system in UnloadSprite(),
	 * but I changed it for simplicity.
	*/
	SetWidth( width );
	SetHeight( height );
}

void Actor::UnloadSprite() {
	m_image.UnloadSurface();

	//zero the values of the actor
	SDL_Rect zeroclip = {0, 0, 0, 0};

	m_image.SetClip(zeroclip);
	*reinterpret_cast<SDL_Rect*>(&m_bbox) = zeroclip;

	m_animator.SetFrameCount( 0 );
}

Uint16 Actor::SetWidth(Uint16 w) {
	//set the values
	m_image.SetClipW( w );
	m_bbox.w = w;

	//adjust the spritesheet
	m_animator.SetFrameCount( (w > 0) ? m_image.GetSurface()->w / w : 0 );

	return m_image.GetClipW();
}

Uint16 Actor::SetHeight(Uint16 h) {
	//set the values
	m_image.SetClipH( h );
	m_bbox.h = h;

	//reset the sprite index (lazy)
	m_image.SetClipY( 0 );

	return m_image.GetClipH();
}

Uint16 Actor::GetWidth() {
	return m_image.GetClipW();
}

Uint16 Actor::GetHeight() {
	return m_image.GetClipH();
}

Uint16 Actor::SetSpriteIndex(Uint16 index) {
	//zero the frame
	m_image.SetClipX( 0 );
	m_animator.SetFrame( 0 );

	//set the index
	m_image.SetClipY( index * m_image.GetClipH() );

	return GetSpriteIndex();
}

Uint16 Actor::GetSpriteIndex() {
	return (m_image.GetClipH() > 0) ? m_image.GetClipY() / m_image.GetClipH() : 0;
}

Uint16 Actor::SetSpriteSpeed(Uint16 fps) {
	m_animator.SetInterval( (fps > 0) ? 1000 / fps : 0 );

	return GetSpriteSpeed();
}

Uint16 Actor::GetSpriteSpeed() {
	return (m_animator.GetInterval() > 0) ? 1000 / (Uint16)m_animator.GetInterval() : 0;
}

void Actor::DrawTo(SDL_Surface* dest, int camX, int camY) {
	//set the current frame
	m_image.SetClipX( m_animator.GetFrame() * m_image.GetClipW() );

	//draw to the correct pos, and hook the camera
	m_image.DrawTo(dest, (int)m_position.x + camX, (int)m_position.y + camY);
}

//-------------------------
//Bounding Box Management
//-------------------------

BBox Actor::GetWorldBBox() {
	return m_bbox.Tweak( (int16_t)m_position.x, (int16_t)m_position.y, 0, 0);
}

BBox Actor::SetRawBBox(BBox b) {
	return m_bbox = b;
}

BBox Actor::GetRawBBox() {
	return m_bbox;
}

//-------------------------
//Position management
//-------------------------

Vector2 Actor::SetPosition(Vector2 v) {
	return m_position = v;
}

Vector2 Actor::SetPosition(double x, double y) {
	m_position.x = x;
	m_position.y = y;

	return m_position;
}

double Actor::SetX(double x) {
	return m_position.x = x;
}

double Actor::SetY(double y) {
	return m_position.y = y;
}

double Actor::ShiftX(double x) {
	return m_position.x += x;
}

double Actor::ShiftY(double y) {
	return m_position.y += y;
}

double Actor::GetX() {
	return m_position.x;
}

double Actor::GetY() {
	return m_position.y;
}

//-------------------------
//Motion management
//-------------------------

Vector2 Actor::SetMotion(Vector2 v) {
	return m_motion = v;
}

Vector2 Actor::SetMotion(double x, double y) {
	m_motion.x = x;
	m_motion.y = y;

	return m_motion;
}

double Actor::SetMotionX(double x) {
	return m_motion.x = x;
}

double Actor::SetMotionY(double y) {
	return m_motion.y = y;
}

double Actor::ShiftMotionX(double x) {
	return m_motion.x += x;
}

double Actor::ShiftMotionY(double y) {
	return m_motion.y += y;
}

double Actor::GetMotionX() {
	return m_motion.x;
}

double Actor::GetMotionY() {
	return m_motion.y;
}
