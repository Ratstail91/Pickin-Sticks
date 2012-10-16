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
	//
}

//-------------------------
//Sprite management
//-------------------------

void Actor::LoadSprite(const char* fname, Uint16 width, Uint16 height) {
	//
}

void Actor::SetSprite(SDL_Surface* surface, Uint16 width, Uint16 height) {
	//
}

void Actor::UnloadSprite() {
	//
}

Uint16 Actor::SetWidth(Uint16) {
	//
}

Uint16 Actor::SetHeight(Uint16) {
	//
}

Uint16 Actor::GetWidth() {
	//
}

Uint16 Actor::GetHeight() {
	//
}

Uint16 Actor::SetSpriteIndex(Uint16) {
	//
}

Uint16 Actor::GetSpriteIndex() {
	//
}

Uint16 Actor::SetSpriteSpeed(Uint16) {
	//
}

Uint16 Actor::GetSpriteSpeed() {
	//
}

void Actor::DrawTo(SDL_Surface* dest, int camX, int camY) {
	//
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
