#pragma once
#include "MyCMovingBitmap.h"


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
	MyCMovingBitmap *getAdress();
	

	void Move();
	void KeyDown(UINT nChar);
	void KeyUp(UINT nChar);

protected:
	MyCMovingBitmap element;
	MyCMovingBitmap background;
	MyCMovingBitmap select1;
	MyCMovingBitmap select2;
	MyCMovingBitmap totalSelect;
	bool playing = false;
	bool elementTrue = false;
	int sel = 0;
	bool buttonA = false;
	bool buttonD = false;

};


