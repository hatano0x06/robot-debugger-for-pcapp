#pragma once
#include "afxwin.h"
#include "detail_window.h"

// C_Homeposition_Dialog ダイアログ

class C_Homeposition_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(C_Homeposition_Dialog)

public:
	C_Homeposition_Dialog(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~C_Homeposition_Dialog();

// ダイアログ データ
	enum { IDD = IDD_HOMEPOSITION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	CComboBox servo_number_combox;
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//	virtual void PreSubclassWindow();
//	virtual void PreInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	CEdit servo_name_box;
	CScrollBar p_gain_scroll_bar;
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar i_gain_scroll_bar;
	CScrollBar d_gain_scroll_bar;
	CEdit p_gain_edit_box;
	CEdit i_gain_edit_box;
	CEdit d_gain_edit_box;
	afx_msg void OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult);
	CScrollBar accel_scroll_bar;
	CEdit accel_edit_box;
	CScrollBar target_position_scroll_bar;
	CEdit target_position_edit_box;
	detail_window detail_dialog; 

	afx_msg void OnNMThemeChangedScrollbar5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMThemeChangedScrollbar8(NMHDR *pNMHDR, LRESULT *pResult);
	CScrollBar speed_limit_scroll_bar;
	CEdit speed_limit_edit_box;
	CScrollBar delay_scroll_bar;
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnBnClickedCheck1();
	CButton sync_check_box;
};
