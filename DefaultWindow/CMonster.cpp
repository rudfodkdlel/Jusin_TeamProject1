#include "pch.h"
#include "CMonster.h"
#include "CBullet.h"

CMonster::CMonster() : m_pBulletList(nullptr), m_ulTime(GetTickCount64())
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{

	int tmpX = rand() % 300 + 250;
	int tmpY = rand() % 475 + 75;

	m_tInfo = { (float)tmpX, (float)tmpY , 30.f, 30.f };
	m_fSpeed = 1.f;



	m_eDir = static_cast<DIRECTION>(rand() % 4);

	
}

int CMonster::Update()
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
	default:
		break;
	}

	if (m_ulTime + 1000 < GetTickCount64())
	{
		m_pBulletList->push_back(Create_Bullet());
		m_ulTime = GetTickCount64();
	}
	

	CObj::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	

	if (m_tRect.left <= GAME_WIN_LEFT)
		SetDead();
	if (m_tRect.right >= GAME_WIN_RIGHT)
		SetDead();
	if (m_tRect.top <= GAME_WIN_TOP)
		SetDead();
	if (m_tRect.bottom >= GAME_WIN_BOTTOM)
		SetDead();
	
}

void CMonster::Render(HDC hDC)
{
	

	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CMonster::Release()
{
}

CObj* CMonster::Create_Bullet()
{
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY + 40);
	pBullet->SetDir(DIR_DOWN);
	return pBullet;
}

