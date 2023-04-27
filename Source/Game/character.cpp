#include "stdafx.h"
#include "../Core/Resource.h"
#include "../Library/gameutil.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
#include "character.h"
#include "background.h"
#include <vector>
using namespace game_framework;


void characterTool::characterInit()
{
	std::vector<string> tmpCharacter = {
			"resources/character1.bmp",
			"resources/character2.bmp",
			"resources/character1.bmp",
			"resources/character3.bmp",
			"resources/character1.bmp" };
	//cleanBitMap(&character, tmpCharacter);
	
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
			chieght = 2000; // Let "(character.GetTop() > chieght - 400)" be false
			headHitfloor = false; // reset headHitfloor
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
		else if (character.GetTop() < 733 && !feetHitblock)//掉到地板
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
		}

	}
	if (character.GetFlagMove() == false && feetHitblock==false)
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
		/*cleanBitMap(&character, {
		"resources/character1.bmp",
		"resources/character6.bmp",
		"resources/character1.bmp",
		"resources/character7.bmp",
		"resources/character1.bmp" });
		int x = character.GetLeft();
		int y = character.GetTop();		
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
		/*cleanBitMap(&character, {
		"resources/character1.bmp",
		"resources/character2.bmp",
		"resources/character1.bmp",
		"resources/character3.bmp",
		"resources/character1.bmp" });
		int x = character.GetLeft();
		int y = character.GetTop();
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

MyCMovingBitmap *characterTool::getCharacterAddress()
{
	return &character;
}

void characterTool::touchingElement(backgroundTool *backgroundElement)
{
	headHitfloor = character.touchUp(&character, backgroundElement->getElementAddress()) ||
		character.touchUp(&character, backgroundElement->getElementGoAddress()) ||
		character.touchUp(&character, backgroundElement->getElementEmptyBlockAddress()) ||
		character.touchUp(&character, backgroundElement->getElementLongBlockAddress()) ||
		character.touchUp(&character, backgroundElement->getElementShortBlockAddress());
	feetHitblock = character.touchDown(&character, backgroundElement->getElementAddress()) ||
		character.touchDown(&character, backgroundElement->getElementGoAddress()) ||
		character.touchDown(&character, backgroundElement->getElementLongBlockAddress())||
		character.touchDown(&character, backgroundElement->getElementShortBlockAddress()) ||
		character.touchDown(&character, backgroundElement->getElementPipe1Address()) ||
		character.touchDown(&character, backgroundElement->getElementPipe2Address());
	faceHitblock = character.touchLeft(&character, backgroundElement->getElementAddress()) ||
		character.touchLeft(&character, backgroundElement->getElementGoAddress()) ||
		character.touchLeft(&character, backgroundElement->getElementLongBlockAddress())||
		character.touchLeft(&character, backgroundElement->getElementShortBlockAddress()) ||
		character.touchLeft(&character, backgroundElement->getElementPipe1Address()) ||
		character.touchLeft(&character, backgroundElement->getElementPipe2Address());
	backHitblock = character.touchRight(&character, backgroundElement->getElementAddress()) ||
		character.touchRight(&character, backgroundElement->getElementGoAddress()) ||
		character.touchRight(&character, backgroundElement->getElementLongBlockAddress())||
		character.touchRight(&character, backgroundElement->getElementShortBlockAddress()) ||
		character.touchRight(&character, backgroundElement->getElementPipe1Address()) ||
		character.touchRight(&character, backgroundElement->getElementPipe2Address());

	if ((backgroundElement->getElementEmptyBlockAddress())->GetFrameIndexOfBitmap() == 1)
	{
		feetHitblock = character.touchDown(&character, backgroundElement->getElementEmptyBlockAddress());
		faceHitblock = character.touchLeft(&character, backgroundElement->getElementEmptyBlockAddress());
		backHitblock = character.touchRight(&character, backgroundElement->getElementEmptyBlockAddress());
	}

	if (character.touchUp(&character, backgroundElement->getElementGoAddress()))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}

	if (character.IsOverlap(*(backgroundElement->getElementCloudAddress()), character))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}

	if (character.IsOverlap(*(backgroundElement->getElementGrassAddress()), character))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}
	
}

void characterTool::drop(backgroundTool *background)
{
	MyCMovingBitmap tmp = *(background->getBackgroundAddress());
	if (character.GetLeft() > tmp.GetLeft() + 1480 && character.GetLeft() < tmp.GetLeft() +1820 &&
		character.GetTop() >= 733)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
	}
	if (character.GetTop() > 960)
	{
		background->backgroundInit();
		background->elementInit();
		characterInit();
	}
}

/*
void characterTool::cleanBitMap(MyCMovingBitmap *item,vector<string> load)
{
	MyCMovingBitmap tmp;
	tmp.LoadBitmapByString(load,  RGB(255, 255, 255));
	tmp.SetTopLeft(item->GetLeft(),item->GetTop());
	*item = tmp;

}
*/