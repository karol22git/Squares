#pragma once
#include "Character.h"

class MainCharacter : public Character
{
public:
	MainCharacter();
	void Move(WPARAM wParam) override;
	void Jump();
	D2D1_RECT_F GetSkin();
	void Update();
	void StopMove(WPARAM wParam);
private:
	bool isJumping = false;
	bool isMovingRight = false;
	bool isMovingLeft = false;
	bool up = false;
	double startOfJumping;
};

