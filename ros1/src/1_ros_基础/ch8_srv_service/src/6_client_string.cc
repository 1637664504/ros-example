#include "ros/ros.h"
#include "common/diagInfo.h"
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_client_string");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<common::diagInfo>("/test_string");
    common::diagInfo srv;
    srv.request.cmd = "get";
    if (client.call(srv))
    {
        ROS_INFO("Sum: %s", srv.response.diagInfo.c_str());
    }
    else
    {
        ROS_ERROR("Failed to call service test_string");
        return 1;
    }

    return 0;
}