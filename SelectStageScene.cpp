#include "SelectStageScene.h"

void SelectStageScene::initialize()
{
}

void SelectStageScene::Update(char keys[256], char preKeys[256])
{

	if (keys[DIK_1] && !preKeys[DIK_1]) {
		isFinished1_ = true;


	} else if (keys[DIK_2] && !preKeys[DIK_2]) {
		isFinished2_ = true;


	} else if (keys[DIK_3] && !preKeys[DIK_3]) {
		isFinished3_ = true;

	} else if (keys[DIK_0] && !preKeys[DIK_0]) {
		isFinished_ = true;

	}
}

void SelectStageScene::Draw()
{

	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, GH, WHITE);

}
