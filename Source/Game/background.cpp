﻿#include "stdafx.h"
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
	element.SetTopLeft(477, 539);
	element.SetFrameIndexOfBitmap(0);
	elementGo.LoadBitmapByString({ "resources/nothing.bmp","resources/go.bmp","resources/godie.bmp" }, RGB(255, 255, 255));
	elementGo.SetFrameIndexOfBitmap(0);
	elementGo.SetTopLeft(0,0);
	//elementGo.SetTopLeft(-1000, -1000);
	//elementGo.SetTopLeft(697, 359);
	elementCloud.LoadBitmapByString({ "resources/cloud.bmp","resources/clouddie.bmp" }, RGB(255, 255, 255));
	elementCloud.SetFrameIndexOfBitmap(0);
	elementCloud.SetTopLeft(1600, -20);

	elementEmptyBlock.LoadBitmapByString({ "resources/emptyBlock.bmp","resources/blackBlock.bmp" }, RGB(255, 255, 255));
	elementEmptyBlock.SetFrameIndexOfBitmap(0);
	elementEmptyBlock.SetTopLeft(1500, 539);
}

void backgroundTool::backgroundKeyDown(UINT nChar)
{
	if (nChar == 0x27 && playing == false)//向右選關鍵
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
	if (nChar == VK_RETURN)//向右選關鍵
	{
		if (sel == 0)
		{
			playing = true;
			background.SetFrameIndexOfBitmap(1);
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

void backgroundTool::touching(characterTool *character)
{
	if (element.touchUp(character->getCharacterAddress(), &element))
	{
		element.SetFrameIndexOfBitmap(1);
		elementGo.SetFrameIndexOfBitmap(1);
		elementGo.SetTopLeft(background.GetLeft() + 697, background.GetTop() + 359);//300
	}

	if (elementGo.touchUp(character->getCharacterAddress(), &elementGo))
	{
		elementGo.SetFrameIndexOfBitmap(2);
	}

	if (elementEmptyBlock.touchUp(character->getCharacterAddress(), &elementEmptyBlock))
	{
		elementEmptyBlock.SetFrameIndexOfBitmap(1);
	}

	if (background.IsOverlap(*(character->getCharacterAddress()), elementCloud))
	{
		elementCloud.SetFrameIndexOfBitmap(1);
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
			background.SetTopLeft(background.GetLeft() + 30, background.GetTop());
			element.SetTopLeft(element.GetLeft() + 30, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() + 30, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() + 30, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() + 30, elementEmptyBlock.GetTop());
		}
		else //有跳躍的時候地圖要跑比較慢，因為有強制墬落
		{
			background.SetTopLeft(background.GetLeft() + 20, background.GetTop());
			element.SetTopLeft(element.GetLeft() + 20, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() + 20, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() + 20, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() + 20, elementEmptyBlock.GetTop());

		}
		

	}

	if (buttonD && run_character->GetFaceHitblock()  == false)
	{
		if (buttonW == false) //沒有跳躍的時候地圖正常跑
		{
			background.SetTopLeft(background.GetLeft() - 30, background.GetTop());
			element.SetTopLeft(element.GetLeft() - 30, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() - 30, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() - 30, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() - 30, elementEmptyBlock.GetTop());


		}
		else //有跳躍的時候地圖要跑比較慢，因為有強制墬落
		{
			background.SetTopLeft(background.GetLeft() - 20, background.GetTop());
			element.SetTopLeft(element.GetLeft() - 20, element.GetTop());
			elementGo.SetTopLeft(elementGo.GetLeft() - 20, elementGo.GetTop());
			elementCloud.SetTopLeft(elementCloud.GetLeft() - 20, elementCloud.GetTop());
			elementEmptyBlock.SetTopLeft(elementEmptyBlock.GetLeft() - 20, elementEmptyBlock.GetTop());

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