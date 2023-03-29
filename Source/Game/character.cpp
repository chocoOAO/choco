#include "stdafx.h"
#include "../Core/Resource.h"
#include "../Library/gameutil.h"
//#include "../Library/audio.h"
//#include "../Library/gamecore.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
#include "mygame.h"
#include "character.h"
using namespace game_framework;

void characterTool::characterInit()
{
	character.LoadBitmapByString({
			"resources/character1.bmp",
			"resources/character2.bmp",
			"resources/character1.bmp",
			"resources/character3.bmp",
			"resources/character1.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(180, 733);
	character_condition = { false, false, false, false };
}

void characterTool::SetFlagMove(bool value)
{
	character.SetFlagMove(value);
}

bool characterTool::GetFlagMove() const
{
	return character.GetFlagMove();
}

void characterTool::characterMove(MyCMovingBitmap background)
{
	if (character_condition.at(0) && character.GetFlagMove() == true)
	{
		if (character.GetTop() > chieght - 400)
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 20);//�������W
		}
		else if (character.GetTop() != 733)
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);
		}

	}
	if (character.GetFlagMove() == false)
	{
		if (character.GetTop() != 733)
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);
	}



	if (character_condition.at(1) && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);//�������S
	}

	if (character_condition.at(2) && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft() - 3, character.GetTop());//�������A
		background.SetTopLeft(background.GetLeft() + 20, background.GetTop());
		character.SetAnimation(150, false);
	}

	if (character_condition.at(3) && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft() + 3, character.GetTop());//�������D
		background.SetTopLeft(background.GetLeft() - 20, background.GetTop());
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
		/*
			for (int i=0; i < 15; i++)
			{
				character.SetTopLeft(character.GetLeft(), character.GetTop() - 30);//�������W

			}*/

			//chieght = 300;
			//character.SetTopLeft(character.GetLeft(), character.GetTop() + 15);



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


