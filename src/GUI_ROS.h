#include "ros/ros.h"
#include "std_msgs/String.h"

#ifndef GUI_ROS_H
#define GUI_ROS_H
void rosPublish(ros::Publisher output, std_msgs::String speech);
#endif
