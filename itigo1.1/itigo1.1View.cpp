
// itigo1.1View.cpp : Citigo11View クラスの実装
//

#include "stdafx.h"

// SHARED_HANDLERS は、プレビュー、サムネイル、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "itigo1.1.h"
#endif

#include "itigo1.1Doc.h"
#include "itigo1.1View.h"
#include <iostream>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include "global.h"

#define ACC 31
#define DEAD_BAND 3
#define DUTY_LIM 5
#define D_GAIN 2
#define INIT_POS 200
#define I_GAIN 10
#define I_LIMIT 1000
#define OFFSET 0
#define POS_MAX 3600
#define POS_MIN 0
#define P_GAIN 5
#define SET_POS 0
#define SPEED_LIMIT 31
#define TARGET_POS 450



using namespace std;


// Citigo11View

IMPLEMENT_DYNCREATE(Citigo11View, CFormView)

BEGIN_MESSAGE_MAP(Citigo11View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_RADIO1, &Citigo11View::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_BUTTON1, &Citigo11View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Citigo11View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO2, &Citigo11View::OnBnClickedRadio2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Citigo11View::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &Citigo11View::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Citigo11View::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &Citigo11View::OnBnClickedButton3)
//	ON_WM_HSCROLL()
ON_EN_CHANGE(IDC_EDIT1, &Citigo11View::OnEnChangeEdit1)
ON_CBN_SELCHANGE(IDC_COMBO4, &Citigo11View::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()

// Citigo11View コンストラクション/デストラクション


Citigo11View::Citigo11View()
	: CFormView(Citigo11View::IDD)
	, button_connect(1)

{
	// TODO: 構築コードをここに追加します。

}

Citigo11View::~Citigo11View()
{
}

void Citigo11View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, button_connect);
	DDX_Control(pDX, IDC_COMBO2, serial_servo_number_combox);
	DDX_Control(pDX, IDC_COMBO3, DC_servo_number_combox);
	DDX_Control(pDX, IDC_COMBO1, serial_port_number);
	DDX_Control(pDX, IDC_EDIT1, file_name_edit_box);
	DDX_Control(pDX, IDC_COMBO4, baud_rate_compo_box);
}

BOOL Citigo11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void Citigo11View::OnInitialUpdate()
{
	static bool First = true;
	CString temp;
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	if(First == true){
		homeposition_dialog.Create(IDD_HOMEPOSITION,this);
		motion_dialog.Create(IDD_MOTION_DIALOG,this);
		for(int i=0;i<20;i++){
			temp.Format("%d",i);
			serial_servo_number_combox.InsertString(-1,temp);
			DC_servo_number_combox.InsertString(-1,temp);
		}
		for(int i=1;i<5;i++){
			temp.Format("%d",i);
			serial_port_number.InsertString(-1,"COM."+temp);
		}
		temp.Format("%d",9600);
		baud_rate_compo_box.InsertString(-1,temp);
		temp.Format("%d",14400);
		baud_rate_compo_box.InsertString(-1,temp);
		temp.Format("%d",19200);
		baud_rate_compo_box.InsertString(-1,temp);
		temp.Format("%d",28800);
		baud_rate_compo_box.InsertString(-1,temp);
		temp.Format("%d",38400);
		baud_rate_compo_box.InsertString(-1,temp);
		temp.Format("%d",57600);
		baud_rate_compo_box.InsertString(-1,temp);
		temp.Format("%d",115200);
		baud_rate_compo_box.InsertString(-1,temp);

		file_output_time=0;
		serial_servo_number = 0;
		DC_servo_number = 0;
		servo_name_number=0;
		motion_number=0;
		comport=0;
		baud_rate=9600;
		max_motion_number=1;
		file_name_edit_box.SetWindowTextA("action");
		for(int i=0;i<30;i++){
			temp.Format("%d",i);
			delay[i]=500;
			for(int j=0; j<30;j++){
				arm[i][j].servo_name_a="arm"+temp;
				arm[i][j].acceleration_limit_a=ACC;
				arm[i][j].dead_band_a=DEAD_BAND;
				arm[i][j].duty_limit_a=DUTY_LIM;
				arm[i][j].d_gain_a=D_GAIN;
				arm[i][j].id_a=i+1;
				arm[i][j].initial_position_a=INIT_POS;
				arm[i][j].i_gain_a=I_GAIN;
				arm[i][j].i_limit_a=I_LIMIT;
				arm[i][j].offset_position_a=OFFSET;	
				arm[i][j].position_limit_max_a=POS_MAX;
				arm[i][j].position_limit_min_a=POS_MIN;
				arm[i][j].p_gain_a=P_GAIN;
				arm[i][j].set_target_position_a=SET_POS;
				arm[i][j].speed_limit_a=SPEED_LIMIT;
				arm[i][j].target_position_a=TARGET_POS;
			}
		}

		sync=0;
		serial_servo_number_combox.SetCurSel(0);
		DC_servo_number_combox.SetCurSel(0);
		serial_port_number.SetCurSel(0);
		baud_rate_compo_box.SetCurSel(0);
		First = false;
	}
}

void Citigo11View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Citigo11View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Citigo11View 診断

#ifdef _DEBUG
void Citigo11View::AssertValid() const
{
	CFormView::AssertValid();
}

void Citigo11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Citigo11Doc* Citigo11View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Citigo11Doc)));
	return (Citigo11Doc*)m_pDocument;
}
#endif //_DEBUG


// Citigo11View メッセージ ハンドラー


void Citigo11View::OnBnClickedRadio1()
{
	//シリアルコネクト
	CButton* pBtn1 = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* pBtn2 = (CButton*)GetDlgItem(IDC_RADIO2);
	CString temp;
	temp.Format("%d",comport+1);
	if(com.CommPortOpen("COM"+temp,baud_rate,ONESTOPBIT,NOPARITY,8)){
		AfxMessageBox("Opened");
		pBtn1->SetCheck(1);
		pBtn2->SetCheck(0);
	}else{
		AfxMessageBox("Can not Open  COM"+temp);
		pBtn1->SetCheck(0);
		pBtn2->SetCheck(1);
	}

	UpdateData(TRUE);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void Citigo11View::OnBnClickedRadio2()
{
	//シリアルディスコネクト
	CButton* pBtn1 = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* pBtn2 = (CButton*)GetDlgItem(IDC_RADIO2);
	if(com.CommPortClose()){
		AfxMessageBox("Closed");		
		pBtn1->SetCheck(0);
		pBtn2->SetCheck(1);
	}else{
		AfxMessageBox("Can not Close");	
		pBtn1->SetCheck(1);
		pBtn2->SetCheck(0);
	}
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void Citigo11View::OnBnClickedButton1()
{
	//ホームホジション
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	UpdateData(TRUE);
	if(button_connect==0){
		homeposition_dialog.ShowWindow(SW_SHOW);
	}
}


void Citigo11View::OnBnClickedButton2()
{
	//モーション
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	UpdateData(TRUE);
	if(button_connect==0){
		motion_dialog.ShowWindow(SW_SHOW);
	}
}

void Citigo11View::OnCbnSelchangeCombo2()
{
	//シリアルサーボの個数
	serial_servo_number = serial_servo_number_combox.GetCurSel();
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void Citigo11View::OnCbnSelchangeCombo3()
{
	//DCサーボの個数
	DC_servo_number = DC_servo_number_combox.GetCurSel();
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void Citigo11View::OnCbnSelchangeCombo1()
{
	//COMポート選択
	comport = serial_port_number.GetCurSel();
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void Citigo11View::OnBnClickedButton3()
{
	//ファイル出力
	CString temp;
	CString temp2;
	CString temp3;
	temp2.Format("%d",file_output_time);
	file_name_edit_box.GetWindowTextA(temp);
	ofstream ofs( temp+temp2+".txt");

	if(!ofs){
		AfxMessageBox("cannot open");
	}else{
//		arm[servo_name_number][motion_number].
		ofs << "// 初期化+宣言" <<endl;
		for(int i=0; i<serial_servo_number;i++){
			ofs<< "servo " << arm[i][0].servo_name_a << "(" << i+1 << "," << arm[i][0].initial_position_a;
			if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}else if(){
			
			}

				arm[i][j].acceleration_limit_a=ACC;
				arm[i][j].dead_band_a=DEAD_BAND;
				arm[i][j].duty_limit_a=DUTY_LIM;
				arm[i][j].d_gain_a=D_GAIN;
				arm[i][j].initial_position_a=INIT_POS;
				arm[i][j].i_gain_a=I_GAIN;
				arm[i][j].i_limit_a=I_LIMIT;
				arm[i][j].offset_position_a=OFFSET;	
				arm[i][j].position_limit_max_a=POS_MAX;
				arm[i][j].position_limit_min_a=POS_MIN;
				arm[i][j].p_gain_a=P_GAIN;
				arm[i][j].set_target_position_a=SET_POS;
				arm[i][j].speed_limit_a=SPEED_LIMIT;


			ofs << << ");" <<endl;
		}
		ofs << endl;
		ofs << endl;
		ofs << "void " << temp << "(";
		for(int i=0;i<serial_servo_number;i++){
			ofs<< "servo " << arm[i][0].servo_name_a;
			if(i!=serial_servo_number-1){
				ofs << ",";
			}
		}
		ofs << ");" << endl;

		ofs << endl;
		ofs << endl;

		for(int j=1; j< max_motion_number ;j++){
//			arm[0][j].delay(delay[j]);
			temp3.Format("%d",j);
			ofs << "// 動作" << temp3 << endl;
			ofs << "delay(" << delay[j] << ");" << endl; 
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].acceleration_limit_a!=arm[i][j].acceleration_limit_a){
//					arm[i][j].acceleration_limit(arm[i][j].acceleration_limit_a);
					ofs << arm[i][0].servo_name_a << ".acceleration_limit(" << arm[i][j].acceleration_limit_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].dead_band_a!=arm[i][j].dead_band_a){
//					arm[i][j].dead_band(arm[i][j].dead_band_a);
					ofs << arm[i][0].servo_name_a << ".dead_band(" << arm[i][j].dead_band_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].duty_limit_a!=arm[i][j].duty_limit_a){
//					arm[i][j].duty_limit(arm[i][j].duty_limit_a);
					ofs << arm[i][0].servo_name_a << ".duty_limit(" << arm[i][j].duty_limit_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].d_gain_a!=arm[i][j].d_gain_a){
//					arm[i][j].d_gain(arm[i][j].d_gain_a);
					ofs << arm[i][0].servo_name_a << ".d_gain(" << arm[i][j].d_gain_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].i_gain_a!=arm[i][j].i_gain_a){
//					arm[i][j].i_gain(arm[i][j].i_gain_a);	
					ofs << arm[i][0].servo_name_a << ".i_gain(" << arm[i][j].i_gain_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].i_limit_a!=arm[i][j].i_limit_a){
//					arm[i][j].i_limit(arm[i][j].i_limit_a);
					ofs << arm[i][0].servo_name_a << ".i_limit(" << arm[i][j].i_limit_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].offset_position_a!=arm[i][j].offset_position_a){
//					arm[i][j].offset_position(arm[i][j].offset_position_a);
					ofs << arm[i][0].servo_name_a << ".offset_position(" << arm[i][j].offset_position_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].position_limit_max_a!=arm[i][j].position_limit_max_a){
//					arm[i][j].position_limit_max(arm[i][j].position_limit_max_a);
					ofs << arm[i][0].servo_name_a << ".position_limit_max(" << arm[i][j].position_limit_max_a << ");" << endl; 
				}	
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].position_limit_min_a!=arm[i][j].position_limit_min_a){
//					arm[i][j].position_limit_min(arm[i][j].position_limit_min_a);
					ofs << arm[i][0].servo_name_a << ".position_limit_min(" << arm[i][j].position_limit_min_a << ");" << endl; 
				}	
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].speed_limit_a!=arm[i][j].speed_limit_a){
//					arm[i][j].speed_limit(arm[i][j].speed_limit_a);
					ofs << arm[i][0].servo_name_a << ".speed_limit(" << arm[i][j].speed_limit_a << ");" << endl; 
				}
			}
			for(int i=0; i< serial_servo_number ;i++){
				if(arm[i][j-1].target_position_a!=arm[i][j].target_position_a){
					arm[i][j].target_position(arm[i][j].target_position_a);
					ofs << arm[i][0].servo_name_a << ".target_position(" << arm[i][j].target_position_a << ");" << endl; 
				}
			}
			ofs << endl;
		}

		file_output_time++;
		AfxMessageBox("success output " + temp+temp2+".txt");
	}

	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


//void Citigo11View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
//	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
//
//	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
//}


void Citigo11View::OnEnChangeEdit1()
{
	//ファイル名
	file_output_time=0;
	// TODO:  これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CFormView::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO:  ここにコントロール通知ハンドラー コードを追加してください。
}


void Citigo11View::OnCbnSelchangeCombo4()
{
	switch(baud_rate_compo_box.GetCurSel()){
		case 0:	baud_rate=9600;		break;
		case 1:	baud_rate=14400;	break;
		case 2:	baud_rate=19200;	break;
		case 3:	baud_rate=28800;	break;
		case 4:	baud_rate=38400;	break;
		case 5:	baud_rate=57600;	break;
		case 6:	baud_rate=115200;	break;
	}

	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}
