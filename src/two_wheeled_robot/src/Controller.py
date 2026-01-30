import rospy 
from hw1.msg import ObjectPosition, RobotPosition, Velocities,feedback

import math

obj=ObjectPosition()
robo=RobotPosition()

obj_ava=False
robo_ava=False

def obj_cb (msg):
	global obj
	obj=msg
	#obj_ava=True


def robo_cb (msg):
	global robo
	robo=msg
	#robo_ava=True


rospy.init_node('Controller_node',anonymous=True)
rospy.Subscriber ('positionO',ObjectPosition,obj_cb)
rospy.Subscriber ('positionR',RobotPosition,robo_cb)

pub_vel=rospy.Publisher('VelocitiesR',Velocities,queue_size=10)

pub_feed=rospy.Publisher('Feedback',feedback,queue_size=10)

rate=rospy.Rate(1)

Kp=0.1
V=2.0

while not rospy.is_shutdown():
	#if obj_ava and robo_ava:
		dx=obj.Xr-robo.X
		dy=obj.Yr-robo.Y
		th_o=math.atan2(dy,dx)
	
		e=th_o-robo.theta
	
		distance=math.sqrt(dx**2+dy**2)
		vel=Velocities()
		feed_back=feedback()
		
		feed_back.current_x=robo.X
		feed_back.current_y=robo.Y
		
		feed_back.distance_to_object=distance
			
		if distance < 20 :
			vel.Forward_Velocity=0
			vel.Angular_Velocity=0
			feed_back.status="arrived"
			
			
		else :
			feed_back.status="not_there_yet"
			vel.Forward_Velocity=V
			vel.Angular_Velocity=Kp*e
			
		
		
		pub_vel.publish(vel)
		pub_feed.publish(feed_back)
		
		rate.sleep()
		 

