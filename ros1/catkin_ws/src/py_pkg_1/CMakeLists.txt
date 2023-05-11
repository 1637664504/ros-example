cmake_minimum_required(VERSION 3.0.2)
project(py_pkg_1)
 
find_package(catkin REQUIRED COMPONENTS
  rospy
)
 
catkin_python_setup()
 
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES py_pkg_1
#  CATKIN_DEPENDS rospy
#  DEPENDS system_lib
)
 
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)