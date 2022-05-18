#include "main.h"

using namespace pros;

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

int power;
int turn;
int strafe;

int front_l_speed;
int front_r_speed;
int back_l_speed;
int back_r_speed;

void opcontrol()
{
    /* Make motors and controller available in this function */
    Controller master(E_CONTROLLER_MASTER);
    Motor front_l(12);
    Motor back_l(17);
    Motor front_r(14);
    Motor back_r(18);

    // Begin loop --------------------------------------------------------------
    while (true)
    {
        power = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        strafe = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
        turn = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

        /* Equations for X-Drive */
        front_l_speed = power + turn + strafe;
        front_r_speed = power - turn - strafe;
        back_l_speed = power + turn - strafe;
        back_r_speed = power - turn + strafe;

        /* Set the motor velocities */
        front_l.move_velocity(front_l_speed);
        front_r.move_velocity(front_r_speed);
        back_l.move_velocity(back_l_speed);
        back_r.move_velocity(back_r_speed);

        delay(20);
    }
}
