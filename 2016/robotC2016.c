task main()
{
	/*
	Motors Power Levels:
	127 = Full power forward
	-127 = Full power backwards
	0 = Stationary

	Servo Position Levels:
	180 = Full upwards (Goes left)
	-180 = Full downwards (Goes right)
	0 = Middle
	
	vexRT[] refers to the Vex Joystick's buttons/joysticks
	
	Binary:
	0 = OFF
	1 = ON

	Motors & Servos Ports:
	port1 = Unused
	
	port2 = [Motor] Right Wheel
	port3 = [Motor] Left Wheel
	
	port4 = [Motor] Up & Down of arm
	
	port5 = [Motor] Water motor
	
	port6 = [Servo] Opening & Closing Claw
	
	*/

	//Infinite loop to continiously update the values
	while(1 == 1)
	{
	//MOTORS (we use motor[] codes)
	//The vexRT[] is negative for logical tank mode (up goes forward, down goes backward)
	motor[port2] = -(vexRT[Ch2]); //Channel 2 (right joystick, up & down) right wheel <-- Motor 1
	motor[port3] = -(vexRT[Ch3]); //Channel 3 (left joystick, up & down) left wheel <-- Motor 2
	
	/* Channel 5 Buttons (Moving the arm up & down) */
	if (vexRT[Btn5U] == 1 && vexRT[Btn5U] != 0) //UP hold (going up)
	{
		motor[port4] = -84; //Motor goes up with 84 power <-- Motor3
	} else if (vexRT[Btn5D] == 1 && vexRT[Btn5D] != 0) //DOWN hold (going down)
	{
		motor[port4] = 84; //Motor goes down with 84 power <-- Motor 3
	} else 
	{
		motor[port4] = 0; //If nothing pressed, make the motor go to power 20 (20 not 0 because weight of claws) <-- Motor 3	
	}
		
	if (vexRT[Btn8U] == 1  && vexRT[Btn8U] != 0) //Channel 8 UP (Water motor up)
	{
		motor[port5] = 64; //Motor goes positive up with 64 power <-- Motor4
	} else if(vexRT[Btn8D] == 1 && vexRT[Btn8D] != 0) //Channel 8 DOWN (Water motor down)
	{
		motor[port5] = -64; //Motor goes positive up with 64 power <-- Motor4
	} else 
	{
	motor[port5] = 0; //Turn the motor off	
	}
	
	//SERVOS (we can use the motor[] codes for a servo, too! However, it uses angle positions rather than power level.)
	/* Channel 6 Buttons (RIGHT TOP SIDE) [Open and close claws] */
	if (vexRT[Btn6U] == 1) //UP Pressed (opening claw)
	{
		motor[port6] = 180; //Position the servo to right wise (open right claw) <-- Servo 1
	} else if (vexRT[Btn6D] == 1) //DOWN Pressed (closing claw)
	{
		motor[port6] = -180; //Position the servo left wise (close right claw) <-- Servo 1
	}
	/*
	When opening the claw, we have one side going right and one going left (inversed direction)
	When closing the claw, we have one side going left and one going right (inversed direction)
	*/
	
  } //End while loop

} //End main task
