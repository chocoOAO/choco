#pragma once


class MyCMovingBitmap : public game_framework::CMovingBitmap
{
    bool flag_move;
public:
    void SetFlagMove(bool value);
    bool GetFlagMove() const;
    int button = 0;
};
