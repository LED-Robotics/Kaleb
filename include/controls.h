#ifndef CONTROLS_H
#define CONTROLS_H
#include "robot_map.h"

// Team Color
#define RED_ID 1
#define BLUE_ID 2

// Deadzone of the Joystick
extern const float deadzone;

// Choose which alliance you are on
extern int alliance;

// Choose which Auton that is selected
extern int autonselect;

// checks if the second controller is connected
extern bool partnerConnected;

//For separating commands between controllers
// extern const controller_id_e_t INTAKE_CONTROLLER;

// extern const controller_id_e_t CATAPULT_CONTROLLER;

// extern const controller_id_e_t ELEVATE_CONTROLLER;

#endif