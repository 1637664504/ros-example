#!/usr/bin/env python3
# coding=utf-8

from __future__ import print_function

import sys
import rospy
from common.srv import diagInfo, diagInfoResponse

import debugpy

debugpy.listen(6688)
debugpy.wait_for_client()
debugpy.breakpoint()

def test_get_diagInfo(cmd):
    rospy.wait_for_service("python_test_server_string")
    try:
        fun_service = rospy.ServiceProxy("/python_test_server_string", diagInfo)
        resp = fun_service(cmd)
        return resp.diagInfo
    except rospy.ServiceException as e:
        print("Service call failed: %s" % e)

def usage():
    return "%s [x y]" % sys.argv[0]

if __name__ == "__main__":
    cmd = "get"
    # cmd = input("test")
    print("Requesting %s" % (cmd))
    print("res %s" % (test_get_diagInfo(cmd)))
