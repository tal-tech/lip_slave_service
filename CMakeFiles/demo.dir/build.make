# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chenhongwei/workspace/clone/lip_slave_service/fir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chenhongwei/workspace/clone/lip_slave_service/fir

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/main.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/main.cpp.o: main.cpp
CMakeFiles/demo.dir/main.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/main.cpp.o -MF CMakeFiles/demo.dir/main.cpp.o.d -o CMakeFiles/demo.dir/main.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/main.cpp

CMakeFiles/demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/main.cpp > CMakeFiles/demo.dir/main.cpp.i

CMakeFiles/demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/main.cpp -o CMakeFiles/demo.dir/main.cpp.s

CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o: det_lip/face_boxes.cpp
CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o -MF CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o.d -o CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_boxes.cpp

CMakeFiles/demo.dir/det_lip/face_boxes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/face_boxes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_boxes.cpp > CMakeFiles/demo.dir/det_lip/face_boxes.cpp.i

CMakeFiles/demo.dir/det_lip/face_boxes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/face_boxes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_boxes.cpp -o CMakeFiles/demo.dir/det_lip/face_boxes.cpp.s

CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o: det_lip/face_landmark.cpp
CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o -MF CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o.d -o CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_landmark.cpp

CMakeFiles/demo.dir/det_lip/face_landmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/face_landmark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_landmark.cpp > CMakeFiles/demo.dir/det_lip/face_landmark.cpp.i

CMakeFiles/demo.dir/det_lip/face_landmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/face_landmark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_landmark.cpp -o CMakeFiles/demo.dir/det_lip/face_landmark.cpp.s

CMakeFiles/demo.dir/det_lip/face_mode.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/face_mode.cpp.o: det_lip/face_mode.cpp
CMakeFiles/demo.dir/det_lip/face_mode.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/demo.dir/det_lip/face_mode.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/face_mode.cpp.o -MF CMakeFiles/demo.dir/det_lip/face_mode.cpp.o.d -o CMakeFiles/demo.dir/det_lip/face_mode.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_mode.cpp

CMakeFiles/demo.dir/det_lip/face_mode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/face_mode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_mode.cpp > CMakeFiles/demo.dir/det_lip/face_mode.cpp.i

CMakeFiles/demo.dir/det_lip/face_mode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/face_mode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/face_mode.cpp -o CMakeFiles/demo.dir/det_lip/face_mode.cpp.s

CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o: det_lip/gen_mouth.cpp
CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o -MF CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o.d -o CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/gen_mouth.cpp

CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/gen_mouth.cpp > CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.i

CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/gen_mouth.cpp -o CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.s

CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o: det_lip/gen_proj_bfm.cpp
CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o -MF CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o.d -o CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/gen_proj_bfm.cpp

CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/gen_proj_bfm.cpp > CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.i

CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/gen_proj_bfm.cpp -o CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.s

CMakeFiles/demo.dir/det_lip/request.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/request.cpp.o: det_lip/request.cpp
CMakeFiles/demo.dir/det_lip/request.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/demo.dir/det_lip/request.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/request.cpp.o -MF CMakeFiles/demo.dir/det_lip/request.cpp.o.d -o CMakeFiles/demo.dir/det_lip/request.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/request.cpp

CMakeFiles/demo.dir/det_lip/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/request.cpp > CMakeFiles/demo.dir/det_lip/request.cpp.i

CMakeFiles/demo.dir/det_lip/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/request.cpp -o CMakeFiles/demo.dir/det_lip/request.cpp.s

CMakeFiles/demo.dir/det_lip/stage.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/stage.cpp.o: det_lip/stage.cpp
CMakeFiles/demo.dir/det_lip/stage.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/demo.dir/det_lip/stage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/stage.cpp.o -MF CMakeFiles/demo.dir/det_lip/stage.cpp.o.d -o CMakeFiles/demo.dir/det_lip/stage.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/stage.cpp

CMakeFiles/demo.dir/det_lip/stage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/stage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/stage.cpp > CMakeFiles/demo.dir/det_lip/stage.cpp.i

CMakeFiles/demo.dir/det_lip/stage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/stage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/stage.cpp -o CMakeFiles/demo.dir/det_lip/stage.cpp.s

CMakeFiles/demo.dir/det_lip/factory.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/det_lip/factory.cpp.o: det_lip/factory.cpp
CMakeFiles/demo.dir/det_lip/factory.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/demo.dir/det_lip/factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/det_lip/factory.cpp.o -MF CMakeFiles/demo.dir/det_lip/factory.cpp.o.d -o CMakeFiles/demo.dir/det_lip/factory.cpp.o -c /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/factory.cpp

CMakeFiles/demo.dir/det_lip/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/det_lip/factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/factory.cpp > CMakeFiles/demo.dir/det_lip/factory.cpp.i

CMakeFiles/demo.dir/det_lip/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/det_lip/factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenhongwei/workspace/clone/lip_slave_service/fir/det_lip/factory.cpp -o CMakeFiles/demo.dir/det_lip/factory.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/main.cpp.o" \
"CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o" \
"CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o" \
"CMakeFiles/demo.dir/det_lip/face_mode.cpp.o" \
"CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o" \
"CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o" \
"CMakeFiles/demo.dir/det_lip/request.cpp.o" \
"CMakeFiles/demo.dir/det_lip/stage.cpp.o" \
"CMakeFiles/demo.dir/det_lip/factory.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

bin/debug/demo: CMakeFiles/demo.dir/main.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/face_boxes.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/face_landmark.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/face_mode.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/gen_mouth.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/gen_proj_bfm.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/request.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/stage.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/det_lip/factory.cpp.o
bin/debug/demo: CMakeFiles/demo.dir/build.make
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_calib3d.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_core.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_dnn.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_features2d.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_flann.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_highgui.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_imgcodecs.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_imgproc.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_ml.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_objdetect.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_photo.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_stitching.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_video.so
bin/debug/demo: det_lip/lip/opencv/lib/libopencv_videoio.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libboost_filesystem.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libboost_log.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libboost_log_setup.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libboost_regex.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libboost_system.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libboost_thread.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libdet_face_boxes.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libdet_landmark_tf.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libgen_deep_speech.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libgen_face_mode.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libgen_mouth_gan.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libgen_phone_params.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libgen_proj_bfm.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libgen_voc_params.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libhiredis.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libopencv_core.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libopencv_imgcodecs.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libopencv_imgproc.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libphonealignment.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libprotobuf-lite.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libpxnn.so
bin/debug/demo: det_lip/lip/libs/linux/gpu/libtensorflow_cc.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_container.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_context.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_coroutine.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_fiber.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_graph.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_graph_parallel.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_locale.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_log.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_math_c99.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_math_c99f.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_math_c99l.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_math_tr1.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_math_tr1f.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_math_tr1l.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_mpi.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_mpi_python-py27.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_mpi_python-py36.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_mpi_python.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_mpi_python3-py36.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_mpi_python3.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_numpy-py27.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_numpy.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_numpy3-py36.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_numpy3.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_prg_exec_monitor.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_python-py27.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_python-py36.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_python.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_python3-py36.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_python3.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_random.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_regex.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_signals.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_stacktrace_addr2line.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_stacktrace_backtrace.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_stacktrace_basic.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_stacktrace_noop.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_thread.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_timer.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_type_erasure.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_wave.so
bin/debug/demo: /usr/lib/x86_64-linux-gnu/libboost_wserialization.so
bin/debug/demo: base/libbase.a
bin/debug/demo: JSON/lib/libjsoncpp.so
bin/debug/demo: JSON/lib/libjsoncpp.a
bin/debug/demo: base/libbase_static.a
bin/debug/demo: base/third_party/dynamic_annotations/libdynamic_annotations.a
bin/debug/demo: base/third_party/symbolize/libsymbolize.a
bin/debug/demo: third_party/modp_b64/libmodp_b64.a
bin/debug/demo: base/third_party/xdg_mime/libxdg_mime.a
bin/debug/demo: base/third_party/libevent/libevent.a
bin/debug/demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable bin/debug/demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: bin/debug/demo
.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/chenhongwei/workspace/clone/lip_slave_service/fir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenhongwei/workspace/clone/lip_slave_service/fir /home/chenhongwei/workspace/clone/lip_slave_service/fir /home/chenhongwei/workspace/clone/lip_slave_service/fir /home/chenhongwei/workspace/clone/lip_slave_service/fir /home/chenhongwei/workspace/clone/lip_slave_service/fir/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend

