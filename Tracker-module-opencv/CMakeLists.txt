cmake_minimum_required(VERSION 3.15)
project(Tracker_module_opencv)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Tracker_module_opencv main.cpp)
target_link_libraries(Tracker_module_opencv ${OpenCV_LIBS})
