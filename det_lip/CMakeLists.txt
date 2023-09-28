cmake_minimum_required(VERSION 3.5)
project(det_lip)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -fPIC ")
#set(CUDA_cublas_device_LIBRARY "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v10.0\\lib\\x64")

if (WIN32)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
else()
  SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")
  SET(CMAKE_CXX_FLAGS "-fPIC -Bsymbolic -fvisibility=hidden")
  SET(CMAKE_C_FLAGS "-fPIC -Bsymbolic -fvisibility=hidden")
endif()

#########################################################################################
function(detect_boost)

  if (WIN32)
    set(HAVE_BOOST TRUE)
    set(BOOST_INCLUDE ${PROJECT_SOURCE_DIR}/../3rdParty/boost/boost_1_66_0/include)
    file(GLOB BOOST_LIBRARY ${PROJECT_SOURCE_DIR}/../3rdParty/boost/boost_1_66_0/lib/x64/*mt-x64-1_66.lib)
  else()
    set(HAVE_BOOST TRUE)
    set(BOOST_INCLUDE /usr/include/)
    file(GLOB BOOST_LIBRARY /usr/lib/x86_64-linux-gnu/libboost*.so)
  endif()

  if (HAVE_BOOST)
    message(STATUS "Found Boost: found (include: ${BOOST_INCLUDE}, library: ${BOOST_LIBRARY})")
    set(HAVE_BOOST ${HAVE_BOOST} PARENT_SCOPE)
    set(BOOST_INCLUDE ${BOOST_INCLUDE} PARENT_SCOPE)
    set(BOOST_LIBRARY ${BOOST_LIBRARY} PARENT_SCOPE)
  endif()
endfunction()


#########################################################################################
function(detect_opencv)

  if (WIN32)
    set(HAVE_OPENCV TRUE)
	  set(OPENCV_INCLUDE ${PROJECT_SOURCE_DIR}/../../3rdParty/opencv/3.1.0/include)
    file(GLOB OPENCV_LIBRARY ${PROJECT_SOURCE_DIR}/../../3rdParty/opencv/3.1.0/lib/x64/v140/Release/*.lib)
  else()
    set(HAVE_OPENCV TRUE)
    set(OPENCV_INCLUDE /usr/local/include/opencv4)
    file(GLOB OPENCV_LIBRARY /usr/local/lib/libopencv_*.so)
  endif()

  if (HAVE_OPENCV)
    message(STATUS "Found Opencv: found (include: ${OPENCV_INCLUDE}, library: ${OPENCV_LIBRARY})")
    set(HAVE_OPENCV ${HAVE_OPENCV}  PARENT_SCOPE )
    set(OPENCV_INCLUDE ${OPENCV_INCLUDE} PARENT_SCOPE)
    set(OPENCV_LIBRARY ${OPENCV_LIBRARY} PARENT_SCOPE)
  endif()

endfunction()

###########################################################################################
function(detect_lip_generator)

  if (WIN32)
    set(HAVE_LIP_GENERATOR TRUE)
    set(LIP_GENERATOR_INCLUDE ${PROJECT_SOURCE_DIR}../../ )
    file(GLOB LIP_GENERATOR_LIBRARY ${PROJECT_SOURCE_DIR}/../libs/linux/gpu )
  else()
    set(HAVE_LIP_GENERATOR TRUE)
    set(LIP_GENERATOR_INCLUDE  ${PROJECT_SOURCE_DIR}/lip/include/)
    file(GLOB LIP_GENERATOR_LIBRARY ${PROJECT_SOURCE_DIR}/lip/libs/linux/gpu/lib*.so )
  endif()

  if (HAVE_LIP_GENERATOR)
    message(STATUS "Found LIP_GENERATOR: found (include: ${LIP_GENERATOR_INCLUDE}, library: ${LIP_GENERATOR_LIBRARY})")
    set(HAVE_LIP_GENERATOR ${HAVE_LIP_GENERATOR}  PARENT_SCOPE )
    set(LIP_GENERATOR_INCLUDE ${LIP_GENERATOR_INCLUDE} PARENT_SCOPE)
    set(LIP_GENERATOR_LIBRARY ${LIP_GENERATOR_LIBRARY} PARENT_SCOPE)
  endif()

endfunction()

###########################################################################################

function(detect_all)
  detect_boost()
  if (HAVE_BOOST)
    list(APPEND PROJECT_INCLUDE ${BOOST_INCLUDE})
    list(APPEND PROJECT_LIBRARY ${BOOST_LIBRARY})
  endif()

  detect_opencv()
  if (HAVE_OPENCV)
    list(APPEND PROJECT_INCLUDE ${OPENCV_INCLUDE})
    list(APPEND PROJECT_LIBRARY ${OPENCV_LIBRARY})
  endif()

  detect_lip_generator()
  if (HAVE_LIP_GENERATOR)
    list(APPEND PROJECT_INCLUDE ${LIP_GENERATOR_INCLUDE})
    list(APPEND PROJECT_LIBRARY ${LIP_GENERATOR_LIBRARY})
  endif()
  
  list(REMOVE_DUPLICATES PROJECT_INCLUDE)
  list(REMOVE_DUPLICATES PROJECT_LIBRARY)

  set(PROJECT_INCLUDE ${PROJECT_INCLUDE} PARENT_SCOPE)
  set(PROJECT_LIBRARY ${PROJECT_LIBRARY} PARENT_SCOPE)

endfunction()


detect_all()
include_directories(${PROJECT_INCLUDE})
message(STATUS ${PROJECT_INCLUDE})
message(STATUS ${PROJECT_LIBRARY})
# link_directories(${PROJECT_BINARY_DIR}/lib)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if (WIN32)
  list(APPEND CUDA_NVCC_FLAGS " -Xcompiler \"/wd 4819\"")
  list(APPEND CUDA_NVCC_FLAGS " -Xcompiler \"/MD\"")
  add_definitions(-DNO_STRICT)
  # add_definitions(-DBOOST_ALL_DYN_LINK)  #only for dynamic library
  add_definitions(-DDLL_EXPORTS)
  add_definitions(-DCOMPILER_MSVC)
  add_definitions(-DNOMINMAX)
else()
  list(APPEND CUDA_NVCC_FLAGS "-std=c++11 -Xcompiler -Wno-deprecated")
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif()

add_library(det_lip face_boxes.cpp face_landmark.cpp face_mode.cpp gen_mouth.cpp gen_proj_bfm.cpp stage.cpp request.cpp factory.cpp)
target_link_libraries(det_lip ${PROJECT_LIBRARY} -ldl -lpthread)
