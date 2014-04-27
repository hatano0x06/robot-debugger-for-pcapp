#include "CommPort.h"

#include "servo_class.h"
#include <String>

#ifdef GLOBAL_INSTANCE
#define GLOBAL 
#else
#define GLOBAL extern 
#endif


GLOBAL servo_class arm[30][30];
GLOBAL int delay[30];
GLOBAL int motion_number;
GLOBAL int serial_servo_number;
GLOBAL int DC_servo_number;
GLOBAL int file_output_time;
GLOBAL int servo_name_number;
GLOBAL int comport;
GLOBAL int baud_rate;
GLOBAL int max_motion_number;
GLOBAL int sync;
GLOBAL CCommPort com;
