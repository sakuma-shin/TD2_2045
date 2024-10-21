#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

void Player::Initialize() {

}

void Player::Update(char* keys, char* preKeys) {
	// プレイヤーの位置を更新
	playerPos_.x += moveSpeed_;

	// プレイヤーの四隅の座標を設定
	playerCorner_ = {
		{playerPos_.x - 10, playerPos_.y - 10},//左上
		{playerPos_.x + 10, playerPos_.y - 10},//右上
		{playerPos_.x - 10, playerPos_.y + 10},//左下
		{playerPos_.x + 10, playerPos_.y + 10}//右下
	};

	ParticleUpdate();

	// ジャンプ中ではなく、地面にいる場合の処理
	if (!isJump_ && isGround_) {
		// スペースキーが押されている場合、ジャンプの溜め処理
		if (keys[DIK_SPACE]) {
			if (pushTime_ < maxPushTime_) {
				isHold_ = true;
				pushTime_ += 2;
			}
		}
		// スペースキーが離された場合、ジャンプ処理
		else if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] && isHold_) {
			isHold_ = false;
			isParticle = true;
			ParticleInitialize(playerPos_);
			// 溜めた時間に応じてジャンプ力を設定
			if (pushTime_ <= 20) {
				startJumpPower_ = 30;
				particleNum = 3;
			}
			else if (pushTime_ > 20 && pushTime_ <= 40) {
				startJumpPower_ = 33;
				particleNum = 6;
			}
			else if (pushTime_ > 40 && pushTime_ <= 60) {
				startJumpPower_ = 36;
				particleNum = 9;
			}
			else if (pushTime_ > 60 && pushTime_ <= 80) {
				startJumpPower_ = 39;
				particleNum = 12;
			}
			else if (pushTime_ > 80 && pushTime_ <= 100) {
				startJumpPower_ = 42;
				particleNum = 15;
			}

			// ジャンプ力をプレイヤーに反映
			playerJumpPower_ = startJumpPower_;
			pushTime_ = 0;
			isJump_ = true;  // ジャンプ開始
			isGround_ = false; // 地面から離れる
		}
	}

	// ジャンプ中の処理
	if (isJump_) {
		// ジャンプ力を減少（重力）
		playerJumpPower_ -= downPower_;

		if (!isHold_) {
			playerPos_.y -= playerJumpPower_;
		}

		// 2段ジャンプがまだ実行されていない場合
		if (!oneMoreJump_) {
			// スペースキーが押されている場合、再度ジャンプの溜め処理
			if (keys[DIK_SPACE]) {
				isHold_ = true;
				pushTime_ += 1;
				downPower_ = 0; // 下降速度の変更
				moveSpeed_ = 0;
				if (pushTime_ >= 100) {
					pushTime_ = 0;
				}
			}
			// スペースキーが離された時の2段ジャンプ処理
			else if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] && isHold_) {
				isHold_ = false;
				ParticleInitialize(playerPos_);
				moveSpeed_ = 7.5f;
				downPower_ = uint32_t(2.5f); // 下降速度をリセット

				// 溜めた時間に応じて2段ジャンプ力を設定
				if (pushTime_ <= 20) {
					startJumpPower_ = 30;
					particleNum = 3;
				}
				else if (pushTime_ > 20 && pushTime_ <= 40) {
					startJumpPower_ = 33;
					particleNum = 6;
				}
				else if (pushTime_ > 40 && pushTime_ <= 60) {
					startJumpPower_ = 36;
					particleNum = 9;
				}
				else if (pushTime_ > 60 && pushTime_ <= 80) {
					startJumpPower_ = 39;
					particleNum = 12;
				}
				else if (pushTime_ > 80 && pushTime_ <= 100) {
					startJumpPower_ = 42;
					particleNum = 15;
				}

				// 2段ジャンプ力をプレイヤーに反映
				playerJumpPower_ = startJumpPower_;
				pushTime_ = 0;
				oneMoreJump_ = true;  // 2段ジャンプが完了
			}
		}

		// ジャンプ終了判定 (プレイヤーが地面に着地したか)
		if (playerPos_.y > 690) {
			playerPos_.y = 690;  // プレイヤー位置をリセット
			startJumpPower_ = 0;
			playerJumpPower_ = 0;
			downPower_ = uint32_t(2.5f);  // 重力のリセット
			oneMoreJump_ = false; // 2段ジャンプリセット
			isJump_ = false; // ジャンプ終了
			isGround_ = true;  // 地面に着地
			isParticle = false;
		}
	}
}

void Player::Draw(float scroll) {
	ParticleDraw(scroll);

	UINT color = 0;

	if (pushTime_ <= 100) {
		color = BLACK;
	}
	if (pushTime_ <= 80) {
		color = RED;
	}
	if (pushTime_ <= 60) {
		color = GREEN;
	}
	if (pushTime_ <= 40) {
		color = BLUE;
	}
	if (pushTime_ <= 20) {
		color = WHITE;
	}
	Novice::DrawBox(0, 700, 12 * pushTime_, 20, 0.0f, color, kFillModeSolid);

	Novice::DrawQuad(int(playerCorner_.leftTop.x - scroll), int(playerCorner_.leftTop.y),
		int(playerCorner_.leftDown.x - scroll), int(playerCorner_.leftDown.y),
		int(playerCorner_.rightTop.x - scroll), int(playerCorner_.rightTop.y),
		int(playerCorner_.rightDown.x - scroll), int(playerCorner_.rightDown.y),
		0, 0, 1, 1, textureHandle_, WHITE);

	Novice::DrawLine(0, 700, 1280, 700, BLACK);

}

uint32_t Player::GetTime() {
	return pushTime_;
}

Corners Player::GetCorners()
{
	return playerCorner_;
}

Vector2 Player::GetPos()
{
	return playerPos_;
}

float Player::GetSpeed()
{
	return moveSpeed_;
}

void Player::ParticleInitialize(Vector2 position) {
	for (int i = 0; i < 15; i++) {
		particle[i].pos = position;
		particle[i].vel = { float(rand() % 21 - 10),float(rand() % 11 - 10) };
		particle[i].deathTime = 10;
		particle[i].isDead = false;
		particle[i].alpha = 255;
	}
}

void Player::ParticleUpdate() {
	unsigned int subColor[15];
	for (int i = 0; i < particleNum; i++) {
		if (particle[i].isDead) {
			particle[i].pos = { -1111,-1111 };
		}
		particle[i].pos.x += particle[i].vel.x;
		particle[i].pos.y += particle[i].vel.y;
		subColor[i] = unsigned int(25.5f);
		particle[i].deathTime--;
		particle[i].alpha -= subColor[i];
		if (particle[i].deathTime == 0) {
			particle[i].isDead = true;
		}
	}
}

void Player::ParticleDraw(float scroll) {
	for (int i = 0; i < particleNum; i++) {
		if (!particle[i].isDead) {
			Novice::DrawTriangle(int(particle[i].pos.x - scroll), int(particle[i].pos.y + 10), int(particle[i].pos.x + 5 - scroll), int(particle[i].pos.y - 5), int(particle[i].pos.x - 5 - scroll), int(particle[i].pos.y - 5), color_->GetColor(255, 255, 255, particle[i].alpha), kFillModeSolid);
		}
	}
}