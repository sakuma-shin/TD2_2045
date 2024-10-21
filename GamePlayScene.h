#pragma once
#include <Novice.h>
#include "Hit.h"
#include "Player.h"
#include"Wall.h"
class GamePlayScene
{
public:

	GamePlayScene();
	~GamePlayScene();

	void Initialize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	Corners PosUpdate(Vector2 pos, float width, float height);

	bool IsFinished() { return isFinished_; }

	bool IsCleared() { return isCleared_; }

	bool IsDead() { return isDead_; }

	void DrawQuad(Corners a, int imageGH, int imageWidth, int imageHeight, unsigned int color, float scroll);

	float GetScroll() { return scroll_; }

	enum class Stage {
		STAGE0,
		STAGE1,
		STAGE2,
		STAGE3
	};


	void SetStage(Stage stage) { stage_ = stage; }

	
private:


	

	Stage stage_ = Stage::STAGE1;

	bool isFinished_ = false;

	bool isCleared_ = false;

	bool isDead_ = false;

	int whiteGH = 0;

	Player* player_ = nullptr;

	Wall* wall_ = nullptr;

	float scroll_ = 0.0f;

	float goalPos = 1000000.0f;

};

