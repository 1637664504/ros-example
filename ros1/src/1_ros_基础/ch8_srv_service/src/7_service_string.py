#!/usr/bin/env python3
# coding=utf-8

from __future__ import print_function

from common.srv import diagInfo, diagInfoResponse
import rospy

def handle_diagInfo(req):
    print("req cmd=%s" % (req.cmd))
    return diagInfoResponse("test ros service string")

def add_two_ints_server():
    rospy.init_node("python_test_server_string")
    s = rospy.Service("/python_test_server_string", diagInfo, handle_diagInfo)
    print("Ready to python_test_server_string.")
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
