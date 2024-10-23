#include "Wall.h"

void Wall::Initialize()
{
}

void Wall::Update()
{
	for (int i = 0;i < wallNum_;i++) {
		corners_[i] = PosUpdate(pos_[i], width_[i], height_[i]);
	}
}

void Wall::Draw(float scroll)
{
	for (int i = 0;i <wallNum_ ;i++) {
		DrawQuad(corners_[i], GH[i], 10, 50, WHITE, scroll);
	}
}

void Wall::DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll) {
	Novice::DrawQuad(int(a.leftTop.x - scroll), int(a.leftTop.y), int(a.rightTop.x - scroll), int(a.rightTop.y), int(a.leftDown.x - scroll), int(a.leftDown.y), int(a.rightDown.x - scroll), int(a.rightDown.y), 0, 0, imageWidth, imageHeight, imageGH, color);
}

void Wall::Stage1Initialize()
{
	wallNum_ = 10;
	const float heightTotal = 800;
	const float distance = 250/**debugDistance*/;
	

	for (int i = 0;i < 28;i++) {
		pos_[i] = {};
		width_[i] = {};
		height_[i] = {};
		corners_[i] = {};
		
	}


	
	

	//下の壁の高さ
	float addHeight = 20.0f;
	height_[0] = addHeight+50.0f;
	height_[2] = addHeight+110.0f;
	height_[4] = addHeight+170.0f;
	height_[6] = addHeight+230.0f;
	height_[8] = addHeight+290.0f;

	//上の壁の高さ
	height_[1] = heightTotal - height_[0];
	height_[3] = heightTotal - height_[2];
	height_[5] = heightTotal - height_[4];
	height_[7] = heightTotal - height_[6];
	height_[9] = heightTotal - height_[8];

	//下の壁の位置
	float range=1.3f;
	pos_[0].x =range*700.0f;
	pos_[2].x =range* 1200.0f;
	pos_[4].x =range* 1700.0f;
	pos_[6].x =range* 2200.0f;
	pos_[8].x =range* 2700.0f;

	

	for (int i = 0;i < wallNum_;i++) {
		pos_[i].y = 700.0f - height_[i] / 2.0f;
		width_[i] = 30.0f/**debugWidth*/;
		GH[i] = redWallGH;
	}

	for (int i = 1;i < wallNum_;i += 2) {
		//上の壁の中心位置
		pos_[i].x = pos_[i - 1].x;
		pos_[i].y = pos_[i - 1].y - height_[i - 1] / 2.0f - distance - height_[i] / 2.0f;
		height_[i] = heightTotal - height_[i - 1];
		GH[i] = redWall2GH;
	}

	for (int i = 0;i < wallNum_;i++) {
		corners_[i] = PosUpdate(pos_[i], width_[i], height_[i]);
	}
}

void Wall::Stage2Initialize()
{
	wallNum_ = 20;
	const float heightTotal = 800;
	const float distance = 200/**debugDistance*/;

	for (int i = 0;i < 28;i++) {
		pos_[i] = {};
		width_[i] = {};
		height_[i] = {};
		corners_[i] = {};
	}

	//下の壁の高さ
	float addHeight = 30.0f;
	height_[0] = addHeight+50.0f;
	height_[2] = addHeight+240.0f;
	height_[4] = addHeight+320.0f;
	height_[6] = addHeight+180.0f;
	height_[8] = addHeight+70.0f;
	height_[10] =addHeight+ 260.0f;
	height_[12] =addHeight+ 150.0f;
	height_[14] =addHeight+ 150.0f;
	height_[16] =addHeight+ 290.0f;
	height_[18] =addHeight+ 350.0f;

	//上の壁の高さ
	height_[1] = heightTotal - height_[0];
	height_[3] = heightTotal - height_[2];
	height_[5] = heightTotal - height_[4];
	height_[7] = heightTotal - height_[6];
	height_[9] = heightTotal - height_[8];
	height_[11] = heightTotal - height_[10];
	height_[13] = heightTotal - height_[12];
	height_[15] = heightTotal - height_[14];
	height_[17] = heightTotal - height_[16];
	height_[19] = heightTotal - height_[18];

	//下の壁の位置
	float range = 1.1f;
	pos_[0].x = range*700.0f;
	pos_[2].x = range*1200.0f;
	pos_[4].x = range*2100.0f;
	pos_[6].x = range*2800.0f;
	pos_[8].x = range*3500.0f;
	pos_[10].x =range* 4200.0f;
	pos_[12].x =range* 4900.0f;
	pos_[14].x =range* 5600.0f;
	pos_[16].x =range* 6300.0f;
	pos_[18].x =range* 7100.0f;

	for (int i = 0;i < wallNum_;i++) {
		pos_[i].y = 700.0f - height_[i] / 2.0f;
		width_[i] = 30.0f/**debugWidth*/;
		GH[i] = redWallGH;
	}

	for (int i = 1;i < wallNum_;i += 2) {
		//上の壁の中心位置
		pos_[i].x = pos_[i - 1].x;
		pos_[i].y = pos_[i - 1].y - height_[i - 1] / 2.0f - distance - height_[i] / 2.0f;
		GH[i] = redWall2GH;
	}

	for (int i = 0;i < wallNum_;i++) {
		corners_[i] = PosUpdate(pos_[i], width_[i], height_[i]);
	}

}

void Wall::Stage3Initialize()
{
	wallNum_ = 28;
	const float heightTotal = 800;
	const float distance = 230/**debugDistance*/;



	for (int i = 0;i < 28;i++) {
		pos_[i] = {};
		width_[i] = {};
		height_[i] = {};
		corners_[i] = {};
	}

	
	//下の壁の高さ
	float addHeight = 100.0f;
	height_[0] = addHeight+150.0f;
	height_[2] = addHeight+20.0f;
	height_[4] = addHeight+40.0f;
	height_[6] = addHeight+350.0f;
	height_[8] = addHeight+20.0f;
	height_[10] =addHeight+ 80.0f;
	height_[12] =addHeight+ 130.0f;
	height_[14] =addHeight+ 140.0f;
	height_[16] =addHeight+ 140.0f;
	height_[18] =addHeight+ 50.0f;
	height_[20] =addHeight+ 440.0f;
	height_[22] =addHeight+ 20.0f;
	height_[24] =addHeight+ 80.0f;
	height_[26] =addHeight+ 500.0f;


	//上の壁の高さ
	height_[1] = heightTotal - height_[0];
	height_[3] = heightTotal - height_[2];
	height_[5] = heightTotal - height_[4];
	height_[7] = heightTotal - height_[6];
	height_[9] = heightTotal - height_[8];
	height_[11] = heightTotal - height_[10];
	height_[13] = heightTotal - height_[12];
	height_[15] = heightTotal - height_[14];
	height_[17] = heightTotal - height_[16];
	height_[19] = heightTotal - height_[18];
	height_[21] = heightTotal - height_[20];
	height_[23] = heightTotal - height_[22];
	height_[25] = heightTotal - height_[24];
	height_[27] = heightTotal - height_[26];

	float range = 2.0f;
	pos_[0].x = range*700.0f;
	pos_[2].x = range*1200.0f;
	pos_[4].x = range*1450.0f;
	pos_[6].x = range*1700.0f;
	pos_[8].x = range*1950.0f;
	pos_[10].x =range* 2450.0f;
	pos_[12].x =range* 2950.0f;
	pos_[14].x =range* 3200.0f;
	pos_[16].x =range* 3700.0f;
	pos_[18].x =range* 3950.0f;
	pos_[20].x =range* 4300.0f;
	pos_[22].x =range* 4800.0f;
	pos_[24].x =range* 5300.0f;
	pos_[26].x =range* 5450.0f;

	for (int i = 0;i < wallNum_;i++) {
		pos_[i].y = 700.0f - height_[i] / 2.0f;
		width_[i] = 30.0f/**debugWidth*/;
		GH[i] = blueWallGH;
	}

	for (int i = 1;i < wallNum_;i += 2) {
		//上の壁の中心位置
		pos_[i].x = pos_[i - 1].x;
		pos_[i].y = pos_[i - 1].y - (height_[i - 1] / 2.0f) - distance - (height_[i] / 2.0f);
		GH[i] = blueWall2GH;
	}

	for (int i = 0;i < wallNum_;i++) {
		corners_[i] = PosUpdate(pos_[i], width_[i], height_[i]);
	}

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

