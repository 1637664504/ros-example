cmake_minimum_required(VERSION 3.0.2)
project(shmCycleQueue)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES shmCycleQueue
 CATKIN_DEPENDS roscpp
 DEPENDS system_lib
)

include_directories(
  include/shmCycleQueue
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/test.cpp)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
