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
		"resources/level1.bmp"},
		0);
	
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
	element.LoadBitmapByString({ "resources/whiteBlock.bmp","resources/blackBlock.bmp" }, RGB(255, 255, 255));
	element.SetTopLeft(427, 539);
	element.SetFrameIndexOfBitmap(0);

	elementGo.LoadBitmapByString({ "resources/nothing.bmp","resources/go.bmp","resources/godie_1.bmp" }, RGB(255, 255, 255));
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

	elementPo = false;
	elementPo1_2 = false;
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
}

MyCMovingBitmap *backgroundTool::getFloor1_2Address()
{
	return &floor1_2;
}

MyCMovingBitmap *backgroundTool::getBackgroundAddress()
{
	return &background;
}

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


void backgroundTool::touching(characterTool *character)
{
	if (element.touchUp(character->getCharacterAddress(), &element))
	{
		element.SetFrameIndexOfBitmap(1);
		elementGo.SetFrameIndexOfBitmap(1);
		elementGo.SetTopLeft(background.GetLeft() + 617, background.GetTop() + 359);//300
	}

	if (elementGo.touchUp(character->getCharacterAddress(), &elementGo))
	{
		elementGo.SetFrameIndexOfBitmap(2);
	}
	
	if (elementEmptyBlock.touchUp(character->getCharacterAddress(), &elementEmptyBlock) && character->GetIsDroppingAddress() == false)
	{
		elementEmptyBlock.SetFrameIndexOfBitmap(1);
	}

	if (elementEmptyBlock2.touchUp(character->getCharacterAddress(), &elementEmptyBlock2) && character->GetIsDroppingAddress() == false)
	{
		elementEmptyBlock2.SetFrameIndexOfBitmap(1);
	}

	if (elementBlockU.touchUp(character->getCharacterAddress(), &elementBlockU) && character->GetIsDroppingAddress() == false)
	{
		elementBlockU.SetFrameIndexOfBitmap(1);
	}

	if (elementBlockD.touchUp(character->getCharacterAddress(), &elementBlockD) && character->GetIsDroppingAddress() == false)
	{
		elementBlockD.SetFrameIndexOfBitmap(1);
	}

	if (elementBlockI.touchUp(character->getCharacterAddress(), &elementBlockI) && character->GetIsDroppingAddress() == false)
	{
		elementBlockI.SetFrameIndexOfBitmap(1);
	}

	if (elementBlockE.touchUp(character->getCharacterAddress(), &elementBlockE) && character->GetIsDroppingAddress() == false)
	{
		elementBlockE.SetFrameIndexOfBitmap(1);
	}

	if (elementBlockD.touchUp(character->getCharacterAddress(), &elementBlockD2) && character->GetIsDroppingAddress() == false)
	{
		elementBlockD2.SetFrameIndexOfBitmap(1);
	}

	if (elementDropFloor.touchDown(character->getCharacterAddress(), &elementDropFloor) || elementDropFloor.GetTop() > 863)
	{
		elementDropFloor.SetTopLeft(elementDropFloor.GetLeft(), elementDropFloor.GetTop() + 30);
	}

	if (background.IsOverlap(*(character->getCharacterAddress()), elementCloud))
	{
		elementCloud.SetFrameIndexOfBitmap(1);
	}

	if (background.IsOverlap(*(character->getCharacterAddress()), elementGrass))
	{
		elementGrass.SetFrameIndexOfBitmap(1);
	}

	if (elementBlockU.GetFrameIndexOfBitmap() == 1 && elementBlockD.GetFrameIndexOfBitmap() == 1 &&
		elementBlockI.GetFrameIndexOfBitmap() == 1 && elementBlockE.GetFrameIndexOfBitmap() == 1 &&
		elementBlockD2.GetFrameIndexOfBitmap() == 1)
	{
		if (elementPo == false)
		{
			elementPoRight.SetTopLeft(background.GetLeft() + 3850, background.GetTop() + 760);
			elementPoLeft.SetTopLeft(background.GetLeft() + 5000, background.GetTop() + 650);
			elementPo = true;
		}
		else
		{
			elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() - 2, elementPoLeft.GetTop());
			elementPoRight.SetTopLeft(elementPoRight.GetLeft() + 2, elementPoRight.GetTop());

		}
		
	}

	if (elementPipe2.touchDown(character->getCharacterAddress(), &elementPipe2)) 
	{
		if (elementPo1_2 == false)
		{
			elementPoUp.SetTopLeft(background.GetLeft() + 5000, background.GetTop() + 600);
			elementPo1_2 = true;
		}
		
	}

	if (elementPo1_2 == true)
	{
		elementPoUp.SetTopLeft(elementPoUp.GetLeft(), elementPoUp.GetTop() - 10);
		if (elementPoUp.GetTop() < -200)
		{
			elementPo1_2 = false;
		}
	}
	

	if (background.IsOverlap(*(character->getCharacterAddress()), elementKey))
	{
		elementKey.SetTopLeft(-1000, -1000);
		elementPrick1.SetTopLeft(background.GetLeft() + 2528, background.GetTop() + 195);
		elementPrick2.SetTopLeft(background.GetLeft() + 3268, background.GetTop() + 195);
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
		if (playing){
			if (buttonW == false) //沒有跳躍的時候地圖正常跑
				{
				floor1_2.SetTopLeft(floor1_2.GetLeft() + 20, floor1_2.GetTop());
				background.SetTopLeft(background.GetLeft() + 20, background.GetTop());
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

				if (elementPo == true)
				{
					elementPoRight.SetTopLeft(elementPoRight.GetLeft() + 20, elementPoRight.GetTop());
					elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() + 20, elementPoLeft.GetTop());
				}
				if (elementPo1_2 == true)
				{
					elementPoUp.SetTopLeft(elementPoUp.GetLeft() + 20, elementPoUp.GetTop());
				}

				}
			else //有跳躍的時候地圖要跑比較慢，因為有強制墬落
				{
				floor1_2.SetTopLeft(floor1_2.GetLeft() + 20, floor1_2.GetTop());
				background.SetTopLeft(background.GetLeft() + 20, background.GetTop());
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

				if (elementPo == true)
				{
					elementPoRight.SetTopLeft(elementPoRight.GetLeft() + 20, elementPoRight.GetTop());
					elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() + 20, elementPoLeft.GetTop());
				}

				if (elementPo1_2 == true)
				{
					elementPoUp.SetTopLeft(elementPoUp.GetLeft() + 20, elementPoUp.GetTop());
				}
				}
		

		}
	}
	if (buttonD && run_character->GetFaceHitblock()  == false)
	{
		if (playing)
		{
			if (buttonW == false) //沒有跳躍的時候地圖正常跑
				{
				floor1_2.SetTopLeft(floor1_2.GetLeft() - 20, floor1_2.GetTop());
				background.SetTopLeft(background.GetLeft() - 20, background.GetTop());
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

				if(elementPo == true)
				{
					elementPoRight.SetTopLeft(elementPoRight.GetLeft() - 30, elementPoRight.GetTop());
					elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() - 30, elementPoLeft.GetTop());
				}

				if (elementPo1_2 == true)
				{
					elementPoUp.SetTopLeft(elementPoUp.GetLeft() - 30, elementPoUp.GetTop());
				}
				}
			else //有跳躍的時候地圖要跑比較慢，因為有強制墬落
				{
				floor1_2.SetTopLeft(floor1_2.GetLeft() - 20, floor1_2.GetTop());
				background.SetTopLeft(background.GetLeft() - 20, background.GetTop());
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

				if (elementPo == true)
				{
					elementPoRight.SetTopLeft(elementPoRight.GetLeft() - 20, elementPoRight.GetTop());
					elementPoLeft.SetTopLeft(elementPoLeft.GetLeft() - 20, elementPoLeft.GetTop());
				}

				if (elementPo1_2 == true)
				{
					elementPoUp.SetTopLeft(elementPoUp.GetLeft() - 20, elementPoUp.GetTop());
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