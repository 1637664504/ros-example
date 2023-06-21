#include <ros/console.h>
#include <ros/ros.h>

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test_log");
    ros::NodeHandle n;

    while (ros::ok())
    {
        ROS_DEBUG("111111 debug");
        ROS_INFO("111111 info");
        ROS_WARN("111111 warn");
        ROS_ERROR("111111 error");
        ROS_FATAL("111111 fatal");
        sleep(1);
        ros::spinOnce();
    }

    return 0;
}
