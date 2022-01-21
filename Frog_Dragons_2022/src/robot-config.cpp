#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor fRight = motor(PORT1, ratio36_1, false);
motor bRight = motor(PORT2, ratio36_1, false);
motor fLeft = motor(PORT3, ratio36_1, true);
motor bLeft = motor(PORT4, ratio36_1, true);
motor Lift = motor(PORT5, ratio36_1, false);
motor Claw = motor(PORT6, ratio36_1, false);
motor bRLift = motor(PORT7, ratio36_1, true);
motor bLLift = motor(PORT8, ratio36_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}