#pragma once
#include <math/Vector2.h>

using namespace KamataEngine;

class Particle
{
private:
	Particle();

	~Particle();

	void Initialize(Vector2 position);

	void Update();

	void Draw();

public:
	Vector2 position_;

	Vector2 velocity_;
};

