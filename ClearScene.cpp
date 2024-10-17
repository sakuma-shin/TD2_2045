#include "ClearScene.h"

void ClearScene::Initialize()
{
}

void ClearScene::Update(char keys[256], char preKeys[256])
{

	if (keys[DIK_RETURN] && preKeys[DIK_RETURN]) {

		isFinished = true;

	}

}

void ClearScene::Draw()
{

	Novice::ScreenPrintf(10, 10, "clearScene");

}
