#pragma once
#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "MyCMovingBitmap.h"

class catalogue
{
public:
    void selectInit();
    void backgroundKeyDown(UINT nChar);
    void selectShowBitmap();
    
protected:
    int slc = 0;
    MyCMovingBitmap background;
    MyCMovingBitmap select1;
    MyCMovingBitmap select2;
    MyCMovingBitmap totalSelect;
    
};



#endif  CATALOGUE_H
