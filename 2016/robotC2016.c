task main()
{
	/*
	Motors Power Levels:
	127 = Full power forward
	-127 = Full power backwards
	0 = Stationary

	Servo Position Levels:
	127 = Full upwards (Goes left)
	-127 = Full downwards (Goes right)
	0 = Middle

	Commands:
	vexRT[] refers to the Vex Joystick's buttons/joysticks
	Booleans:
	0 = STOP
	1 = GO

	Motors & Servos Ports:
	port1 = Unused
	port2 = [Motor] Right Wheel
	port3 = [Motor] Left Wheel

	port6 = [Servo] Left claw (opening & closing)
	port7 = [Servo] Up & Down of arm
	*/

	// Pre-Auton:
	motor[port5] = 0;
	motor[port6] = 0;

	//Infinite loop to continiously update the values
	while(1 == 1)
	{
	//MOTORS (we use motor[] codes)
	motor[port2] = vexRT[Ch2]; //Channel 2 (right joystick, up & down) right wheel <-- Motor 2
	motor[port3] = vexRT[Ch3]; //Channel 3 (left joystick, up & down) left wheel <-- Motor 3

	//SERVOS (we can use the motor[] codes for a servo, too! However, it uses angle positions rather than power level.)
	/* Channel 6 Buttons (RIGHT TOP SIDE) [Open and close claws] */
	if (vexRT[Btn6U] == 1) //UP Pressed (opening claw)
	{
		motor[port5] = 45; //Position the servo to right wise (open right claw) <-- Servo 2
		motor[port6] = -45; //Position the servo to left wise (open left claw) <-- Servo 3
	} else if (vexRT[Btn6D] == 1) //DOWN Pressed (closing claw)
	{
		motor[port5] = -45; //Position the servo left wise (close right claw) <-- Servo 2
		motor[port6] = 45; //Position the servo right wise (close left claw) <-- Servo 3
	}
	/*
	When opening the claw, we have one side going right (thumb) and one going left (four fingers).
	When closing the claw, we have one side going left (thumb) and one going right (four fingers).
	*/
	} //End while loop

} //End main task
