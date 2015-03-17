cmake_minimum_required(VERSION 2.8)

project(LSD-demo)

set(CMAKE_CXX_FLAGS_RELEASE)
find_package(OpenCV REQUIRED)
add_executable(LSD-demo lsd-demo.cpp lsd.c)
target_link_libraries(LSD-demo ${OpenCV_LIBS})
