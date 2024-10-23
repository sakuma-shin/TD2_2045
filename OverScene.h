#include "Novice.h"

class OverScene {

public:

	void Initialize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	bool IsFinished() { return isFinished_; }

private:

	int GH = Novice::LoadTexture("./Resources/over.png");

	bool isFinished_ = false;

};