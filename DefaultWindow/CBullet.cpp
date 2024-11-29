#include "pch.h"
#include "CBullet.h"

CBullet::CBullet() 
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 5.f;
}

int CBullet::Update()
{

	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eDir)
	{
	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_RU:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_END:
		break;
	default:
		break;
	}
	

	CObj::Update_Rect();

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	if (m_tRect.left   <= GAME_WIN_LEFT  )
		SetDead();
	if ( m_tRect.right  >= GAME_WIN_RIGHT )
		SetDead();
	if ( m_tRect.top  <= GAME_WIN_TOP )
		SetDead();
	if ( m_tRect.bottom  >= GAME_WIN_BOTTOM)
		SetDead();
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{
}
