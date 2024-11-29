#pragma once

#include "Define.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBullet.h"
#include "CItem.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC			m_hDC;

	list<CObj*>			m_ObjList[OBJID::OBJ_END];

	ULONG64		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[16];

};

// 1. W, A, S, D Ű�� ���� ��� �� ������ ���ϴ� �̻��� �߻��ϱ�
// 2. ��ü ȭ�麸�� ���� 100, ���� 100 ���� �簢���� �׸��� �� ������ ��� �̻��� �Ҹ��Ű��
// 3. ���� �簢�� �ȿ��� �·� �Ǵ� ��� ���ϴ� ���͸� �����ϱ�
// 4. �߻��� �Ѿ˰� ���Ͱ� �浹�� ��� �����ض�

// BOOL IntersectRect(�浹�� ��Ʈ�� ���� �߻��� ��Ʈ�� ������ ������ �ּ�, ��Ʈ �ּ�1, ��Ʈ �ּ�2)