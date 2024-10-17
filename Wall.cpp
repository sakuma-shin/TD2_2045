#include "Wall.h"

void Wall::Initialize()
{
	Wall::Stage1Initialize();
}

void Wall::Update()
{
}

void Wall::Draw(float scroll)
{
	for (int i = 0;i <wallNum_ ;i++) {
		DrawQuad(corners_[i], GH, 1, 1, WHITE, scroll);
	}
}

void Wall::DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll) {
	Novice::DrawQuad(int(a.leftTop.x - scroll), int(a.leftTop.y), int(a.rightTop.x - scroll), int(a.rightTop.y), int(a.leftDown.x - scroll), int(a.leftDown.y), int(a.rightDown.x - scroll), int(a.rightDown.y), 0, 0, imageWidth, imageHeight, imageGH, color);
}

void Wall::Stage1Initialize()
{
	wallNum_ = 10;
	const float heightTotal = 800;
	const float distance = 150;
	


	for (int i = 0;i < 28;i++) {
		pos_[i] = {};
		width_[i] = {};
		height_[i] = {};
		corners_[i] = {};
	}
	

	//下の壁の高さ
	height_[0] = 20.0f;
	height_[2] = 80.0f;
	height_[4] = 140.0f;
	height_[6] = 200.0f;
	height_[8] = 260.0f;

	//上の壁の高さ
	height_[1] = heightTotal - height_[0];
	height_[3] = heightTotal - height_[2];
	height_[5] = heightTotal - height_[4];
	height_[7] = heightTotal - height_[6];
	height_[9] = heightTotal - height_[8];

	//下の壁の位置
	pos_[0].x =700.0f;
	pos_[2].x = 1200.0f;
	pos_[4].x = 1700.0f;
	pos_[6].x = 2200.0f;
	pos_[8].x = 2700.0f;

	

	for (int i = 0;i < wallNum_;i++) {
		pos_[i].y = 700.0f - height_[i] / 2.0f;
		width_[i] = 10.0f;
	}

	for (int i = 1;i < wallNum_;i += 2) {
		//上の壁の中心位置
		pos_[i].x = pos_[i - 1].x;
		pos_[i].y = pos_[i - 1].y - height_[i - 1] / 2.0f - distance - height_[i] / 2.0f;
		height_[i] = heightTotal - height_[i - 1];
	}

	for (int i = 0;i < wallNum_;i++) {
		corners_[i] = PosUpdate(pos_[i], width_[i], height_[i]);
	}
}

void Wall::Stage2Initialize()
{
	wallNum_ = 20;
	const float heightTotal = 800;
	const float distance = 150;

	for (int i = 0;i < 28;i++) {
		pos_[i] = {};
		width_[i] = {};
		height_[i] = {};
		corners_[i] = {};
	}

	//下の壁の高さ
	height_[0] = 50.0f;
	height_[2] = 240.0f;
	height_[4] = 320.0f;
	height_[6] = 180.0f;
	height_[8] = 70.0f;
	height_[10] = 260.0f;
	height_[12] = 150.0f;
	height_[14] = 150.0f;
	height_[16] = 290.0f;
	height_[18] = 180.0f;

	//上の壁の高さ
	height_[1] = heightTotal - height_[0];
	height_[3] = heightTotal - height_[2];
	height_[5] = heightTotal - height_[4];
	height_[7] = heightTotal - height_[6];
	height_[9] = heightTotal - height_[8];
	height_[11] = heightTotal - height_[0];
	height_[13] = heightTotal - height_[2];
	height_[15] = heightTotal - height_[4];
	height_[17] = heightTotal - height_[6];
	height_[19] = heightTotal - height_[8];

	//下の壁の位置
	pos_[0].x = 700.0f;
	pos_[2].x = 1000.0f;
	pos_[4].x = 1700.0f;
	pos_[6].x = 2200.0f;
	pos_[8].x = 2700.0f;
	pos_[10].x = 3200.0f;
	pos_[12].x = 3700.0f;
	pos_[14].x = 4200.0f;
	pos_[16].x = 4700.0f;
	pos_[18].x = 5200.0f;

	for (int i = 0;i < wallNum_;i++) {
		pos_[i].y = 700.0f - height_[i] / 2.0f;
		width_[i] = 10.0f;
	}

	for (int i = 1;i < wallNum_;i += 2) {
		//上の壁の中心位置
		pos_[i].x = pos_[i - 1].x;
		pos_[i].y = pos_[i - 1].y - height_[i - 1] / 2.0f - distance - height_[i] / 2.0f;
	}

	for (int i = 0;i < wallNum_;i++) {
		corners_[i] = PosUpdate(pos_[i], width_[i], height_[i]);
	}

}

void Wall::Stage3Initialize()
{
	
}

Corners Wall::PosUpdate(Vector2 pos, float width, float height)
{
	Corners c = {};

	c.leftTop.x = (pos.x - width / 2.0f);
	c.leftTop.y = (pos.y - height / 2.0f);

	c.rightTop.x = ((pos.x + width / 2.0f));
	c.rightTop.y = (pos.y - height / 2.0f);

	c.leftDown.x = (pos.x - width / 2.0f);
	c.leftDown.y = ((pos.y + height / 2.0f));

	c.rightDown.x = ((pos.x + width / 2.0f));
	c.rightDown.y = ((pos.y + height / 2.0f));

	return c;
}

