#include "ros/ros.h"
#include "std_msgs/String.h"

static int count=0;
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I listen %d: %s",count,msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter",1000,chatterCallback);
    ros::spin();
    return 0;
}