
// itigo1.1.h : itigo1.1 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// Citigo11App:
// ���̃N���X�̎����ɂ��ẮAitigo1.1.cpp ���Q�Ƃ��Ă��������B
//

class Citigo11App : public CWinAppEx
{
public:
	Citigo11App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Citigo11App theApp;
