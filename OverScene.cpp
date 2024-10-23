#include "OverScene.h"

void OverScene::Initialize()
{
}

void OverScene::Update(char keys[256], char preKeys[256])
{
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {

		isFinished_ = true;

	}
}

void OverScene::Draw()
{

	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, GH, WHITE);

}
