task main()
{
	/*
	Motors Power Levels:
	127 = Full power clockwise
	-127 = Full power backwards
	0 = Stationary

	Servo Positionioning:
	360 = Positive Degrees positioning on a circle
	-360 = Negative degrees positioning on a circle
	0 = Middle

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
	port 7 = Unused
	port 8 = Unused
	
	Note: vexRT[] refers to the VEX Joystick's channels (there are up to 8 channels on the joystick).
	*/

	// Infinite while loop to continiously run the robot
	while(1 == 1) {
	motor[port2] = (vexRT[Ch2]); // Channel 2 (right-side joystick, up & down) for the right wheel
	motor[port3] = (vexRT[Ch3]); // Channel 3 (left-side joystick, up & down) for the left wheel

	// Channel 5 Buttons [Roll Arm String to move Up and Down]
	if (vexRT[Btn5U] == 1 && vexRT[Btn5U] != 0) {// Holding Channel 5 Up Button
		motor[port4] = 42; // Port 4 Motor rolls string down with 42 power
	} else if (vexRT[Btn5D] == 1 && vexRT[Btn5D] != 0) {// Holding Channel 5 Down Button
		motor[port4] = -84; // Port 4 Motor rolls string up with 84 power
	} else {
		motor[port4] = 0; // Else, stop the Port 4 Motor
	}

	// Channel 8 Buttons [Water Wheel]
	if (vexRT[Btn8U] == 1  && vexRT[Btn8U] != 0) // Holding Channel 8 Up Button
	{
		motor[port5] = 127; // Port 5 Motor spins clockwise with full power
	} else if(vexRT[Btn8D] == 1 && vexRT[Btn8D] != 0) // Holding Channel 8 Down Button
	{
		motor[port5] = -127; // Port 5 Motor spins counter-clockwise with full power
	} else {
	motor[port5] = 0; // Else, stop the Port 5 Motor
	}

	// Note: we can use the motor[] code for a servo, too!
	
	// Channel 6 Buttons [Open and close claws]
	if (vexRT[Btn6U] == 1) { // Press Channel 6 Up Button
		motor[port6] = 200; // Position Port 6 servo to open the claw
	} else if (vexRT[Btn6D] == 1) { // Press Channel 6 Down Button
		motor[port6] = -330; // Position Port 6 Servo to close the claw
	}
	
	} // End while loop

} // End main task function
