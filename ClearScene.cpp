#include "ClearScene.h"

void ClearScene::Initialize()
{
}

void ClearScene::Update(char keys[256], char preKeys[256])
{

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {

		isFinished_ = true;

	}

}

void ClearScene::Draw()
{

	Novice::ScreenPrintf(10, 10, "clearScene");

}
