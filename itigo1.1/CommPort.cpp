//////////////////////////////////////////////////////////////////////////
// Program: Serial port Class
// Programed by Ryu Kato
// Copyright(C)�@2001-2005 Ryu Kato. All rights reserved.
//////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "commport.h"
#define OTHERWISE 5

CCommPort::CCommPort(void)
{
	//���p�\�ȃ|�[�g���C�{�[���[�g�C�X�g�b�v�r�b�g�̐ݒ�
	availablePortName = new LPCTSTR[5];
	availablePortName[0]="COM1";
	availablePortName[1]="COM2";
	availablePortName[2]="COM3";
	availablePortName[3]="COM4";
	availablePortName[4]=NULL;

	availableBaudRate = new unsigned long[8];
	availableBaudRate[0]=115200;
	availableBaudRate[1]=57600;
	availableBaudRate[2]=38400;
	availableBaudRate[3]=28800;
	availableBaudRate[4]=19200;
	availableBaudRate[5]=14400;
	availableBaudRate[6]=9600;
	availableBaudRate[7]=NULL;

	availableParity = new unsigned char[4];
	availableParity[0]=NOPARITY;
	availableParity[1]=EVENPARITY;
	availableParity[2]=ODDPARITY;
	availableParity[3]=OTHERWISE;

	availableStopBits = new unsigned char[4];
	availableStopBits[0]=ONESTOPBIT;
	availableStopBits[1]=ONE5STOPBITS;
	availableStopBits[2]=TWOSTOPBITS;
	availableStopBits[3]=OTHERWISE;

	availableByteSize = new unsigned char[5];
	availableByteSize[0]=5;
	availableByteSize[1]=6;
	availableByteSize[2]=7;
	availableByteSize[3]=8;
	availableByteSize[4]=NULL;
}

CCommPort::~CCommPort(void)
{
	delete [] availablePortName;
	delete [] availableBaudRate;
	delete [] availableStopBits;
	delete [] availableParity;
	delete [] availableByteSize;
}

bool CCommPort::CommPortOpen(LPCTSTR nameOfCommPort,unsigned long baudRate,unsigned char stopBits,unsigned char parity,unsigned char byteSize)
{
	isError=true;
	for(int i=0;availablePortName[i]!=NULL ;i++){
		if( lstrcmp(nameOfCommPort,availablePortName[i])==0 ){
			commPort=availablePortName[i];
			isError=false;
		}
	}
	if(isError) return false;

	isError=true;
	for(int i=0;availableBaudRate[i]!=NULL ;i++){
		if( baudRate==availableBaudRate[i] )
			isError=false;
	}
	if(isError) return false;

	isError=true;
	for(int i=0;availableStopBits[i]!=OTHERWISE ;i++){
		if( stopBits==availableStopBits[i] )
			isError=false;
	}
	if(isError) return false;

	isError=true;
	for(int i=0;availableParity[i]!=OTHERWISE ;i++){
		if( parity==availableParity[i] )
			isError=false;
	}
	if(isError) return false;
	
	isError=true;
	for(int i=0;availableByteSize[i]!=NULL;i++){
		if( byteSize==availableByteSize[i] )
			isError=false;
	}
	if(isError) return false;
    
	// �|�[�g�I�[�v��
	commHandle = CreateFile(
		commPort,						//CommPort�� 
		GENERIC_READ | GENERIC_WRITE,	//�ǂݎ��E�������A�N�Z�X
		0,								//�|�[�g���L�s��
		NULL,							//�n���h�����q�v���Z�X�֌p�����Ȃ�
		OPEN_EXISTING,					//�t�@�C�������݂���
		FILE_ATTRIBUTE_NORMAL,			//���Ԃ̂����鏈���ɑ΂��� ERROR_IO_PENDING ��Ԃ�
		NULL							//NULL
	);
	if(commHandle == INVALID_HANDLE_VALUE) return false;

	if( !SetCommMask(commHandle, 0) || !SetupComm(commHandle, 4096, 4096) ) {
		CommPortClose();
		return false;
	}

	if( !GetCommState(commHandle, &dcb) ){
		CommPortClose();
		return false;
	}

	//DCB�ݒ�
	dcb.DCBlength = sizeof(DCB);
	dcb.fBinary = TRUE;
	dcb.BaudRate	= baudRate;
	dcb.ByteSize	= byteSize;
	dcb.Parity		= parity;
	dcb.StopBits	= stopBits;
	dcb.fParity = (parity == NOPARITY) ? FALSE : TRUE;
	dcb.fRtsControl = RTS_CONTROL_DISABLE;
	dcb.fDtrControl = DTR_CONTROL_DISABLE;
	dcb.fOutxCtsFlow = FALSE;
	dcb.fTXContinueOnXoff = TRUE;
	dcb.fInX = dcb.fOutX = FALSE;
	dcb.XonChar = 0x11;
	dcb.XoffChar = 0x13;
	dcb.XonLim = 100;
	dcb.XoffLim = 1500;

	if( !SetCommState(commHandle, &dcb) ){
		CommPortClose();
		return false;
	}

	timeouts.ReadIntervalTimeout		= 100;	// ���̃L�����N�^����M����܂ł̃^�C���A�E�g //MAXDWORD
	timeouts.ReadTotalTimeoutMultiplier	= 100;	// Read : 1�o�C�g�ɑ΂���^�C���A�E�g
	timeouts.ReadTotalTimeoutConstant	= 500;	// Read : 0�o�C�g���̃^�C���A�E�g
	timeouts.WriteTotalTimeoutMultiplier= 10;	// Write : 1�o�C�g�ɑ΂���^�C���A�E�g
	timeouts.WriteTotalTimeoutConstant	= 500;	// Write : 0�o�C�g���̃^�C���A�E�g

	if(!SetCommTimeouts(commHandle, &timeouts)){
		CommPortClose();
		return false;
	}
	return true;
}

bool CCommPort::CommPortClose(void)
{
	CloseHandle(commHandle);
	return true;
}

BOOL CCommPort::CommWriteChar(int nChar)
{
	DWORD dwWritten;
	return WriteFile(commHandle, &nChar, 1, &dwWritten, NULL);
}

BOOL CCommPort::CommReadChar(char* pnChar)
{
	DWORD dwRead;

	if(!ReadFile(commHandle,pnChar, 1, &dwRead, NULL))
		return FALSE;
	
	if(dwRead == 0)
		return FALSE;
	
	return TRUE;
}

BOOL CCommPort::CommReadStr(char* pnChar)
{
	DWORD dwRead;

	if(!ReadFile(commHandle,pnChar,8, &dwRead, NULL))
		return FALSE;
	
	if(dwRead == 0)
		return FALSE;
	
	return TRUE;
}

