#include <stdint.h>
#include <vector>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>
using namespace std;

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test_topic");
    ros::NodeHandle n;


    ros::Publisher pub_uint8_array = n.advertise<std_msgs::UInt8MultiArray>("/test/UInt8MultiArray", 5);
    std_msgs::UInt8MultiArray msg_uint8_array;
    // uint8_t data[4] = { 0x1, 0x2, 0x4, 0x8 };
    vector<uint8_t> data = { 0x1, 0x2, 0x4, 0x8 };
    while (ros::ok())
    {
        msg_uint8_array.data = data;
        pub_uint8_array.publish(msg_uint8_array);
        sleep(1);
        ros::spinOnce();
    }

    return 0;
}
