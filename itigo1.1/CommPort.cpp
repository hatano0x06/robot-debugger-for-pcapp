//////////////////////////////////////////////////////////////////////////
// Program: Serial port Class
// Programed by Ryu Kato
// Copyright(C)　2001-2005 Ryu Kato. All rights reserved.
//////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "commport.h"
#define OTHERWISE 5

CCommPort::CCommPort(void)
{
	//利用可能なポート名，ボーレート，ストップビットの設定
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
    
	// ポートオープン
	commHandle = CreateFile(
		commPort,						//CommPort名 
		GENERIC_READ | GENERIC_WRITE,	//読み取り・書き取りアクセス
		0,								//ポート共有不可
		NULL,							//ハンドルを子プロセスへ継承しない
		OPEN_EXISTING,					//ファイルが存在する
		FILE_ATTRIBUTE_NORMAL,			//時間のかかる処理に対して ERROR_IO_PENDING を返す
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

	//DCB設定
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

	timeouts.ReadIntervalTimeout		= 100;	// 次のキャラクタを受信するまでのタイムアウト //MAXDWORD
	timeouts.ReadTotalTimeoutMultiplier	= 100;	// Read : 1バイトに対するタイムアウト
	timeouts.ReadTotalTimeoutConstant	= 500;	// Read : 0バイト時のタイムアウト
	timeouts.WriteTotalTimeoutMultiplier= 10;	// Write : 1バイトに対するタイムアウト
	timeouts.WriteTotalTimeoutConstant	= 500;	// Write : 0バイト時のタイムアウト

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

