
// itigo1.1View.h : Citigo11View クラスのインターフェイス
//

#pragma once

#include "resource.h"
#include "C_Homeposition_Dialog.h"
#include "C_Motion_dialog.h"
#include "afxwin.h"


class Citigo11View : public CFormView
{
protected: // シリアル化からのみ作成します。
	Citigo11View();
	DECLARE_DYNCREATE(Citigo11View)

public:
	enum{ IDD = IDD_ITIGO11_FORM };

// 属性
public:
	Citigo11Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual void OnInitialUpdate(); // 構築後に初めて呼び出されます。

// 実装
public:
	virtual ~Citigo11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedButton1();
	C_Homeposition_Dialog homeposition_dialog;
	C_Motion_dialog motion_dialog;
	afx_msg void OnBnClickedButton2();
	int button_connect;
	afx_msg void OnBnClickedRadio2();
	CComboBox serial_servo_number_combox;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox DC_servo_number_combox;
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox serial_port_number;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton3();
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeEdit1();
	CEdit file_name_edit_box;
	afx_msg void OnCbnSelchangeCombo4();
	CComboBox baud_rate_compo_box;
};

#ifndef _DEBUG  // itigo1.1View.cpp のデバッグ バージョン
inline Citigo11Doc* Citigo11View::GetDocument() const
   { return reinterpret_cast<Citigo11Doc*>(m_pDocument); }
#endif

