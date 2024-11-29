#include "pch.h"
#include "CMainGame.h"
#include "CCollisionMgr.h"

CMainGame::CMainGame():
	 m_dwTime(GetTickCount64()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	srand(unsigned(time(NULL)));

	CObj* Player = new CPlayer;
	Player->Initialize();

	m_ObjList[OBJ_PLAYER].push_back(Player);
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);

	CObj* Monster = new CMonster;
	Monster->Initialize();
	m_ObjList[OBJ_MONSTER].push_back(Monster);
	dynamic_cast<CMonster*>(m_ObjList[OBJ_MONSTER].back())->Set_Bullet(&m_ObjList[OBJ_BULLET]);

	CObj* Item = new CItem;
	Item->Initialize();
	m_ObjList[OBJ_ITEM].push_back(Item);
}

void CMainGame::Update()
{
	if (m_dwTime + 1000 < GetTickCount64())
	{
		CObj* Monster = new CMonster;
		Monster->Initialize();
		m_ObjList[OBJ_MONSTER].push_back(Monster);
		dynamic_cast<CMonster*>(m_ObjList[OBJ_MONSTER].back())->Set_Bullet(&m_ObjList[OBJ_BULLET]);

		CObj* Item = new CItem;
		Item->Initialize();
		m_ObjList[OBJ_ITEM].push_back(Item);

		m_dwTime = GetTickCount64();
	}

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto j = m_ObjList[i].begin(); j != m_ObjList[i].end();)
		{
			int result = (*j)->Update();
			if (result == OBJ_DEAD)
			{
				Safe_Delete<CObj*>(*j);
				j = m_ObjList[i].erase(j);
			}
			else
				++j;
		}
	}
	
} 

void CMainGame::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& j : m_ObjList[i])
		{
			j->Late_Update();
		}
	}
	CCollisionMgr::Collision_Circle(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET]);
	
	
}

void CMainGame::Render()
{
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount64();
	}


	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, GAME_WIN_LEFT, GAME_WIN_TOP, GAME_WIN_RIGHT, GAME_WIN_BOTTOM);
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Render(m_hDC);
		}

	}


	TCHAR		szBuf[32] = L"";
	wsprintf(szBuf, L"Bullet : %d", (int)m_ObjList[OBJ_BULLET].size());

	TextOut(m_hDC, 50, 50, szBuf, lstrlen(szBuf));

	// wsprintf(szBuf, L"Bullet : %f", 3.141592f);	// 소수점 자릿수 출력이 불가능
	// swprintf_s(szBuf, L"Bullet : %f", 3.141592f);	// 모든 서식 문자 지원 함수
	// RECT	rcRect{ 100, 100, 200, 200 };	
	// DrawText(m_hDC, szBuf, lstrlen(szBuf), &rcRect, DT_CENTER);


}

void CMainGame::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& j : m_ObjList[i])
		{
			Safe_Delete<CObj*>(j);
			
		}
		m_ObjList[i].clear();
	}

	ReleaseDC(g_hWnd, m_hDC);
}
