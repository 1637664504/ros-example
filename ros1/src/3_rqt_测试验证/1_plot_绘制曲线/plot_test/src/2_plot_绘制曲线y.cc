#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/Float32.h>

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "plot_y");
    ros::NodeHandle n;
    ros::Publisher a_pub;
    a_pub = n.advertise<std_msgs::Float32>("/pose/y", 1);
    std_msgs::Float32 val;
    val.data = 0;
    int count = 0;

    while (ros::ok())
    {
        val.data = (count++)%2? 0.3 : 0.6;
        a_pub.publish(val);
        sleep(2);
        ros::spinOnce();
    }

    return 0;
}