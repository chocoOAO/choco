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
	character.characterMove(background.getAdress());
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	character.characterInit();
	background.backgroundInit();
	background.selectInit();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	character.characterKeyDown(nChar);
	background.backgroundKeyDown(nChar);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	character.characterKeyUp(nChar);
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

}

void CGameStateRun::show_image_by_phase() 
{
	//background.SetFrameIndexOfBitmap((phase - 1) * 2 + (sub_phase - 1));
	background.backroundShowBitmap();
	character.characterShowBitmap();
	background.selectShowBitmap();

}

/*
void CGameStateRun::show_text_by_phase()
{
	CDC *pDC = CDDraw::GetBackCDC();
	//CFont* fp;

	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 79, 228, "IQ:200");

	
	CTextDraw::ChangeFontLog(pDC, fp, 24, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 182, 431, "Press any key to start");
	
	CDDraw::ReleaseBackCDC();
}
*/