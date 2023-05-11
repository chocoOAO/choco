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
		if (headHitfloor == true && character.GetTop() != 733 )//如果頭撞到方塊強制掉下去
		{
			chieght = 2000; // Let "(character.GetTop() > chieght - 400)" be false
			headHitfloor = false; // reset headHitfloor
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
			isJumping = false;
			isDropping = true;
		}
		
		else if (character.GetTop() > chieght - 400 )//按住持續W
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 30);
			isJumping = true;
			isDropping = false;
		}
		else if (character.GetTop() < 733 && !feetHitblock)//掉到地板
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
			isJumping = false;
			isDropping = true;
		}

	}
	if (!character_condition.at(0) == true && feetHitblock==false) 
	{
		if (character.GetTop() < 733)
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
			isJumping = false;
			isDropping = true;
		}
		else
		{
			isJumping = false;
			isDropping = false;
		}
			
	}

	if ((isJumping == true || isDropping == true) && feetHitblock == false)
	{
		dontRead = true;
	}
	else
	{
		dontRead = false;
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
		if(dontRead == false)
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

bool characterTool::GetIsDroppingAddress()
{
	return isDropping;
}

void characterTool::touchingElement(backgroundTool *backgroundElement)
{
		std::vector<MyCMovingBitmap *> stage;
		stage = *(backgroundElement->getStageAddress());
		
		std::vector<int> intFloor = { element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock,
								 elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2 };
		std::vector<int> intFeet = { element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock,
								 elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2 };
		std::vector<int> intFace = { element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock,
								 elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2 };
		std::vector<int> intBack = { element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock,
								 elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2 };
		headHitfloor = false;
		feetHitblock = false;
		faceHitblock = false;
		backHitblock = false;
		
		for (int i = 0; i < int(intFloor.size()); i++)
		{
			headHitfloor = headHitfloor || character.touchUp(&character, stage[intFloor[i]]);
		}
		/*
		headHitfloor = character.touchUp(&character, stage[element]) ||
		character.touchUp(&character, stage[elementGo]) ||
		character.touchUp(&character, stage[elementEmptyBlock]) ||
		character.touchUp(&character, stage[elementLongBlock]) ||
		character.touchUp(&character, stage[elementShortBlock]) ||
		character.touchUp(&character, stage[elementEmptyBlock2]) ||
		character.touchUp(&character, stage[elementBlockU]) ||
		character.touchUp(&character, stage[elementBlockD]) ||
		character.touchUp(&character, stage[elementBlockI]) ||
		character.touchUp(&character, stage[elementBlockE]) ||
		character.touchUp(&character, stage[elementBlockD2]);
		*/
	feetHitblock = character.touchDown(&character, stage[element]) ||
		character.touchDown(&character, stage[elementGo]) ||
		character.touchDown(&character, stage[elementLongBlock])||
		character.touchDown(&character, stage[elementShortBlock]) ||
		character.touchDown(&character, stage[elementPipe1]) ||
		character.touchDown(&character, stage[elementPipe2]) ||
		(stage[elementEmptyBlock]->GetFrameIndexOfBitmap() == 1 && character.touchDown(&character, stage[elementEmptyBlock])) ||
		(stage[elementEmptyBlock2]->GetFrameIndexOfBitmap() == 1 && character.touchDown(&character, stage[elementEmptyBlock2]));
		
	faceHitblock = character.touchLeft(&character, stage[element]) ||
		character.touchLeft(&character, stage[elementGo]) ||
		character.touchLeft(&character, stage[elementLongBlock])||
		character.touchLeft(&character, stage[elementShortBlock]) ||
		character.touchLeft(&character, stage[elementPipe1]) ||
		character.touchLeft(&character, stage[elementPipe2]) ||
		character.touchLeft(&character, backgroundElement->getFloor1_2Address()) ||
		(stage[elementEmptyBlock]->GetFrameIndexOfBitmap() == 1 && character.touchLeft(&character, stage[elementEmptyBlock])) ||
		(stage[elementEmptyBlock2]->GetFrameIndexOfBitmap() == 1 && character.touchLeft(&character, stage[elementEmptyBlock2]));
	backHitblock = character.touchRight(&character, stage[element]) ||
		character.touchRight(&character, stage[elementGo]) ||
		character.touchRight(&character, stage[elementLongBlock])||
		character.touchRight(&character, stage[elementShortBlock]) ||
		character.touchRight(&character, stage[elementPipe1]) ||
		character.touchRight(&character, stage[elementPipe2]) ||
		character.touchRight(&character, backgroundElement->getFloor1_2Address()) ||
		(stage[elementEmptyBlock]->GetFrameIndexOfBitmap() == 1 && character.touchRight(&character, stage[elementEmptyBlock])) ||
		(stage[elementEmptyBlock2]->GetFrameIndexOfBitmap() == 1 && character.touchRight(&character, stage[elementEmptyBlock2]));
		

	if (character.touchUp(&character, stage[elementGo]))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}

	if (character.IsOverlap(*stage[elementCloud], character))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}

	if (character.IsOverlap(*stage[elementGrass], character))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}
	
	if (character.IsOverlap(*stage[elementPrick1], character) ||
		character.IsOverlap(*stage[elementPrick2], character) ||
		character.IsOverlap(*stage[elementPoRight], character) ||
		character.IsOverlap(*stage[elementPoLeft], character) ||
		character.IsOverlap(*stage[elementPoUp], character))
	{
		backgroundElement->backgroundInit();
		backgroundElement->elementInit();
		characterInit();
	}
}

void characterTool::drop(backgroundTool *background)
{
	std::vector<MyCMovingBitmap *> stage;
	stage = *(background->getStageAddress());
	MyCMovingBitmap tmp = *(background->getBackgroundAddress());
	if (character.GetLeft() +50 > tmp.GetLeft() + 1480 && character.GetLeft() -50 < tmp.GetLeft() + 1820 &&
		character.GetTop() >= 733)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
	}

	if (character.GetLeft() + 50> tmp.GetLeft() + 5454 && character.GetLeft() - 50 < tmp.GetLeft() + 5604 &&
		character.GetTop() >= 733 && character.touchDown(&character, stage[elementDropFloor]) == false)
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