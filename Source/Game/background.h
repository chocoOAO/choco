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

	MyCMovingBitmap *getFloor1_2Address();
	MyCMovingBitmap *getBackgroundAddress();
	MyCMovingBitmap *getElementAddress();
	MyCMovingBitmap *getElementGoAddress();
	MyCMovingBitmap *getElementCloudAddress();
	MyCMovingBitmap *getElementEmptyBlockAddress();
	MyCMovingBitmap *getElementGrassAddress();
	MyCMovingBitmap *getElementLongBlockAddress();
	MyCMovingBitmap *getElementShortBlockAddress();
	MyCMovingBitmap *getElementPipe1Address();
	MyCMovingBitmap *getElementPipe2Address();
	MyCMovingBitmap *getElementPrick1Address();
	MyCMovingBitmap *getElementPrick2Address();
	MyCMovingBitmap *getElementEmptyBlock2Address();
	MyCMovingBitmap *getElementBlockUAddress();
	MyCMovingBitmap *getElementBlockDAddress();
	MyCMovingBitmap *getElementBlockIAddress();
	MyCMovingBitmap *getElementBlockEAddress();
	MyCMovingBitmap *getElementBlockD2Address();
	MyCMovingBitmap *getElementPoRightAddress();
	MyCMovingBitmap *getElementPoLeftAddress();
	MyCMovingBitmap *getElementPoUpAddress();
	MyCMovingBitmap *getElementDropFloorAddress();


	void Move(characterTool *run_character);
	void KeyDown(UINT nChar);
	void KeyUp(UINT nChar);

protected:
	MyCMovingBitmap element;
	MyCMovingBitmap elementGo;
	MyCMovingBitmap elementCloud;
	MyCMovingBitmap elementEmptyBlock;
	MyCMovingBitmap elementGrass;
	MyCMovingBitmap elementLongBlock;
	MyCMovingBitmap elementShortBlock;
	MyCMovingBitmap elementPipe1;
	MyCMovingBitmap elementPipe2;
	MyCMovingBitmap elementKey;
	MyCMovingBitmap elementPrick1;
	MyCMovingBitmap elementPrick2;
	MyCMovingBitmap elementEmptyBlock2;
	MyCMovingBitmap elementBlockU;
	MyCMovingBitmap elementBlockD;
	MyCMovingBitmap elementBlockI;
	MyCMovingBitmap elementBlockE;
	MyCMovingBitmap elementBlockD2;
	MyCMovingBitmap elementPoRight;
	MyCMovingBitmap elementPoLeft;
	MyCMovingBitmap elementPoUp;
	MyCMovingBitmap elementDropFloor;
	MyCMovingBitmap floor1_2;
	MyCMovingBitmap elementLady;

	MyCMovingBitmap background;
	MyCMovingBitmap select1;
	MyCMovingBitmap select2;
	MyCMovingBitmap totalSelect;
	bool playing = false;
	bool elementTrue = false;
	bool elementPo = false;
	bool elementPo1_2 = false;
	int sel = 0;
	bool buttonW = false;
	bool buttonA = false;
	bool buttonD = false;

};


#endif