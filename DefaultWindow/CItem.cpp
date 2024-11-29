#include "pch.h"
#include "CItem.h"

CItem::CItem()
{
}

CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
	m_tInfo = { WINCX / 2.f, 200.f, 50.f, 50.f };


	m_fSpeed = 5.f;
}

int CItem::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	
	m_tInfo.fY += m_fSpeed;

	CObj::Update_Rect();

    return OBJ_NOEVENT;
}

void CItem::Late_Update()
{
	// �� �浹 �ϸ� ��
}

void CItem::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
	// ������? �� ����� ���Ƽ� �򰥸��µ�
}

void CItem::Release()
{
}
