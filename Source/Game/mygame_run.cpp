#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "MyCMovingBitmap.h"
#include "mygame.h"
#include "character.h"
#include <iostream>
#include <string>

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	character.touchingElement(&background);
	character.drop(&background);
	if (!character.popUpFlag)
	{
		character.characterMove(background.getBackgroundAddress());	
		background.Move(&character);
		if (character.needToReInit)
		{
			character.characterInit();
			background.backgroundInit();
			background.elementInit();
			character.needToReInit = false;
		}
	}

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	character.characterInit();
	background.backgroundInit();
	background.selectInit();
	background.elementInit();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	character.characterKeyDown(nChar);
	background.backgroundKeyDown(nChar);
	background.KeyDown(nChar);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	character.characterKeyUp(nChar);
	background.KeyUp(nChar);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	show_image_by_phase();
	//show_text_by_phase();
}

void CGameStateRun::show_image_by_phase() 
{
	//background.SetFrameIndexOfBitmap((phase - 1) * 2 + (sub_phase - 1));
	background.backroundShowBitmap();
	background.selectShowBitmap();
	if (background.getPlaying())
	{
		
		background.touching(&character);
		character.characterShowBitmap();
	}

}


void CGameStateRun::show_text_by_phase()
{
	/*
	CDC *pDC = CDDraw::GetBackCDC();
	//CFont* fp;
	MyCMovingBitmap tmp = *(background.getBackgroundAddress());
	MyCMovingBitmap tmp3 = *(character.getCharacterAddress());
	string tmp2 = std::to_string(tmp.GetLeft());
	string tmp4 = std::to_string(tmp3.GetTop());
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 50, 50, tmp2);
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 50, 100, tmp4);
	//CTextDraw::Print(pDC, 50, 50, "IQ:200");
		
	CDDraw::ReleaseBackCDC();
	*/
}
