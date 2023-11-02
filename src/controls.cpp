#include "controls.h"

// Deadzone of the Controller's Joystick
const float deadzone{.02};

// Choose which Alliance you are on
int alliance{BLUE_ID}; //Default

// Choose which Auton to use
int autonselect{-1}; //Default

bool partnerConnected{true};

// const controller_id_e_t INTAKE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t CATAPULT_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t ELEVATE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};