#include "Main.h"

void main ( void )
{
      // Dead Bands are used so that if we accidently jerk the Vex Joystick, then the motors/servos would not move. 
      // Also, Joy1 refers to the entire Vex Remote. It does NOT refer to the Joystick on the Vex Remote. 
      SetJoystickAnalogDeadband ( Joy1 , Stk1 , 16 , 16 ) ;
      SetJoystickAnalogDeadband ( Joy1 , Stk2 , 16 , 16 ) ;
      SetJoystickAnalogDeadband ( Joy1 , Stk3 , 16 , 16 ) ;
      SetJoystickAnalogDeadband ( Joy1 , Stk4 , 16 , 16 ) ;
      while ( 1 == 1 ) // Will work in constant motion.... Repeats forever!
      {
            Tank2 ( 1 , 3 , 2 , 2 , 3 , 0 , 1 ) ; // Tank Control Version 2 [PORTS: 2 For Left Motor, 3 for Right Motor]
            // Tank Controls:  Both joysticks down = go forward. Left joystick down & right joystick up = go right. Left joystick up & right joystick down = go left. 
            JoystickToMotor ( 1 , 1 , 4 , 0 ) ; // Moving the right joystick left and right will move this motor. [PORT 4]
            JoystickToMotor ( 1 , 4 , 5 , 0 ) ; // Moving the left joystick left and right will move this motor. [PORT 5]
            JoystickDigitalToServo ( 1 , 5 , 1 , 127 , 2 , -127 , 6 ) ; // Go to Channel #5 (Front Horizontal Sides of Controller). The Up Button will make this Servo go positive, and the Top Button will make the Servo go negative. [PORT 6]
            JoystickDigitalToServo ( 1 , 6 , 1 , 127 , 2 , -127 , 7 ) ; // Go to Channel #6 (Front Horizontal Sides of Controller). The Up Button will make this Servo go positive, and the Top Button will make the Servo go negative. [PORT 7]
            JoystickDigitalToServo ( 1 , 7 , 1 , 127 , 2 , -127 , 8 ) ; // Go to Channel #7 (Face Buttons of Controller). The Up Button will make this Servo go positive, and the Top Button will make the Servo go negative. [PORT 8]
            JoystickDigitalToServo ( 1 , 8 , 1 , 127 , 2 , -127 , 9 ) ; // Go to Channel #8 (Face Buttons of Controller). The Up Button will make this Servo go positive, and the Top Button will make the Servo go negative. [PORT 9]
            // Since BEST Robotics gave us 4 Motors and 4 Servos, I utilized them all in this code. 
            // It's possible we won't even use all of the Servos and Motors, but I programmed them anyways! 
      }
      // Beefy V (Uplift North Hills Preperatory) [BEST Robotics] 
}
