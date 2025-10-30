cmake_minimum_required(VERSION 4.0)
project(asio_presentation)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(asio_presentation main.cpp)

target_link_libraries(asio_presentation boost::boost)

add_executable(loop_example loop_example.cpp)

target_link_libraries(loop_example boost::boost)

add_executable(timer_loop_example timer_loop_example.cpp)

target_link_libraries(timer_loop_example boost::boost)

add_executable(concurrent_loops concurrent_loops.cpp)

target_link_libraries(concurrent_loops boost::boost)

add_executable(multithreading multithreading.cpp)

target_link_libraries(multithreading boost::boost)

add_executable(multithreading_with_strand multithreading_with_strand.cpp)

target_link_libraries(multithreading_with_strand boost::boost)

add_executable(channel_example channel_example.cpp)

target_link_libraries(channel_example boost::boost)

add_executable(channel_coroutine_example channel_coroutine_example.cpp)

target_link_libraries(channel_coroutine_example boost::boost)
