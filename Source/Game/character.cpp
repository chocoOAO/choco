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
	if (playing == false && init == false)
	{
		character.LoadBitmapByString({
			"resources/character1.bmp",
			"resources/character2.bmp",
			"resources/character1.bmp",
			"resources/character3.bmp",
			"resources/character1.bmp" }, RGB(255, 255, 255));
		//character.SetTopLeft(0, 733);

		aircraft.LoadBitmapByString({
			"resources/aircraftNormal3_1.bmp",
			"resources/aircraftNormal3_1Cry.bmp"
			}, RGB(255, 255, 255));
		//aircraft.SetTopLeft(922, 753);

		popUp.LoadBitmapA({"Resources/animation_after_died.bmp"}, RGB(14, 209, 69)); // image of animation after died

		characterCry.LoadBitmapByString({
			"resources/characterCry.bmp",
			}, RGB(255, 255, 255));

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5 - i; j++)
			{
				MyCMovingBitmap *x = new MyCMovingBitmap;
				x->LoadBitmapByString({ "resources/slime2_1.bmp", "resources/emptyBlock.bmp" }, RGB(255, 255, 255));
				//x->SetTopLeft(j * 128 + 917, i * 88 + 20);
				slime.push_back(x);
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)
			{
				MyCMovingBitmap *x = new MyCMovingBitmap;
				x->LoadBitmapByString({ "resources/slime2_1.bmp", "resources/emptyBlock.bmp" }, RGB(255, 255, 255));
				//x->SetTopLeft(787 - j * 128, i * 88 + 20);
				slime.push_back(x);
			}
		}

	}
	aircraft.SetFrameIndexOfBitmap(0);
	characterCry.SetTopLeft(-2000, -2000);
	character.SetTopLeft(0, 733);
	aircraft.SetTopLeft(922, 753);		
	character_condition = { false, false, false, false };
	feetHitblock = true;
	popUp.SetTopLeft(500, 150);
	int tmp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{			
			slime[tmp]->SetTopLeft(j * 128 + 917, i * 88 + 20);
			slime[tmp]->SetFrameIndexOfBitmap(0);
			tmp += 1;

		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{			
			slime[tmp]->SetTopLeft(787 - j * 128, i * 88 + 20);
			slime[tmp]->SetFrameIndexOfBitmap(0);
			tmp += 1;
		}
	}
	for (int i = 0; i < int(slime.size()); i++)
	{
		slime[i]->SetJudge( false);
	}
	time3 = 8;
	init = true;
	start3_1 = clock();
	hitClock = 0;
	leftEnemy = 25;
}

void characterTool::characterMove(backgroundTool *element)
{
	MyCMovingBitmap background = *element->getBackgroundAddress();
	std::vector<MyCMovingBitmap *> stage = *element->getStageAddress();
	if (character_condition.at(0) && character.GetFlagMove() == true && *element->getSelAddress() != 2 && element->getPlaying() == true)
	{
		if (headHitfloor == true && character.GetTop() != 733 )//如果頭撞到方塊強制掉下去
		{
			chieght = 2000; // Let "(character.GetTop() > chieght - 400)" be false
			headHitfloor = false; // reset headHitfloor
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
			if (*element->getSelAddress() == 1)
			{
				stage[elenentslime2_1]->SetTopLeft(stage[elenentslime2_1]->GetLeft(), stage[elenentslime2_1]->GetTop() + 30);
			}
			isJumping = false;
			isDropping = true;
		}
		
		else if (character.GetTop() > chieght - 400 )//按住持續W
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 30);
			if (*element->getSelAddress() == 1)
			{
				stage[elenentslime2_1]->SetTopLeft(stage[elenentslime2_1]->GetLeft(), stage[elenentslime2_1]->GetTop() - 30);
			}
			isJumping = true;
			isDropping = false;
		}
		else if (!feetHitblock)//掉到地板
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
			if (stage[elenentslime2_1]->touchDown(stage[elenentslime2_1], stage[elementLongBlock2_2]) == false && *element->getSelAddress() == 1)
			{
				stage[elenentslime2_1]->SetTopLeft(stage[elenentslime2_1]->GetLeft(), stage[elenentslime2_1]->GetTop() + 30);
			}
			isJumping = false;
			isDropping = true;
		}
		
	}
	
	if (!character_condition.at(0) == true && *element->getSelAddress() != 2 && element->getPlaying() == true)
	{
		if (feetHitblock == false)//character.GetTop() <733 feetHitblock == false
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 30);
			if (stage[elenentslime2_1]->touchDown(stage[elenentslime2_1], stage[elementLongBlock2_2]) == false && * element->getSelAddress() == 1)
			{
				stage[elenentslime2_1]->SetTopLeft(stage[elenentslime2_1]->GetLeft(), stage[elenentslime2_1]->GetTop() + 30);
			}
			isJumping = false;
			isDropping = true;
		}
		else
		{
			if (stage[elenentslime2_1]->touchDown(stage[elenentslime2_1], stage[elementLongBlock2_2]) == false && *element->getSelAddress() == 1)
			{
				stage[elenentslime2_1]->SetTopLeft(stage[elenentslime2_1]->GetLeft(), stage[elenentslime2_1]->GetTop() + 30);
			}
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
	
	if (character_condition.at(0) && *element->getSelAddress() == 2 && element->getPlaying() == true && popUpFlag == false)
	{
		
		if (first == false)
		{
			creatAmmo();
			start = clock();
			first = true;
		}
	
		if (first == true)
		{
			if (((clock() - start) / (double)(CLOCKS_PER_SEC)) >= 0.4)
			{				
				first = false;
			}
		}
		
	}

	for (int i = 0; i < int(ammo.size()); i++)
	{	
		if (ammo[i]->GetTop() > -20)
		{
			ammo[i]->SetTopLeft(ammo[i]->GetLeft(), ammo[i]->GetTop() - 10);
		}
		
	}
	/*if (character_condition.at(1) && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);//按住持續S
	}*/
	std::vector<vector<int>> map;
	map =
	{
		{-4400},
		{-3950},
		{0}
	};

	if (character_condition.at(2)  && (backHitblock == false) && !popUpFlag && (character.GetLeft() < 910 || (background.GetLeft() >= 0) || (background.GetLeft() <= map[*element->getSelAddress()][0])))//&& character.GetFlagMove() == true 
	{
		if(character.GetLeft() >= 0)//卡邊界
		{
			character.SetTopLeft(character.GetLeft() - 14, character.GetTop());//按住持續A
		}	
		if (aircraft.GetLeft() >= 0)
		{
			aircraft.SetTopLeft(aircraft.GetLeft() - 10, aircraft.GetTop());
		}		
		character.SetAnimation(150, false);
	}	

	if (character_condition.at(3) && (faceHitblock == false) && !popUpFlag && (character.GetLeft() < 910  || background.GetLeft() <= map[*element->getSelAddress()][0]))//&& character.GetFlagMove() == true
	{
		character.SetTopLeft(character.GetLeft() + 14, character.GetTop());//按住持續D 
		if (aircraft.GetLeft() <= 1790)
		{
			aircraft.SetTopLeft(aircraft.GetLeft() + 10, aircraft.GetTop());
		}
		character.SetAnimation(150, false);

	}

	allSel = *element->getSelAddress();
}

void characterTool::characterKeyDown(UINT nChar)
{
	if (nChar == 0x57 && !popUpFlag)//W
	{
		character.SetFlagMove(true);
		character_condition.at(0) = TRUE;
		if(dontRead == false)
			chieght = int(character.GetTop());

	}
	if (nChar == 0x53 && !popUpFlag)//S
	{
		character.SetFlagMove(true);
		character_condition.at(1) = TRUE;
	}
	if (nChar == 0x41 && !popUpFlag)//A
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


	if (nChar == 0x44 && !popUpFlag)//D
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


void characterTool::characterKeyUp(UINT nChar, backgroundTool *background)
{
	if (nChar == 0x57 && !popUpFlag)//W
	{
		character.SetFlagMove(false);
		character_condition.at(0) = false;
		
	}
	if (nChar == 0x53 && !popUpFlag)//S
	{
		//character.SetFlagMove(false);
		character_condition.at(1) = false;
	}
	if (nChar == 0x41 && !popUpFlag)//A
	{
		//character.SetFlagMove(false);
		character_condition.at(2) = false;
		character.SetAnimation(200, true);
	}
	if (nChar == 0x44 && !popUpFlag)//D
	{
		//character.SetFlagMove(false);
		character.SetAnimation(200, true);
		character_condition.at(3) = false;
		character.SetFrameIndexOfBitmap(0);

	}

	if (nChar == 0x52 && popUpFlag == true) // R to return beginning state
	{
		popUpFlag = false;
		
		if (needToReInit == true)
		{
			background->backgroundInit();
			background->elementInit();
			characterInit();
			if (allSel == 2)
			{
				character.SetTopLeft(-2000, -2000);
			}
			needToReInit = false;
		}
	}
}
void characterTool::characterShowBitmap()
{
	if (popUpFlag == true) // to show the animation after died
	{				
		if (((clock() - die) / (double)(CLOCKS_PER_SEC)) >= 0.7)
		{
			popUp.ShowBitmap();
		}
		else
		{
			characterCry.SetTopLeft(character.GetLeft(), character.GetTop());
			characterCry.ShowBitmap();
			if (allSel == 2)
			{
				aircraft.ShowBitmap();
			}
		}
	}
	else
	{
		character.ShowBitmap();		
		if (allSel == 2)
		{
			aircraft.ShowBitmap();
		}
	}	

	if (allSel == 2)
	{		
		for (int i = 0; i < int(ammo.size()); i++)
		{
			ammo[i]->ShowBitmap();
		}

		for (int i = 0; i < int(slime.size()); i++)
		{
			slime[i]->ShowBitmap();
		}
	}
	
	
}

void characterTool::SetFlagMove(bool value)
{
	character.SetFlagMove(value);
}

void characterTool::SetPopUpFlag(bool value)
{
	popUpFlag = value;
}

bool characterTool::GetFlagMove() const
{
	return character.GetFlagMove();
}

bool characterTool::GetpopUpFlag() const
{
	return popUpFlag;
}


bool characterTool::GetFaceHitblock() const
{
	return  faceHitblock;
}

bool characterTool::GetBackHitblock() const
{
	return backHitblock;
}

int characterTool::GetTime() const
{
	return time3;
}

int characterTool::GetLeftEnmy() const
{
	return leftEnemy;
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

	std::vector<vector<int>> intFloor = {
							{ element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock,
							 elementEmptyBlock2, elementBlockU, elementBlockD, elementBlockI, elementBlockE, elementBlockD2},
							{elementQuestion, elementHit, elementLongBlock2_1, elementLongBlock2_2, elementVerticalLongBlock2_1, elementEmptyBlock2_1,
						 	 elementEmptyBlock2_2, elementEmptyBlock2_3},//
							{}
	};
	std::vector<vector<int>> intFeetFloor = {
							{ element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock, floor1_1, floor1_2, floor1_3,
							elementEmptyBlock2,elementPipe1, elementPipe2},
							{elementQuestion, elementFloor2_1, elementDropFloor2_1, elementFloor2_2, elementDropFloor2_2, elementFloor2_3,
							 elementHit, elementLongBlock2_1, elementLongBlock2_2, elementVerticalLongBlock2_1, elementEmptyBlock2_1, elementEmptyBlock2_2,
							 elementEmptyBlock2_3},
							{}

	};
	std::vector<vector<int>> intFeetFaceBack = {
							{ element, elementGo, elementEmptyBlock, elementLongBlock, elementShortBlock,
							 elementEmptyBlock2,elementPipe1, elementPipe2, floor1_1, floor1_2, floor1_3},
							{elementQuestion, elementHit, elementLongBlock2_1, elementLongBlock2_2, elementVerticalLongBlock2_1, elementEmptyBlock2_1,
							 elementEmptyBlock2_2, elementEmptyBlock2_3},//
							{}
	};
	std::vector<vector<int>> empty = {  { elementEmptyBlock, elementEmptyBlock2 },
										{ elementEmptyBlock2_1, elementEmptyBlock2_2, elementEmptyBlock2_3},
										{}
	};

	bool judge = false;
	headHitfloor = false;
	feetHitblock = false;
	faceHitblock = false;
	backHitblock = false;
	int sel = *backgroundElement->getSelAddress();
	for (int i = 0; i < int(intFloor[sel].size()); i++)
	{
		headHitfloor = headHitfloor || character.touchUp(&character, stage[intFloor[sel][i]]);
	}	

	for (int i = 0; i < int(intFeetFloor[sel].size()); i++)
	{
		for (int j = 0; j < int(empty[sel].size()); j++)
		{
			if (intFeetFloor[sel][i] == empty[sel][j])
			{
				judge = true;
			}
		}
		if (judge == false)
		{
			feetHitblock = feetHitblock || character.touchDown(&character, stage[intFeetFloor[sel][i]]);
		}
		else
		{
			feetHitblock = feetHitblock || (character.touchDown(&character, stage[intFeetFloor[sel][i]]) && stage[intFeetFloor[sel][i]]->GetFrameIndexOfBitmap() == 1);
			
		}
		judge = false;
	}

	for (int i = 0; i < int(intFeetFaceBack[sel].size()); i++)
	{
		for (int j = 0; j < int(empty[sel].size()); j++)
		{
			if (intFeetFaceBack[sel][i] == empty[sel][j])
			{
				judge = true;
			}
		}
		if (judge == false)
		{
			faceHitblock = faceHitblock || character.touchLeft(&character, stage[intFeetFaceBack[sel][i]]);
			backHitblock = backHitblock || character.touchRight(&character, stage[intFeetFaceBack[sel][i]]);
		}
		else
		{
			faceHitblock = faceHitblock || (character.touchLeft(&character, stage[intFeetFaceBack[sel][i]]) && stage[intFeetFaceBack[sel][i]]->GetFrameIndexOfBitmap() == 1);
			backHitblock = backHitblock || (character.touchRight(&character, stage[intFeetFaceBack[sel][i]]) && stage[intFeetFaceBack[sel][i]]->GetFrameIndexOfBitmap() == 1);
		}
		judge = false;
	}
	if (backgroundElement->getPlaying() == true)
	{
		switch (*(backgroundElement->getSelAddress()))
		{
		case 0:
			if (character.touchUp(&character, stage[elementGo]))
			{
				if (!popUpFlag && !needToReInit)
				{
					dieChange();
				}
			}

			if (character.IsOverlap(*stage[elementCloud], character))
			{
				if (!popUpFlag && !needToReInit)
				{
					dieChange();
				}
			}

			if (character.IsOverlap(*stage[elementGrass], character))
			{
				if (!popUpFlag && !needToReInit) {
					dieChange();
				}
			}

			if (character.IsOverlap(*stage[elementPrick1], character) ||
				character.IsOverlap(*stage[elementPrick2], character) ||
				character.IsOverlap(*stage[elementPoRight], character) ||
				character.IsOverlap(*stage[elementPoLeft], character) ||
				character.IsOverlap(*stage[elementPoUp], character))
			{
				if (!popUpFlag && !needToReInit)
				{
					dieChange();
				}
			}

			if (character.IsOverlap(*stage[elementLady], character))
			{
				backgroundElement->setSel(1);
				backgroundElement->setBackground(2);
				backgroundElement->setClearStage();
				backgroundElement->setInit(true);
				backgroundElement->backgroundInit();
				backgroundElement->elementInit();
				characterInit();
			}
			break;
		case 1:
			if (character.touchUp(&character, stage[elementHit]))
			{
				dieChange();
			}
			if (character.touchUp(&character, stage[elementLongBlock2_1]))
			{
				dieChange();
			}
			if (character.IsOverlap(*stage[elementFlower2_1], character) || character.IsOverlap(*stage[elementDoublePoLeft], character))
			{
				dieChange();
			}
			if (character.IsOverlap(*stage[elenentslime2_1], character) || character.IsOverlap(*stage[elenentslime2_1], character))
			{
				dieChange();
			}
			if (stage[elementPrick2_1]->IsOverlap(*stage[elementPrick2_1], character))
			{
				dieChange();
			}
			if (character.IsOverlap(*stage[elementLady2_1], character))
			{
				backgroundElement->setSel(2);
				backgroundElement->setBackground(3);
				characterInit();
				character.SetTopLeft(-2000, -2000);
				backgroundElement->setClearStage();
				backgroundElement->setInit(true);
				backgroundElement->backgroundInit();
				backgroundElement->elementInit();
				
			}

			break;

		case 2:
			for (int i = 0; i < int(ammo.size()); i++)
			{
				for (int j = 0; j < int(slime.size()); j++)
				{
					if (ammo[i]->IsOverlap(*ammo[i], *slime[j]))
					{
						slime[j]->SetFrameIndexOfBitmap(1);
						slime[j]->SetTopLeft(200, -1000);
						ammo[i]->SetTopLeft(0, -20);
					}
				}
				if (ammo[i]->IsOverlap(*ammo[i], *stage[elementClock3_1]))
				{
					ammo[i]->SetTopLeft(0, -20);
					hitClock += 1;
				}
			}
			for (int i = int(ammo.size()) - 1; i > 0; i--)
			{
				if (ammo[i]->GetTop() == -20)
				{
					delete ammo[i];
					ammo.erase(ammo.begin() + i);
				}
			}
			bool tmpCaculate = true;
			for (int i = 0; i < int(slime.size()); i++)
			{
				if (slime[i]->GetFrameIndexOfBitmap() == 1)
				{
					if (slime[i]->GetJudge() == false)
					{
						leftEnemy -= 1;
						slime[i]->SetJudge(true);
					}					
					tmpCaculate = tmpCaculate && true;
				}
				else
				{
					tmpCaculate = tmpCaculate && false;
				}
			}
			if (tmpCaculate == true)
			{
				dieChange();
			}

			if (((clock() - start3_1) / (double)(CLOCKS_PER_SEC)) >= 1)
			{
				if (aircraft.GetLeft() > 1500 && 2 < hitClock && hitClock < 6 && stage[elementClock3_1]->GetElementPo() == false)
				{
				}
				else if (hitClock >= 6 )
				{
				}
				else
				{
					if (time3 > 0)
					{
						time3 -= 1;
					}
					start3_1 = clock();
				}
			}
			if (hitClock >= 6)
			{
				stage[elementClock3_1]->SetFrameIndexOfBitmap(2);
			}
			else if (aircraft.GetLeft() > 1500 && 2 < hitClock && hitClock < 6 && stage[elementClock3_1]->GetElementPo() == false)
			{
				stage[elementClock3_1]->SetFrameIndexOfBitmap(1);
				stage[elementClock3_1]->SetJudge(true);
			}
			else if (aircraft.GetLeft() < 1500 && stage[elementClock3_1]->GetJudge() == true)
			{
				stage[elementClock3_1]->SetFrameIndexOfBitmap(0);
				stage[elementClock3_1]->SetElementPo(true);
			}


			if (time3 <= 0)
			{
				for (int i = 0; i < int(ammo.size()); i++)
				{
					ammo[i]->SetTopLeft(0, -20);
				}
				if (popUpFlag == false)
				{
					aircraft.SetFrameIndexOfBitmap(1);
					dieChange();
				}
				
			}

		}
	}

	
		

}

void characterTool::drop(backgroundTool *background)
{
	std::vector<MyCMovingBitmap *> stage;
	stage = *(background->getStageAddress());
	MyCMovingBitmap tmp = *(background->getBackgroundAddress());
	

	if (character.GetTop() > 960 && popUpFlag == false)
	{
		/*
		background->backgroundInit();
		background->elementInit();
		characterInit();*/
		dieChange();
	}
}

void characterTool::creatAmmo()
{
	MyCMovingBitmap *x = new MyCMovingBitmap;
	x->LoadBitmapByString({ "resources/ammo.bmp" },RGB(255, 255, 255));
	x->SetTopLeft(aircraft.GetLeft() + 42, aircraft.GetTop());
	ammo.push_back(x);
}
void characterTool::dieChange()
{
	die = clock();
	popUpFlag = true;
	needToReInit = true;
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

