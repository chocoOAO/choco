#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

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
	void touching(characterTool *characterAddress);
	bool getPlaying();
	MyCMovingBitmap *getBackgroundAddress();
	MyCMovingBitmap *getElementAddress();
	MyCMovingBitmap *getElementGoAddress();
	MyCMovingBitmap *getElementCloudAddress();
	MyCMovingBitmap *getElementEmptyBlockAddress();



	void Move(characterTool *run_character);
	void KeyDown(UINT nChar);
	void KeyUp(UINT nChar);

protected:
	MyCMovingBitmap element;
	MyCMovingBitmap elementGo;
	MyCMovingBitmap elementCloud;
	MyCMovingBitmap elementEmptyBlock;
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


#endif