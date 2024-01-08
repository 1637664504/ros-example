#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <thread>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/Header.h>
using namespace std;

struct statistics_loss {
    bool start_flag = false;
    uint32_t start_data;
    uint32_t last_data;
    uint32_t loss;
}static_loss;

void handler_callback(const std_msgs::Header& msg)
{
    if (static_loss.start_flag) {
        if (msg.seq != static_loss.last_data + 1)
            static_loss.loss += (msg.seq - static_loss.last_data - 1);

        static_loss.last_data = msg.seq;
        ros::Time now = ros::Time::now();
        ROS_INFO("topic_time=%f, now=%f, diff_t=%f, seq=%u, loss=%d, precent=%f", msg.stamp.toSec(), now.toSec(), now.toSec() - msg.stamp.toSec(),
            msg.seq, static_loss.loss, (double)static_loss.loss / (msg.seq - static_loss.start_data));
    }
    else {
        static_loss.start_flag = true;
        static_loss.last_data = static_loss.start_data = msg.seq;
        static_loss.loss = 0;
    }

}

void threadFunction(ros::NodeHandle& n)
{
    ros::Subscriber sub_msg = n.subscribe("/test/multi_thread", 1, handler_callback);
    // ros::spin();
    ros::Rate rate(100);
    while (ros::ok()) {
        ros::spinOnce();
        rate.sleep();
    }
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "test_topic");
    ros::NodeHandle n;

    std::thread myThread(threadFunction, std::ref(n));
    myThread.detach();

    ros::Publisher pub_msg = n.advertise<std_msgs::Header>("/test/multi_thread", 1);
    std_msgs::Header msg;
    uint32_t seq = 0;
    ros::Rate rate(10);
    while (ros::ok())
    {
        msg.seq = seq++;
        msg.stamp = ros::Time::now();
        pub_msg.publish(msg);

        rate.sleep();
    }
    ros::spin();

    return 0;
}
