#include "ros/ros.h"
#include "common/diagInfo.h"
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_client_string");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<common::diagInfo>("/test_string");

    // 一直超时
    // client.waitForExistence();

    // 超时5S
    // if (!client.waitForExistence(ros::Duration(5.0))) {
    //     ROS_ERROR("Service did not exist");
    //     return -1;
    // }

    // 超时5s
    ros::service::waitForService("/test_string", ros::Duration(5.0));

    ROS_INFO("Waiting for service up");

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