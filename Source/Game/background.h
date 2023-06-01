#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "MyCMovingBitmap.h"
#include "character.h"


class backgroundTool //:public MyCMovingBitmap
{
public:
	backgroundTool()=default;
	~backgroundTool() 
	{
		for (int i = 0; i < int(stage.size()); i++)
		{
			delete stage[i];
		}
	}
	void backgroundInit();
	void selectInit();
	void elementInit();
	void backgroundKeyDown(UINT nChar);
	void backroundShowBitmap();
	void selectShowBitmap();
	void elementShowBitmap();
	void touching(characterTool *characterAddress);
	bool getPlaying();
	int* getSelAddress();

	MyCMovingBitmap *getBackgroundAddress();	
	std::vector<MyCMovingBitmap *> *getStageAddress();

	void setSel(int value);
	void setBackground(int value);
	void setClearStage();
	void setPlaying(bool value);
	void setInit(bool value);

	void Move(characterTool *run_character);
	void KeyDown(UINT nChar);
	void KeyUp(UINT nChar);

protected:
	std::vector<MyCMovingBitmap *> stage;
	std::vector<vector<vector<string>>> stage1LoadBitMap;
	std::vector<vector<vector<int>>> stage1SetTopLeft;
	std::vector<vector<int>> stageTouchUpElement;
	std::vector<vector<int>> stageTouchUpEmpty;
	std::vector<vector<int>> stageJudgeMove;


	MyCMovingBitmap floor1_2;
	MyCMovingBitmap background;
	MyCMovingBitmap select1;
	MyCMovingBitmap select2;
	MyCMovingBitmap select3;
	MyCMovingBitmap totalSelect;
	bool playing = false;
	bool init = false;
	bool elementTrue = false;
	bool elementPo = false;
	bool elementPo1_2 = false;
	int sel = 0;
	bool buttonW = false;
	bool buttonA = false;
	bool buttonD = false;
	bool judgeMove = false;

	clock_t start;
	bool first = false;
	bool elementFlower = false;
	bool longblock = false;
};

enum stage1Id
{
	element, elementGo, elementCloud, elementEmptyBlock, elementGrass, elementLongBlock, elementShortBlock, elementPipe1, elementPoUp, elementKey,
	elementPrick1, elementPipe2, elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2, elementPoRight, elementPoLeft,
	elementPrick2, elementDropFloor, elementLady, floor1_1, floor1_2, floor1_3
};

enum stage2Id
{
	elementFlower2_1, elementFloor2_1, elementDropFloor2_1, elementFloor2_2, elementDropFloor2_2, elementFloor2_3, brick, elementHit, elementLongBlock2_1, elementLongBlock2_2,
	elementVerticalLongBlock2_1, elementPrick2_1, elementEmptyBlock2_1, elementQuestion, elementDoublePoLeft, elementEmptyBlock2_2, elementEmptyBlock2_3, elenentslime2_1
};
#endif