#include "stdafx.h"
#include "../Core/Resource.h"
#include "../Library/gameutil.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
#include "character.h"
#include "background.h"
using namespace game_framework;


void characterTool::characterInit()
{
	character.LoadBitmapByString({
			"resources/character1.bmp",
			"resources/character2.bmp",
			"resources/character1.bmp",
			"resources/character3.bmp",
			"resources/character1.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(0, 733);
	character_condition = { false, false, false, false };
}

void characterTool::characterMove(MyCMovingBitmap *background)
{
	if (character_condition.at(0)== true && character.GetFlagMove() == true)
	{
		if (character.GetTop() != 733 && headHitfloor == true) // 如果頭撞到方塊強制掉落
		{
			chieght = 2000; // Let "(character.GetTop() > chieght - 400)" be false
			headHitfloor = false; // reset headHitfloor
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
		}
		/*else if (feetHitblock == true)
		{
			//character.SetTopLeft(0, 0);
			character.SetFlagMove(false);
		}*/
		
		else if (character.GetTop() > chieght - 400) // "cheight - 400" 高度限制
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 30);
		}
		
		else if (character.GetTop() < 733 && feetHitblock == false) // 腳沒踩到地板
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
		}
		
	}

	
	if (character.GetFlagMove() == false && character.GetTop() < 733 && feetHitblock == false)
		// 腳沒踩到地板 且 腳沒踩到方塊
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
	}
	
	/*if (character_condition.at(1) && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 20); //持續按住S
	}*/

	if (character_condition.at(2) == true && character.GetFlagMove() == true && backHitblock == false)
		// 按A 且 背沒碰到方塊
	{
		if (character_condition.at(0) == false && (feetHitblock == true || (character.GetTop() == 733)))
			// W放開必須 等到墜落到 "地面上" 或 "方塊上" 才能左右移動
		{
			character.SetTopLeft(character.GetLeft() - 2, character.GetTop()); //持續按住A
			character.SetAnimation(150, false);
		}
	}
	/*
	if (faceHitblock == true)
	{
		character.SetTopLeft(0, 30);
	}*/

	if (character_condition.at(3) == true && character.GetFlagMove() == true && faceHitblock == false)
		// 按D 且 臉沒碰到方塊
	{
		if (character_condition.at(0) == false && (feetHitblock == true || (character.GetTop() == 733)))
			// W放開必須 等到墜落到 "地面上" 或 "方塊上" 才能左右移動
		{
			character.SetTopLeft(character.GetLeft() + 2, character.GetTop());//持續按住D
			character.SetAnimation(150, false);
		}
		
	}
}

void characterTool::characterKeyDown(UINT nChar)
{
	if (nChar == 0x57)//W
	{
		character.SetFlagMove(true);
		character_condition.at(0) = true;
		chieght = int(character.GetTop());

	}
	if (nChar == 0x53)//S
	{
		character.SetFlagMove(true);
		character_condition.at(1) = true;
	}
	if (nChar == 0x41)//A
	{
		character.SetFlagMove(true);
		character_condition.at(2) = true;
		/*
		int x = character.GetLeft();
		int y = character.GetTop();
		character.LoadBitmapByString({ "resources/character1.bmp" }, 1);
		character.LoadBitmapByString({
		"resources/character1.bmp",
		"resources/character6.bmp",
		"resources/character1.bmp",
		"resources/character7.bmp",
		"resources/character1.bmp" },  RGB(255, 255, 255));
		character.SetTopLeft(x, y);*/
	}


	if (nChar == 0x44)//D
	{
		character.SetFlagMove(true);
		character_condition.at(3) = true;
		/*
		int x = character.GetLeft();
		int y = character.GetTop();
		character.LoadBitmapByString({ "resources/character1.bmp" }, 1);
		character.LoadBitmapByString({
		"resources/character1.bmp",
		"resources/character2.bmp",
		"resources/character1.bmp",
		"resources/character3.bmp",
		"resources/character1.bmp" }, RGB(255, 255, 255));
		character.SetTopLeft(x, y);*/
	}
}


void characterTool::characterKeyUp(UINT nChar)
{
	if (nChar == 0x57)//W
	{
		character.SetFlagMove(false);
		character_condition.at(0) = false;
	}
	if (nChar == 0x53)//S
	{
		character.SetFlagMove(false);
		character_condition.at(1) = false;
	}
	if (nChar == 0x41)//A
	{
		character.SetFlagMove(false);
		character_condition.at(2) = false;
		character.SetAnimation(200, true);
	}
	if (nChar == 0x44)//D
	{
		character.SetFlagMove(false);
		character.SetAnimation(200, true);
		character_condition.at(3) = false;
		character.SetFrameIndexOfBitmap(0);

	}
}
void characterTool::characterShowBitmap()
{
	character.ShowBitmap();

}

void characterTool::SetFlagMove(bool value)
{
	character.SetFlagMove(value);
}

bool characterTool::GetFlagMove() const
{
	return character.GetFlagMove();
}

bool characterTool::GetFaceHitblock() const
{
	return  faceHitblock;
}

bool characterTool::GetBackHitblock() const
{
	return backHitblock;
}

MyCMovingBitmap *characterTool::getCharacterAdress()
{
	return &character;
}

void characterTool::touchingElement(backgroundTool *backgroundElement)
{
	headHitfloor = character.touchUp(&character, backgroundElement->getElementAdress()) ||
		character.touchUp(&character, backgroundElement->getElementGoAdress());
	feetHitblock = character.touchDown(&character, backgroundElement->getElementAdress()) ||
		character.touchDown(&character, backgroundElement->getElementGoAdress());
	faceHitblock = character.touchLeft(&character, backgroundElement->getElementAdress()) ||
		character.touchLeft(&character, backgroundElement->getElementGoAdress());
	backHitblock = character.touchRight(&character, backgroundElement->getElementAdress()) ||
		character.touchRight(&character, backgroundElement->getElementGoAdress());

}