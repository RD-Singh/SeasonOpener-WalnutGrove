#include "main.h"
#include "motionProfile.h"
#include "okapi/api.hpp"


using namespace okapi;

auto myChassis = ChassisControllerFactory::create(
  {1, 2}, // Left motors
  {-10, -9},   // Right motors
  AbstractMotor::gearset::green, // Torque gearset
  {4_in, 12.5_in} // 4 inch wheels, 12.5 inch wheelbase width
);

auto profileController = AsyncControllerFactory::motionProfile(
  1.0,  // Maximum linear velocity of the Chassis in m/s
  2.0,  // Maximum linear acceleration of the Chassis in m/s/s
  10.0, // Maximum linear jerk of the Chassis in m/s/s/s
  myChassis // Chassis Controller
);

void path() {
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
}
