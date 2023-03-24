#include "stdafx.h"
#include "../Core/Resource.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
using namespace game_framework;

void MyCMovingBitmap::SetFlagMove(bool value)
{
    flag_move = value;
}

bool MyCMovingBitmap::GetFlagMove() const
{
    return flag_move;
}
