// C_Homeposition_Dialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "itigo1.1.h"
#include "C_Homeposition_Dialog.h"
#include "afxdialogex.h"

#define GLOBAL_INSTANCE

#include "global.h"


// C_Homeposition_Dialog �_�C�A���O

IMPLEMENT_DYNAMIC(C_Homeposition_Dialog, CDialogEx)

C_Homeposition_Dialog::C_Homeposition_Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Homeposition_Dialog::IDD, pParent)
{

}

C_Homeposition_Dialog::~C_Homeposition_Dialog()
{
}

void C_Homeposition_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, servo_number_combox);
	DDX_Control(pDX, IDC_EDIT1, servo_name_box);
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
	DDX_Control(pDX, IDC_CHECK1, sync_check_box);
}


BEGIN_MESSAGE_MAP(C_Homeposition_Dialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &C_Homeposition_Dialog::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &C_Homeposition_Dialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C_Homeposition_Dialog::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &C_Homeposition_Dialog::OnEnChangeEdit1)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &C_Homeposition_Dialog::OnNMThemeChangedScrollbar1)
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &C_Homeposition_Dialog::OnNMThemeChangedScrollbar2)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR5, &C_Homeposition_Dialog::OnNMThemeChangedScrollbar5)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR8, &C_Homeposition_Dialog::OnNMThemeChangedScrollbar8)
	ON_EN_CHANGE(IDC_EDIT7, &C_Homeposition_Dialog::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT3, &C_Homeposition_Dialog::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &C_Homeposition_Dialog::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT6, &C_Homeposition_Dialog::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT5, &C_Homeposition_Dialog::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT9, &C_Homeposition_Dialog::OnEnChangeEdit9)
	ON_BN_CLICKED(IDC_CHECK1, &C_Homeposition_Dialog::OnBnClickedCheck1)
END_MESSAGE_MAP()


// C_Homeposition_Dialog ���b�Z�[�W �n���h���[


BOOL C_Homeposition_Dialog::OnInitDialog()
{
	CString temp;
	CDialogEx::OnInitDialog();
	static bool First = true;
	if(First == true){

		target_position_scroll_bar.SetScrollRange(0,3600);
		p_gain_scroll_bar.SetScrollRange(0,255);
		i_gain_scroll_bar.SetScrollRange(0,255);
		d_gain_scroll_bar.SetScrollRange(0,255);
		accel_scroll_bar.SetScrollRange(31,6018);
		speed_limit_scroll_bar.SetScrollRange(31,6018);
		detail_dialog.Create(IDD_DETAIL,this);
		First = false;
	}
	// TODO:  �����ɏ�������ǉ����Ă�������

	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


void C_Homeposition_Dialog::OnCbnSelchangeCombo1()
{
	CString temp;
	servo_name_number = servo_number_combox.GetCurSel();
	servo_name_box.SetWindowTextA(arm[servo_name_number][0].servo_name_a);

	p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].p_gain_a);
	temp.Format("%d",arm[servo_name_number][0].p_gain_a);
	p_gain_edit_box.SetWindowText(temp);

	i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].i_gain_a);
	temp.Format("%d",arm[servo_name_number][0].i_gain_a);
	i_gain_edit_box.SetWindowText(temp);

	d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].d_gain_a);
	temp.Format("%d",arm[servo_name_number][0].d_gain_a);
	d_gain_edit_box.SetWindowText(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][0].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][0].acceleration_limit_a);
	accel_edit_box.SetWindowText(temp);

	speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][0].speed_limit_a);
	temp.Format("%d",arm[servo_name_number][0].speed_limit_a);
	speed_limit_edit_box.SetWindowText(temp);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][0].target_position_a);
	temp.Format("%d",arm[servo_name_number][0].target_position_a);
	target_position_edit_box.SetWindowText(temp);

	if(sync==1){	
		arm[servo_name_number][0].target_position(arm[servo_name_number][0].target_position_a);
	}

	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void C_Homeposition_Dialog::OnBnClickedButton1()
{
	//�ڍ�
	detail_dialog.ShowWindow(SW_SHOW);
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}



void C_Homeposition_Dialog::OnBnClickedButton2()
{
	//�ǂݎ��
	CString temp;

	static bool First = true;
	if(First == true){
			for(int i=1;i<(DC_servo_number+serial_servo_number+1);i++){
			temp.Format("%d",i);
			servo_number_combox.InsertString(-1,temp);
		}
		First =false;
	}

	servo_number_combox.SetCurSel(0);
	servo_name_box.SetWindowTextA(arm[servo_name_number][0].servo_name_a);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][0].target_position_a);
	temp.Format("%d",arm[servo_name_number][0].target_position_a);
	target_position_edit_box.SetWindowTextA(temp);

	p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].p_gain_a);
	temp.Format("%d",arm[servo_name_number][0].p_gain_a);
	p_gain_edit_box.SetWindowTextA(temp);

	i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].i_gain_a);
	temp.Format("%d",arm[servo_name_number][0].i_gain_a);
	i_gain_edit_box.SetWindowTextA(temp);

	d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].d_gain_a);
	temp.Format("%d",arm[servo_name_number][0].d_gain_a);
	d_gain_edit_box.SetWindowTextA(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][0].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][0].acceleration_limit_a);
	accel_edit_box.SetWindowTextA(temp);

	target_position_scroll_bar.SetScrollPos(arm[servo_name_number][0].target_position_a);
	temp.Format("%d",arm[servo_name_number][0].target_position_a);
	target_position_edit_box.SetWindowText(temp);

	accel_scroll_bar.SetScrollPos(arm[servo_name_number][0].acceleration_limit_a);
	temp.Format("%d",arm[servo_name_number][0].acceleration_limit_a);
	accel_edit_box.SetWindowText(temp);

	speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][0].speed_limit_a);
	temp.Format("%d",arm[servo_name_number][0].speed_limit_a);
	speed_limit_edit_box.SetWindowText(temp);
}


void C_Homeposition_Dialog::OnEnChangeEdit1()
{
	//�T�[�{���O
	CString temp;

	servo_name_box.GetWindowTextA(temp);
	arm[servo_name_number][0].servo_name_a=temp;

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Homeposition_Dialog::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//p_gain_scroll_bar
	// ���̋@�\�� Windows XP ����ȍ~�̃o�[�W������K�v�Ƃ��܂��B
	// �V���{�� _WIN32_WINNT �� >= 0x0501�ɂȂ�Ȃ���΂Ȃ�܂���B
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	*pResult = 0;
}


void C_Homeposition_Dialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B

	CString temp;
	if(pScrollBar == &p_gain_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][0].p_gain_a= p_gain_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][0].p_gain_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][0].p_gain_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].p_gain_a -= 10;
				if(arm[servo_name_number][0].p_gain_a<0){
					arm[servo_name_number][0].p_gain_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].p_gain_a += 10;
				if(arm[servo_name_number][0].p_gain_a>255){
					arm[servo_name_number][0].p_gain_a=255;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][0].p_gain_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][0].p_gain_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][0].p_gain_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][0].p_gain_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		p_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].p_gain_a);
		temp.Format("%d",arm[servo_name_number][0].p_gain_a);
		p_gain_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][0].p_gain(arm[servo_name_number][0].p_gain_a);
		}
	}


	if(pScrollBar == &i_gain_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][0].i_gain_a= i_gain_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][0].i_gain_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][0].i_gain_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].i_gain_a -= 10;
				if(arm[servo_name_number][0].i_gain_a<0){
					arm[servo_name_number][0].i_gain_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].i_gain_a += 10;
				if(arm[servo_name_number][0].i_gain_a>255){
					arm[servo_name_number][0].i_gain_a=255;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][0].i_gain_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][0].i_gain_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][0].i_gain_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][0].i_gain_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		i_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].i_gain_a);
		temp.Format("%d",arm[servo_name_number][0].i_gain_a);
		i_gain_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][0].i_gain(arm[servo_name_number][0].i_gain_a);
		}
	}


	if(pScrollBar == &d_gain_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][0].d_gain_a= d_gain_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][0].d_gain_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][0].d_gain_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].d_gain_a -= 10;
				if(arm[servo_name_number][0].d_gain_a<0){
					arm[servo_name_number][0].d_gain_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].d_gain_a += 10;
				if(arm[servo_name_number][0].d_gain_a>255){
					arm[servo_name_number][0].d_gain_a=255;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][0].d_gain_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][0].d_gain_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][0].d_gain_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][0].d_gain_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		d_gain_scroll_bar.SetScrollPos(arm[servo_name_number][0].d_gain_a);
		temp.Format("%d",arm[servo_name_number][0].d_gain_a);
		d_gain_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][0].d_gain(arm[servo_name_number][0].d_gain_a);
		}
	}

	if(pScrollBar == &accel_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][0].acceleration_limit_a= accel_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][0].acceleration_limit_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][0].acceleration_limit_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].acceleration_limit_a -= 10;
				if(arm[servo_name_number][0].acceleration_limit_a<31){
					arm[servo_name_number][0].acceleration_limit_a=31;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].acceleration_limit_a += 10;
				if(arm[servo_name_number][0].acceleration_limit_a>6018){
					arm[servo_name_number][0].acceleration_limit_a=6018;
				}

				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][0].acceleration_limit_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][0].acceleration_limit_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][0].acceleration_limit_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][0].acceleration_limit_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		if(arm[servo_name_number][0].speed_limit_a>arm[servo_name_number][0].acceleration_limit_a){
			arm[servo_name_number][0].speed_limit_a=arm[servo_name_number][0].acceleration_limit_a;
			speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][0].speed_limit_a);
			temp.Format("%d",arm[servo_name_number][0].speed_limit_a);
			speed_limit_edit_box.SetWindowText(temp);
			if(sync==1){	
				arm[servo_name_number][0].speed_limit(arm[servo_name_number][0].speed_limit_a);
			}
		}
		accel_scroll_bar.SetScrollPos(arm[servo_name_number][0].acceleration_limit_a);
		temp.Format("%d",arm[servo_name_number][0].acceleration_limit_a);
		accel_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][0].acceleration_limit(arm[servo_name_number][0].acceleration_limit_a);
		}
	}

	if(pScrollBar == &target_position_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][0].target_position_a= target_position_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][0].target_position_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][0].target_position_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].target_position_a -= 10;
				if(arm[servo_name_number][0].target_position_a<0){
					arm[servo_name_number][0].target_position_a=0;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].target_position_a += 10;
				if(arm[servo_name_number][0].target_position_a>3600){
					arm[servo_name_number][0].target_position_a=3600;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][0].target_position_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][0].target_position_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][0].target_position_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][0].target_position_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		target_position_scroll_bar.SetScrollPos(arm[servo_name_number][0].target_position_a);
		temp.Format("%d",arm[servo_name_number][0].target_position_a);
		target_position_edit_box.SetWindowText(temp);
		arm[servo_name_number][0].initial_position_a=arm[servo_name_number][0].target_position_a;
		if(sync==1){	
			arm[servo_name_number][0].target_position(arm[servo_name_number][0].target_position_a);
		}
	}

	if(pScrollBar == &speed_limit_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][0].speed_limit_a= speed_limit_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][0].speed_limit_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][0].speed_limit_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].speed_limit_a -= 10;
				if(arm[servo_name_number][0].speed_limit_a<31){
					arm[servo_name_number][0].speed_limit_a = 31;
				}
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][0].speed_limit_a += 10;
				if(arm[servo_name_number][0].speed_limit_a>arm[servo_name_number][0].acceleration_limit_a){
					arm[servo_name_number][0].speed_limit_a = arm[servo_name_number][0].acceleration_limit_a;
				}
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][0].speed_limit_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][0].speed_limit_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][0].speed_limit_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][0].speed_limit_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		speed_limit_scroll_bar.SetScrollPos(arm[servo_name_number][0].speed_limit_a);
		temp.Format("%d",arm[servo_name_number][0].speed_limit_a);
		speed_limit_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][0].speed_limit(arm[servo_name_number][0].speed_limit_a);
		}
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void C_Homeposition_Dialog::OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// ���̋@�\�� Windows XP ����ȍ~�̃o�[�W������K�v�Ƃ��܂��B
	// �V���{�� _WIN32_WINNT �� >= 0x0501�ɂȂ�Ȃ���΂Ȃ�܂���B
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	*pResult = 0;
}


void C_Homeposition_Dialog::OnNMThemeChangedScrollbar5(NMHDR *pNMHDR, LRESULT *pResult)
{
	// ���̋@�\�� Windows XP ����ȍ~�̃o�[�W������K�v�Ƃ��܂��B
	// �V���{�� _WIN32_WINNT �� >= 0x0501�ɂȂ�Ȃ���΂Ȃ�܂���B
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	*pResult = 0;
}


void C_Homeposition_Dialog::OnNMThemeChangedScrollbar8(NMHDR *pNMHDR, LRESULT *pResult)
{
	// ���̋@�\�� Windows XP ����ȍ~�̃o�[�W������K�v�Ƃ��܂��B
	// �V���{�� _WIN32_WINNT �� >= 0x0501�ɂȂ�Ȃ���΂Ȃ�܂���B
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	*pResult = 0;
}


void C_Homeposition_Dialog::OnEnChangeEdit7()
{
	//target_edit_box
	CString temp;
	target_position_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][0].target_position_a=atoi(temp);
	target_position_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][0].target_position(arm[servo_name_number][0].target_position_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Homeposition_Dialog::OnEnChangeEdit3()
{
	//p_gain
	CString temp;
	p_gain_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][0].p_gain_a=atoi(temp);
	p_gain_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][0].p_gain(arm[servo_name_number][0].p_gain_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Homeposition_Dialog::OnEnChangeEdit4()
{
	//i_gain
	CString temp;
	i_gain_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][0].i_gain_a=atoi(temp);
	i_gain_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][0].i_gain(arm[servo_name_number][0].i_gain_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Homeposition_Dialog::OnEnChangeEdit6()
{
	//d_gain
	CString temp;
	d_gain_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][0].d_gain_a=atoi(temp);
	d_gain_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][0].d_gain(arm[servo_name_number][0].d_gain_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Homeposition_Dialog::OnEnChangeEdit5()
{
	//accel
	CString temp;
	accel_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][0].acceleration_limit_a=atoi(temp);
	accel_scroll_bar.SetScrollPos(atoi(temp));
	if(arm[servo_name_number][0].speed_limit_a>arm[servo_name_number][0].acceleration_limit_a){
		arm[servo_name_number][0].speed_limit_a=arm[servo_name_number][0].acceleration_limit_a;
		speed_limit_edit_box.SetWindowTextA(temp);
	}
	if(sync==1){	
		arm[servo_name_number][0].acceleration_limit(arm[servo_name_number][0].acceleration_limit_a);
	}


	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void C_Homeposition_Dialog::OnEnChangeEdit9()
{
	//speed_limit
	CString temp;
	speed_limit_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][0].speed_limit_a=atoi(temp);
	if(arm[servo_name_number][0].speed_limit_a>arm[servo_name_number][0].acceleration_limit_a){
		arm[servo_name_number][0].speed_limit_a=arm[servo_name_number][0].acceleration_limit_a;
		temp.Format("%d",arm[servo_name_number][0].speed_limit_a);
		speed_limit_edit_box.SetWindowTextA(temp);
		speed_limit_edit_box.GetWindowTextA(temp);
	}
	speed_limit_scroll_bar.SetScrollPos(atoi(temp));

	if(sync==1){	
		arm[servo_name_number][0].speed_limit(arm[servo_name_number][0].speed_limit_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}

void C_Homeposition_Dialog::OnBnClickedCheck1()
{
	//����
	CString temp;
	if(sync_check_box.GetCheck() == BST_CHECKED){
		sync=1;
	}else if(sync_check_box.GetCheck() == BST_UNCHECKED){
		sync=0;
	}
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}
