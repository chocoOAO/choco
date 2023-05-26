#pragma once



class MyCMovingBitmap : public game_framework::CMovingBitmap
{
public:
    void SetFlagMove(bool value);
    bool GetElementPo() const;
	void SetElementPo(bool value);
	bool GetElementPo2() const;
	void SetElementPo2(bool value);
	bool GetFlagMove() const;
	bool touchUp(MyCMovingBitmap *character, MyCMovingBitmap *element);
	bool touchDown(MyCMovingBitmap *character, MyCMovingBitmap *element);
	bool touchLeft(MyCMovingBitmap *character, MyCMovingBitmap *element);
	bool touchRight(MyCMovingBitmap *character, MyCMovingBitmap *element);
	int button = 0;

protected:
	bool elementPo = false;
	bool elementPo2 = false;
	bool flag_move;

};
