#include "GUI_ROS.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

void rosPublish(ros::Publisher output, std_msgs::String speech){
  output.publish(speech);
  return;
}
