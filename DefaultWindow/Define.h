#pragma once

#define WINCX      800
#define WINCY      600

#define GAME_WINCX      400
#define GAME_WINCY      550

#define GAME_WIN_LEFT      (WINCX - GAME_WINCX) * 0.5f
#define GAME_WIN_TOP      (WINCY - GAME_WINCY) * 0.5f
#define GAME_WIN_RIGHT      (WINCX - GAME_WINCX) * 0.5f + GAME_WINCX
#define GAME_WIN_BOTTOM      (WINCY - GAME_WINCY) * 0.5f + GAME_WINCY

#define	PURE		= 0
#define PI			3.141592f

#define OBJ_NOEVENT			0
#define OBJ_DEAD			1	

extern HWND		g_hWnd;

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

enum OBJID { OBJ_PLAYER, OBJ_MONSTER, OBJ_BULLET, OBJ_ITEM, OBJ_MOUSE, OBJ_BUTTON, OBJ_END };

enum BULLETTYPE {B_PLAYER, B_MONSTER, B_MOON, B_END}; //  if������ OBJID�� ���� �ɾ ���� ������ �ٸ��� �浹 ó�� �ϸ� �ɵ�?

typedef struct tagInfo
{
	float		fX, fY;
	float		fCX, fCY;	// ����, ���� ����

}INFO;


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}