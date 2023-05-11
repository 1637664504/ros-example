cmake_minimum_required(VERSION 3.0.2)
project(use_lib)

find_package(catkin REQUIRED COMPONENTS
  lib_test
  roscpp
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES use_lib
 CATKIN_DEPENDS lib_test roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
