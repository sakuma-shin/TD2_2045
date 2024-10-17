#pragma once
#include <math/Vector2.h>
#include <cstdint>

using namespace KamataEngine;

class Particle
{
public:
	Particle();

	~Particle();

	void Initialize(Vector2 position);

	void Update();

	void Draw();

private:
	Vector2 position_ = { 0,0 };

	Vector2 velocity_ = { 0,0 };

};

