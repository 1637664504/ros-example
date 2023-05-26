#!/usr/bin/env python3
# coding:utf-8
import sys
import rospy

if __name__ == '__main__':
    rospy.init_node('test4_launch',anonymous=False,disable_signals=True)
    rospy.loginfo('param----- py ---- {}'.format(sys.argv))
    rospy.loginfo('liuj debug')
    result = rospy.get_param_names()
    for it in result:
        var = rospy.get_param(it)
        rospy.loginfo("%s:%s"%(it,var))

    var1 = rospy.get_param('/test1_py/haha')
    var2 = rospy.get_param('/test1_py/abc')
    print(var1,type(var1))
    print(var2,type(var2))

    rospy.spin()
