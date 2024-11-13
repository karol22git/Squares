#include "Graphics.h"

ID2D1Factory* Graphics::factory;


void Graphics::BeginDraw() {
	renderTarget->BeginDraw();
}

void Graphics::EndDraw() {
	renderTarget->EndDraw();
}

Graphics::Graphics() {
	factory = nullptr;
	renderTarget = nullptr;
}

Graphics::~Graphics() {
	if (factory) {
		factory->Release();
	}
	if (renderTarget) {
		renderTarget->Release();
	}
}

bool Graphics::Init(HWND windowHandle) {
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK) {
		return false;
	}
	RECT rect;
	GetClientRect(windowHandle, &rect);
	res = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget);
	if (res != S_OK) {
		return false;
	}

	return true;
}

void Graphics::ClearScreen(float r, float g, float b) {
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a) {
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
	//renderTarget-> DrawEllipse(c.e, brush, 3.0f);
	brush->Release();
}

ID2D1RenderTarget* Graphics::GetRenderTarget() {
	return renderTarget;
}

void Graphics::DrawShape(ID2D1RectangleGeometry* rect) {
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f), &brush);
	renderTarget->DrawGeometry(rect, brush, 1);
}

void Graphics::DrawRectangle(D2D1_RECT_F r) {
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f), &brush);
	renderTarget->DrawRectangle(&r, brush);
}

void Graphics::DrawFilledRectangle(D2D1_RECT_F r) {
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(255.0f, 0.0f, 0.0f, 1.0f), &brush);
	renderTarget->FillRectangle(&r, brush);
}