#include "ros/ros.h"
#include "common/diagInfo.h"

bool callback_diagInfo(common::diagInfo::Request& req,
    common::diagInfo::Response& res)
{
    ROS_INFO("request: cmd=%s", req.cmd.c_str());
    res.diagInfo = "test diag info";
    ROS_INFO("sending back response: %s", res.diagInfo.c_str());
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_string_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("/test_string", callback_diagInfo);
    ROS_INFO("Ready to test_string.");
    ros::spin();

    return 0;
}