// C_Motion_dialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "itigo1.1.h"
#include "C_Motion_dialog.h"
#include "afxdialogex.h"
#include "global.h"


// C_Motion_dialog �_�C�A���O

IMPLEMENT_DYNAMIC(C_Motion_dialog, CDialogEx)

C_Motion_dialog::C_Motion_dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Motion_dialog::IDD, pParent)
{

}

C_Motion_dialog::~C_Motion_dialog()
{
}

void C_Motion_dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, motion_servo_number_combox);
	DDX_Control(pDX, IDC_SCROLLBAR1, p_gain_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR2, i_gain_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR3, d_gain_scroll_bar);
	DDX_Control(pDX, IDC_EDIT3, p_gain_edit_box);
	DDX_Control(pDX, IDC_EDIT4, i_gain_edit_box);
	DDX_Control(pDX, IDC_EDIT6, d_gain_edit_box);
	DDX_Control(pDX, IDC_SCROLLBAR4, accel_scroll_bar);
	DDX_Control(pDX, IDC_EDIT5, accel_edit_box);
	DDX_Control(pDX, IDC_SCROLLBAR5, target_position_scroll_bar);
	DDX_Control(pDX, IDC_EDIT7, target_position_edit_box);
	DDX_Control(pDX, IDC_SCROLLBAR8, speed_limit_scroll_bar);
	DDX_Control(pDX, IDC_EDIT9, speed_limit_edit_box);
	DDX_Control(pDX, IDC_LIST2, motion_list);
	DDX_Control(pDX, IDC_SCROLLBAR9, delay_scroll_bar);
	DDX_Control(pDX, IDC_EDIT11, delay_edit_box);
	DDX_Control(pDX, IDC_CHECK1, sync_check_box);
}


BEGIN_MESSAGE_MAP(C_Motion_dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &C_Motion_dialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C_Motion_dialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C_Motion_dialog::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &C_Motion_dialog::OnCbnSelchangeCombo1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON4, &C_Motion_dialog::OnBnClickedButton4)
	ON_LBN_SELCHANGE(IDC_LIST2, &C_Motion_dialog::OnLbnSelchangeList2)
	ON_EN_CHANGE(IDC_EDIT1, &C_Motion_dialog::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT7, &C_Motion_dialog::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT3, &C_Motion_dialog::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &C_Motion_dialog::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT6, &C_Motion_dialog::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT5, &C_Motion_dialog::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT9, &C_Motion_dialog::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT11, &C_Motion_dialog::OnEnChangeEdit11)
	ON_BN_CLICKED(IDC_CHECK1, &C_Motion_dialog::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON5, &C_Motion_dialog::OnBnClickedButton5)
END_MESSAGE_MAP()


// C_Motion_dialog ���b�Z�[�W �n���h���[


BOOL C_Motion_dialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	static bool First = true;
	if(First == true){
		target_position_scroll_bar.SetScrollRange(0,3600);
		p_gain_scroll_bar.SetScrollRange(0,255);
		i_gain_scroll_bar.SetScrollRange(0,255);
		d_gain_scroll_bar.SetScrollRange(0,255);
		accel_scroll_bar.SetScrollRange(31,6018);
		speed_limit_scroll_bar.SetScrollRange(31,6018);
		delay_scroll_bar.SetScrollRange(0,1000);
		detail_dialog.Create(IDD_DETAIL,this);
		First=false;
	}
	// TODO:  �����ɏ�������ǉ����Ă�������

	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


void C_Motion_dialog::OnBnClickedButton1()
{
	//�ڍ׃{�^��
	detail_dialog.ShowWindow(SW_SHOW);
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Motion_dialog::OnBnClickedButton2()
{
	//�ǂݎ��{�^��
	CString temp;
	static bool First = true;
	if(First == true){
		for(int i=0;i<(DC_servo_number+serial_servo_number);i++){
			motion_servo_number_combox.InsertString(-1,arm[i][0].servo_name_a);
		}
		First = false;
		motion_list.InsertString(-1,"motion_number.1");
		for(int j=1; j<30 ;j++){
			for(int i=0; i< serial_servo_number ;i++){
				arm[i][j].acceleration_limit_a = arm[i][0].acceleration_limit_a;
				arm[i][j].dead_band_a = arm[i][0].dead_band_a;
				arm[i][j].duty_limit_a = arm[i][0].duty_limit_a;
				arm[i][j].d_gain_a = arm[i][0].d_gain_a;
				arm[i][j].i_gain_a = arm[i][0].i_gain_a;
				arm[i][j].i_limit_a = arm[i][0].i_limit_a;
				arm[i][j].offset_position_a = arm[i][0].offset_position_a;
				arm[i][j].position_limit_max_a = arm[i][0].position_limit_max_a;
				arm[i][j].position_limit_min_a = arm[i][0].position_limit_min_a;
				arm[i][j].speed_limit_a = arm[i][0].speed_limit_a;
				arm[i][j].target_position_a = arm[i][0].target_position_a;
			}
		}
	}
	CStatic* text=(CStatic*)GetDlgItem(IDC_STATIC_A);
	text ->SetWindowTextA("motion_number.1");
	motion_number=1;
	motion_servo_number_combox.SetCurSel(0);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].target_position_a);
	temp.Format("%d",arm[servo_name_number][motion_number].target_position_a);
	target_position_edit_box.SetWindowTextA(temp);

	p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].p_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].p_gain_a);
	p_gain_edit_box.SetWindowTextA(temp);

	i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].i_gain_a);
	i_gain_edit_box.SetWindowTextA(temp);

	d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].d_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].d_gain_a);
	d_gain_edit_box.SetWindowTextA(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].acceleration_limit_a);
	accel_edit_box.SetWindowTextA(temp);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].target_position_a);
	temp.Format("%d",arm[servo_name_number][motion_number].target_position_a);
	target_position_edit_box.SetWindowText(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].acceleration_limit_a);
	accel_edit_box.SetWindowText(temp);

	speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].speed_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
	speed_limit_edit_box.SetWindowText(temp);

	delay_scroll_bar.SetScrollPos(delay[0]);
	temp.Format("%d",delay[0]);
	delay_edit_box.SetWindowText(temp);

	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Motion_dialog::OnBnClickedButton3()
{
	//���[�V�������s

	for(int i=0; i< serial_servo_number ;i++){
		arm[i][motion_number].acceleration_limit(arm[i][0].acceleration_limit_a);
		arm[i][0].dead_band(arm[i][0].dead_band_a);
		arm[i][0].duty_limit(arm[i][0].duty_limit_a);
		arm[i][0].d_gain(arm[i][0].d_gain_a);
		arm[i][0].i_gain(arm[i][0].i_gain_a);
		arm[i][0].i_limit(arm[i][0].i_limit_a);
		arm[i][0].offset_position(arm[i][0].offset_position_a);
		arm[i][0].position_limit_max(arm[i][0].position_limit_max_a);
		arm[i][0].position_limit_min(arm[i][0].position_limit_min_a);
		arm[i][0].p_gain(arm[i][0].p_gain_a);
		arm[i][0].speed_limit(arm[i][0].speed_limit_a);
		arm[i][0].target_position(arm[i][0].target_position_a);
	}

	for(int j=1; j< max_motion_number ;j++){
		arm[0][j].delay(delay[j]);
		for(int i=0; i< serial_servo_number ;i++){
			if(arm[i][j-1].acceleration_limit_a!=arm[i][j].acceleration_limit_a){
				arm[i][j].acceleration_limit(arm[i][j].acceleration_limit_a);
			}
			if(arm[i][j-1].dead_band_a!=arm[i][j].dead_band_a){
				arm[i][j].dead_band(arm[i][j].dead_band_a);
			}
			if(arm[i][j-1].duty_limit_a!=arm[i][j].duty_limit_a){
				arm[i][j].duty_limit(arm[i][j].duty_limit_a);
			}
			if(arm[i][j-1].d_gain_a!=arm[i][j].d_gain_a){
				arm[i][j].d_gain(arm[i][j].d_gain_a);
			}
			if(arm[i][j-1].i_gain_a!=arm[i][j].i_gain_a){
				arm[i][j].i_gain(arm[i][j].i_gain_a);
			}
			if(arm[i][j-1].i_limit_a!=arm[i][j].i_limit_a){
				arm[i][j].i_limit(arm[i][j].i_limit_a);
			}
			if(arm[i][j-1].offset_position_a!=arm[i][j].offset_position_a){
				arm[i][j].offset_position(arm[i][j].offset_position_a);
			}
			if(arm[i][j-1].position_limit_max_a!=arm[i][j].position_limit_max_a){
				arm[i][j].position_limit_max(arm[i][j].position_limit_max_a);
			}
			if(arm[i][j-1].position_limit_min_a!=arm[i][j].position_limit_min_a){
				arm[i][j].position_limit_min(arm[i][j].position_limit_min_a);
			}
			if(arm[i][j-1].speed_limit_a!=arm[i][j].speed_limit_a){
				arm[i][j].speed_limit(arm[i][j].speed_limit_a);
			}
			if(arm[i][j-1].target_position_a!=arm[i][j].target_position_a){
				arm[i][j].target_position(arm[i][j].target_position_a);
			}
		}
	}
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Motion_dialog::OnCbnSelchangeCombo1()
{
	//�T�[�{�I��
	CString temp;
	servo_name_number = motion_servo_number_combox.GetCurSel();
	p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].p_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].p_gain_a);
	p_gain_edit_box.SetWindowText(temp);

	i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].i_gain_a);
	i_gain_edit_box.SetWindowText(temp);

	d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].d_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].d_gain_a);
	d_gain_edit_box.SetWindowText(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].acceleration_limit_a);
	accel_edit_box.SetWindowText(temp);

	speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].speed_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
	speed_limit_edit_box.SetWindowText(temp);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].target_position_a);
	temp.Format("%d",arm[servo_name_number][motion_number].target_position_a);
	target_position_edit_box.SetWindowText(temp);

	delay_scroll_bar.SetScrollPos(delay[motion_number]);
	temp.Format("%d",delay[motion_number]);
	delay_edit_box.SetWindowText(temp);


	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Motion_dialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	CString temp;
	if(pScrollBar == &p_gain_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].p_gain_a= p_gain_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].p_gain_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].p_gain_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].p_gain_a -= 10;
				if(arm[servo_name_number][motion_number].p_gain_a<0){
					arm[servo_name_number][motion_number].p_gain_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].p_gain_a += 10;
				if(arm[servo_name_number][motion_number].p_gain_a>255){
					arm[servo_name_number][motion_number].p_gain_a=255;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].p_gain_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].p_gain_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].p_gain_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].p_gain_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].p_gain_a);
		temp.Format("%d",arm[servo_name_number][motion_number].p_gain_a);
		p_gain_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].p_gain();
		}
	}


	if(pScrollBar == &i_gain_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].i_gain_a= i_gain_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].i_gain_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].i_gain_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_gain_a -= 10;
				if(arm[servo_name_number][motion_number].i_gain_a<0){
					arm[servo_name_number][motion_number].i_gain_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_gain_a += 10;
				if(arm[servo_name_number][motion_number].i_gain_a>255){
					arm[servo_name_number][motion_number].i_gain_a=255;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_gain_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_gain_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_gain_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_gain_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_gain_a);
		temp.Format("%d",arm[servo_name_number][motion_number].i_gain_a);
		i_gain_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].i_gain(arm[servo_name_number][motion_number].p_gain_a);
		}
	}


	if(pScrollBar == &d_gain_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].d_gain_a= d_gain_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].d_gain_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].d_gain_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].d_gain_a -= 10;
				if(arm[servo_name_number][motion_number].d_gain_a<0){
					arm[servo_name_number][motion_number].d_gain_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].d_gain_a += 10;
				if(arm[servo_name_number][motion_number].d_gain_a>255){
					arm[servo_name_number][motion_number].d_gain_a=255;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].d_gain_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].d_gain_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].d_gain_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].d_gain_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].d_gain_a);
		temp.Format("%d",arm[servo_name_number][motion_number].d_gain_a);
		d_gain_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].d_gain(arm[servo_name_number][motion_number].d_gain_a);
		}

	}

	if(pScrollBar == &accel_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].acceleration_limit_a= accel_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].acceleration_limit_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].acceleration_limit_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].acceleration_limit_a -= 10;
				if(arm[servo_name_number][motion_number].acceleration_limit_a<31){
					arm[servo_name_number][motion_number].acceleration_limit_a=31;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].acceleration_limit_a += 10;
				if(arm[servo_name_number][motion_number].acceleration_limit_a>6018){
					arm[servo_name_number][motion_number].acceleration_limit_a=6018;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].acceleration_limit_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].acceleration_limit_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].acceleration_limit_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].acceleration_limit_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		if(arm[servo_name_number][motion_number].speed_limit_a>arm[servo_name_number][motion_number].acceleration_limit_a){
			arm[servo_name_number][motion_number].speed_limit_a=arm[servo_name_number][motion_number].acceleration_limit_a;
			speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].speed_limit_a);
			temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
			speed_limit_edit_box.SetWindowText(temp);
			if(sync==1){	
				arm[servo_name_number][motion_number].speed_limit(arm[servo_name_number][motion_number].speed_limit_a);
			}
		}

		accel_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].acceleration_limit_a);
		temp.Format("%d",arm[servo_name_number][motion_number].acceleration_limit_a);
		accel_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].acceleration_limit(arm[servo_name_number][motion_number].acceleration_limit_a);
		}
	}

	if(pScrollBar == &target_position_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].target_position_a= target_position_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].target_position_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].target_position_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].target_position_a -= 10;
				if(arm[servo_name_number][motion_number].target_position_a<0){
					arm[servo_name_number][motion_number].target_position_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].target_position_a += 10;
				if(arm[servo_name_number][motion_number].target_position_a>3600){
					arm[servo_name_number][motion_number].target_position_a=3600;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].target_position_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].target_position_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].target_position_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].target_position_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		target_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].target_position_a);
		temp.Format("%d",arm[servo_name_number][motion_number].target_position_a);
		target_position_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].target_position(arm[servo_name_number][motion_number].target_position_a);
		}
	}

	if(pScrollBar == &speed_limit_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].speed_limit_a= speed_limit_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].speed_limit_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].speed_limit_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].speed_limit_a -= 10;
				if(arm[servo_name_number][motion_number].speed_limit_a<31){
					arm[servo_name_number][motion_number].speed_limit_a = 31;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].speed_limit_a += 10;
				if(arm[servo_name_number][motion_number].speed_limit_a>arm[servo_name_number][motion_number].acceleration_limit_a){
					arm[servo_name_number][motion_number].speed_limit_a = arm[servo_name_number][motion_number].acceleration_limit_a;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].speed_limit_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].speed_limit_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].speed_limit_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].speed_limit_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].speed_limit_a);
		temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
		speed_limit_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].speed_limit(arm[servo_name_number][motion_number].speed_limit_a);
		}
	}


	if(pScrollBar == &delay_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		delay[motion_number]= delay_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				delay[motion_number] = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				delay[motion_number] = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				delay[motion_number] -= 10;
				if(delay[motion_number]<0){
					delay[motion_number]=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				delay[motion_number] += 10;
				if(delay[motion_number]>1000){
					delay[motion_number]=1000;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				delay[motion_number] -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				delay[motion_number] += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				delay[motion_number] = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				delay[motion_number] = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		delay_scroll_bar.SetScrollPos(delay[motion_number]);
		temp.Format("%d",delay[motion_number]);
		delay_edit_box.SetWindowText(temp);
	}


	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void C_Motion_dialog::OnBnClickedButton4()
{
	//��
	CStatic* text=(CStatic*)GetDlgItem(IDC_STATIC_A);
	CString temp;
	motion_number++;
	if(motion_number>=max_motion_number){
		max_motion_number = motion_number+1;
	}
	temp.Format("%d",motion_number);
	if(motion_list.GetCount()<motion_number){
		motion_list.InsertString(-1,"motion_number."+ temp);
	}
	text ->SetWindowTextA("motion_number"+temp);
	servo_name_number = motion_servo_number_combox.GetCurSel();

	p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].p_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].p_gain_a);
	p_gain_edit_box.SetWindowText(temp);

	i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].i_gain_a);
	i_gain_edit_box.SetWindowText(temp);

	d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].d_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].d_gain_a);
	d_gain_edit_box.SetWindowText(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].acceleration_limit_a);
	accel_edit_box.SetWindowText(temp);

	speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].speed_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
	speed_limit_edit_box.SetWindowText(temp);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].target_position_a);
	temp.Format("%d",arm[servo_name_number][motion_number].target_position_a);
	target_position_edit_box.SetWindowText(temp);

	delay_scroll_bar.SetScrollPos(delay[motion_number]);
	temp.Format("%d",delay[motion_number]);
	delay_edit_box.SetWindowText(temp);

	if(sync==1){	
		arm[servo_name_number][motion_number].target_position(arm[servo_name_number][motion_number].target_position_a);
	}


	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Motion_dialog::OnLbnSelchangeList2()
{
	//���X�g
	CString temp;
	CStatic* text=(CStatic*)GetDlgItem(IDC_STATIC_A);
	motion_number = motion_list.GetCurSel()+1;
	temp.Format("%d",motion_number);
	text ->SetWindowTextA("motion_number"+temp);

	servo_name_number = motion_servo_number_combox.GetCurSel();
	p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].p_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].p_gain_a);
	p_gain_edit_box.SetWindowText(temp);

	i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].i_gain_a);
	i_gain_edit_box.SetWindowText(temp);

	d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].d_gain_a);
	temp.Format("%d",arm[servo_name_number][motion_number].d_gain_a);
	d_gain_edit_box.SetWindowText(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].acceleration_limit_a);
	accel_edit_box.SetWindowText(temp);

	speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].speed_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
	speed_limit_edit_box.SetWindowText(temp);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].target_position_a);
	temp.Format("%d",arm[servo_name_number][motion_number].target_position_a);
	target_position_edit_box.SetWindowText(temp);

	delay_scroll_bar.SetScrollPos(delay[motion_number]);
	temp.Format("%d",delay[motion_number]);
	delay_edit_box.SetWindowText(temp);

	if(sync==1){	
		arm[servo_name_number][motion_number].target_position(arm[servo_name_number][motion_number].target_position_a);
	}

	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
//	AfxMessageBox(motion_number);
}


void C_Motion_dialog::OnEnChangeEdit1()
{
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit7()
{	
	//targetposition edit box
	CString temp;
	target_position_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].target_position_a=atoi(temp);
	target_position_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].target_position(arm[servo_name_number][motion_number].target_position_a);
	}

	
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit3()
{
	//p_gain_edit_box
	CString temp;
	p_gain_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].p_gain_a=atoi(temp);
	p_gain_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].p_gain(arm[servo_name_number][motion_number].p_gain_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit4()
{
	//i_gain
	CString temp;
	i_gain_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].i_gain_a=atoi(temp);
	i_gain_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].i_gain(arm[servo_name_number][motion_number].i_gain_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit6()
{
	//d_gain
	CString temp;
	d_gain_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].d_gain_a=atoi(temp);
	d_gain_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].d_gain(arm[servo_name_number][motion_number].d_gain_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit5()
{
	//accel
	CString temp;
	accel_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].acceleration_limit_a=atoi(temp);
	accel_scroll_bar.SetScrollPos(atoi(temp));
	if(arm[servo_name_number][motion_number].speed_limit_a>arm[servo_name_number][motion_number].acceleration_limit_a){
		arm[servo_name_number][motion_number].speed_limit_a=arm[servo_name_number][motion_number].acceleration_limit_a;
		temp.Format("%d",arm[servo_name_number][motion_number].speed_limit_a);
		speed_limit_edit_box.SetWindowTextA(temp);
		speed_limit_edit_box.GetWindowTextA(temp);
	}

	if(sync==1){	
		arm[servo_name_number][motion_number].acceleration_limit(arm[servo_name_number][motion_number].acceleration_limit_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit9()
{
	//speed_limit
	CString temp;
	speed_limit_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].speed_limit_a=atoi(temp);
	if(arm[servo_name_number][motion_number].speed_limit_a>arm[servo_name_number][motion_number].acceleration_limit_a){
		arm[servo_name_number][motion_number].speed_limit_a=arm[servo_name_number][motion_number].acceleration_limit_a;
		speed_limit_edit_box.SetWindowTextA(temp);
	}
	speed_limit_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].speed_limit(arm[servo_name_number][motion_number].speed_limit_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnEnChangeEdit11()
{
	//delay
	CString temp;
	delay_edit_box.GetWindowTextA(temp);
	delay[motion_number]=atoi(temp);
	delay_scroll_bar.SetScrollPos(atoi(temp));


	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Motion_dialog::OnBnClickedCheck1()
{
	//����
	if(sync_check_box.GetCheck() == BST_CHECKED){
		sync=1;
	}else if(sync_check_box.GetCheck() == BST_UNCHECKED){
		sync=0;
	}
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Motion_dialog::OnBnClickedButton5()
{
	//���݂̃��[�V�������s
	for(int i=0; i< serial_servo_number ;i++){
		arm[i][motion_number-1].acceleration_limit(arm[i][motion_number-1].acceleration_limit_a);
		arm[i][motion_number-1].dead_band(arm[i][motion_number-1].dead_band_a);
		arm[i][motion_number-1].duty_limit(arm[i][motion_number-1].duty_limit_a);
		arm[i][motion_number-1].d_gain(arm[i][motion_number-1].d_gain_a);
		arm[i][motion_number-1].i_gain(arm[i][motion_number-1].i_gain_a);
		arm[i][motion_number-1].i_limit(arm[i][motion_number-1].i_limit_a);
		arm[i][motion_number-1].offset_position(arm[i][motion_number-1].offset_position_a);
		arm[i][motion_number-1].position_limit_max(arm[i][motion_number-1].position_limit_max_a);
		arm[i][motion_number-1].position_limit_min(arm[i][motion_number-1].position_limit_min_a);
		arm[i][motion_number-1].speed_limit(arm[i][motion_number-1].speed_limit_a);
		arm[i][motion_number-1].target_position(arm[i][motion_number-1].target_position_a);
	}

	arm[0][motion_number].delay(delay[motion_number]);
	for(int i=0; i< serial_servo_number ;i++){
		if(arm[i][motion_number-1].acceleration_limit_a!=arm[i][motion_number].acceleration_limit_a){
			arm[i][motion_number].acceleration_limit(arm[i][motion_number].acceleration_limit_a);
		}
		if(arm[i][motion_number-1].dead_band_a!=arm[i][motion_number].dead_band_a){
			arm[i][motion_number].dead_band(arm[i][motion_number].dead_band_a);
		}
		if(arm[i][motion_number-1].duty_limit_a!=arm[i][motion_number].duty_limit_a){
			arm[i][motion_number].duty_limit(arm[i][motion_number].duty_limit_a);
		}
		if(arm[i][motion_number-1].d_gain_a!=arm[i][motion_number].d_gain_a){
			arm[i][motion_number].d_gain(arm[i][motion_number].d_gain_a);
		}
		if(arm[i][motion_number-1].i_gain_a!=arm[i][motion_number].i_gain_a){
			arm[i][motion_number].i_gain(arm[i][motion_number].i_gain_a);
		}
		if(arm[i][motion_number-1].i_limit_a!=arm[i][motion_number].i_limit_a){
			arm[i][motion_number].i_limit(arm[i][motion_number].i_limit_a);
		}
		if(arm[i][motion_number-1].offset_position_a!=arm[i][motion_number].offset_position_a){
			arm[i][motion_number].offset_position(arm[i][motion_number].offset_position_a);
		}
		if(arm[i][motion_number-1].position_limit_max_a!=arm[i][motion_number].position_limit_max_a){
			arm[i][motion_number].position_limit_max(arm[i][motion_number].position_limit_max_a);
		}
		if(arm[i][motion_number-1].position_limit_min_a!=arm[i][motion_number].position_limit_min_a){
			arm[i][motion_number].position_limit_min(arm[i][motion_number].position_limit_min_a);
		}
		if(arm[i][motion_number-1].speed_limit_a!=arm[i][motion_number].speed_limit_a){
			arm[i][motion_number].speed_limit(arm[i][motion_number].speed_limit_a);
		}
		if(arm[i][motion_number-1].target_position_a!=arm[i][motion_number].target_position_a){
			arm[i][motion_number].target_position(arm[i][motion_number].target_position_a);
		}
	}
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}
