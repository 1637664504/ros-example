#!/usr/bin/env python3
# coding:utf-8
import sys
import rospy

if __name__ == '__main__':
    rospy.init_node('4_launch_2_param_rw',anonymous=False,disable_signals=True)

    var1 = rospy.get_param('/test1_py/haha')
    var2 = rospy.get_param('/test1_py/abc')
    print(var1,type(var1))
    print(var2,type(var2))

    rospy.set_param('/test1_py/haha','kkk')
    rospy.get_param('/test1_py/abc',555)

    var1 = rospy.get_param('/test1_py/haha')
    var2 = rospy.get_param('/test1_py/abc')
    print(var1,type(var1))
    print(var2,type(var2))

    rospy.spin()

''' 
结果:

123 <class 'str'>
234 <class 'int'>
kkk <class 'str'>
234 <class 'int'>
'''