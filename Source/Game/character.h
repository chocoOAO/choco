#pragma once



class characterTool
{
public:
	void characterInit();
	void characterMove(MyCMovingBitmap *background);
	void characterKeyDown(UINT nChar);
	void characterKeyUp(UINT nChar);
	void characterShowBitmap();
	void SetFlagMove(bool value);
	bool GetFlagMove() const;
	bool GetFaceHitblock() const;
	bool GetBackHitblock() const;
	MyCMovingBitmap *getCharacterAdress();
	void touchingElement(MyCMovingBitmap *element);



protected:
	MyCMovingBitmap character;
	MyCMovingBitmap characterleft;
	std::vector<bool> character_condition;
	int chieght = 0;
	bool headHitfloor=false;
	bool fitHitblock = false;
	bool faceHitblock = false;
	bool backHitblock = false;

};


