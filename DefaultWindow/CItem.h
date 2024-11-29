#pragma once

#include "CObj.h"

class CItem : public CObj
{
public:
	CItem();
	virtual ~CItem();

private:


	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

};
