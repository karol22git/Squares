#include "GameController.h"


GameLevel* GameController::currentLevel;
bool GameController::Loading;


void GameController::LoadInitialLevel(GameLevel* lvl) {
	Loading = true;
	currentLevel = lvl;
	currentLevel->Load();
	Loading = false;
}

void GameController::Render() {
	if (Loading) return;
	currentLevel->Render();
}

void GameController::Update() {
	if (Loading) return;
	currentLevel->Update();
}

void GameController::Init() {
	Loading = true;
	currentLevel = 0;
}

void GameController::ProceedMove(WPARAM wParam, UINT msg) {
	currentLevel->ProceedMove(wParam,msg);
}