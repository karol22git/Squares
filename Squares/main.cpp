#include <windows.h>
#include <tchar.h>
#include "Graphics.h"
#include "Level1.h"
#include "GameController.h"
Graphics* g;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_KEYDOWN:
		GameController::ProceedMove(wParam,msg);
		if (wParam == VK_UP) {
			//SetWindowText(hWnd, _T("Hello1"));

		}
		else if (wParam == VK_DOWN) {
			//SetWindowText(hWnd, _T("Hello2"));
		}
		else if (wParam == VK_LEFT) {
		}
		else if (wParam == VK_RIGHT) {
		}
		UpdateWindow(hWnd);
		break;
	case WM_KEYUP:
		GameController::ProceedMove(wParam, msg);
		if (wParam == VK_LEFT) {
			SetWindowText(hWnd, _T("Hello1"));

		}
		else if (wParam == VK_RIGHT) {
			SetWindowText(hWnd, _T("Hello2"));
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}

	return 0;
}


int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	static TCHAR szWindowClassName[] = _T("myFrame");
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = nullptr;
	wcex.hCursor = nullptr;
	wcex.hbrBackground = nullptr;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClassName;
	wcex.hIconSm = nullptr;

	RegisterClassEx(&wcex);
	RECT rect = { 0,0,1200,800 };
	AdjustWindowRectEx(&rect, 0, false, 0);
	g = new Graphics();
	HWND h = CreateWindowEx(
		0,
		szWindowClassName,
		_T("Hello world"),
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,
		200,
		rect.right - rect.left,
		rect.bottom - rect.top,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
	if (!g->Init(h)) {
		//delete g;
		return -1;
	}
	GameLevel::Init(g);
	ShowWindow(h, SW_SHOW);

	GameController::LoadInitialLevel(new Level1());
	MSG message;
	message.message = WM_NULL;
	while (message.message != WM_QUIT) {
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&message);

		}
		else {
			GameController::Update();
			GameController::Render();
		}
	}
	return 0;
}