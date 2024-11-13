#include "MainCharacter.h"
#include "Graphics.h"


void MainCharacter::Move(WPARAM wParam) {
	/*if (wParam == VK_UP) {
		skin.top += 10;
		skin.bottom += 10;
	}*/
	switch (wParam) {
	case VK_UP :
		//skin.top -= 10;
		//skin.bottom -= 10;
		Jump();
		break;
	case VK_DOWN: 
		skin.top += 10;
		skin.bottom += 10;
		break;
	case VK_LEFT :
		//skin.left -= 10;
		//skin.right -= 10;
		isMovingLeft = true;
		break;
	case VK_RIGHT:
		//skin.left += 10;
		//skin.right += 10;
		isMovingRight = true;
		break;
	default:
		break;
	}

}

void MainCharacter::StopMove(WPARAM wParam) {
	switch (wParam) {
	case VK_LEFT:
		isMovingLeft = false;
		break;
	case VK_RIGHT:
		isMovingRight = false;
		break;
	default:
		break;
	}

}

MainCharacter::MainCharacter() {
	//Graphics::factory->CreateRectangleGeometry(D2D1::RectF(400.0f, 400.f, 600.0f, 600.0f), &skin);
	//skin = D2D1Rect(positionX, positionY, positionX + characterWidth, positionY + characterHeight);
	positionX = 400;
	positionY = 400;
	characterWidth = 200;
	characterHeight = 200;
	skin = D2D1::Rect(positionX, positionY, positionX + characterWidth, positionY + characterHeight);
}

D2D1_RECT_F MainCharacter::GetSkin() {
	return skin;
}

void MainCharacter::Jump() {
	isJumping = true;
	up = true;
	startOfJumping = skin.top;

}

void MainCharacter::Update() {
	if (isJumping) {
		if (up) {
			if (startOfJumping - skin.top > 400) {
				up = false;
			}
			skin.top -= 10;
			skin.bottom -= 10;
		}
		else {
			skin.top += 10;
			skin.bottom += 10;
			if (skin.top == startOfJumping) isJumping = false;
		}
	}
	if (isMovingRight) {
		skin.left += 10;
		skin.right += 10;
	}
	if (isMovingLeft) {
		skin.left -= 10;
		skin.right -= 10;
	}
}