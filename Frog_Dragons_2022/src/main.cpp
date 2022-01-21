/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Frog Dragons                                              */
/*    Created:      Tue Jan 11 2022                                           */
/*    Description:  Frog Dragons Code                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// fRight               motor         1               
// bRight               motor         2               
// fLeft                motor         3               
// bLeft                motor         4               
// Lift                 motor         5               
// Claw                 motor         6               
// bRLift               motor         7               
// bLLift               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;
// Defining Motor Groups and the Drivetrain
motor_group leftDrive = motor_group(bLeft, fLeft); // Defining the Left Drive Motor Group
motor_group rightDrive = motor_group(bRight, fRight); // Defining the Right Drive Motor Group
drivetrain Drivetrain = drivetrain(leftDrive, rightDrive, 319.19, 295, 40, mm, 1.5); // Using the Left and Right Drives to define the Drivetrain

motor_group bLift = motor_group(bRLift, bLLift); // Defining the Back Lift Motor Group

void pre_auton(void)
{
  Brain.Screen.clearScreen();
  Brain.Screen.print("preAuton");
  wait(1, seconds);
}

void autonomous(void)
{
  Drivetrain.setDriveVelocity(100, pct);
  Lift.setVelocity(100, pct);
  Claw.setVelocity(100, pct);

  Lift.spinFor(fwd, 20, deg);
  
  Drivetrain.driveFor(fwd, 1400, mm); // Drive forward to Middle Mobile Goal

  Lift.spinFor(fwd, 10, deg); // Spin Lift up slightly so that Mobile Goal is pressing against bottom of lift plate

  Claw.spinFor(fwd, 2, sec); // Close the Claw onto the Mobile Goal

  Drivetrain.driveFor(reverse, 1000, mm); // Back up so that Mobile Goal is out of the Neutral Zone

  Claw.spinFor(reverse, 0.2, sec); // Open Claw so it can back out from under the Mobile Goal

  Drivetrain.driveFor(reverse, 200, mm); // Back out from under the Mobile Goal

  Drivetrain.turnFor(right, 45, deg); // Turn towards the Middle Mobile Goal

  Drivetrain.driveFor(fwd, 1400, mm); // Drive toward the Middle Mobile Goal
}

void usercontrol(void)
{
  Brain.Screen.clearScreen();
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(0, 0);
  Controller1.Screen.print(Brain.Battery.voltage()); 
  Controller1.Screen.newLine();
  Controller1.Screen.print(Brain.Battery.current());

  while (true) 
  {
    // Controls for Drivetrain
    // Tank Control, Axis2 and Axis3
    rightDrive.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    leftDrive.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);

    // Quick Drive Controls -
    // ----------------------
    // FWD --------------- UP
    // REV ------------- DOWN
    // LEFT TURN ------- LEFT
    // RIGHT TURN ----- RIGHT
    // ----------------------
    if(Controller1.ButtonUp.pressing())
    {
      Drivetrain.drive(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonLeft.pressing()) 
    {
      Drivetrain.turn(vex::turnType::right, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonRight.pressing())
    {
      Drivetrain.turn(vex::turnType::left, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonDown.pressing())
    {
      Drivetrain.drive(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    // ----------------------

    // Controls for Lift ----
    // ----------------------
    // UP ---- Controller1 L1
    // DOWN -- Controller1 L2
    // ----------------------
    Lift.setStopping(hold);
    if (Controller1.ButtonL1.pressing()) 
    {
      Lift.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonL2.pressing())
    {
      Lift.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    else {
      Lift.stop(vex::brakeType::hold);
    }
    // ----------------------

    // Controls for Claw ----
    // ----------------------
    // OPEN -- Controller1 R1
    // CLOSE - Controller1 R2
    // ----------------------
    Claw.setStopping(hold);
    if (Controller1.ButtonR1.pressing()) 
    {
      Claw.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);  
    }
    else if (Controller1.ButtonR2.pressing()) 
    {
      Claw.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    else {
      Claw.stop(vex::brakeType::hold);
    }
    // ---------------------

    // Controls for Rear Lift 
    // ---------------------
    // UP ---- Controller1 X
    // DOWN -- Controller1 B
    // ---------------------
    bRLift.setStopping(hold);
    bLLift.setStopping(hold);
    if (Controller1.ButtonX.pressing()) 
    {
      bLift.spin(vex::directionType::fwd, 90, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonB.pressing()) 
    {
      bLift.spin(vex::directionType::rev, 90, vex::velocityUnits::pct);
    }
    else {
      bLift.stop(vex::brakeType::hold);
    }
    // ---------------------
    wait(20, msec);
  }
}
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
 



