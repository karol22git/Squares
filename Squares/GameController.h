#pragma once
#include "GameLevel.h"
class GameController
{
public:
	static bool Loading;
	static void Init();
	static void LoadInitialLevel(GameLevel*);
	static void SwitchLevel(GameLevel*);
	static void Render();
	static void Update();

private:
	GameController();
	static GameLevel* currentLevel;
};

