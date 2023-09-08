#!/usr/bin/env python3
# coding:utf-8
import sys
import rospy

if __name__ == '__main__':
    rospy.init_node('test4_launch',anonymous=False,disable_signals=True)
    rospy.loginfo("liuj debug")
    for it in sys.argv:
        rospy.loginfo(it)

    rospy.spin()

''' 
结果:
liuj debug
/home/liuj/1_data/6_ros-robot-example/ros1/src/1_ros_基础/ch4_launch/src/4_launch_arg_xml变量.py
aaa123
18
__name:=launch_arg_xml_localVar
__log:=/home/liuj/.ros/log/42dd4d9a-4c89-11ee-8d99-bbdee33537f0/launch_arg_xml_localVar-1.log
'''