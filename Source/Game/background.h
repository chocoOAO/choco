#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "MyCMovingBitmap.h"
#include "character.h"


class backgroundTool
{
public:
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

	//MyCMovingBitmap *getFloor1_2Address();
	MyCMovingBitmap *getBackgroundAddress();	
	std::vector<MyCMovingBitmap *> *getStageAddress();

	void setSel(int value);
	void setBackground(int value);
	void setPlaying(bool value);
	void setInit(bool value);
	void setClearStage();

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
	bool judgeMove;

};

enum stage1Id
{
	element, elementGo, elementCloud, elementEmptyBlock, elementGrass, elementLongBlock, elementShortBlock, elementPipe1, elementPipe2, elementKey,
	elementPrick1, elementPrick2, elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2, elementPoRight, elementPoLeft,
	elementPoUp, elementDropFloor, elementLady, floor1_1, floor1_2, floor1_3
};

enum stage2Id
{
	elementQuestion 
};

#endif