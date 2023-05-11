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
	background.LoadBitmapByString({
		"resources/background3.bmp",
		"resources/level1.bmp"
		}, 0);
	background.SetTopLeft(0, 0);

	floor1_2.LoadBitmapByString({
		"resources/floor2.bmp",
		});
	floor1_2.SetTopLeft(1971, 860);
	
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
	//vector<MyCMovingBitmap *>().swap(stage);
	stage1LoadBitMap =
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
		{ "resources/lady.bmp" }								
	};//2x11+1
	stage1SetTopLeft =
	{
		{427, 539}, {0, 0}, {1600, -20}, {1500, 539}, {2375, 800}, {2527, 538}, {2686, 220}, {3790, 538}, {4900, 538}, {2858, 410},
		{-1000, -1000}, {-1000, -1000}, {4120, 175}, {4109, 539}, {4268, 539}, {4427, 539}, {4586, 539}, {4745,539}, {-1000, -1000}, {-1000, -1000},
		{-1000, -1000}, {5454, 863}, {6054, 730}
	};//2x10+3
	
	
	for (int i = 0; i < 23; i++)
	{
		if (playing == false)
		{
			MyCMovingBitmap *x = new MyCMovingBitmap;
			x->LoadBitmapByString(stage1LoadBitMap[i], RGB(255, 255, 255));
			x->SetTopLeft(stage1SetTopLeft[i][0], stage1SetTopLeft[i][1]);
			x->SetFrameIndexOfBitmap(0);
			stage.push_back(x);
		}
		else
		{
			for (int i = 0; i < int(stage.size()); i++)
			{
				stage[i]->SetTopLeft(stage1SetTopLeft[i][0], stage1SetTopLeft[i][1]);
				stage[i]->SetFrameIndexOfBitmap(0);
			}
			elementPo = false;
		}
		
	}
	
	/*
	stage[0]->LoadBitmapByString({ "resources/whiteBlock.bmp","resources/blackBlock.bmp" }, RGB(255, 255, 255));
	element.SetTopLeft(427, 539);
	element.SetFrameIndexOfBitmap(0);

	elementGo.LoadBitmapByString({ "resources/nothing.bmp","resources/go.bmp","resources/godie.bmp" }, RGB(255, 255, 255));
	elementGo.SetFrameIndexOfBitmap(0);
	elementGo.SetTopLeft(0,0);
	
	elementCloud.LoadBitmapByString({ "resources/cloud.bmp","resources/clouddie.bmp" }, RGB(255, 255, 255));
	elementCloud.SetFrameIndexOfBitmap(0);
	elementCloud.SetTopLeft(1600, -20);

	elementEmptyBlock.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlock.bmp" }, RGB(255, 255, 255));
	elementEmptyBlock.SetFrameIndexOfBitmap(0);
	elementEmptyBlock.SetTopLeft(1500, 539);

	elementGrass.LoadBitmapByString({ "resources/grass.bmp","resources/grassdie.bmp" }, RGB(255, 255, 255));
	elementGrass.SetFrameIndexOfBitmap(0);
	elementGrass.SetTopLeft(2375, 800);

	elementLongBlock.LoadBitmapByString({ "resources/longBlock.bmp" }, RGB(255, 255, 255));
	elementLongBlock.SetFrameIndexOfBitmap(0);
	elementLongBlock.SetTopLeft(2527, 538);

	elementShortBlock.LoadBitmapByString({ "resources/shortBlock.bmp" }, RGB(255, 255, 255));
	elementShortBlock.SetTopLeft(2686, 220);

	elementPipe1.LoadBitmapByString({ "resources/pipe.bmp" }, RGB(255, 255, 255));
	elementPipe1.SetTopLeft(3790, 538);

	elementPipe2.LoadBitmapByString({ "resources/pipe.bmp" });
	elementPipe2.SetTopLeft(4900, 538);

	elementKey.LoadBitmapByString({ "resources/key.bmp" }, RGB(255, 255, 255));
	elementKey.SetTopLeft(2858, 410);

	elementPrick1.LoadBitmapByString({ "resources/prick1.bmp" }, RGB(255, 255, 255));
	elementPrick1.SetTopLeft(-1000, -1000);
	
	elementPrick2.LoadBitmapByString({ "resources/prick2.bmp" }, RGB(255, 255, 255));
	elementPrick2.SetTopLeft(-1000, -1000);
	
	elementEmptyBlock2.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlock.bmp" }, RGB(255, 255, 255));
	elementEmptyBlock2.SetFrameIndexOfBitmap(0);
	elementEmptyBlock2.SetTopLeft(4120, 175);

	elementBlockU.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlockU.bmp" }, RGB(255, 255, 255));
	elementBlockU.SetFrameIndexOfBitmap(0);
	elementBlockU.SetTopLeft(4109, 539);

	elementBlockD.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlockD.bmp" }, RGB(255, 255, 255));
	elementBlockD.SetFrameIndexOfBitmap(0);
	elementBlockD.SetTopLeft(4268, 539);

	elementBlockI.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlockI.bmp" }, RGB(255, 255, 255));
	elementBlockI.SetFrameIndexOfBitmap(0);
	elementBlockI.SetTopLeft(4427, 539);

	elementBlockE.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlockE.bmp" }, RGB(255, 255, 255));
	elementBlockE.SetFrameIndexOfBitmap(0);
	elementBlockE.SetTopLeft(4586, 539);

	elementBlockD2.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlock!.bmp" }, RGB(255, 255, 255));
	elementBlockD2.SetFrameIndexOfBitmap(0);
	elementBlockD2.SetTopLeft(4745, 539);

	elementPoRight.LoadBitmapByString({ "resources/PoRight.bmp"}, RGB(255, 255, 255));
	elementPoRight.SetFrameIndexOfBitmap(0);
	elementPoRight.SetTopLeft(-1000, -1000);

	elementPoLeft.LoadBitmapByString({ "resources/PoLeft.bmp" }, RGB(255, 255, 255));
	elementPoLeft.SetFrameIndexOfBitmap(0);
	elementPoLeft.SetTopLeft(-1000, -1000);

	elementPoUp.LoadBitmapByString({ "resources/PoUp.bmp" }, RGB(255, 255, 255));
	elementPoUp.SetFrameIndexOfBitmap(0);
	elementPoUp.SetTopLeft(-1000, -1000);

	elementDropFloor.LoadBitmapByString({ "resources/dropFloor.bmp" }, RGB(255, 255, 255));
	elementDropFloor.SetFrameIndexOfBitmap(0);
	elementDropFloor.SetTopLeft(5454, 863);

	elementLady.LoadBitmapByString({ "resources/lady.bmp" }, RGB(255, 255, 255));
	elementLady.SetFrameIndexOfBitmap(0);
	elementLady.SetTopLeft(6054, 730);

	elementPo = false;
	elementPo1_2 = false;
	*/
}

void backgroundTool::backgroundKeyDown(UINT nChar)
{
	if ((nChar == VK_RIGHT || nChar == VK_LEFT) && playing == false)//向右選關鍵
	{
		if (sel < 1)
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
	floor1_2.ShowBitmap();
}

void backgroundTool::selectShowBitmap()
{
	select1.ShowBitmap();
	select2.ShowBitmap();
	totalSelect.ShowBitmap();
}

void backgroundTool::elementShowBitmap()
{
	for (int i = 0; i < 23; i++)
	{
		//MyCMovingBitmap a;
		//a = *(stage[0]);
		//a.ShowBitmap();
		//stage[0]->ShowBitmap();
		stage[i]->ShowBitmap();

	}
	/*
	element.ShowBitmap();
	elementGo.ShowBitmap();
	elementCloud.ShowBitmap();
	elementEmptyBlock.ShowBitmap();
	elementGrass.ShowBitmap();
	elementLongBlock.ShowBitmap();
	elementShortBlock.ShowBitmap();
	elementPipe1.ShowBitmap();
	elementPoUp.ShowBitmap();
	elementPipe2.ShowBitmap();
	elementKey.ShowBitmap();
	elementPrick1.ShowBitmap();
	elementPrick2.ShowBitmap();
	elementEmptyBlock2.ShowBitmap();
	elementBlockU.ShowBitmap();
	elementBlockD.ShowBitmap();
	elementBlockI.ShowBitmap();
	elementBlockE.ShowBitmap();
	elementBlockD2.ShowBitmap();
	elementPoRight.ShowBitmap();
	elementPoLeft.ShowBitmap();
	elementDropFloor.ShowBitmap();
	elementLady.ShowBitmap();
	*/
}

MyCMovingBitmap *backgroundTool::getFloor1_2Address()
{
	return &floor1_2;
}

MyCMovingBitmap *backgroundTool::getBackgroundAddress()
{
	return &background;
}
/*
MyCMovingBitmap *backgroundTool::getElementAddress()
{
	return &element;
}

MyCMovingBitmap *backgroundTool::getElementGoAddress()
{
	return &elementGo;
}

MyCMovingBitmap *backgroundTool::getElementCloudAddress()
{
	return &elementCloud;
}

MyCMovingBitmap *backgroundTool::getElementEmptyBlockAddress()
{
	return &elementEmptyBlock;
}

MyCMovingBitmap *backgroundTool::getElementGrassAddress()
{
	return &elementGrass;
}

MyCMovingBitmap *backgroundTool::getElementLongBlockAddress()
{
	return &elementLongBlock;
}

MyCMovingBitmap *backgroundTool::getElementShortBlockAddress()
{
	return &elementShortBlock;
}

MyCMovingBitmap *backgroundTool::getElementPipe1Address()
{
	return &elementPipe1;
}

MyCMovingBitmap *backgroundTool::getElementPipe2Address()
{
	return &elementPipe2;
}

MyCMovingBitmap *backgroundTool::getElementPrick1Address()
{
	return &elementPrick1;
}

MyCMovingBitmap *backgroundTool::getElementPrick2Address()
{
	return &elementPrick2;
}

MyCMovingBitmap *backgroundTool::getElementEmptyBlock2Address()
{
	return &elementEmptyBlock2;
}

MyCMovingBitmap *backgroundTool::getElementBlockUAddress()
{
	return &elementBlockU;
}

MyCMovingBitmap *backgroundTool::getElementBlockDAddress()
{
	return &elementBlockD;
}

MyCMovingBitmap *backgroundTool::getElementBlockIAddress()
{
	return &elementBlockI;
}

MyCMovingBitmap *backgroundTool::getElementBlockEAddress()
{
	return &elementBlockE;
}

MyCMovingBitmap *backgroundTool::getElementBlockD2Address()
{
	return &elementBlockD2;
}

MyCMovingBitmap *backgroundTool::getElementPoRightAddress()
{
	return &elementPoRight;
}

MyCMovingBitmap *backgroundTool::getElementPoLeftAddress()
{
	return &elementPoLeft;
}

MyCMovingBitmap *backgroundTool::getElementPoUpAddress()
{
	return &elementPoUp;
}

MyCMovingBitmap *backgroundTool::getElementDropFloorAddress()
{
	return &elementDropFloor;
}

*/
std::vector<MyCMovingBitmap *> *backgroundTool::getStageAddress()
{
	return &stage;
}


void backgroundTool::touching(characterTool *character)
{
	
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

	if (stage[elementEmptyBlock]->touchUp(character->getCharacterAddress(), stage[elementEmptyBlock]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementEmptyBlock]->SetFrameIndexOfBitmap(1);
	}

	if (stage[elementEmptyBlock2]->touchUp(character->getCharacterAddress(), stage[elementEmptyBlock2]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementEmptyBlock2]->SetFrameIndexOfBitmap(1);
	}

	if (stage[elementBlockU]->touchUp(character->getCharacterAddress(), stage[elementBlockU]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementBlockU]->SetFrameIndexOfBitmap(1);
	}

	if (stage[elementBlockD]->touchUp(character->getCharacterAddress(), stage[elementBlockD]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementBlockD]->SetFrameIndexOfBitmap(1);
	}

	if (stage[elementBlockI]->touchUp(character->getCharacterAddress(), stage[elementBlockI]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementBlockI]->SetFrameIndexOfBitmap(1);
	}

	if (stage[elementBlockE]->touchUp(character->getCharacterAddress(), stage[elementBlockE]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementBlockE]->SetFrameIndexOfBitmap(1);
	}

	if (stage[elementBlockD]->touchUp(character->getCharacterAddress(), stage[elementBlockD2]) && character->GetIsDroppingAddress() == false)
	{
		stage[elementBlockD2]->SetFrameIndexOfBitmap(1);
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

	elementShowBitmap();
	
}

bool backgroundTool::getPlaying()
{
	return playing;
}


void backgroundTool::Move(characterTool *run_character)
{

	if (buttonA && run_character->GetBackHitblock() == false)
	{
		if (buttonW == false) //沒有跳躍的時候地圖正常跑
		{
			floor1_2.SetTopLeft(floor1_2.GetLeft() + 20, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() + 20, background.GetTop());
			for (int i = 0; i < 23; i++)
			{
				if (i == elementPoLeft || i == elementPoRight || i == elementPoUp)
				{
					
					continue;
				}
				else
				{
					stage[i]->SetTopLeft(stage[i]->GetLeft() + 20, stage[i]->GetTop());
				}
			}

			if (elementPo == true)
			{
				stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() + 20, stage[elementPoRight]->GetTop());
				stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() + 20, stage[elementPoLeft]->GetTop());
			}
			if (elementPo1_2 == true)
			{
				stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() + 20, stage[elementPoUp]->GetTop());
			}
			/*
			element.SetTopLeft(element.GetLeft() + 20, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() + 20, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() + 20, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() + 20, elementEmptyBlock.GetTop());
			elementGrass.SetTopLeft(elementGrass.GetLeft() + 20, elementGrass.GetTop());
			elementLongBlock.SetTopLeft(elementLongBlock.GetLeft() + 20, elementLongBlock.GetTop());
			elementShortBlock.SetTopLeft(elementShortBlock.GetLeft() + 20, elementShortBlock.GetTop());
			elementPipe1.SetTopLeft(elementPipe1.GetLeft() + 20, elementPipe1.GetTop());
			elementPipe2.SetTopLeft(elementPipe2.GetLeft() + 20, elementPipe2.GetTop());
			elementKey.SetTopLeft(elementKey.GetLeft() + 20, elementKey.GetTop());
			elementPrick1.SetTopLeft(elementPrick1.GetLeft() + 20, elementPrick1.GetTop());
			elementPrick2.SetTopLeft(elementPrick2.GetLeft() + 20, elementPrick2.GetTop());
			elementEmptyBlock2.SetTopLeft(elementEmptyBlock2.GetLeft() + 20, elementEmptyBlock2.GetTop());
			elementBlockU.SetTopLeft(elementBlockU.GetLeft() + 20, elementBlockU.GetTop());
			elementBlockD.SetTopLeft(elementBlockD.GetLeft() + 20, elementBlockD.GetTop());
			elementBlockI.SetTopLeft(elementBlockI.GetLeft() + 20, elementBlockI.GetTop());
			elementBlockE.SetTopLeft(elementBlockE.GetLeft() + 20, elementBlockE.GetTop());
			elementBlockD2.SetTopLeft(elementBlockD2.GetLeft() + 20, elementBlockD2.GetTop());
			elementDropFloor.SetTopLeft(elementDropFloor.GetLeft() + 20, elementDropFloor.GetTop());
			elementLady.SetTopLeft(elementLady.GetLeft() + 20, elementLady.GetTop());
			*/

			

		}
		else //有跳躍的時候地圖要跑比較慢，因為有強制墬落
		{
			floor1_2.SetTopLeft(floor1_2.GetLeft() + 15, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() + 15, background.GetTop());
			for (int i = 0; i < 23; i++)
			{
				if (i == elementPoLeft || i == elementPoRight || i==elementPoUp)
				{
					continue;
				}
				else
				{
					stage[i]->SetTopLeft(stage[i]->GetLeft() + 15, stage[i]->GetTop());
				}
			}

			if (elementPo == true)
			{
				stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() + 15, stage[elementPoRight]->GetTop());
				stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() + 15, stage[elementPoLeft]->GetTop());
			}
			if (elementPo1_2 == true)
			{
				stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() + 15, stage[elementPoUp]->GetTop());
			}
			/*element.SetTopLeft(element.GetLeft() + 20, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() + 20, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() + 20, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() + 20, elementEmptyBlock.GetTop());
			elementGrass.SetTopLeft(elementGrass.GetLeft() + 20, elementGrass.GetTop());
			elementLongBlock.SetTopLeft(elementLongBlock.GetLeft() + 20, elementLongBlock.GetTop());
			elementShortBlock.SetTopLeft(elementShortBlock.GetLeft() + 20, elementShortBlock.GetTop());
			elementPipe1.SetTopLeft(elementPipe1.GetLeft() + 20, elementPipe1.GetTop());
			elementPipe2.SetTopLeft(elementPipe2.GetLeft() + 20, elementPipe2.GetTop());
			elementKey.SetTopLeft(elementKey.GetLeft() + 20, elementKey.GetTop());
			elementPrick1.SetTopLeft(elementPrick1.GetLeft() + 20, elementPrick1.GetTop());
			elementPrick2.SetTopLeft(elementPrick2.GetLeft() + 20, elementPrick2.GetTop());
			elementEmptyBlock2.SetTopLeft(elementEmptyBlock2.GetLeft() + 20, elementEmptyBlock2.GetTop());
			elementBlockU.SetTopLeft(elementBlockU.GetLeft() + 20, elementBlockU.GetTop());
			elementBlockD.SetTopLeft(elementBlockD.GetLeft() + 20, elementBlockD.GetTop());
			elementBlockI.SetTopLeft(elementBlockI.GetLeft() + 20, elementBlockI.GetTop());
			elementBlockE.SetTopLeft(elementBlockE.GetLeft() + 20, elementBlockE.GetTop());
			elementBlockD2.SetTopLeft(elementBlockD2.GetLeft() + 20, elementBlockD2.GetTop());
			elementDropFloor.SetTopLeft(elementDropFloor.GetLeft() + 20, elementDropFloor.GetTop());
			elementLady.SetTopLeft(elementLady.GetLeft() + 20, elementLady.GetTop());
			*/

		}
		

	}

	if (buttonD && run_character->GetFaceHitblock()  == false)
	{
		if (buttonW == false) //沒有跳躍的時候地圖正常跑
		{
			floor1_2.SetTopLeft(floor1_2.GetLeft() - 20, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() - 20, background.GetTop());
			for (int i = 0; i < 23; i++)
			{
				if (i == elementPoLeft || i == elementPoRight || i==elementPoUp)
				{
					continue;
				}
				else
				{
					stage[i]->SetTopLeft(stage[i]->GetLeft() - 20, stage[i]->GetTop());
				}
			}

			if (elementPo == true)
			{
				stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() - 20, stage[elementPoRight]->GetTop());
				stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() - 20, stage[elementPoLeft]->GetTop());
			}
			if (elementPo1_2 == true)
			{
				stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() - 20, stage[elementPoUp]->GetTop());
			}
			/*
			element.SetTopLeft(element.GetLeft() - 20, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() - 20, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() - 20, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() - 20, elementEmptyBlock.GetTop());
			elementGrass.SetTopLeft(elementGrass.GetLeft() - 20, elementGrass.GetTop());
			elementLongBlock.SetTopLeft(elementLongBlock.GetLeft() - 20, elementLongBlock.GetTop());
			elementShortBlock.SetTopLeft(elementShortBlock.GetLeft() - 20, elementShortBlock.GetTop());
			elementPipe1.SetTopLeft(elementPipe1.GetLeft() - 20, elementPipe1.GetTop());
			elementPipe2.SetTopLeft(elementPipe2.GetLeft() - 20, elementPipe2.GetTop());
			elementKey.SetTopLeft(elementKey.GetLeft() - 20, elementKey.GetTop());
			elementPrick1.SetTopLeft(elementPrick1.GetLeft() - 20, elementPrick1.GetTop());
			elementPrick2.SetTopLeft(elementPrick2.GetLeft() - 20, elementPrick2.GetTop());
			elementEmptyBlock2.SetTopLeft(elementEmptyBlock2.GetLeft() - 20, elementEmptyBlock2.GetTop());
			elementBlockU.SetTopLeft(elementBlockU.GetLeft() - 20, elementBlockU.GetTop());
			elementBlockD.SetTopLeft(elementBlockD.GetLeft() - 20, elementBlockD.GetTop());
			elementBlockI.SetTopLeft(elementBlockI.GetLeft() - 20, elementBlockI.GetTop());
			elementBlockE.SetTopLeft(elementBlockE.GetLeft() - 20, elementBlockE.GetTop());
			elementBlockD2.SetTopLeft(elementBlockD2.GetLeft() - 20, elementBlockD2.GetTop());
			elementDropFloor.SetTopLeft(elementDropFloor.GetLeft() - 20, elementDropFloor.GetTop());
			elementLady.SetTopLeft(elementLady.GetLeft() - 20, elementLady.GetTop());


			if(elementPo == true)
			{
				elementPoRight.SetTopLeft(elementPoRight.GetLeft() - 20, elementPoRight.GetTop());
				elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() - 20, elementPoLeft.GetTop());
			}

			if (elementPo1_2 == true)
			{
				elementPoUp.SetTopLeft(elementPoUp.GetLeft() - 20, elementPoUp.GetTop());
			}
			*/
		}
		else //有跳躍的時候地圖要跑比較慢，因為有強制墬落
		{
			floor1_2.SetTopLeft(floor1_2.GetLeft() - 15, floor1_2.GetTop());
			background.SetTopLeft(background.GetLeft() - 15, background.GetTop());
			for (int i = 0; i < 23; i++)
			{
				if (i == elementPoLeft || i == elementPoRight || i==elementPoUp)
				{
					continue;
				}
				else
				{
					stage[i]->SetTopLeft(stage[i]->GetLeft() - 15, stage[i]->GetTop());
				}
			}

			if (elementPo == true)
			{
				stage[elementPoRight]->SetTopLeft(stage[elementPoRight]->GetLeft() - 15, stage[elementPoRight]->GetTop());
				stage[elementPoLeft]->SetTopLeft(stage[elementPoLeft]->GetLeft() - 15, stage[elementPoLeft]->GetTop());
			}
			if (elementPo1_2 == true)
			{
				stage[elementPoUp]->SetTopLeft(stage[elementPoUp]->GetLeft() - 15, stage[elementPoUp]->GetTop());
			}
			/*
			element.SetTopLeft(element.GetLeft() - 20, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() - 20, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() - 20, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() - 20, elementEmptyBlock.GetTop());
			elementGrass.SetTopLeft(elementGrass.GetLeft() - 20, elementGrass.GetTop());
			elementLongBlock.SetTopLeft(elementLongBlock.GetLeft() - 20, elementLongBlock.GetTop());
			elementShortBlock.SetTopLeft(elementShortBlock.GetLeft() - 20, elementShortBlock.GetTop());
			elementPipe1.SetTopLeft(elementPipe1.GetLeft() - 20, elementPipe1.GetTop());
			elementPipe2.SetTopLeft(elementPipe2.GetLeft() - 20, elementPipe2.GetTop());
			elementKey.SetTopLeft(elementKey.GetLeft() - 20, elementKey.GetTop());
			elementPrick1.SetTopLeft(elementPrick1.GetLeft() - 20, elementPrick1.GetTop());
			elementPrick2.SetTopLeft(elementPrick2.GetLeft() - 20, elementPrick2.GetTop());
			elementEmptyBlock2.SetTopLeft(elementEmptyBlock2.GetLeft() - 20, elementEmptyBlock2.GetTop());
			elementBlockU.SetTopLeft(elementBlockU.GetLeft() - 20, elementBlockU.GetTop());
			elementBlockD.SetTopLeft(elementBlockD.GetLeft() - 20, elementBlockD.GetTop());
			elementBlockI.SetTopLeft(elementBlockI.GetLeft() - 20, elementBlockI.GetTop());
			elementBlockE.SetTopLeft(elementBlockE.GetLeft() - 20, elementBlockE.GetTop());
			elementBlockD2.SetTopLeft(elementBlockD2.GetLeft() - 20, elementBlockD2.GetTop());
			elementDropFloor.SetTopLeft(elementDropFloor.GetLeft() - 20, elementDropFloor.GetTop());
			elementLady.SetTopLeft(elementLady.GetLeft() - 20, elementLady.GetTop());
			

			if (elementPo == true)
			{
				elementPoRight.SetTopLeft(elementPoRight.GetLeft() - 20, elementPoRight.GetTop());
				elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() - 20, elementPoLeft.GetTop());
			}

			if (elementPo1_2 == true)
			{
				elementPoUp.SetTopLeft(elementPoUp.GetLeft() - 20, elementPoUp.GetTop());
			}*/
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