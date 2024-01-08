#include <iostream>
// ROS include
#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/UInt32.h>

using namespace std;

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test_multi_thread");
    ros::NodeHandle n("test_multi_thread");
    setlocale(LC_CTYPE, "zh_CN.utf8");

    ros::Publisher pub_msg = n.advertise<std_msgs::UInt32>("/test/multi_thread", 1);
    std_msgs::UInt32 msg;

    uint32_t seq = 0;
    ros::Rate rate(10);
    while (ros::ok())
    {
        msg.data = seq++;
        pub_msg.publish(msg);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
