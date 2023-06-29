#include "lib_test/libheader.h"
#include <ros/ros.h>

int LibFunc(int a, int b){
    ROS_INFO("LibFunc is called %d", a+b);
    return a+b;
}