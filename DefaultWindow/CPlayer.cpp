#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"

CPlayer::CPlayer() : m_pBullet(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo  = { WINCX / 2.f, WINCY / 2.f, 50.f, 50.f };
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	Key_Input();

	CObj::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	

}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, 
		m_tRect.left, 
		m_tRect.top, 
		m_tRect.right, 
		m_tRect.bottom);
	
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	// GetKeyState
	// GetAsyncKeyState // 함수 호출 시 반환되는 값에 따른 키 값 처리 가능

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_tRect.right + m_fSpeed <= GAME_WIN_RIGHT)
			m_tInfo.fX += m_fSpeed;
		else
			m_tInfo.fX = GAME_WIN_RIGHT - m_tInfo.fCX / 2.f;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if(m_tRect.left - m_fSpeed >= GAME_WIN_LEFT)
			m_tInfo.fX -= m_fSpeed;
		else
			m_tInfo.fX = GAME_WIN_LEFT + m_tInfo.fCX / 2.f;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (m_tRect.top - m_fSpeed >= GAME_WIN_TOP)
			m_tInfo.fY -= m_fSpeed;
		else
			m_tInfo.fY = GAME_WIN_TOP + m_tInfo.fCY / 2.f;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_tRect.bottom + m_fSpeed <= GAME_WIN_BOTTOM)
			m_tInfo.fY += m_fSpeed;
		else
			m_tInfo.fY = GAME_WIN_BOTTOM - m_tInfo.fCY / 2.f;
	}


	// 조건 추가해서 3방향 되도록
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(Create_Bullet(DIR_UP));
		//m_pBullet->push_back(Create_Bullet(DIR_RU));
		//m_pBullet->push_back(Create_Bullet(DIR_LU));
	}
}

CObj* CPlayer::Create_Bullet(DIRECTION eDir)
{
	CObj* pBullet = new CBullet;

	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	pBullet->SetDir(eDir);

	return pBullet;
}
