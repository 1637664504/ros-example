#include <stdint.h>
#include <vector>
#include <thread>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/UInt32.h>
using namespace std;

void handler_callback(const std_msgs::UInt32 &msg)
{
    ROS_INFO("data=%u",msg.data);
}

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test_topic");
    ros::NodeHandle n;

    ros::Subscriber sub_uint8_array = n.subscribe("/test/multi_thread", 2,handler_callback);
    ros::spin();

    return 0;
}
