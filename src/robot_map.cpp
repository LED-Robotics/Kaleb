#include "robot_map.h"

// Sets the Motor ports, Gearsets, if they are Reversed and what there Encoder Units they are using
Motor rear_left{4, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};
Motor front_left{2, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};
Motor rear_right{3, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};
Motor front_right{1, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};

Motor intake{11, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};//*Small Motors 200 RPM

Motor catapult{7,MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES};

// Sets the ADI ports
ADIDigitalOut intake_extender{'G'};

// Sets the IMU/Gyro ports
IMU gyro{20};

// Sets what controller is the main and which is the partner
Controller master{CONTROLLER_MASTER};
Controller partner{CONTROLLER_PARTNER};
