# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/prajjawal12/Desktop/go_quant_assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/prajjawal12/Desktop/go_quant_assignment/build

# Include any dependencies generated for this target.
include CMakeFiles/WebSocketClientExecutable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WebSocketClientExecutable.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WebSocketClientExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WebSocketClientExecutable.dir/flags.make

CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o: CMakeFiles/WebSocketClientExecutable.dir/flags.make
CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o: /home/prajjawal12/Desktop/go_quant_assignment/src/WebSocketClient.cpp
CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o: CMakeFiles/WebSocketClientExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/prajjawal12/Desktop/go_quant_assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o -MF CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o.d -o CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o -c /home/prajjawal12/Desktop/go_quant_assignment/src/WebSocketClient.cpp

CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/prajjawal12/Desktop/go_quant_assignment/src/WebSocketClient.cpp > CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.i

CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/prajjawal12/Desktop/go_quant_assignment/src/WebSocketClient.cpp -o CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.s

# Object files for target WebSocketClientExecutable
WebSocketClientExecutable_OBJECTS = \
"CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o"

# External object files for target WebSocketClientExecutable
WebSocketClientExecutable_EXTERNAL_OBJECTS =

WebSocketClientExecutable: CMakeFiles/WebSocketClientExecutable.dir/src/WebSocketClient.cpp.o
WebSocketClientExecutable: CMakeFiles/WebSocketClientExecutable.dir/build.make
WebSocketClientExecutable: /usr/lib/x86_64-linux-gnu/libcurl.so
WebSocketClientExecutable: /usr/lib/x86_64-linux-gnu/libssl.so
WebSocketClientExecutable: /usr/lib/x86_64-linux-gnu/libcrypto.so
WebSocketClientExecutable: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.83.0
WebSocketClientExecutable: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.83.0
WebSocketClientExecutable: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.83.0
WebSocketClientExecutable: CMakeFiles/WebSocketClientExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/prajjawal12/Desktop/go_quant_assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WebSocketClientExecutable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WebSocketClientExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WebSocketClientExecutable.dir/build: WebSocketClientExecutable
.PHONY : CMakeFiles/WebSocketClientExecutable.dir/build

CMakeFiles/WebSocketClientExecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WebSocketClientExecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WebSocketClientExecutable.dir/clean

CMakeFiles/WebSocketClientExecutable.dir/depend:
	cd /home/prajjawal12/Desktop/go_quant_assignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/prajjawal12/Desktop/go_quant_assignment /home/prajjawal12/Desktop/go_quant_assignment /home/prajjawal12/Desktop/go_quant_assignment/build /home/prajjawal12/Desktop/go_quant_assignment/build /home/prajjawal12/Desktop/go_quant_assignment/build/CMakeFiles/WebSocketClientExecutable.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WebSocketClientExecutable.dir/depend
