#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

class CTextDraw;
class CDDraw;
class backgroundTool;
class characterTool
{
public:
	~characterTool()
	{
		for (int i = 0; i < int(ammo.size()); i++)
		{
			delete ammo[i];
		}
		for (int i = 0; i < int(slime.size()); i++)
		{
			delete slime[i];
		}
	}
	void characterInit();
	void characterMove(backgroundTool *element);
	void characterKeyDown(UINT nChar);
	void characterKeyUp(UINT nChar, backgroundTool *background);
	void characterShowBitmap();
	void SetFlagMove(bool value);
	void SetPopUpFlag(bool value);
	bool GetFlagMove() const;
	bool GetpopUpFlag() const;
	bool GetFaceHitblock() const;
	bool GetBackHitblock() const;
	int GetTime() const;
	int GetLeftEnmy() const;
	MyCMovingBitmap *getCharacterAddress();
	bool GetIsDroppingAddress();
	void touchingElement(backgroundTool *element);
	void drop(backgroundTool *background);
	void creatAmmo();
	void dieChange();
	//void cleanBitMap(MyCMovingBitmap *item,vector<string> load);

	
protected:
	std::vector<MyCMovingBitmap *> slime;
	std::vector<MyCMovingBitmap *> ammo;
	std::vector<MyCMovingBitmap *> erraseAmmo;
	MyCMovingBitmap character;
	MyCMovingBitmap characterCry;
	MyCMovingBitmap aircraft;
	MyCMovingBitmap characterleft;
	MyCMovingBitmap dieCry;
	std::vector<bool> character_condition;
	int chieght = 0;
	bool headHitfloor=false;
	bool feetHitblock = false;
	bool faceHitblock = false;
	bool backHitblock = false;
	bool isDropping = false;
	bool isJumping = false;
	bool dontRead = false;
	bool popUpFlag = false; // using for animation after died
	bool needToReInit = false; // using to ReInit after died
	game_framework::CMovingBitmap popUp; // pop up image after died 
	
	clock_t start;
	clock_t start3_1;
	clock_t die;

	bool first = false;

	bool playing = false;
	bool init = false;
	int allSel;
	int time3;
	int hitClock;
	int leftEnemy;
};

#endif