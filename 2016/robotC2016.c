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
	motor[port2] = (vexRT[Ch2]); //Channel 2 (right joystick, up & down) right wheel <-- Motor 1
	motor[port3] = (vexRT[Ch3]); //Channel 3 (left joystick, up & down) left wheel <-- Motor 2

	/* Channel 5 Buttons (Moving the arm up & down) */
	if (vexRT[Btn5U] == 1 && vexRT[Btn5U] != 0) //UP hold (going up)
	{
		motor[port4] = 42; //Motor goes down with 42 power <-- Motor3
	} else if (vexRT[Btn5D] == 1 && vexRT[Btn5D] != 0) //DOWN hold (going down)
	{
		motor[port4] = -84; //Motor goes up with 84 power <-- Motor 3
	} else
	{
		motor[port4] = 0; //If nothing pressed, make the motor go to power 20 (20 not 0 because weight of claws) <-- Motor 3
	}

	/*Channel 8 Buttons (RIGHT FRONT SIDE) [Water Wheel]*/
	if (vexRT[Btn8U] == 1  && vexRT[Btn8U] != 0) //Channel 8 UP (Water motor up)
	{
		motor[port5] = 127; //Motor goes positive down with 127 power <-- Motor4
	} else if(vexRT[Btn8D] == 1 && vexRT[Btn8D] != 0) //Channel 8 DOWN (Water motor down)
	{
		motor[port5] = -127; //Motor goes positive up with 127 power <-- Motor4
	} else
	{
	motor[port5] = 0; //Turn the motor off
	}

	//SERVOS (we can use the motor[] codes for a servo, too! However, it uses angle positions rather than power level.)
	/* Channel 6 Buttons (RIGHT TOP SIDE) [Open and close claws] */
	if (vexRT[Btn6U] == 1) //UP Pressed (opening claw)
	{
		motor[port6] = 200; //Position the servo to open (open right claw) <-- Servo 1
	} else if (vexRT[Btn6D] == 1) //DOWN Pressed (closing claw)
	{
		motor[port6] = -330; //Position the servo to close tightly (close right claw) <-- Servo 1
	}

  } //End while loop

} //End main task
