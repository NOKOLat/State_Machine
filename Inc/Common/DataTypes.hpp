#ifndef DataTypes_HPP
#define DataTypes_HPP

#include <cstdint>
#include <array>

struct ControlData {

    float throttle;

    std::array<float, 3> target_rate;
    std::array<float, 4> pid_result;

    /*Motor PWM*/
	std::array<uint16_t, 8> motor_pwm;

	/*Servo Motor PWM*/
	std::array<uint16_t, 2> servo_pwm;
};

struct SensorData {

	/*Data from IMU*/
	std::array<float, 3> accel;
	std::array<float, 3> gyro;
	std::array<float, 3> angle;

	/*Data from IR transistor*/
    uint16_t adc_value;
};

#endif /* DataTypes_HPP */