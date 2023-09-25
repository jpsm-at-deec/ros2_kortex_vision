
#include "vision.h"

extern "C" {
#include "gst/gst.h"
#include "gst/app/gstappsink.h"
}

//#include <ros/ros.h>
#include "rclcpp/rclcpp.hpp"
#include <signal.h>

Vision* g_vision = NULL;

void sigintHandler(int signal)
{
  if (g_vision)
  {
    g_vision->quit();
  }

  //ros::shutdown();
  rclcpp::shutdown();
}

int main(int argc, char** argv)
{
  //ros::init(argc, argv, "kinova_vision", ros::init_options::NoSigintHandler);
  //ros::NodeHandle nh, nh_private("~");

  rclcpp::init(argc, argv);
  auto nh = rclcpp::Node::make_shared("ros_kortex_vision");
  auto nh_private = rclcpp::Node::make_shared("~");

  // Override the default ros sigint handler.
  signal(SIGINT, sigintHandler);

  g_vision = new Vision(nh, nh_private);
  g_vision->run();

  delete g_vision;

  return 0;
}
