#include "stdafx.h"
#include "../Library/gameutil.h"
#include <mmsystem.h>
#include "MyCMovingBitmap.h"
#include "catalogue.h"

using namespace game_framework;

void catalogue::selectInit()
{
    select1.LoadBitmapByString({ "resources/select1.bmp" }, RGB(255, 255, 255));
    select1.SetTopLeft(600, 400);

    select2.LoadBitmapByString({ "resources/select2.bmp" }, RGB(255, 255, 255));
    select2.SetTopLeft(880, 400);

    totalSelect.LoadBitmapByString({ "resources/select1_2.bmp", "resources/select2_2.bmp" }, RGB(255, 255, 255));
    totalSelect.SetTopLeft(600, 400);
}

void catalogue::backgroundKeyDown(UINT nChar)
{
    if (nChar == 0x27) 
    {
        if (slc < 1)
            slc += 1;
        else
            slc = 0;
        totalSelect.SetFrameIndexOfBitmap(slc);
        if (slc == 0)
            totalSelect.SetTopLeft(600, 400);
        if (slc == 1)
            totalSelect.SetTopLeft(880, 400);

    }
    if (nChar == VK_RETURN)
    {
        if (slc == 0)
        {
            background.SetFrameIndexOfBitmap(1);
            for (int i = 0; i < 2; i++)
            {
                totalSelect.SetFrameIndexOfBitmap(i);
                totalSelect.SetTopLeft(-600, -400);
            }
            select1.SetTopLeft(-600, -400);
            select2.SetTopLeft(-600, -400);
        }
    }
}

void catalogue::selectShowBitmap()
{
    select1.ShowBitmap();
    select2.ShowBitmap();
    totalSelect.ShowBitmap();
}
