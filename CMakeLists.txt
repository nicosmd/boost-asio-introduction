cmake_minimum_required(VERSION 4.0)
project(asio_presentation)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(asio_presentation main.cpp)

target_link_libraries(asio_presentation boost::boost)

add_executable(loop_example loop_example.cpp)

target_link_libraries(loop_example boost::boost)
