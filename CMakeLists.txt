cmake_minimum_required(VERSION 3.10)

project(demo)
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/package")
#set(PACKVERSION 2.0.0.1)
######################################################################
#全局编译标志
######################################################################

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

######################################################################
#全局链接和包含
######################################################################

include_directories(${PROJECT_SOURCE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/3rdParty/tensorflow/r1.8/libs/Linux/cuda10)
link_directories(${CMAKE_SOURCE_DIR}/det_lip/lip/opencv/lib)
#link_directories(${CMAKE_SOURCE_DIR}/eureka/lib ${CMAKE_SOURCE_DIR}/librdkafka/lib)
set(OPENCV_INCLUDE ${CMAKE_SOURCE_DIR}/det_lip/lip/opencv/include/)
file(GLOB DET_LIP ${CMAKE_SOURCE_DIR}/det_lip/lip/libs/linux/gpu/lib*.so)
file(GLOB OPENCV_LIBRARY ${CMAKE_SOURCE_DIR}/det_lip/lip/opencv/lib/libopencv_*.so)
file(GLOB BOOST_LIBRARY /usr/lib/x86_64-linux-gnu/libboost_*.so)
#################################################################L#####
#全局编译输出指定
######################################################################

#IF(CMAKE_BUILD_TYPE MATCHES Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)
#ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${BUILD_TYPE})


######################################################################
#子工程目录
######################################################################

add_subdirectory(base/third_party/dynamic_annotations)
add_subdirectory(base/third_party/symbolize)
add_subdirectory(base/third_party/xdg_mime)
add_subdirectory(base/third_party/libevent)
add_subdirectory(third_party)
add_subdirectory(base)
#add_subdirectory(JSON)
add_subdirectory(base/i18n)

#add_subdirectory(url)
#add_subdirectory(eureka)
#add_subdirectory(grpc)
#add_subdirectory(breakpad)
######################################################################
#编译对象
######################################################################

add_executable(demo
                main.cpp
                det_lip/face_boxes.cpp
                det_lip/face_boxes.hpp
                det_lip/face_landmark.cpp
                det_lip/face_landmark.hpp
                det_lip/face_mode.cpp
                det_lip/face_mode.hpp
                det_lip/gen_mouth.cpp 
                det_lip/gen_mouth.hpp 
                det_lip/gen_proj_bfm.cpp 
                det_lip/gen_proj_bfm.hpp 
                det_lip/request.cpp 
                det_lip/request.hpp 
                det_lip/stage.cpp 
                det_lip/stage.hpp 
                det_lip/factory.cpp 
                det_lip/factory.hpp
            )

target_include_directories(demo PRIVATE
        ${PROJECT_SOURCE_DIR}/det_lip/lip/include
        ${PROJECT_SOURCE_DIR}/det_lip
        ${OPENCV_INCLUDE}
        )

target_link_libraries(demo
        ${OPENCV_LIBRARY}
        ${DET_LIP}
        ${BOOST_LIBRARY}
        pthread
        base
        ${CMAKE_SOURCE_DIR}/JSON/lib/libjsoncpp.so
        ${CMAKE_SOURCE_DIR}/JSON/lib/libjsoncpp.a
        #${CMAKE_SOURCE_DIR}/third_party/modp_b64/libmodp_b64.a
        )
######################################################################
#程序发布设置
######################################################################

install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ DESTINATION bin)
install(DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/ DESTINATION lib)
#install(DIRECTORY 3rdParty/tensorflow/r1.8/libs/Linux/cpu DESTINATION lib)
install(DIRECTORY 3rdParty/tensorflow/r1.8/libs/Linux/cuda10/ DESTINATION lib
        FILES_MATCHING PATTERN "*.so")
install(DIRECTORY det_lip/lip/opencv/lib/ DESTINATION lib
        FILES_MATCHING PATTERN "*.so")
install(DIRECTORY det_lip/lip/libs/linux/gpu/ DESTINATION lib
        FILES_MATCHING PATTERN "*.so")
install(DIRECTORY ai_model DESTINATION bin)
install(DIRECTORY config/ DESTINATION bin/config)
install(FILES scripts/requirments.sh DESTINATION .)
install(FILES scripts/install.sh DESTINATION .)
install(FILES scripts/ReadMe.txt DESTINATION .)
