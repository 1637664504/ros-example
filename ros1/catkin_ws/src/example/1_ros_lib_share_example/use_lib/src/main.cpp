#include "lib_test/libheader.h"
#include <ros/ros.h>

int main(int argc, char **argv){
    int result = LibFunc(1,2);
    ROS_INFO("result = %d", result);
}
