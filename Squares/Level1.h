#pragma once
#include "GameLevel.h"
#include "MainCharacter.h"
#include <vector>
class Level1 : public GameLevel
{
public:
	Level1();
	void BuildTerrain();
	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;
	void ProceedMove(WPARAM wParam, UINT msg) override;
private:
	ID2D1RectangleGeometry* rectangleGeometry;
	std::vector<ID2D1RectangleGeometry*> terrain;
	MainCharacter* mainCharacter;
};

