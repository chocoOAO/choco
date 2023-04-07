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

bool MyCMovingBitmap::touchUp(MyCMovingBitmap *character, MyCMovingBitmap *element)
{
	if ((character->GetTop() - 5 <= element->GetTop() + element->GetHeight()) && (character->GetTop()  > element->GetTop() + element->GetHeight() - 10) &&
		(character->GetLeft() < element->GetLeft() + character->GetWidth()) && character->GetLeft() + 150 > element->GetLeft()
		)
	{
		return true;
	}
	return false;
}

bool MyCMovingBitmap::touchDown(MyCMovingBitmap *character, MyCMovingBitmap *element)
{
	if ((character->GetTop() +character->GetHeight()+20  >=  element->GetTop()) && (character->GetTop() + character->GetHeight() -100 < element->GetTop()) &&
		(character->GetLeft() < element->GetLeft() + character->GetWidth()) && (character->GetLeft() + 150 > element->GetLeft())
		)
	{
		return true;
	}
	return false;
}