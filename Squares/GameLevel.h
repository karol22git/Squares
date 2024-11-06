#pragma once
#include "Graphics.h"
class GameLevel
{
public:
	static void Init(Graphics* graphics) { gfx = graphics;}
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void ProceedMove(WPARAM wParam, UINT msg) = 0;
protected:
	static Graphics* gfx;
};

