
#include <string.h>

class servo_class{
private:

//		extern motion_number;

public:
	int id_a;
	CString servo_name_a;
	int d_gain_a;
	int i_gain_a;
	int p_gain_a;
	int dead_band_a;
	int duty_limit_a;
	int target_position_a;
	int position_limit_min_a;
	int initial_position_a;
	int set_target_position_a;
	int offset_position_a;
	int i_limit_a;
	int speed_limit_a;
	int acceleration_limit_a;
	int position_limit_max_a;

	servo_class();

	//読み込み専用  まだ使えないよー
	int baud_rate();
	int d_gain();
	int i_gain();
	int p_gain();
	int current_position();
	int temperature();
	int dead_band();
	int duty_limit();
	int target_position();
	int position_limit_min();
	int initial_position();
	int set_target_position();
	int offset_position();
	int i_limit();
	int speed_limit();
	int acceleration_limit();
	int position_limit_max();

	//書き込み専用
	void write_project(int rock);
	void offset_lock();
	void baud_rate(int baud_rate);
	void duty_offset();
	void delay(int delay);
	void d_gain(int Dgain);
	void i_gain(int Igain);
	void p_gain(int speed);
	void dead_band(int dead_band);
	void duty_limit(int duty_limit);
	void target_position(int position);
	void position_limit_min(int position_limit_min);
	void initial_position(int position);
	void set_target_position(int position);
	void offset_position(int offset);		
	void i_limit(int limit);
	void speed_limit(int speed_limit);
	void acceleration_limit(int acceleration);
	void position_limit_max(int limit);
	void excute(void);
	void servo_move(void);
	void servo_on(void);
	void servo_off(void);
	void digital_servo_mode(void);
	void pid_mode(void);
	void home_position(void);
};