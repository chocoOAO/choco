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



protected:
	MyCMovingBitmap character;
	MyCMovingBitmap characterleft;
	std::vector<bool> character_condition;
	int chieght = 0;
};


