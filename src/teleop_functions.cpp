#include "teleop_functions.h"
#include "controls.h"

using namespace pros;

double turn; // Turn variable
double straight; // Straight variable

// The teleop drive function
void driveOP() {
    turn = (double)master.get_analog(ANALOG_RIGHT_X); // Sets the turn variable to the Right X joystick
    straight = (double)master.get_analog(ANALOG_LEFT_Y);// Sets the straight variable to the Left Y joystick
    
    if (fabs(turn) < deadzone) {
        turn = 0.0;
    }
    if (fabs(straight) < deadzone) {
        straight = 0.0;
    }
    double speed_left = straight;
    double speed_right = straight; // The speed for going straight/backwards
    
    if (turn != 0.0){//If You Want to Turn
        if(turn > 0.0) { // Turn Right
            if (straight > 0.0) {// Going Forwards
                speed_right = straight - fabs(turn);
                if(speed_right < 0.0){
                    speed_right = 0.0;
                }
            } else if (straight < 0.0) {//Going Backwards
                speed_right = straight + fabs(turn);
                if (speed_right > 0.0) {
                    speed_right = 0.0;
                }
            }
            else{
                speed_left = fabs(turn);
                speed_right = - fabs(turn);
            }
        }
        if (turn < 0.0) {// Turn Left
            if (straight > 0.0) {//Going Forward
                speed_left = straight - fabs(turn);
                if (speed_left < 0.0) {
                    speed_left = 0.0;
                }
            } else if (straight < 0) {//Going Backwards
                speed_left = straight + fabs(turn);
                if (speed_left > 0.0) {
                    speed_left = 0.0;
                }
            } else {
                speed_left = -fabs(turn);
                speed_right = fabs (turn);
            }
        } //Pos. values for right turn relative, Neg. for left relative
    }

    rear_left.move((int32_t)(speed_left)); // Sets the back left drive motor to the value of speed_left
    front_left.move((int32_t)(speed_left)); // Sets the front left drive motor to the value of speed_left
    rear_right.move((int32_t)(speed_right)); // Sets the back right drive motor to the value of speed_right
    front_right.move((int32_t)(speed_right)); // Sets the front right drive motor to the value of speed_right
}

bool Intake; // Intake variable
bool Outake; // Outake variable
bool extend; // Intake Extender variable

// The teleop Intake function
void intakeOP() {
    Intake = master.get_digital(DIGITAL_L1); // Sets the intake variable to the First Left Bumper
    Outake = master.get_digital(DIGITAL_R1); // Sets the outake variable to the First Right Bumper
    if (Intake == 1 && Outake == 0) { // Sets the Intake variable to true and move the Intake Motor forwards
        intake = 127;
    } else if (Intake == 0 && Outake == 1) { // Sets the Outake variable to true and move the Intake Motor backwards
        intake = -127;
    } else { // Turns the Intake off
        intake = 0;
    }

    if(master.get_digital_new_press(DIGITAL_A)) { // Intake extender
        extend = !extend;
        intake_extender.set_value(extend);
    }

}

// The teleop Catapault function
void catapultOP() {
    bool Shoot = master.get_digital(DIGITAL_R2); // Sets Shoot button to the Second Right Bumper

    if (Shoot == 1) { // Fires the Catapault
        catapult.move(100);
    } else { // Stops the Catapault
        catapult.move(0);
    }
}

// void teleopElevate() {

// }


//For drive, turning controlled by right sitck, left stick for forward and backward
//Turning, reverse drive value to make spin
//drive y left stick
//drive x right stick
//left, right is the positive