#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor fr = motor(PORT1, ratio18_1, false);
motor br = motor(PORT2, ratio18_1, false);
motor fl = motor(PORT3, ratio18_1, true);
motor bl = motor(PORT4, ratio18_1, true);
motor BLift = motor(PORT7, ratio36_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}