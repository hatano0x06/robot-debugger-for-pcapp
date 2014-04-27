#pragma once
#include "afxwin.h"


// detail_window ダイアログ

class detail_window : public CDialogEx
{
	DECLARE_DYNAMIC(detail_window)

public:
	detail_window(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~detail_window();

// ダイアログ データ
	enum { IDD = IDD_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	CScrollBar offset_position_scroll_bar;
	CScrollBar duty_limit_scroll_bar;
	CScrollBar dead_band_scroll_bar;
	CScrollBar position_limit_max_scroll_bar;
	CScrollBar position_limit_min_scroll_bar;
	CScrollBar i_limit_scroll_bar;
	CEdit offset_position_edit_box;
	CEdit duty_limit_edit_box;
	CEdit dead_band_edit_box;
	CEdit position_limit_max_edit_box;
	CEdit position_limit_min_edit_box;
	CEdit i_limit_edit_box;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit6();
};
