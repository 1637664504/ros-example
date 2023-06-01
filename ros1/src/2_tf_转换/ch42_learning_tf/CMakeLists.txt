cmake_minimum_required(VERSION 3.0.2)
project(ch42_learning_tf)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES 
 CATKIN_DEPENDS roscpp
 DEPENDS system_lib
)

include_directories(
  # include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
add_executable(turtle_tf_listener src/turtle_tf_listener.cpp)

target_link_libraries(turtle_tf_broadcaster
  ${catkin_LIBRARIES}
)

target_link_libraries(turtle_tf_listener
  ${catkin_LIBRARIES}
)