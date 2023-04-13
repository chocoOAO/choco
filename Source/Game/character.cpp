﻿#include "stdafx.h"
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
	if (character_condition.at(0) && character.GetFlagMove() == true)
	{
		if (headHitfloor == true && character.GetTop() != 733)//如果頭撞到方塊強制掉下去
		{
			chieght = 2000;
			headHitfloor = false;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
		}
		/*else if (fitHitblock == true)
		{
			//character.SetTopLeft(0, 0);
			character.SetFlagMove(false);
		}*/
		else if (character.GetTop() > chieght - 400)//按住持續W
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 30);
		}
		else if (character.GetTop() < 733 && !fitHitblock)//掉到地板
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
		}

	}
	if (character.GetFlagMove() == false && fitHitblock==false)
	{
		if (character.GetTop() < 733)
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
	}
	
	/*if (character_condition.at(1) && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);//按住持續S
	}*/

	if (character_condition.at(2) && character.GetFlagMove() == true && (backHitblock == false))
	{
		character.SetTopLeft(character.GetLeft() - 2, character.GetTop());//按住持續A
		character.SetAnimation(150, false);
	}
	/*
	if (faceHitblock == true)
	{
		character.SetTopLeft(0, 30);
	}*/

	if (character_condition.at(3) && character.GetFlagMove() == true && (faceHitblock == false))
	{
		character.SetTopLeft(character.GetLeft() + 2, character.GetTop());//按住持續D
		character.SetAnimation(150, false);

	}
}

void characterTool::characterKeyDown(UINT nChar)
{
	if (nChar == 0x57)//W
	{
		character.SetFlagMove(true);
		character_condition.at(0) = TRUE;
		chieght = int(character.GetTop());

	}
	if (nChar == 0x53)//S
	{
		character.SetFlagMove(true);
		character_condition.at(1) = TRUE;
	}
	if (nChar == 0x41)//A
	{
		character.SetFlagMove(true);
		character_condition.at(2) = TRUE;
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
		character_condition.at(3) = TRUE;
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
	fitHitblock = character.touchDown(&character, backgroundElement->getElementAdress()) ||
		character.touchDown(&character, backgroundElement->getElementGoAdress());
	faceHitblock = character.touchLeft(&character, backgroundElement->getElementAdress()) ||
		character.touchLeft(&character, backgroundElement->getElementGoAdress());
	backHitblock = character.touchRight(&character, backgroundElement->getElementAdress()) ||
		character.touchRight(&character, backgroundElement->getElementGoAdress());

}