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

[INFO] [1685094946.751086]: /home/liuj/1_Data/5_ros_example/ros1/src/1_ros_基础/4_launch/src/4_launch_arg_xml变量.py
[INFO] [1685094946.751684]: aaa123
[INFO] [1685094946.752280]: __name:=launch_arg_xml_localVar
[INFO] [1685094946.752850]: __log:=/home/liuj/.ros/log/36954ff2-fba7-11ed-860b-00155db16574/launch_arg_xml_localVar-1.log
'''