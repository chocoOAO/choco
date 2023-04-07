#include "stdafx.h"
#include "../Core/Resource.h"
#include "../Library/gameutil.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
#include "background.h"
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
}

MyCMovingBitmap *backgroundTool::getBackgroundAdress()
{
	return &background;
}

MyCMovingBitmap *backgroundTool::getElementAdress()
{
	return &element;
}


void backgroundTool::touching(MyCMovingBitmap *character)//
{
	if (background.touchUp(character, &element))
	{
		element.SetFrameIndexOfBitmap(1);
	}
	//if (background.IsOverlap(*character, element))
	//	element.SetFrameIndexOfBitmap(1);
	elementShowBitmap();
	
}

bool backgroundTool::getPlaying()
{
	return playing;
}



void backgroundTool::Move()
{

	if (buttonA)
	{
		
		background.SetTopLeft(background.GetLeft() + 30, background.GetTop());
		element.SetTopLeft(element.GetLeft() + 30, element.GetTop());
		
	}

	if (buttonD)
	{
		background.SetTopLeft(background.GetLeft() - 30, background.GetTop());
		element.SetTopLeft(element.GetLeft() - 30, element.GetTop());
		
	}
}

void backgroundTool::KeyDown(UINT nChar)
{
	
	if (nChar == 0x57)//W
	{		
		
		
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