#include <Novice.h>

class SelectStageScene {

public:

	void initialize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	bool IsFinished() { return isFinished_; }

	bool IsFinished1() { return isFinished1_; }

	bool IsFinished2() { return isFinished2_; }

	bool IsFinished3() { return isFinished3_; }

private:

	int GH = Novice::LoadTexture("./Resources/stageSelect.png");

	bool isFinished1_ = false;

	bool isFinished2_ = false;

	bool isFinished3_ = false;

	bool isFinished_ = false;

};