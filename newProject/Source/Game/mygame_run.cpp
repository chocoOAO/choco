#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

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
	if (character.button == 1 && character.GetFlagMove() == true)
	{
		if (character.GetTop() > chieght-400 )
		{
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 20);//按住持續W
		}
		else if(character.GetTop() != 733)
		{
			chieght = 2000;
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);
		}
						
	}
	if (character.GetFlagMove() == false)
	{
		if (character.GetTop() != 733)
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);
	}

	

	if (character.button == 2 && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft(), character.GetTop() + 20);//按住持續S
	}

	if (character.button == 3 && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft() - 3, character.GetTop());//按住持續A
		background.SetTopLeft(background.GetLeft() + 20, background.GetTop());
		character.SetAnimation(150, false);
	}

	if (character.button == 4 && character.GetFlagMove() == true)
	{
		character.SetTopLeft(character.GetLeft() + 3, character.GetTop());//按住持續D
		background.SetTopLeft(background.GetLeft() - 20, background.GetTop());
		character.SetAnimation(150, false);

	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({
		"resources/background3.bmp",
		"resources/level1.bmp"
		}, 0);
	background.SetTopLeft(0, 0);

	character.LoadBitmapByString({
		"resources/character1.bmp",
		"resources/character2.bmp",
		"resources/character1.bmp",
		"resources/character3.bmp",
		"resources/character1.bmp" }, 0, RGB(255, 255, 255));
	character.SetTopLeft(180, 733);

	select1.LoadBitmapByString({ "resources/select1.bmp" }, 0, RGB(255, 255, 255));
	select1.SetTopLeft(600, 400);

	select2.LoadBitmapByString({ "resources/select2.bmp" }, 0, RGB(255, 255, 255));
	select2.SetTopLeft(880, 400);

	totalSelect.LoadBitmapByString({ "resources/select1_2.bmp", "resources/select2_2.bmp" }, 0, RGB(255, 255, 255));
	totalSelect.SetTopLeft(600, 400);

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if (nChar == 0x57)//W
	{
		character.SetFlagMove(true);
		character.button = 1;
		chieght = int(character.GetTop());
		/*
			for (int i=0; i < 15; i++)
			{
				character.SetTopLeft(character.GetLeft(), character.GetTop() - 30);//按住持續W
			
			}*/
		
		//chieght = 300;
		//character.SetTopLeft(character.GetLeft(), character.GetTop() + 15);
		
			   	
		
	}
	if (nChar == 0x53)//S
	{
		character.SetFlagMove(true);
		character.button = 2;
	}
	if (nChar == 0x41)//A
	{
		character.SetFlagMove(true);
		character.button = 3;
		int x = character.GetLeft();
		int y = character.GetTop();
		character.LoadBitmapByString({ "resources/character1.bmp" }, 1);
		character.LoadBitmapByString({
		"resources/character1.bmp",
		"resources/character6.bmp",
		"resources/character1.bmp",
		"resources/character7.bmp",
		"resources/character1.bmp" }, 1, RGB(255, 255, 255));
		character.SetTopLeft(x, y);
	}

		
	if (nChar == 0x44)//D
	{
		character.SetFlagMove(true);
		character.button = 4;
		int x = character.GetLeft();
		int y = character.GetTop();
		character.LoadBitmapByString({ "resources/character1.bmp" }, 1);
		character.LoadBitmapByString({
		"resources/character1.bmp",
		"resources/character2.bmp",
		"resources/character1.bmp",
		"resources/character3.bmp",
		"resources/character1.bmp" }, 1, RGB(255, 255, 255));
		character.SetTopLeft(x, y);
	}
	
	if (nChar == 0x27 && playing==false)//向右選關鍵
	{
		if (sel < 1)
			sel += 1;
		else
			sel = 0;
		totalSelect.SetFrameIndexOfBitmap(sel);
		if (sel == 0)
			totalSelect.SetTopLeft(600, 400);
		if (sel == 1)
			totalSelect.SetTopLeft(880, 400);

	}
	if (nChar == VK_RETURN)//向右選關鍵
	{
		if (sel == 0)
		{
			playing = true;
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

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == 0x57)//W
	{
		character.SetFlagMove(false);
	}
	if (nChar == 0x53)//S
	{
		character.SetFlagMove(false);
	}
	if (nChar == 0x41)//A
	{
		character.SetFlagMove(false);
		character.SetAnimation(200, true);
	}
	if (nChar == 0x44)//D
	{
		character.SetFlagMove(false);
		character.SetAnimation(200, true);
		character.SetFrameIndexOfBitmap(0);

	}
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
	background.ShowBitmap();
	character.ShowBitmap();
	select1.ShowBitmap();
	select2.ShowBitmap();
	totalSelect.ShowBitmap();

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