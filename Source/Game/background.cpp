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
		"resources/level2.bmp",
		"resources/level3.bmp"
		}, 0);
	background.SetTopLeft(0, 0);
	start = clock();
	
}

void backgroundTool::selectInit()
{
	select1.LoadBitmapByString({ "resources/select1.bmp" }, RGB(255, 255, 255));
	select1.SetTopLeft(600, 400);

	select2.LoadBitmapByString({ "resources/select2.bmp" }, RGB(255, 255, 255));
	select2.SetTopLeft(880, 400);

	select3.LoadBitmapByString({ "resources/select3.bmp" }, RGB(255, 255, 255));
	select3.SetTopLeft(1160, 400);

	totalSelect.LoadBitmapByString({ "resources/select1_2.bmp", "resources/select2_1.bmp", "resources/select3_1.bmp" }, RGB(255, 255, 255));
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
			{ "resources/PoUp.bmp" }, { "resources/key.bmp" },
			{ "resources/prick1.bmp" }, { "resources/pipe.bmp" },//
			{ "resources/emptyBlock.bmp","resources/blackBlock.bmp" }, { "resources/emptyBlock.bmp","resources/blackBlockU.bmp" },
			{ "resources/emptyBlock.bmp","resources/blackBlockD.bmp" }, { "resources/emptyBlock.bmp","resources/blackBlockI.bmp" },
			{ "resources/emptyBlock.bmp","resources/blackBlockE.bmp" }, { "resources/emptyBlock.bmp","resources/blackBlock!.bmp" },
			{ "resources/PoRight.bmp"}, { "resources/PoLeft.bmp" },
			{ "resources/prick2.bmp" }, { "resources/dropFloor.bmp" },//
			{ "resources/lady.bmp" }, {	"resources/floor1_1.bmp"},
			{ "resources/floor1_2.bmp"}, { "resources/floor1_3.bmp"}//2x13							
		},
		{
			{ "resources/flower2_1.bmp" },{	"resources/floor2_1.bmp"},
			{ "resources/dropFloor2_1.bmp" }, { "resources/floor2_2.bmp"}, 
			{ "resources/dropFloor2_2.bmp" }, { "resources/floor2_3.bmp"},
			{ "resources/brickChip/chip1.bmp","resources/brickChip/chip2.bmp","resources/brickChip/chip3.bmp","resources/brickChip/chip4.bmp","resources/brickChip/chip5.bmp","resources/brickChip/chip6.bmp","resources/brickChip/chip7.bmp" }, { "resources/hit.bmp","resources/hitDie.bmp"},
			{ "resources/longBlock2_1.bmp" }, { "resources/longBlock2_2.bmp" },
			{ "resources/verticalLongBlock2_1.bmp" }, { "resources/prick2_1.bmp" },
			{ "resources/emptyBlock.bmp", "resources/blackBlock.bmp"}, { "resources/whiteBlock.bmp","resources/blackBlock.bmp" },
			{ "resources/doublePoLeft.bmp" }, { "resources/emptyBlock.bmp", "resources/blackBlock.bmp"},
			{ "resources/emptyBlock.bmp", "resources/blackBlock.bmp"}, { "resources/slime2_1.bmp", "resources/slime2_1.bmp"},
			{ "resources/lady.bmp" }
		},
		{
			{ "resources/clock3_1.bmp", "resources/clock3_2.bmp", "resources/clock3_3.bmp"}, { "resources/stagePicture3_1.bmp" }
		}
	};
	stage1SetTopLeft =
	{
		{
			{427, 539}, {0, 0}, {1600, -20}, {1500, 539}, {2375, 800}, {2527, 538}, {2686, 220}, {3790, 538}, {-1000, -1000}, {2858, 410},
			{-1000, -1000}, {4900, 538}, {4120, 175}, {4109, 539}, {4268, 539}, {4427, 539}, {4586, 539}, {4745,539}, {-1000, -1000}, {-1000, -1000},
			{-1000, -1000}, {5455, 863}, {6054, 730}, {0, 860}, {1971, 860}, {5769, 860} //2x10+6
		},
		{
			{-1000, -1000}, {0, 860}, {794, 862}, {1740, 862}, {4595, 860}, {5716, 860}, {-1000, -1000}, {870, 384}, {1660, 236}, {3097, 540},
			{4755, 51}, {2696, 830}, {2947, 236}, {558,539}, {-1000, -1000}, {4599, 533}, {4429, 179}, {3907, 459}, {5725, 730}//
		},
		{
			{1600, 160}, {0, 0}
		}
	};
	std::vector<vector<int>> takeOutWite = 
	{ 
		{elementPoUp, elementPoRight, elementPoLeft},
		{},
		{}
	};

	bool judge = false;
	

	for (int i = 0; i < int(stage1LoadBitMap[sel].size()); i++)
	{
		
		if (playing == false || init == true)
		{
			MyCMovingBitmap *x = new MyCMovingBitmap;
			for (int j = 0; j < int(takeOutWite[sel].size()); j++)
			{
				if (i == takeOutWite[sel][j])
				{
					judge = true;
				}
			}
			if (judge == false)
			{
				x->LoadBitmapByString(stage1LoadBitMap[sel][i]);
			}
			else
			{
				x->LoadBitmapByString(stage1LoadBitMap[sel][i], RGB(255, 255, 255));
			}
			judge = false;			
			x->SetTopLeft(stage1SetTopLeft[sel][i][0], stage1SetTopLeft[sel][i][1]);
			x->SetFrameIndexOfBitmap(0);
			stage.push_back(x);			
		}
		else
		{
			for (int i = 0; i < int(stage.size()); i++)
			{
				stage[i]->SetTopLeft(stage1SetTopLeft[sel][i][0], stage1SetTopLeft[sel][i][1]);
				stage[i]->SetFrameIndexOfBitmap(0);
				stage[i]->SetJudge(false);
				stage[i]->SetElementPo(false);
				stage[i]->SetJudge(false);
			}
			
		}
		
	}
	elementPo = false;
	init = false;
	judgeMove = false;
	elementFlower = false;
	longblock = false;

}

void backgroundTool::goBackContent()
{
	playing = false;
	init = false;
	elementTrue = false;
	elementPo = false;
	elementPo1_2 = false;
	sel = 0;
	buttonW = false;
	buttonA = false;
	buttonD = false;
	judgeMove = false;
	first = false;
	elementFlower = false;
	longblock = false;
	setClearStage();
	elementInit();
	selectInit();
	totalSelect.SetFrameIndexOfBitmap(0);
	background.SetTopLeft(0, 0);
	background.SetFrameIndexOfBitmap(0);
}


void backgroundTool::backgroundKeyDown(UINT nChar, characterTool *characterAddress)
{
	MyCMovingBitmap *character = characterAddress->getCharacterAddress();
	if ((nChar == 0x50) && playing == true)
	{
		goBackContent();
	}
	if ((nChar == VK_RIGHT || nChar == VK_LEFT) && playing == false)//向右選關鍵
	{		

		if (nChar == VK_RIGHT && sel < 2)
			sel += 1;
		else if (nChar == VK_RIGHT && sel == 2)
			sel = 0;

		if (nChar == VK_LEFT && sel > 0)
			sel -= 1;
		else if (nChar == VK_LEFT && sel == 0)
			sel = 2;


		totalSelect.SetFrameIndexOfBitmap(sel); // set level's image

		for (int i = 0; i < 3; i++) // there are 3 stages
		{
			if (sel == i)
				totalSelect.SetTopLeft(600 + 280 * i, 400);
		}
	}

	if (nChar == VK_RETURN && playing == false) // VK_RETURN = Enter
	{
		if (sel == 0)
		{
			setClearStage();
			init = true;
			playing = true;
			elementInit();
			characterAddress->characterInit();
			background.SetFrameIndexOfBitmap(1); // enter the level
			for (int i = 0; i < 3; i++) // origin i < 2
			{
				totalSelect.SetFrameIndexOfBitmap(i);
				totalSelect.SetTopLeft(-600, -400);
			}
			select1.SetTopLeft(-600, -400);
			select2.SetTopLeft(-600, -400);
			select3.SetTopLeft(-600, -400);
		}
		if (sel == 1)
		{
			setClearStage();
			init = true;
			playing = true;
			elementInit();
			characterAddress->characterInit();
			background.SetFrameIndexOfBitmap(2); // enter the level
			for (int i = 0; i < 3; i++) // origin i < 2
			{
				totalSelect.SetFrameIndexOfBitmap(i);
				totalSelect.SetTopLeft(-600, -400);
			}
			select1.SetTopLeft(-600, -400);
			select2.SetTopLeft(-600, -400);
			select3.SetTopLeft(-600, -400);
		}
		if (sel == 2)
		{
			characterAddress->characterInit();
			character->SetTopLeft(-2000, -2000);
			setClearStage();
			init = true;
			playing = true;
			elementInit();
			background.SetFrameIndexOfBitmap(3); // enter the level
			for (int i = 0; i < 3; i++) // origin i < 2
			{
				totalSelect.SetFrameIndexOfBitmap(i);
				totalSelect.SetTopLeft(-600, -400);
			}
			select1.SetTopLeft(-600, -400);
			select2.SetTopLeft(-600, -400);
			select3.SetTopLeft(-600, -400);
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
	select3.ShowBitmap();
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
		{},
		{},
		{}
	};
	stageTouchUpEmpty =
	{
		{elementEmptyBlock, elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2},
		{elementEmptyBlock2_1, elementEmptyBlock2_2, elementEmptyBlock2_3},
		{}
	};
	for (int j = 0; j < int(stageTouchUpElement[sel].size()); j++)
	{
		if (stage[stageTouchUpElement[sel][j]]->touchUp(character->getCharacterAddress(), stage[stageTouchUpElement[sel][j]]))
			stage[stageTouchUpElement[sel][j]]->SetFrameIndexOfBitmap(1);
	}

	for (int j = 0; j < int(stageTouchUpEmpty[sel].size()); j++)
	{
		if (stage[stageTouchUpEmpty[sel][j]]->touchUp(character->getCharacterAddress(), stage[stageTouchUpEmpty[sel][j]]) && character->GetIsDroppingAddress() == false)
			stage[stageTouchUpEmpty[sel][j]]->SetFrameIndexOfBitmap(1);
	}
	switch (sel)
	{
	case 0:		

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

	case 1:
		if (stage[elementQuestion]->touchDown(character->getCharacterAddress(), stage[elementQuestion]))
		{
			if (first == false)
			{
				start = clock();
				first = true;
			}
		}
		if (first == true)
		{
			if (1 - ((clock() - start) / (double)(CLOCKS_PER_SEC)) <= 0.5)
			{
				stage[brick]->SetTopLeft(background.GetLeft() + 508, background.GetTop() + 489);
				stage[elementQuestion]->SetTopLeft(-1000, -1000);
				stage[brick]->SetAnimation(100, false);
				stage[brick]->SetAnimation(100, true);
				first = false;
			}
		}

		if (stage[elementHit]->touchUp(character->getCharacterAddress(), stage[elementHit]))
		{
			stage[elementHit]->SetFrameIndexOfBitmap(1);
		}
		
		if (stage[elementQuestion]->touchUp(character->getCharacterAddress(), stage[elementQuestion]) && stage[elementQuestion]->GetFrameIndexOfBitmap() == 0)
		{
			stage[elementQuestion]->SetFrameIndexOfBitmap(1);
			elementFlower = true;			 
			stage[elementFlower2_1]->SetTopLeft(background.GetLeft() + 585, background.GetTop() + 536);
		}
		if (elementFlower == true && stage[elementFlower2_1]->GetTop() > 445)
		{			
			stage[elementFlower2_1]->SetTopLeft(stage[elementFlower2_1]->GetLeft(), stage[elementFlower2_1]->GetTop() - 5);
		}
		if ((character->getCharacterAddress())->GetLeft() > background.GetLeft() + 1720 && (character->getCharacterAddress())->GetLeft() < background.GetLeft() + 2000 && (character->getCharacterAddress())->GetTop() > 300)
		{
			longblock = true;
		}
		if (longblock == true)
		{
			stage[elementLongBlock2_1]->SetTopLeft(stage[elementLongBlock2_1]->GetLeft(), stage[elementLongBlock2_1]->GetTop() + 20);
			if (stage[elementDropFloor2_1]->touchDown(character->getCharacterAddress(), stage[elementDropFloor2_1]))
			{
				stage[elementDropFloor2_1]->SetTopLeft(stage[elementDropFloor2_1]->GetLeft(), stage[elementDropFloor2_1]->GetTop() + 20);
			}
		}
		if (stage[elementLongBlock2_1]->touchDown(character->getCharacterAddress(), stage[elementLongBlock2_1]))
		{
			if (elementPo == false)
			{
				stage[elementDoublePoLeft]->SetTopLeft(background.GetLeft() + 2650, background.GetTop() + 10);
				elementPo = true;
			}			
		}
		if (elementPo == true)
		{
			stage[elementDoublePoLeft]->SetTopLeft(stage[elementDoublePoLeft]->GetLeft() - 45, stage[elementDoublePoLeft]->GetTop());
		}
				
		if ((character->getCharacterAddress())->GetLeft() > background.GetLeft() + 4800 && (character->getCharacterAddress())->GetLeft() < background.GetLeft() + 4900 && (character->getCharacterAddress())->GetTop() > 300)
		{
			stage[elementDropFloor2_2]->SetJudge(true);
		}

		if (stage[elementDropFloor2_2]->GetJudge() == true)
		{
			stage[elementDropFloor2_2]->SetTopLeft(stage[elementDropFloor2_2]->GetLeft(), stage[elementDropFloor2_2]->GetTop() + 20);
		}
		
		if (stage[elementLongBlock2_2]->touchDown(character->getCharacterAddress(), stage[elementLongBlock2_2]))
		{
			stage[elementLongBlock2_2]->SetJudge(true);
		}
		if (stage[elementLongBlock2_2]->GetJudge() == true)
		{
			stage[elenentslime2_1]->SetTopLeft(stage[elenentslime2_1]->GetLeft() - 5, stage[elenentslime2_1]->GetTop());
		}
		
		break;	

		
	}
	
	elementShowBitmap();
	
}

bool backgroundTool::getPlaying()
{
	return playing;
}

bool backgroundTool::getInit()
{
	return init;
}

void backgroundTool::Move(characterTool *run_character)
{
	MyCMovingBitmap *character = run_character->getCharacterAddress();
	stageJudgeMove =
	{
		{elementPoLeft, elementPoRight, elementPoUp},
		{},
		{}
	};
	std::vector<vector<int>> map;
	map=
	{
		{-4400},
		{-3950},
		{0}
	};
	
	if (playing && sel != 2)
	{
		if (buttonA && run_character->GetBackHitblock() == false && run_character->GetpopUpFlag() == false && character->GetLeft() > 900 && character->GetLeft() < 960)
		{			
			background.SetTopLeft(background.GetLeft() + 20 - buttonW * 2, background.GetTop());//
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
					stage[i]->SetTopLeft(stage[i]->GetLeft() + 20 - buttonW * 2, stage[i]->GetTop());
				}
				judgeMove = false;
					
			}
			switch (sel)
			{
			case 0:
				if (elementPo == true)
				{
					stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() + 20 - buttonW * 2, stage[elementPoRight]->GetTop());
					stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() + 20 - buttonW * 2, stage[elementPoLeft]->GetTop());
				}
				if (elementPo1_2 == true)
				{
					stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() + 20 - buttonW * 2, stage[elementPoUp]->GetTop());
				}
				break;
			}
						
		}


		

		if (buttonD && run_character->GetFaceHitblock() == false && run_character->GetpopUpFlag() == false && (character->GetLeft() > 900 && character->GetLeft() < 960) && background.GetLeft() > map[sel][0])// 
		{			
			//floor1_2.SetTopLeft(floor1_2.GetLeft() - 20 + buttonD * 2, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() - 20 + buttonW * 2, background.GetTop());
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
					stage[i]->SetTopLeft(stage[i]->GetLeft() - 20 + buttonW * 2, stage[i]->GetTop());
				}
				judgeMove = false;

			}
				
			switch (sel)
			{
			case 0:
				if (elementPo == true)
				{
					stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() - 20 + buttonW * 2, stage[elementPoRight]->GetTop());
					stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() - 20 + buttonW * 2, stage[elementPoLeft]->GetTop());
				}
				if (elementPo1_2 == true)
				{
					stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() - 20 + buttonW * 2, stage[elementPoUp]->GetTop());
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