#include <iostream>
// ROS include
#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/UInt8MultiArray.h>

using namespace std;

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test1_MultiArray");
    ros::NodeHandle n("test1_MultiArray");
    setlocale(LC_CTYPE, "zh_CN.utf8");

    ros::Publisher pub_uint8_array = n.advertise<std_msgs::UInt8MultiArray>("/test/UInt8MultiArray", 5);
    std_msgs::UInt8MultiArray multiArray_msg;

    ros::Rate rate(10);
    vector<uint8_t> data = { 0x1, 0x2, 0x4, 0x8 };
    auto it = data.begin();
    int idx = 10;
    while (ros::ok() && idx--)
    {
        *it = idx;
        multiArray_msg.data = data;
        pub_uint8_array.publish(multiArray_msg);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
