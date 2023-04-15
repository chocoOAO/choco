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
	if ((character->GetTop() - 5 <= element->GetTop() + element->GetHeight()) && (character->GetTop()  > element->GetTop() + element->GetHeight() - 90) &&
		(character->GetLeft() < element->GetLeft() + element->GetWidth() - 20) && character->GetLeft() + 150 > element->GetLeft()
		)
	{
		return true;
	}
	return false;
}

bool MyCMovingBitmap::touchDown(MyCMovingBitmap *character, MyCMovingBitmap *element)
{
	if ((character->GetTop() +character->GetHeight() + 10  >=  element->GetTop()) && (character->GetTop() + character->GetHeight() -100 < element->GetTop()) &&
		(character->GetLeft() < element->GetLeft() + element->GetWidth() - 20) && (character->GetLeft() + 150 > element->GetLeft())
		)
	{
		return true;
	}
	return false;
}

bool MyCMovingBitmap::touchLeft(MyCMovingBitmap *character, MyCMovingBitmap *element)
{
	if ((character->GetLeft() + character->GetWidth() + 5 >= element->GetLeft()) && (character->GetLeft() + character->GetWidth() <= element->GetLeft() + 50) &&
		(character->GetTop() > element->GetTop() - 130) && character->GetTop() < element->GetTop() + element->GetHeight()
		)
	{
		return true;
	}
	return false;
}

bool MyCMovingBitmap::touchRight(MyCMovingBitmap *character, MyCMovingBitmap *element)
{
	if ((character->GetLeft() -5 <= element->GetLeft() +element->GetWidth()) && (character->GetLeft() >= element->GetLeft() + element->GetWidth() - 50) &&
		(character->GetTop() > element->GetTop() - 130) && character->GetTop() < element->GetTop() + element->GetHeight()
		)
	{
		return true;
	}
	return false;
}

