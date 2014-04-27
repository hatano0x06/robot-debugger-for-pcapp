#pragma once

//////////////////////////////////////////////////////////////////////////
// Program: Serial port Class
// Programed by Ryu Kato
// Copyright(C)Å@2001-2005 Ryu Kato. All rights reserved.
//////////////////////////////////////////////////////////////////////////

class CCommPort
{
public:
	CCommPort(void);
	~CCommPort(void);

	bool CommPortOpen(
		LPCTSTR nameOfCommPort,
		unsigned long baudRate,
		unsigned char stopBits,
		unsigned char parity,
		unsigned char byteSize
	);
	bool CommPortClose(void);
	BOOL CommWriteChar(int nChar);
	BOOL CommReadChar(char* pnChar);
	BOOL CommReadStr(char* pnChar);

protected:
	LPCTSTR			commPort;
	DCB				dcb;
	HANDLE			commHandle;
	COMMTIMEOUTS	timeouts;
	LPCTSTR			*availablePortName;
	unsigned long	*availableBaudRate;
	unsigned char	*availableStopBits;
	unsigned char	*availableParity;
	unsigned char	*availableByteSize;
	bool isError;
};
