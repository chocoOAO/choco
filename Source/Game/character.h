#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

class CTextDraw;
class CDDraw;
class backgroundTool;
class characterTool
{
public:
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
	MyCMovingBitmap *getCharacterAddress();
	bool GetIsDroppingAddress();
	void touchingElement(backgroundTool *element);
	void drop(backgroundTool *background);
	//void cleanBitMap(MyCMovingBitmap *item,vector<string> load);

	
protected:
	MyCMovingBitmap character;
	MyCMovingBitmap characterleft;
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
};

#endif