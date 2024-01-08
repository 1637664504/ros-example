#include <stdint.h>
#include <vector>
#include <thread>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/UInt32.h>
using namespace std;

struct statistics_loss {
    bool start_flag = false;
    uint32_t start_data;
    uint32_t last_data;
    uint32_t loss;
}static_loss;

void handler_callback(const std_msgs::UInt32& msg)
{
    if (static_loss.start_flag) {
        if (msg.data != static_loss.last_data + 1)
            static_loss.loss += (msg.data - static_loss.last_data - 1);

        static_loss.last_data = msg.data;
        ROS_INFO("data=%u, loss=%d, precent=%f", msg.data, static_loss.loss, (double)static_loss.loss / (msg.data - static_loss.start_data));
    }
    else {
        static_loss.start_flag = true;
        static_loss.last_data = static_loss.start_data = msg.data;
        static_loss.loss = 0;
    }

}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "test_topic");
    ros::NodeHandle n;

    int count = 0;
    ros::Subscriber sub_uint8_array = n.subscribe("/test/multi_thread", 2, handler_callback);
    ros::Rate rate(5);
    while (ros::ok()) {

        ros::spinOnce();
        rate.sleep();
    }
    ros::spin();

    return 0;
}
