#include <ros/ros.h>
#include "hw1/ObjectPosition.h"
// #include "hw1/RobotPosition.h"
// #include "hw1/Velocities.h"


int main(int argc, char **argv){

	ros :: init(argc,argv,"Camera_node");
	
	ros :: NodeHandle n;
	
	
	
	int freq=100;
	int queue_size=1000;
	if (argc==2)
	{	
		freq=atoi(argv[1]);
	}
	else if (argc==3)
	{
		freq=atoi(argv[1]);
		queue_size=atoi(argv[2]);
	}
	ros :: Publisher pub = n.advertise<hw1::ObjectPosition>("positionO",queue_size);
	
	ros :: Rate rate(freq);
	
	
	while(ros :: ok()){
		hw1 :: ObjectPosition msg;
		msg.Xr=30;
		msg.Yr=30;
		
		
		pub.publish(msg);
		rate.sleep();
		
	}
		




}
