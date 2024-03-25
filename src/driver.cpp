#include <stdio.h>
#include "main.h"

#define MOTOR_PORT 1

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

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor drive_left(MOTOR_PORT);

	pros::lcd::set_text(3, "Driver Control is running!");

	// FILE *port;

	// port = fopen("/dev/port11", "wb");

	while (true)
	{
		// pros::lcd::set_text(0, "Left Joystick: %d", master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		// pros::lcd::set_text(1, "Right Joystick: %d", master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));

		drive_left.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		pros::delay(20);
	}
}