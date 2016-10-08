#pragma config(Motor,  port2,           rightWheel,    tmotorVex269, openLoop)
#pragma config(Motor,  port3,           leftWheel,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port4,           rotateClaw,     tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	/*
	Power Levels:
	127 = Full power forward
	-127 = Full power backwards
	0 = Stationary
	
	Commands:
	vexRT[] refers to the Vex Joystick's buttons/joysticks
	#pragmas refer to the ports. Only motors have #pragmas, NOT servos!
	
	Booleans:
	0 = STOP
	1 = GO
	
	Motors & Servos Ports:
	port1 = Unused
	port2 = [Motor] Right Wheel
	port3 = [Motor] Left Wheel
	port4 = [Motor] Rotation of arm
	port5 = [Servo] Right claw (opening & closing)
	port6 = [Servo] Left claw (opening & closing)
	port7 = [Servo] Up & Down of arm
	*/
	
	//Infinite loop to continiously update the values
	while(1 == 1)
	{ 
	
	//MOTORS (we use motor[] codes)
	motor[rotateClaw] = vexRT[Ch1]; //Channel 1 (right joystick, left & right) rotates claw <-- Motor 1
	motor[rightWheel] = vexRT[Ch2]; //Channel 2 (right joystick, up & down) right wheel <-- Motor 2
	motor[leftWheel] = vexRT[Ch3]; //Channel 3 (left joystick, up & down) left wheel <-- Motor 3
	//We probably won't have a fourth motor because Kiran broke it :(. Ok, it probably wasn't kiran, but when in doubt blame kiran.
	motor[port7] = vexRT[Ch4]; //Channel 4  (left joystick, left & right) claw up & down <-- Servo 1
	
	//SERVOS (we can use the motor[] codes for a servo, too!)
	/* Channel 6 Buttons (RIGHT TOP SIDE) [Open and close claws] */
	if (vexRT[Btn6U] == 1) //UP Pressed (opening claw)
	{
	motor[port5] = 127; //Full power positive servo (open right claw) <-- Servo 2
	motor[port6] = 127; //Full power positive servo (open left claw) <-- Servo 3
	wait1Msec(1000); //Play for 1 second (or 1000 miliseconds)
	motor[port5] = 0; //Then stop (stop power of right claw & leave it opened) <-- Servo 2
	motor[port6] = 0; //Then stop (stop power of left claw & leave it opened) <-- Servo 3
	} else if (vexRT[Btn6D] == 1) //DOWN Pressed (closing claw)
	{
	motor[port5] = -127; //Full power negative servo (close right claw) <-- Servo 2
	motor[port6] = -127; //Full power negative servo (close left claw) <-- Servo 3
	wait1Msec(1000); //Play for 1 second (or 1000 miliseconds)
	motor[port5] = 0; //Then stop (stop power of right claw & leave it closed) <-- Servo 2
	motor[port6] = 0; //Then stop (stop power of left claw & leave it closed) <-- Servo 3
	}
		
	} //End while loop	
	
} //End main task
