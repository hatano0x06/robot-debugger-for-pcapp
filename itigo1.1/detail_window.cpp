// detail_window.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "itigo1.1.h"
#include "detail_window.h"
#include "afxdialogex.h"
#include "global.h"


// detail_window �_�C�A���O

IMPLEMENT_DYNAMIC(detail_window, CDialogEx)

detail_window::detail_window(CWnd* pParent /*=NULL*/)
	: CDialogEx(detail_window::IDD, pParent)
{

}

detail_window::~detail_window()
{
}

void detail_window::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR7, offset_position_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR1, duty_limit_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR2, dead_band_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR3, position_limit_max_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR4, position_limit_min_scroll_bar);
	DDX_Control(pDX, IDC_SCROLLBAR6, i_limit_scroll_bar);
	DDX_Control(pDX, IDC_EDIT8, offset_position_edit_box);
	DDX_Control(pDX, IDC_EDIT1, duty_limit_edit_box);
	DDX_Control(pDX, IDC_EDIT2, dead_band_edit_box);
	DDX_Control(pDX, IDC_EDIT4, position_limit_max_edit_box);
	DDX_Control(pDX, IDC_EDIT3, position_limit_min_edit_box);
	DDX_Control(pDX, IDC_EDIT6, i_limit_edit_box);
}


BEGIN_MESSAGE_MAP(detail_window, CDialogEx)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &detail_window::OnNMThemeChangedScrollbar2)
	ON_BN_CLICKED(IDC_BUTTON1, &detail_window::OnBnClickedButton1)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT8, &detail_window::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT1, &detail_window::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &detail_window::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &detail_window::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &detail_window::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT6, &detail_window::OnEnChangeEdit6)
END_MESSAGE_MAP()


// detail_window ���b�Z�[�W �n���h���[


BOOL detail_window::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	static bool First = true;
	if(First == true){

		offset_position_scroll_bar.SetScrollRange(0,2500);
		duty_limit_scroll_bar.SetScrollRange(0,1000);
		dead_band_scroll_bar.SetScrollRange(0,900);
		position_limit_max_scroll_bar.SetScrollRange(0,3600);
		position_limit_min_scroll_bar.SetScrollRange(0,3600);
		i_limit_scroll_bar.SetScrollRange(0,1225);
		First = false;
	}
	// TODO:  �����ɏ�������ǉ����Ă�������

	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


void detail_window::OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// ���̋@�\�� Windows XP ����ȍ~�̃o�[�W������K�v�Ƃ��܂��B
	// �V���{�� _WIN32_WINNT �� >= 0x0501�ɂȂ�Ȃ���΂Ȃ�܂���B
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	*pResult = 0;
}


void detail_window::OnBnClickedButton1()
{
	//�ǂݎ��
	CString temp;
	offset_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].offset_position_a);
	temp.Format("%d",arm[servo_name_number][motion_number].offset_position_a);
	offset_position_edit_box.SetWindowTextA(temp);
	duty_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].duty_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].duty_limit_a);
	duty_limit_edit_box.SetWindowTextA(temp);
	dead_band_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].dead_band_a);
	temp.Format("%d",arm[servo_name_number][motion_number].dead_band_a);
	dead_band_edit_box.SetWindowTextA(temp);
	position_limit_max_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].position_limit_max_a);
	temp.Format("%d",arm[servo_name_number][motion_number].position_limit_max_a);
	position_limit_max_edit_box.SetWindowTextA(temp);
	position_limit_min_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].position_limit_min_a);
	temp.Format("%d",arm[servo_name_number][motion_number].position_limit_min_a);
	position_limit_min_edit_box.SetWindowTextA(temp);
	i_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_limit_a);
	temp.Format("%d",arm[servo_name_number][motion_number].i_limit_a);
	i_limit_edit_box.SetWindowTextA(temp);


	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void detail_window::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	//����
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	CString temp;
	if(pScrollBar == &offset_position_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].offset_position_a= offset_position_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].offset_position_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].offset_position_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].offset_position_a -= 10;
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].offset_position_a += 10;
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].offset_position_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].offset_position_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].offset_position_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].offset_position_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		offset_position_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].offset_position_a);
		temp.Format("%d",arm[servo_name_number][motion_number].offset_position_a);
		offset_position_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].offset_position(arm[servo_name_number][motion_number].offset_position_a);
		}
	}

	if(pScrollBar == &duty_limit_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].duty_limit_a= duty_limit_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].duty_limit_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].duty_limit_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].duty_limit_a -= 10;
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].duty_limit_a += 10;
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].duty_limit_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].duty_limit_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].duty_limit_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].duty_limit_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		duty_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].duty_limit_a);
		temp.Format("%d",arm[servo_name_number][motion_number].duty_limit_a);
		duty_limit_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].duty_limit(arm[servo_name_number][motion_number].duty_limit_a);
		}
	}

	if(pScrollBar == &dead_band_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].dead_band_a= dead_band_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].dead_band_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].dead_band_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].dead_band_a -= 10;
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].dead_band_a += 10;
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].dead_band_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].dead_band_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].dead_band_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].dead_band_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		dead_band_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].dead_band_a);
		temp.Format("%d",arm[servo_name_number][motion_number].dead_band_a);
		dead_band_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].dead_band(arm[servo_name_number][motion_number].dead_band_a);
		}
	}

	if(pScrollBar == &position_limit_max_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].position_limit_max_a= position_limit_max_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].position_limit_max_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].position_limit_max_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_max_a -= 10;
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_max_a += 10;
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_max_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_max_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_max_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_max_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		position_limit_max_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].position_limit_max_a);
		temp.Format("%d",arm[servo_name_number][motion_number].position_limit_max_a);
		position_limit_max_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].position_limit_max(arm[servo_name_number][motion_number].position_limit_max_a);
		}
	}

	if(pScrollBar == &position_limit_min_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].position_limit_min_a= position_limit_min_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].position_limit_min_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].position_limit_min_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_min_a -= 10;
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_min_a += 10;
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_min_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_min_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_min_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].position_limit_min_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		position_limit_min_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].position_limit_min_a);
		temp.Format("%d",arm[servo_name_number][motion_number].position_limit_min_a);
		position_limit_min_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].position_limit_min(arm[servo_name_number][motion_number].position_limit_min_a);
		}
	}

	if(pScrollBar == &i_limit_scroll_bar){	//���삳�ꂽ�R���g���[���̃A�h���X���m�F
		arm[servo_name_number][motion_number].i_limit_a= i_limit_scroll_bar.GetScrollPos();	//GetScrollPos():�w�肳�ꂽ�X�N���[���o�[�̈ʒu���擾����D�߂�l��int�^

		switch(nSBCode){
			case SB_LEFT: //���֍s���؂�����
				arm[servo_name_number][motion_number].i_limit_a = 0;
				break;
			case SB_RIGHT: //�E�֍s���؂�����
				arm[servo_name_number][motion_number].i_limit_a = 1000;
				break;
			case SB_LINELEFT: //�o�[���[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_limit_a -= 10;
				break;
			case SB_LINERIGHT: //�o�[�E�[�̃{�^���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_limit_a += 10;
				break;
			case SB_PAGELEFT: //�܂݂̍����������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_limit_a -= 20;
				break;
			case SB_PAGERIGHT: //�܂݂̉E���������ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_limit_a += 20;
				break;
			case SB_THUMBPOSITION: //�܂݂��h���b�v���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_limit_a = nPos;
				break;
			case SB_THUMBTRACK: //�܂݂��h���b�O���ꂽ�Ƃ�
				arm[servo_name_number][motion_number].i_limit_a = nPos;
				break;
			case SB_ENDSCROLL: //�R���g���[���ւ̕ύX���I�������(��{�C�Ȃ��Ă悢)
				break;
		}
		i_limit_scroll_bar.SetScrollPos(arm[servo_name_number][motion_number].i_limit_a);
		temp.Format("%d",arm[servo_name_number][motion_number].i_limit_a);
		i_limit_edit_box.SetWindowText(temp);
		if(sync==1){	
			arm[servo_name_number][motion_number].i_limit(arm[servo_name_number][motion_number].i_limit_a);
		}
	}

	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void detail_window::OnEnChangeEdit8()
{	
	//offset_position
	CString temp;
	offset_position_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].offset_position_a=atoi(temp);
	offset_position_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].offset_position(arm[servo_name_number][motion_number].offset_position_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void detail_window::OnEnChangeEdit1()
{
	//duty_limit
	CString temp;
	duty_limit_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].duty_limit_a=atoi(temp);
	duty_limit_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].duty_limit(arm[servo_name_number][motion_number].duty_limit_a);
	}

	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void detail_window::OnEnChangeEdit2()
{
	//dead_band
	CString temp;
	dead_band_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].dead_band_a=atoi(temp);
	dead_band_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].dead_band(arm[servo_name_number][motion_number].dead_band_a);
	}


	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void detail_window::OnEnChangeEdit4()
{
	//position_limit_max
	CString temp;
	position_limit_max_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].position_limit_max_a=atoi(temp);
	position_limit_max_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].position_limit_max(arm[servo_name_number][motion_number].position_limit_max_a);
	}
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void detail_window::OnEnChangeEdit3()
{
	//position_limit_min
	CString temp;
	position_limit_min_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].position_limit_min_a=atoi(temp);
	position_limit_min_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].position_limit_min(arm[servo_name_number][motion_number].position_limit_min_a);
	}
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void detail_window::OnEnChangeEdit6()
{
	//i_limit
	CString temp;
	i_limit_edit_box.GetWindowTextA(temp);
	arm[servo_name_number][motion_number].i_limit_a=atoi(temp);
	i_limit_scroll_bar.SetScrollPos(atoi(temp));
	if(sync==1){	
		arm[servo_name_number][motion_number].i_limit(arm[servo_name_number][motion_number].i_limit_a);
	}	
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}
