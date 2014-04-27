
#include "stdafx.h"
//#include "servo_class.h" 
#include "global.h"
#include <windows.h>

servo_class::servo_class()
{

}


void servo_class::write_project(int rock=0)
{

}

void servo_class::offset_lock()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);
	com.CommWriteChar(id_a);
	
}

int servo_class::baud_rate()
{
	return 0;
}

void servo_class::baud_rate(int baud_rate)
{
	char data;
	char csam;
	//送信部分
	data=(baud_rate)&0x00ff;
	
	csam=(id_a+194+data)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(194);
	com.CommWriteChar(data);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

void servo_class::duty_offset()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);
	com.CommWriteChar(id_a);
	
	
}

int servo_class::d_gain()
{

	return 0;
}

void servo_class::d_gain(int Dgain)
{
	char data;
	char csam;

	//送信部分	
	data=(Dgain)&0x00ff;
	
	csam=(id_a+208+data)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(208);
	com.CommWriteChar(data);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::i_gain()
{

	return 0;
}

void servo_class::i_gain(int Igain)
{
	char data;
	char csam;
	
	//送信部分
	data=(Igain)&0x00ff;
	
	csam=(id_a+207+data)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(207);
	com.CommWriteChar(data);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

int servo_class::p_gain()
{

	return 0;
}

void servo_class::p_gain(int speed)
{
	int data;
	int csam;

	//送信部分	
	data=(speed)&0x00ff;
	
	csam=(id_a+210+data)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(data);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

int servo_class::current_position()
{

	return 0;
}

int servo_class::temperature()
{

	return 0;
}

int servo_class::dead_band()
{

	return 0;
}

void servo_class::dead_band(int dead_band)
{
	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(dead_band>>8)&(0x00ff);
	data_d=(dead_band)&0x00ff;

	csam=(id_a+225+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(225);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

int servo_class::duty_limit()
{

	return 0;
}

void servo_class::duty_limit(int duty_limit)
{

	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(duty_limit>>8)&(0x00ff);
	data_d=(duty_limit)&0x00ff;

	csam=(id_a+227+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(227);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::target_position()
{

	return 0;
}

void servo_class::target_position(int position)
{
	int data_u,data_d;
	int csam;

	//送信部分
	data_u=(position>>8)&(0x00ff);
	data_d=(position)&0x00ff;
	csam=(id_a+228+data_u+data_d)&0x00ff;
	com.CommWriteChar(255);
	com.CommWriteChar(0);
	com.CommWriteChar(id_a);
	com.CommWriteChar(228);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::position_limit_min()
{

	return 0;
}

void servo_class::position_limit_min(int position_limit_min)
{
	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(position_limit_min>>8)&(0x00ff);
	data_d=(position_limit_min)&0x00ff;
	
	csam=(id_a+229+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(229);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::initial_position()
{

	return 0;
}

void servo_class::initial_position(int position)
{
	int data_u,data_d;
	int csam;
	
	//送信部分
	data_u=(position>>8)&(0x00ff);
	data_d=(position)&0x00ff;
		
	csam=(id_a+230+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(230);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

int servo_class::set_target_position()
{

	return 0;
}

void servo_class::set_target_position(int position)
{
	int data_u,data_d;
	int csam;
	
	//送信部分
	data_u=(position>>8)&(0x00ff);
	data_d=(position)&0x00ff;
		
	csam=(id_a+231+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(231);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::offset_position()
{

	return 0;
}

void servo_class::offset_position(int offset)
{
	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(offset>>8)&(0x00ff);
	data_d=(offset)&0x00ff;
	
	csam=(id_a+232+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(232);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::i_limit()
{

	return 0;
}

void servo_class::i_limit(int limit)
{
	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(limit>>8)&(0x00ff);
	data_d=(limit)&0x00ff;
	
	csam=(id_a+233+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(233);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::speed_limit()
{

	return 0;
}

void servo_class::speed_limit(int speed_limit)
{
	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(speed_limit>>8)&(0x00ff);
	data_d=(speed_limit)&0x00ff;
	
	csam=(id_a+234+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(234);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::acceleration_limit()
{

	return 0;
}

void servo_class::acceleration_limit(int acceleration)
{
	char data_u,data_d;
	char csam;

	//送信部分	
	data_u=(acceleration>>8)&(0x00ff);
	data_d=(acceleration)&0x00ff;
	
	csam=(id_a+235+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(235);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

int servo_class::position_limit_max()
{

	return 0;
}

void servo_class::position_limit_max(int limit)
{
	char data_u,data_d;
	char csam;
	
	//送信部分
	data_u=(limit>>8)&(0x00ff);
	data_d=(limit)&0x00ff;
	
	csam=(id_a+245+data_u+data_d)&0x00ff;

	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(245);
	com.CommWriteChar(data_u);
	com.CommWriteChar(data_d);
	com.CommWriteChar(csam);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

void servo_class::delay(int delay)
{
	Sleep(delay);
}


void servo_class::excute()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(88);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

void servo_class::servo_move()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(83);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

void servo_class::servo_on()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(89);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

void servo_class::servo_off()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(90);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

void servo_class::digital_servo_mode()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(33);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

void servo_class::pid_mode()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(34);

	com.CommWriteChar(255);
	com.CommWriteChar(0);
}

void servo_class::home_position()
{
	com.CommWriteChar(255);
	com.CommWriteChar(0);

	com.CommWriteChar(id_a);
	com.CommWriteChar(83);

	com.CommWriteChar(255);
	com.CommWriteChar(0);

}

