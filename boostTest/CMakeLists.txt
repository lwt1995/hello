cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME boostTest)

#include_directories(D:\\install\\boost_1_80_0\\boost_1_80_0\\compile\\include\\boost-1_80)
#link_directories(D:\\install\\boost_1_80_0\\boost_1_80_0\\compile\\lib)

#set(Boost_USE_STATIC_LIBS ON)
include("cm.cmake")
#set(BOOST_ROOT E:/data/boost_1_81_0)
#set(BOOST_INCLUDEDIR ${BOOST_ROOT})
#set(BOOST_LIBRARYDIR ${BOOST_ROOT}/stage/lib)
find_package(BOOST 1.80.0 COMPONENTS  thread system)
if(Boost_FOUND)
   message(Boost_INCLUDE_DIRS " ${Boost_INCLUDE_DIRS}")
   message(Boost_LIBRARY_DIRS " ${Boost_LIBRARY_DIRS}")
   include_directories(${Boost_INCLUDE_DIRS})
   link_directories(${Boost_LIBRARY_DIRS})
   link_libraries(ws2_32)
   message(Boost_LIBRARIES " ${Boost_LIBRARIES}")
   add_executable(${PROJECT_NAME} main.cpp)
endif()
#set(CMAKE_SHARED_LIBRARY_PREFIX "")
#add_library(${PROJECT_NAME} SHARED main.cpp)


target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
