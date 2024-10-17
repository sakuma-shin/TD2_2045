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

	Novice::ScreenPrintf(10, 10, "overScene");

}
