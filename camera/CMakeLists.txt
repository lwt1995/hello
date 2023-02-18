cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME camera.qcom)

#set(CMAKE_SHARED_LIBRARY_PREFIX "")
#add_library(${PROJECT_NAME} SHARED main.cpp)
AUX_SOURCE_DIRECTORY(./utils/head UTILS_HEAD)
AUX_SOURCE_DIRECTORY(./utils/src UTILS_SRC)
add_executable(main main.cpp ${UTILS_HEAD} ${UTILS_SRC})