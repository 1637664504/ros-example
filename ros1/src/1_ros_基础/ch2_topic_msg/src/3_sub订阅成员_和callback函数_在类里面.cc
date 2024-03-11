#include "ros/ros.h"
#include "std_msgs/Int8.h"
class subInt8
{
private:
    ros::NodeHandle &n;
    ros::Subscriber test_sub;

public:
    subInt8(ros::NodeHandle &_n)
        : n(_n)
    {
        ros_init();
    }

    void ros_init()
    {
        test_sub = n.subscribe("/test/sub_in_class", 2, &subInt8::callback_test, this);
    }

    void callback_test(const std_msgs::Int8::ConstPtr &msg)
    {
        ROS_INFO("test: [%d]", msg->data);
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    subInt8 s8(n);

    ros::spin();
    return 0;
}
