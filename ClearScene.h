#include "Novice.h"

class ClearScene {

public:

	void Initialize();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	bool IsFinished() { return isFinished_; }

private:

	bool isFinished_ = false;

};