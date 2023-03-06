cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME threadPoolTest)

add_executable(${PROJECT_NAME} main.cpp ../threadPoolFactory/threadpool.hpp)