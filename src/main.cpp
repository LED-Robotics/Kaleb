#include "main.h"
#include "robot_map.h"
#include "autonomous_functions.h"
#include "autonomous.h"
#include "teleop_functions.h"
#include "controls.h"

using namespace pros;


// The intialization code
void initialize() {
	pros::lcd::initialize();

    // Stops the Catapault from running at the start
	catapult.set_brake_mode(MOTOR_BRAKE_HOLD);
	// Resets the GYRO/IMU
	gyro.reset(true);
}

// The Disable code
void disabled() {}

// The Compettion Initialization code
void competition_initialize() {}

// The Auton code
void autonomous() {}

// The Teleop control code
void opcontrol() {
	while (true) {
		// Calls the teleop Drive code
		driveOP();

		// Calls the teleop Intake code
		intakeOP();

		// Calls the teleop Catapault code
		catapultOP();

		// teleopElevate();

		delay(20);
	}
}
