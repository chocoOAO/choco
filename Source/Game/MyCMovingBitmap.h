#pragma once



class MyCMovingBitmap : public game_framework::CMovingBitmap
{
    bool flag_move;
public:
    void SetFlagMove(bool value);
    bool GetFlagMove() const;
	bool touchUp(MyCMovingBitmap *character, MyCMovingBitmap *element);
	bool touchDown(MyCMovingBitmap *character, MyCMovingBitmap *element);
	bool touchLeft(MyCMovingBitmap *character, MyCMovingBitmap *element);
	bool touchRight(MyCMovingBitmap *character, MyCMovingBitmap *element);
	int button = 0;
};
