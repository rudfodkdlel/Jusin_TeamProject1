#pragma once

#include "CObj.h"

class CMonster : public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:

	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	CObj* Create_Bullet();
	void        Set_Bullet(list<CObj*>* pBullet) { m_pBulletList = pBullet; }
	

private:
	list<CObj*>* m_pBulletList;
	ULONG64		m_ulTime;

};

