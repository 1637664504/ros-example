#include <ros/ros.h>
#include <std_msgs/Int8.h>

class pubInt8
{
private:
    ros::Publisher chatter_pub;//set the publisher as a member
    ros::NodeHandle& n;

public:
    pubInt8(ros::NodeHandle& nh)
    :n(nh)
    {
        chatter_pub = n.advertise<std_msgs::Int8>("/test/sub_in_class", 2); //assign value to chatter_pub
    };

    void pub()
    {
        int count = 0;
        ros::Rate loop_rate(10);
        while (ros::ok())
        {
            std_msgs::Int8 msg;
            msg.data = count;// msg.data = ss.str();          
            ROS_INFO("%d", msg.data);
            chatter_pub.publish(msg);
            ros::spinOnce();
            loop_rate.sleep();
            ++count;
        }
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    pubInt8 p8(n);
    p8.pub();
    return 0;
}
