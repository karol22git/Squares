#pragma once
#include <d2d1.h>
class Character
{
public:
	virtual void Move(WPARAM wParam) = 0;

protected:
	int positionX;
	int positionY;
	int characterWidth;
	int characterHeight;
	D2D1_RECT_F skin;
};
