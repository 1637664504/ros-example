// ROS include
#include <ros/ros.h>
#include <ros/console.h>

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "test1_param_get_set_node");
    ros::NodeHandle n("test1_param_get_set_node");
    setlocale(LC_CTYPE, "zh_CN.utf8");

    int param_rate;
    n.param<int>("rate", param_rate, 20);

    ros::Rate rate(param_rate);
    int idx = 1000;;
    while (ros::ok() && idx--)
    {
        n.param<int>("rate", param_rate, 10);
        // ROS_INFO("rate: %d", param_rate);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
