#include <ros/ros.h>
#include "hw1/RobotPosition.h"
#include "hw1/Velocities.h"
#include <cmath>


//initial position and orientation
float x = 0.0;
float y = 0.0;
float theta = 0.0;

float linear_velocity = 0.0;
float angular_velocity = 0.0;



//void vel_cb(const hw1::Velocities::ConstPtr& msg) {
   // linear_velocity = msg->Forward_Velocity;
 //   angular_velocity = msg->Angular_Velocity;
//}
void vel_cb(const hw1::Velocities msg) {

    linear_velocity = msg.Forward_Velocity;
    angular_velocity = msg.Angular_Velocity;
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "Robot_node");
    ros::NodeHandle n;

    ros::Publisher pos_pub = n.advertise<hw1::RobotPosition>("positionR", 1000);
    
    ros::Subscriber vel_sub = n.subscribe("VelocitiesR", 1000, vel_cb);

    ros::Rate rate(100); 
    
    float dt = 1.0 / 100.0;

    while (ros::ok()) {

        x += linear_velocity * cos(theta) * dt;
        y += linear_velocity * sin(theta) * dt;
        theta += angular_velocity * dt;


        hw1::RobotPosition msg;
        msg.X = x;
        msg.Y = y;
        msg.theta = theta;
        pos_pub.publish(msg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
