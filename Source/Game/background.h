#pragma once
#include "MyCMovingBitmap.h"


class backgroundTool
{
public:
	void backgroundInit();
	void selectInit();
	void backgroundKeyDown(UINT nChar);
	void backroundShowBitmap();
	void selectShowBitmap();
	MyCMovingBitmap *getAdress();



protected:
	MyCMovingBitmap background;
	MyCMovingBitmap select1;
	MyCMovingBitmap select2;
	MyCMovingBitmap totalSelect;
	bool playing = false;
	int sel = 0;
};


