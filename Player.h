#pragma once

#include <cstdint>
#include <Novice.h>
#include <KamataEngine.h>
#include "Hit.h"
#include "Color.h"

struct Particle {
	Vector2 pos;
	Vector2 vel;
	int deathTime;
	bool isDead;
	unsigned int alpha;
};

class Player
{
public:
	Player();

	~Player();

	void Initialize();

	void Update(char* keys, char* preKeys);

	void Draw(float scroll);

	uint32_t GetTime();

	Corners GetCorners();

	Vector2 GetPos();

	float GetSpeed();

	void ParticleInitialize(Vector2 position);

	void ParticleUpdate();

	void ParticleDraw(float scroll);
private:

	float startJumpPower_ = 0;

	float playerJumpPower_ = 0;

	uint32_t textureHandle_ = Novice::LoadTexture("./NoviceResources/white1x1.png");

	uint32_t pushTime_ = 0;

	const uint32_t maxPushTime_ = 100;;

	float moveSpeed_ = 7.5f;

	Vector2 playerPos_ = { 20,690 };

	Corners playerCorner_;

	uint32_t downPower_ = 2;

	bool isHold_ = false;

	bool isJump_ = false;

	bool oneMoreJump_ = false;

	bool isGround_ = true;

	bool isParticle = false;

	int particleNum;

	Particle particle[15];

	Color* color_ = nullptr;
};