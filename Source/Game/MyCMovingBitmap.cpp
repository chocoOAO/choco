#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "MyCMovingBitmap.h"
#include"mygame.h"
using namespace game_framework;

void MyCMovingBitmap::SetFlagMove(bool value)
{
    flag_move = value;
}

bool MyCMovingBitmap::GetFlagMove()
{
    return flag_move;
}
