#include "main.h"
#include "definitions.h"
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

static Motors * driveM = new Motors();
static Drive * pid = new Drive();

void opcontrol() {
	pros::Motor rightF(10, HIGHSPEED, REV, COUNTS);
	pros::Motor rightB(9, HIGHSPEED, REV, COUNTS);
	pros::Motor leftF(1, HIGHSPEED, N_REV, COUNTS);
	pros::Motor leftB(2, HIGHSPEED, N_REV, COUNTS);

	pros::Motor intakeL(3, TORQUE, N_REV, DEGREES);
	pros::Motor intakeR(8, TORQUE, REV, DEGREES);
	pros::Motor lift(7, TORQUE, REV, DEGREES);
	pros::Motor tray(4, TORQUE, N_REV, DEGREES);

	pros::Controller master (MAIN);

	leftF.set_brake_mode(HOLD);
	leftB.set_brake_mode(HOLD);
	rightF.set_brake_mode(HOLD);
	rightB.set_brake_mode(HOLD);
	intakeR.set_brake_mode(HOLD);
	intakeL.set_brake_mode(HOLD);
	tray.set_brake_mode(HOLD);
	lift.set_brake_mode(HOLD);


	while (true) {

		rightF.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));
		rightB.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));
		leftF.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		leftB.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));

		lift.move(master.get_analog(RIGHT_Y));
		tray.move(master.get_analog(RIGHT_X));



		if(master.get_digital(BTN_L1) == 1)
		{
			intakeR.move(97);
			intakeL.move(97);
		}
		else if(master.get_digital(BTN_L2) == 1)
		{
			intakeR.move(-67);
			intakeL.move(-67);
		}
		else if(master.get_digital(BTN_UP))
		{
			intakeR.move(-27);
			intakeL.move(-27);
		}
		else if(master.get_digital(BTN_X))
		{
			intakeR.move(127);
			intakeL.move(127);
		}
		else if(master.get_digital(BTN_A))
		{
			intakeL.move(-127);
			intakeR.move(-127);
		}
		else
		{
			intakeR.move(0);
			intakeL.move(0);
		}

		if(master.get_digital(BTN_B))
		{
			tray.move_relative(90, 50);

		  pros::delay(600);

		  lift.move_relative(740, 127);

		  pros::delay(1600);

		  lift.move_relative(-650, -127);

		  tray.move(0);
		  intakeL.move(0);
		  intakeR.move(0);

		  pros::delay(900);

		}

		if(master.get_digital(BTN_Y))
		{
			tray.move_relative(700, 30);

			pros::delay(3200);
		}


		pros::delay(20);
	}
}
