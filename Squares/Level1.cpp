#include "Level1.h"


void Level1::Load() {

}

void Level1::Unload() {

}
bool flag = false;
void Level1::Update() {
	mainCharacter->Update();
	flag = false;
	for (auto n : terrain) {
		D2D1_RECT_F r; 
		n->GetRect(&r);
		auto r2 = mainCharacter->GetSkin();
		if (cDetector->RectangleColissionDetection(r,r2)){
			flag = true;
		}
	}
}

void Level1::Render() {
	gfx->BeginDraw();
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);
	for (auto n : terrain) gfx->DrawShape(n);
	//gfx->DrawShape(rectangleGeometry);
	//gfx->DrawShape(mainCharacter->GetSkin());
	if (flag) gfx->DrawFilledRectangle(mainCharacter->GetSkin());
	else gfx->DrawRectangle(mainCharacter->GetSkin());
	gfx->EndDraw();

}

Level1::Level1() {
	//Graphics::factory->CreateRectangleGeometry(D2D1::RectF(150.0f, 150.f, 200.0f, 200.0f),&rectangleGeometry);
	BuildTerrain();
	mainCharacter = new MainCharacter();
}

void Level1::BuildTerrain() {
	/*for (int i = 1; i <= 3; ++i) {
		ID2D1RectangleGeometry* tempGeometry;
		Graphics::factory->CreateRectangleGeometry(D2D1::RectF(i*150.0f, i*150.f, i*200.0f, i*200.0f), &tempGeometry);
		terrain.push_back(tempGeometry);
	}*/
	ID2D1RectangleGeometry* tempGeometry;
	Graphics::factory->CreateRectangleGeometry(D2D1::RectF(0.0f, 600.f, 1180.0f, 760.0f), &tempGeometry);
	terrain.push_back(tempGeometry);
}

void Level1::ProceedMove(WPARAM wParam, UINT msg) {
	if(msg == WM_KEYDOWN) mainCharacter->Move(wParam);
	else if(msg == WM_KEYUP) mainCharacter->StopMove(wParam);
}