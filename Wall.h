#pragma once
#include"ExMath.h"
#include"Hit.h"

class Wall {
public:


	void Initialize();
	void Update();
	void Draw(float scroll);

	void DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll);

	void Stage1Initialize();
	void Stage2Initialize();
	void Stage3Initialize();

	Corners PosUpdate(Vector2 pos, float width, float height);


	Corners GetCorners(int i) { return corners_[i]; }

private:

	Vector2 pos_[28];
	float width_[28];
	float height_[28];
	Corners corners_[28];

	int wallNum_ = 0;

	int GH[28] = {};

	int redWallGH= Novice::LoadTexture("./Resources/wall.png");
	int redWall2GH = Novice::LoadTexture("./Resources/wall2.png");

	int blueWallGH = Novice::LoadTexture("./Resources/bluewall.png");
	int blueWall2GH = Novice::LoadTexture("./Resources/bluewall2.png");

	float debugWidth = 1.3f;
	float debugDistance = 0.8f;
};
