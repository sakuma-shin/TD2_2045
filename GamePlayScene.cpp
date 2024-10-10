#include "GamePlayScene.h"

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
	delete player_;
	delete wall_;
}

void GamePlayScene::Initialize()
{
	whiteGH = Novice::LoadTexture("white1x1.png");

	player_ = new Player();

	wall_ = new Wall();

	wall_->Initialize();

	scroll_ = 0.0f;

}

void GamePlayScene::Update(char keys[256], char preKeys[256])
{
	//if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
	//	/*isFinished_ = true;*/
	//}

	player_->Update(keys,preKeys);

	wall_->Update();

	if (player_->GetPos().x>=640.0f) {
		scroll_ += player_->GetSpeed();
	}

	for (int i = 0;i < 28;i++) {
		if (HitBox(wall_->GetCorners(i), player_->GetCorners())) {
			isFinished_ = true;
		}
	}
}

void GamePlayScene::Draw()
{
	player_->Draw(scroll_);

	wall_->Draw(scroll_);
}

Corners GamePlayScene::PosUpdate(Vector2 pos, float width, float height)
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

void GamePlayScene::DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll)
{
	Novice::DrawQuad(int(a.leftTop.x - scroll), int(a.leftTop.y), int(a.rightTop.x - scroll), int(a.rightTop.y), int(a.leftDown.x - scroll), int(a.leftDown.y), int(a.rightDown.x - scroll), int(a.rightDown.y), 0, 0, imageWidth, imageHeight, imageGH, color);
}
