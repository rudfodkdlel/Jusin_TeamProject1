#include "pch.h"
#include "CCollisionMgr.h"


void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT rc{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, Dst->GetRect(), Src->GetRect()))
			{
				Dst->SetDead();
				Src->SetDead();
			}
		}
	}

}

void CCollisionMgr::Collision_Circle(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT rc{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Circle(Dst, Src))
			{
				Dst->SetDead();
				Src->SetDead();
			}
		}
	}
}

bool CCollisionMgr::Check_Circle(CObj* _Dst, CObj* _Src)
{
	float fRadius = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	float fWidth = abs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float fHeight = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	return fRadius >= fDiagonal;
}
