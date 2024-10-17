#include "Particle.h"
#include <stdlib.h>
#include <Novice.h>

Particle::Particle() {

}

Particle::~Particle() {

}

void Particle::Initialize(Vector2 position) {
	position_ = position;
	velocity_ = { float(rand() % 11 - 5),float(rand() % 11 - 5) };
}

void Particle::Update() {
	position_.x += velocity_.x;
	position_.y += velocity_.y;

}

void Particle::Draw() {
	Novice::DrawTriangle(int(position_.x), int(position_.y + 5), int(position_.x + 2.5f), int(position_.y - 2.5f), int(position_.x - 2.5f), int(position_.y - 2.5f), WHITE, kFillModeSolid);
}