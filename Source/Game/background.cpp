#include "stdafx.h"
#include "../Core/Resource.h"
#include "../Library/gameutil.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
#include "background.h"
#include "character.h"
using namespace game_framework;

void backgroundTool::backgroundInit()
{

	switch (sel)		
	{
	case 0:
		
		break;
	case 1:

		break;
	}
	background.LoadBitmapByString({
		"resources/background3.bmp",
		"resources/level1.bmp",
		"resources/level2.bmp"
		}, 0);
	background.SetTopLeft(0, 0);

	
}

void backgroundTool::selectInit()
{
	select1.LoadBitmapByString({ "resources/select1.bmp" }, RGB(255, 255, 255));
	select1.SetTopLeft(600, 400);

	select2.LoadBitmapByString({ "resources/select2.bmp" }, RGB(255, 255, 255));
	select2.SetTopLeft(880, 400);

	totalSelect.LoadBitmapByString({ "resources/select1_2.bmp", "resources/select2_2.bmp" }, RGB(255, 255, 255));
	totalSelect.SetTopLeft(600, 400);
}

void backgroundTool::elementInit()
{
	stage1LoadBitMap =
	{
		{
		{ "resources/whiteBlock.bmp","resources/blackBlock.bmp" }, { "resources/nothing.bmp","resources/go.bmp","resources/godie.bmp" },
		{ "resources/cloud.bmp","resources/clouddie.bmp" }, { "resources/emptyBlock.bmp","resources/blackBlock.bmp" },
		{ "resources/grass.bmp","resources/grassdie.bmp" }, { "resources/longBlock.bmp" },
		{ "resources/shortBlock.bmp" }, { "resources/pipe.bmp" },
		{ "resources/pipe.bmp" }, { "resources/key.bmp" },
		{ "resources/prick1.bmp" }, { "resources/prick2.bmp" },
		{ "resources/emptyBlock.bmp","resources/blackBlock.bmp" }, { "resources/emptyBlock.bmp","resources/blackBlockU.bmp" },
		{ "resources/emptyBlock.bmp","resources/blackBlockD.bmp" }, { "resources/emptyBlock.bmp","resources/blackBlockI.bmp" },
		{ "resources/emptyBlock.bmp","resources/blackBlockE.bmp" } ,{ "resources/emptyBlock.bmp","resources/blackBlock!.bmp" },
		{ "resources/PoRight.bmp"}, { "resources/PoLeft.bmp" },
		{ "resources/PoUp.bmp" }, { "resources/dropFloor.bmp" },
		{ "resources/lady.bmp" }, {	"resources/floor1_1.bmp"},
		{ "resources/floor1_2.bmp"}, { "resources/floor1_3.bmp"}//2x13							
		},
		{
			{ "resources/whiteBlock.bmp","resources/blackBlock.bmp" }
		}
	};
	stage1SetTopLeft =
	{
		{
		{427, 539}, {0, 0}, {1600, -20}, {1500, 539}, {2375, 800}, {2527, 538}, {2686, 220}, {3790, 538}, {4900, 538}, {2858, 410},
		{-1000, -1000}, {-1000, -1000}, {4120, 175}, {4109, 539}, {4268, 539}, {4427, 539}, {4586, 539}, {4745,539}, {-1000, -1000}, {-1000, -1000},
		{-1000, -1000}, {5454, 863}, {6054, 730}, {0, 860}, {1971, 860}, {5769, 860} //2x10+6
		},
		{
			{327,539}
		}
	};
	
	
	for (int i = 0; i < int(stage1LoadBitMap[sel].size()); i++)
	{
		if (playing == false || init == true)
		{
			//setBackground(1);
			MyCMovingBitmap *x = new MyCMovingBitmap;
			x->LoadBitmapByString(stage1LoadBitMap[sel][i], RGB(255, 255, 255));
			x->SetTopLeft(stage1SetTopLeft[sel][i][0], stage1SetTopLeft[sel][i][1]);
			x->SetFrameIndexOfBitmap(0);
			stage.push_back(x);
			init = false;
			//playing = true;
		}
		else
		{
			for (int i = 0; i < int(stage.size()); i++)
			{
				stage[i]->SetTopLeft(stage1SetTopLeft[sel][i][0], stage1SetTopLeft[sel][i][1]);
				stage[i]->SetFrameIndexOfBitmap(0);
			}
			elementPo = false;
		}
		
	}
	
	
}

void backgroundTool::backgroundKeyDown(UINT nChar)
{
	if ((nChar == VK_RIGHT || nChar == VK_LEFT) && playing == false)//向右選關鍵
	{
		if (sel == 0)
			sel += 1;
		else
			sel = 0;
		totalSelect.SetFrameIndexOfBitmap(sel);
		if (sel == 0)
			totalSelect.SetTopLeft(600, 400);
		if (sel == 1)
			totalSelect.SetTopLeft(880, 400);

	}
	if (nChar == VK_RETURN) // VK_RETURN = Enter
	{
		if (sel == 0)
		{
			playing = true;
			background.SetFrameIndexOfBitmap(1); // background
			for (int i = 0; i < 2; i++)
			{
				totalSelect.SetFrameIndexOfBitmap(i);
				totalSelect.SetTopLeft(-600, -400);
			}
			select1.SetTopLeft(-600, -400);
			select2.SetTopLeft(-600, -400);
		}
	}
}

void backgroundTool::backroundShowBitmap()
{
	background.ShowBitmap();
	//floor1_2.ShowBitmap();
}

void backgroundTool::selectShowBitmap()
{
	select1.ShowBitmap();
	select2.ShowBitmap();
	totalSelect.ShowBitmap();
}

void backgroundTool::elementShowBitmap()
{
	for (int i = 0; i < int(stage.size()); i++)
	{
		stage[i]->ShowBitmap();
	}
	
}

int* backgroundTool::getSelAddress()
{
	return &sel;
}
/*
MyCMovingBitmap *backgroundTool::getFloor1_2Address()
{
	return &floor1_2;
}*/

MyCMovingBitmap *backgroundTool::getBackgroundAddress()
{
	return &background;
}

std::vector<MyCMovingBitmap *> *backgroundTool::getStageAddress()
{
	return &stage;
}

void backgroundTool::setSel(int value)
{
	sel = value;
}

void backgroundTool::setBackground(int value)
{
	background.SetFrameIndexOfBitmap(value);
}

void backgroundTool::setClearStage()
{
	for (int i = 0; i < int(stage.size()); i++)
	{
		delete stage[i];
	}
	stage.clear();
}

void backgroundTool::setPlaying(bool value)
{
	playing = value;
}

void backgroundTool::setInit(bool value)
{
	init = value;
}

void backgroundTool::touching(characterTool *character)
{
	
	stageTouchUpElement = 
	{
		{elementGo}
	};
	stageTouchUpEmpty =
	{
		{elementEmptyBlock, elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2}
	};

	switch (sel)
	{
	case 0:
		
		for (int j = 0; j < int(stageTouchUpElement[sel].size()); j++)
		{
			if (stage[stageTouchUpElement[sel][j]]->touchUp(character->getCharacterAddress(), stage[stageTouchUpElement[sel][j]]) )
				stage[stageTouchUpElement[sel][j]]->SetFrameIndexOfBitmap(1);
		}
		
		for (int j = 0; j < int(stageTouchUpEmpty[sel].size()); j++)
		{
			if (stage[stageTouchUpEmpty[sel][j]]->touchUp(character->getCharacterAddress(), stage[stageTouchUpEmpty[sel][j]]) && character->GetIsDroppingAddress() == false)
				stage[stageTouchUpEmpty[sel][j]]->SetFrameIndexOfBitmap(1);
		}
		

		if (stage[element]->touchUp(character->getCharacterAddress(), stage[element]))
		{
			stage[element]->SetFrameIndexOfBitmap(1);
			stage[elementGo]->SetFrameIndexOfBitmap(1);
			stage[elementGo]->SetTopLeft(background.GetLeft() + 617, background.GetTop() + 359);//300
		}

		if (stage[elementGo]->touchUp(character->getCharacterAddress(), stage[elementGo]))
		{
			stage[elementGo]->SetFrameIndexOfBitmap(2);
		}
		
		if (stage[elementDropFloor]->touchDown(character->getCharacterAddress(), stage[elementDropFloor]) || stage[elementDropFloor]->GetTop() > 863)
		{
			stage[elementDropFloor]->SetTopLeft(stage[elementDropFloor]->GetLeft(), stage[elementDropFloor]->GetTop() + 30);
		}

		if (background.IsOverlap(*(character->getCharacterAddress()), *stage[elementCloud]))
		{
			stage[elementCloud]->SetFrameIndexOfBitmap(1);
		}

		if (background.IsOverlap(*(character->getCharacterAddress()), *stage[elementGrass]))
		{
			stage[elementGrass]->SetFrameIndexOfBitmap(1);
		}
				
		if (stage[elementBlockU]->GetFrameIndexOfBitmap() == 1 && stage[elementBlockD]->GetFrameIndexOfBitmap() == 1 &&
			stage[elementBlockI]->GetFrameIndexOfBitmap() == 1 && stage[elementBlockE]->GetFrameIndexOfBitmap() == 1 &&
			stage[elementBlockD2]->GetFrameIndexOfBitmap() == 1)
		{
			if (elementPo == false)
			{
				stage[elementPoRight]->SetTopLeft(background.GetLeft() + 3850, background.GetTop() + 760);
				stage[elementPoLeft]->SetTopLeft(background.GetLeft() + 5000, background.GetTop() + 650);
				elementPo = true;
			}
			else
			{
				stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() - 2, stage[elementPoLeft]->GetTop());
				stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() + 2, stage[elementPoRight]->GetTop());

			}

		}

		if (stage[elementPipe2]->touchDown(character->getCharacterAddress(), stage[elementPipe2]))
		{
			if (elementPo1_2 == false)
			{
				stage[elementPoUp]->SetTopLeft(background.GetLeft() + 5000, background.GetTop() + 600);
				elementPo1_2 = true;
			}

		}

		if (elementPo1_2 == true)
		{
			stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft(), stage[elementPoUp]->GetTop() - 10);
			if (stage[elementPoUp]->GetTop() < -200)
			{
				elementPo1_2 = false;
			}
		}
		
		if (background.IsOverlap(*(character->getCharacterAddress()), *stage[elementKey]))
		{
			stage[elementKey]->SetTopLeft(-1000, -1000);
			stage[elementPrick1]->SetTopLeft(background.GetLeft() + 2528, background.GetTop() + 195);
			stage[elementPrick2]->SetTopLeft(background.GetLeft() + 3268, background.GetTop() + 195);
		}
		break;
	}

	

	elementShowBitmap();
	
}

bool backgroundTool::getPlaying()
{
	return playing;
}


void backgroundTool::Move(characterTool *run_character)
{
	stageJudgeMove =
	{
		{elementPoLeft, elementPoRight, elementPoUp},
		{}
	};
	if (playing)
	{
		if (buttonA && run_character->GetBackHitblock() == false)
		{			
			//floor1_2.SetTopLeft(floor1_2.GetLeft() + 20 - buttonD * 2, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() + 20 - buttonD * 2, background.GetTop());
			for (int i = 0; i < int(stage.size()); i++)
			{
				for (int j = 0; j < int(stageJudgeMove[sel].size()); j++)
				{
					if (i == stageJudgeMove[sel][j])
					{
						judgeMove = true;
					}						
				}
				if (judgeMove == false)
				{
					stage[i]->SetTopLeft(stage[i]->GetLeft() + 20 - buttonD * 2, stage[i]->GetTop());
				}
				judgeMove = false;
					
			}
			switch (sel)
			{
			case 0:
				if (elementPo == true)
				{
					stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() + 20 - buttonD * 2, stage[elementPoRight]->GetTop());
					stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() + 20 - buttonD * 2, stage[elementPoLeft]->GetTop());
				}
				if (elementPo1_2 == true)
				{
					stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() + 20 - buttonD * 2, stage[elementPoUp]->GetTop());
				}
				break;
			}
						
		}


		

		if (buttonD && run_character->GetFaceHitblock() == false)
		{			
			//floor1_2.SetTopLeft(floor1_2.GetLeft() - 20 + buttonD * 2, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() - 20 + buttonD * 2, background.GetTop());
			for (int i = 0; i < int(stage.size()); i++)
			{
				for (int j = 0; j < int(stageJudgeMove[sel].size()); j++)
				{
					if (i == stageJudgeMove[sel][j])
					{
						judgeMove = true;
					}
				}
				if (judgeMove == false)
				{
					stage[i]->SetTopLeft(stage[i]->GetLeft() - 20 + buttonD * 2, stage[i]->GetTop());
				}
				judgeMove = false;

			}
				
			switch (sel)
			{
			case 0:
				if (elementPo == true)
				{
					stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() - 20 + buttonD * 2, stage[elementPoRight]->GetTop());
					stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() - 20 + buttonD * 2, stage[elementPoLeft]->GetTop());
				}
				if (elementPo1_2 == true)
				{
					stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() - 20 + buttonD * 2, stage[elementPoUp]->GetTop());
					break;
				}
			}	

		}
	}
	
	
}

void backgroundTool::KeyDown(UINT nChar)
{
	
	if (nChar == 0x57)//W
	{		
		buttonW = true;		
	}
	if (nChar == 0x53)//S
	{
		
	}
	if (nChar == 0x41)//A
	{
		buttonA = true;
	}
	
	if (nChar == 0x44)//D
	{
		buttonD = true;
	}
}


void backgroundTool::KeyUp(UINT nChar)
{
	if (nChar == 0x57)//W
	{
		buttonW = false;
	}
	if (nChar == 0x53)//S
	{
		
	}
	if (nChar == 0x41)//A
	{
		buttonA = false;
	}
	if (nChar == 0x44)//D
	{
		buttonD = false;
	}
}