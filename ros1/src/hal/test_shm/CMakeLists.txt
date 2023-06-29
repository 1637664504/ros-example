cmake_minimum_required(VERSION 3.0.2)
project(test_shm)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  shmCycleQueue
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_shm
#  CATKIN_DEPENDS roscpp shmCycleQueue
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/test.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

