import rospy 
from hw1.msg import Velocities
from hw1.msg import feedback


def vel_cb(msg):
	rospy.loginfo(f'linear velocity is {msg.Forward_Velocity} and angular velocity is {msg.Angular_Velocity}')

def feed_cb(msg):
	rospy.loginfo(f'current state  is {msg.status} and the robot is at x: {msg.current_x}  and  y: {msg.current_y}  and the remaining distance to the object is {msg.distance_to_object}')


rospy.init_node ('interface_node',anonymous=True)

rospy.Subscriber('VelocitiesR',Velocities,vel_cb)

rospy.Subscriber('Feedback',feedback,feed_cb)

rospy.spin()
