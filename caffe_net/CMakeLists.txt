cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CAFFE_DIR /home/zivlin/Desktop/caffe-master/install)
set(glog_DIR /usr/include/glog)
set(CAFFE_LIB_DIR ${CAFFE_DIR}/lib/x86_64-linux-gnu)
add_definitions(-DCPU_ONLY)

find_package(Caffe  REQUIRED)

set(SOURCE_FILES main.cpp)

set(PROJECT_NAME caffe_net)
project(${PROJECT_NAME})
add_executable(caffe_net ${SOURCE_FILES})
MESSAGE("--project name is " ${PROJECT_NAME})                           #print some massage for debug
link_directories(${CAFFE_LIB_DIR})

target_link_libraries(${PROJECT_NAME} caffe)
target_link_libraries(${PROJECT_NAME} glog)
target_link_libraries(${PROJECT_NAME} boost_system)

include_directories(${CAFFE_DIR}/include ${glog_DIR})
install(TARGETS caffe_net RUNTIME DESTINATION bin)
file(COPY ${CAFFE_LIB_DIR}/ DESTINATION ./ )                            #copy file from caffe/lib to current dir