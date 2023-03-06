cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME test01)
##set(PROJECT_NAME usehello)
#project(${PROJECT_NAME})
#
#message("${PROJECT_NAME}")
#set(CMAKE_CXX_STANDARD 11)
#
#if (${PROJECT_NAME} STREQUAL "hello")
#    #引入头文件
#    include_directories(./shared)
#include_directories("E:/installApp/java/include/win32")
#    #引入库文件
#    link_directories(./lib)
#    add_executable(${PROJECT_NAME} main.cpp)
#    #链接库到可执行文件
#    target_link_libraries(${PROJECT_NAME}  -lusehello)
#
#else ()
#    # 设置 库文件的默认输出路径
##    set (LIBRARY_OUTPUT_PATH ../lib)
    #add_library(${PROJECT_NAME} SHARED ./shared/fourOperations.h ./shared/fourOperations.cpp)
set(CMAKE_SHARED_LIBRARY_PREFIX "")
#add_library(${PROJECT_NAME} SHARED dll_DataManger.h dll_DataManger.cpp)
add_library(${PROJECT_NAME} SHARED ./shared/fourOperations.h ./shared/fourOperations.cpp)
##    set_target_properties(${PROJECT_NAME} PROPERTIES
##            OUTPUT_NAME ${PROJECT_NAME}
##            PREFIX lib
##            SUFFIX dll
##            VERSION ${CMAKE_PROJECT_VERSION}
##            SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR})
#endif()
#add_executable(${PROJECT_NAME} test.cpp ../camera/main.cpp ../camera/metadata.cpp ../camera/metadata.h "../camera/camera app/camera.cpp" "../camera/camera app/camera.h")









