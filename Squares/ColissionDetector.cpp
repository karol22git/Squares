#include "ColissionDetector.h"


bool ColissionDetector::RectangleColissionDetection(D2D1_RECT_F &recta, D2D1_RECT_F &rectb) {
	float width = rectb.right - rectb.left;
	float hight = rectb.bottom - rectb.top;
	float x2 = rectb.left + width;
	float y2 = rectb.top + hight;
	return RectanglePointContainment(recta, rectb.left, rectb.top) ||
		RectanglePointContainment(recta, x2, rectb.top) ||
		RectanglePointContainment(recta, rectb.left, y2) ||
		RectanglePointContainment(recta, x2, y2);
}

bool ColissionDetector::RectanglePointContainment(D2D1_RECT_F& rect, float& x, float& y) {
	return (x >= rect.left && x <= rect.right) && (y >= rect.top && y <= rect.bottom);
}