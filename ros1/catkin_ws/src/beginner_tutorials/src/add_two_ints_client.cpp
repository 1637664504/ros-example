#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc,argv,"add_two_ints_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
    beginner_tutorials::AddTwoInts srv;
    long int x,y;
    while(1){
        cout << "please input x,y" << endl;
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "不合法的输入，请重新输入: ";
            continue;
        }
        srv.request.a = x;
        srv.request.b = y;
        if(client.call(srv))
        {
            ROS_INFO("sum=%ld",(long int)srv.response.sum);
        }else{
            ROS_ERROR("Fail to call service add_two_ints");
            return -1;
        }
    }


    return 0;
}