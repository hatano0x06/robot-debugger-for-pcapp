#pragma once
#include "afxwin.h"
#include "detail_window.h"

// C_Motion_dialog ダイアログ

class C_Motion_dialog : public CDialogEx
{
	DECLARE_DYNAMIC(C_Motion_dialog)

public:
	C_Motion_dialog(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~C_Motion_dialog();

// ダイアログ データ
	enum { IDD = IDD_MOTION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CComboBox motion_servo_number_combox;
	afx_msg void OnBnClickedButton3();
	CScrollBar accel_scroll_bar;
	CEdit accel_edit_box;
	CScrollBar target_position_scroll_bar;
	CEdit target_position_edit_box;
	detail_window detail_dialog; 
	CScrollBar p_gain_scroll_bar;
	CScrollBar i_gain_scroll_bar;
	CScrollBar d_gain_scroll_bar;
	CEdit p_gain_edit_box;
	CEdit i_gain_edit_box;
	CEdit d_gain_edit_box;
	CScrollBar speed_limit_scroll_bar;
	CEdit speed_limit_edit_box;

	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButton4();
	CListBox motion_list;
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit7();
	CScrollBar delay_scroll_bar;
	CEdit delay_edit_box;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnEnChangeEdit11();
	afx_msg void OnBnClickedCheck1();
	CButton sync_check_box;
	afx_msg void OnBnClickedButton5();
};
