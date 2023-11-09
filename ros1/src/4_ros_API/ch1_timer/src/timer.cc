#include <stdint.h>

#include <ros/ros.h>
#include <ros/console.h>
using namespace std;

void timerCallback(const ros::TimerEvent& msg)
{
    // cout << msg << endl;
    ros::Time recv_time = ros::Time::now();
    cout << recv_time << endl;
}

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test_topic");
    ros::NodeHandle n;
    ros::Timer timer = n.createTimer(ros::Duration(5), timerCallback);

    ros::spin();
    return 0;
}
