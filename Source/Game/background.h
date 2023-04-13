#pragma once
#include "MyCMovingBitmap.h"
#include "character.h"


class backgroundTool
{
public:
	void backgroundInit();
	void selectInit();
	void elementInit();
	void backgroundKeyDown(UINT nChar);
	void backroundShowBitmap();
	void selectShowBitmap();
	void elementShowBitmap();
	void touching(MyCMovingBitmap *character);
	bool getPlaying();
	MyCMovingBitmap *getBackgroundAdress();
	MyCMovingBitmap *getElementAdress();


	void Move(characterTool *run_character);
	void KeyDown(UINT nChar);
	void KeyUp(UINT nChar);

protected:
	MyCMovingBitmap element;
	MyCMovingBitmap elementGo;
	MyCMovingBitmap background;
	MyCMovingBitmap select1;
	MyCMovingBitmap select2;
	MyCMovingBitmap totalSelect;
	bool playing = false;
	bool elementTrue = false;
	int sel = 0;
	bool buttonW = false;
	bool buttonA = false;
	bool buttonD = false;

};


