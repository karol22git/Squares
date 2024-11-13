#pragma once
#pragma once
#include <Windows.h>
#include <d2d1.h>

class Graphics {
public:
	Graphics();
	~Graphics();
	bool Init(HWND windowHandle);
	void BeginDraw();
	void EndDraw();
	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);
	ID2D1RenderTarget* GetRenderTarget();
	static ID2D1Factory* factory;
	void DrawShape(ID2D1RectangleGeometry* rect);
	void DrawRectangle(D2D1_RECT_F r);
	void DrawFilledRectangle(D2D1_RECT_F r);
private:
	ID2D1HwndRenderTarget* renderTarget;

};

