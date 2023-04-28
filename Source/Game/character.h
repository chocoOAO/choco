#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H


class backgroundTool;
class characterTool
{
public:
	void characterInit();
	void characterMove(MyCMovingBitmap *background);
	void characterKeyDown(UINT nChar);
	void characterKeyUp(UINT nChar);
	void characterShowBitmap();
	void SetFlagMove(bool value);
	//void jump(std::vector<bool> vector);
	bool GetFlagMove() const;
	bool GetFaceHitblock() const;
	bool GetBackHitblock() const;
	MyCMovingBitmap *getCharacterAdress();
	void touchingElement(backgroundTool *element);



protected:
	MyCMovingBitmap character;
	MyCMovingBitmap characterleft;
	std::vector<bool> character_condition;
	int chieght = 0; // restore the height before character jump
	bool headHitfloor = false;
	bool feetHitblock = false;
	bool faceHitblock = false;
	bool backHitblock = false;

};

#endif