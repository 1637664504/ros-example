#include <stdint.h>
#include <vector>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>
using namespace std;

void callback_test_uint8MultiArray(const std_msgs::UInt8MultiArray &msg)
{
    ROS_INFO("msg size: %lu", msg.data.size());
    ROS_INFO("recv array size: data:%x %x %x %x",msg.data[0], msg.data[1], msg.data[2], msg.data[3]);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "test_sub_uint8MultiArray");
    ros::NodeHandle n;

    ros::Subscriber sub_uint8_array = n.subscribe("/test/UInt8MultiArray", 10, callback_test_uint8MultiArray);
    ros::spin();

    return 0;
}
