cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(Caffe_DIR /home/zivlin/Desktop/caffe-master/install/)
set(glog_DIR /usr/include/glog)
add_definitions(-DCPU_ONLY)

# include(/home/zivlin/Desktop/caffe-master/cmake/Modules/FindGlog.cmake)
# find_package(OpenCV REQUIRED) 
find_package(Caffe  REQUIRED)
# find_package(glog  REQUIRED)
# find_package(boost_system  REQUIRED)
# find_package(Cublas REQUIRED)

# find_path(Caffe_INCLUDE_DIRS NAMES caffe/caffe.hpp caffe/blob.hpp caffe/common.hpp caffe/net.hpp caffe/proto/caffe.pb.h caffe/util/io.hpp caffe/vision_layers.hpp
#     HINTS
#     ${Caffe_DIR}/include)
# find_path(CUDA_BIAS_DIRS NAMES cublas_v2.h)
# find_path(temp_path NAMES caffe/blob.hpp)
# find_library(Caffe_LIBRARIES NAMES caffe
#   HINTS
#  ${Caffe_DIR}/lib)
  
#message("--Caffe_INCLUDE_DIRS: " ${Caffe_INCLUDE_DIRS})
#message("--Caffe_LIBRARIES: " ${Caffe_LIBRARIES})

set(PROJECT_NAME caffe_test)            
set(SOURCE_FILES main.cpp)
project(${PROJECT_NAME})                                                #PROJECT_NAME
MESSAGE("--project name is " ${PROJECT_NAME})                           #print some massage for debug

add_executable(caffe_test ${SOURCE_FILES})
link_directories(${Caffe_DIR}/install/lib/x86_64-linux-gnu/)
target_link_libraries(${PROJECT_NAME} caffe)
target_link_libraries(${PROJECT_NAME} glog)
target_link_libraries(${PROJECT_NAME} boost_system)

include_directories(${Caffe_DIR}/include ${glog_DIR})
# set_property(TARGET *binary* PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)
# MESSAGE()
install(TARGETS caffe_test RUNTIME DESTINATION bin)