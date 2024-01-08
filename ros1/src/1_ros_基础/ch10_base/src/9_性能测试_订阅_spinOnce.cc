#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <thread>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/Header.h>
using namespace std;

void handler_callback(const std_msgs::Header& msg)
{
    ros::Time now = ros::Time::now();
    ROS_INFO("topic_time=%f, now=%f, diff_t=%f, seq=%u", msg.stamp.toSec(), now.toSec(), now.toSec() - msg.stamp.toSec(), msg.seq);
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "test_topic");
    ros::NodeHandle n;

    ros::Subscriber sub_msg = n.subscribe("/test/multi_thread", 1, handler_callback);
    ros::Rate rate(10);
    while (ros::ok()) {

        ros::spinOnce();
        rate.sleep();
    }
    ros::spin();

    return 0;
}
