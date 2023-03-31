#pragma once
#include "MyCMovingBitmap.h"


class character :public MyCMovingBitmap
{
public:


protected:
	MyCMovingBitmap background;
	MyCMovingBitmap select1;
	MyCMovingBitmap select2;
	MyCMovingBitmap totalSelect;
};