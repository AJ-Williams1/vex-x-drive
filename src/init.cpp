#include "main.h"

using namespace pros;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize()
{
    lcd::initialize();

    Controller master(E_CONTROLLER_MASTER);

    Motor front_l(12, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
    Motor front_r(14, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);

    Motor back_l(17, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
    Motor back_r(18, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize()
{
}
