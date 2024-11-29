#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	INFO		Get_Info() { return m_tInfo; }
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

public:
	virtual void		Initialize()PURE;
	virtual int			Update()PURE;
	virtual void		Late_Update()PURE;
	virtual void		Render(HDC hDC)PURE;
	virtual void		Release()PURE;

public:
	void	Update_Rect();
	void	SetDir(DIRECTION eDir) { m_eDir = eDir; }
	void	SetDead() { m_bDead = true;  }
	const RECT*	GetRect() { return &m_tRect; }
protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fAngle;
	float		m_fSpeed;
	bool		m_bDead;
	DIRECTION	m_eDir;
	int			m_iHp;
	int			m_iAP;
};

