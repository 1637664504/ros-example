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

[INFO] [1685095494.601011]: 1.0
[INFO] [1685095494.601570]: 2.0
[INFO] [1685095494.602158]: 3.0
[INFO] [1685095494.602739]: __name:=launch_many_args
[INFO] [1685095494.603291]: __log:=/home/liuj/.ros/log/36954ff2-fba7-11ed-860b-00155db16574/launch_many_args-1.log
'''