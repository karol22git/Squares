#pragma once
#include <d2d1.h>

class ColissionDetector
{
public:
	static ColissionDetector* GetInstance();
	static bool RectangleColissionDetection(D2D1_RECT_F &recta, D2D1_RECT_F &rectb);
	static bool RectanglePointContainment(D2D1_RECT_F& rect, float& x, float& y);
	~ColissionDetector();

private:
	ColissionDetector();
	static ColissionDetector* instance;
};

