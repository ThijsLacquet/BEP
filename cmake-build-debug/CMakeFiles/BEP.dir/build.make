# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/thijslaptop/Documents/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/thijslaptop/Documents/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thijslaptop/Documents/BEP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thijslaptop/Documents/BEP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BEP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BEP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BEP.dir/flags.make

CMakeFiles/BEP.dir/main.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BEP.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/main.cpp.o -c /home/thijslaptop/Documents/BEP/main.cpp

CMakeFiles/BEP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/main.cpp > CMakeFiles/BEP.dir/main.cpp.i

CMakeFiles/BEP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/main.cpp -o CMakeFiles/BEP.dir/main.cpp.s

CMakeFiles/BEP.dir/Network/TCPServer.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/Network/TCPServer.cpp.o: ../Network/TCPServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BEP.dir/Network/TCPServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/Network/TCPServer.cpp.o -c /home/thijslaptop/Documents/BEP/Network/TCPServer.cpp

CMakeFiles/BEP.dir/Network/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/Network/TCPServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/Network/TCPServer.cpp > CMakeFiles/BEP.dir/Network/TCPServer.cpp.i

CMakeFiles/BEP.dir/Network/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/Network/TCPServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/Network/TCPServer.cpp -o CMakeFiles/BEP.dir/Network/TCPServer.cpp.s

CMakeFiles/BEP.dir/Network/TCPClient.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/Network/TCPClient.cpp.o: ../Network/TCPClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BEP.dir/Network/TCPClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/Network/TCPClient.cpp.o -c /home/thijslaptop/Documents/BEP/Network/TCPClient.cpp

CMakeFiles/BEP.dir/Network/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/Network/TCPClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/Network/TCPClient.cpp > CMakeFiles/BEP.dir/Network/TCPClient.cpp.i

CMakeFiles/BEP.dir/Network/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/Network/TCPClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/Network/TCPClient.cpp -o CMakeFiles/BEP.dir/Network/TCPClient.cpp.s

CMakeFiles/BEP.dir/Network/UDP.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/Network/UDP.cpp.o: ../Network/UDP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BEP.dir/Network/UDP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/Network/UDP.cpp.o -c /home/thijslaptop/Documents/BEP/Network/UDP.cpp

CMakeFiles/BEP.dir/Network/UDP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/Network/UDP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/Network/UDP.cpp > CMakeFiles/BEP.dir/Network/UDP.cpp.i

CMakeFiles/BEP.dir/Network/UDP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/Network/UDP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/Network/UDP.cpp -o CMakeFiles/BEP.dir/Network/UDP.cpp.s

CMakeFiles/BEP.dir/Functions/FFT.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/Functions/FFT.cpp.o: ../Functions/FFT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/BEP.dir/Functions/FFT.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/Functions/FFT.cpp.o -c /home/thijslaptop/Documents/BEP/Functions/FFT.cpp

CMakeFiles/BEP.dir/Functions/FFT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/Functions/FFT.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/Functions/FFT.cpp > CMakeFiles/BEP.dir/Functions/FFT.cpp.i

CMakeFiles/BEP.dir/Functions/FFT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/Functions/FFT.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/Functions/FFT.cpp -o CMakeFiles/BEP.dir/Functions/FFT.cpp.s

CMakeFiles/BEP.dir/Functions/QAM.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/Functions/QAM.cpp.o: ../Functions/QAM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/BEP.dir/Functions/QAM.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/Functions/QAM.cpp.o -c /home/thijslaptop/Documents/BEP/Functions/QAM.cpp

CMakeFiles/BEP.dir/Functions/QAM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/Functions/QAM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/Functions/QAM.cpp > CMakeFiles/BEP.dir/Functions/QAM.cpp.i

CMakeFiles/BEP.dir/Functions/QAM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/Functions/QAM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/Functions/QAM.cpp -o CMakeFiles/BEP.dir/Functions/QAM.cpp.s

CMakeFiles/BEP.dir/Other/Counter.cpp.o: CMakeFiles/BEP.dir/flags.make
CMakeFiles/BEP.dir/Other/Counter.cpp.o: ../Other/Counter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/BEP.dir/Other/Counter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BEP.dir/Other/Counter.cpp.o -c /home/thijslaptop/Documents/BEP/Other/Counter.cpp

CMakeFiles/BEP.dir/Other/Counter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BEP.dir/Other/Counter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thijslaptop/Documents/BEP/Other/Counter.cpp > CMakeFiles/BEP.dir/Other/Counter.cpp.i

CMakeFiles/BEP.dir/Other/Counter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BEP.dir/Other/Counter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thijslaptop/Documents/BEP/Other/Counter.cpp -o CMakeFiles/BEP.dir/Other/Counter.cpp.s

# Object files for target BEP
BEP_OBJECTS = \
"CMakeFiles/BEP.dir/main.cpp.o" \
"CMakeFiles/BEP.dir/Network/TCPServer.cpp.o" \
"CMakeFiles/BEP.dir/Network/TCPClient.cpp.o" \
"CMakeFiles/BEP.dir/Network/UDP.cpp.o" \
"CMakeFiles/BEP.dir/Functions/FFT.cpp.o" \
"CMakeFiles/BEP.dir/Functions/QAM.cpp.o" \
"CMakeFiles/BEP.dir/Other/Counter.cpp.o"

# External object files for target BEP
BEP_EXTERNAL_OBJECTS =

BEP: CMakeFiles/BEP.dir/main.cpp.o
BEP: CMakeFiles/BEP.dir/Network/TCPServer.cpp.o
BEP: CMakeFiles/BEP.dir/Network/TCPClient.cpp.o
BEP: CMakeFiles/BEP.dir/Network/UDP.cpp.o
BEP: CMakeFiles/BEP.dir/Functions/FFT.cpp.o
BEP: CMakeFiles/BEP.dir/Functions/QAM.cpp.o
BEP: CMakeFiles/BEP.dir/Other/Counter.cpp.o
BEP: CMakeFiles/BEP.dir/build.make
BEP: CMakeFiles/BEP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable BEP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BEP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BEP.dir/build: BEP

.PHONY : CMakeFiles/BEP.dir/build

CMakeFiles/BEP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BEP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BEP.dir/clean

CMakeFiles/BEP.dir/depend:
	cd /home/thijslaptop/Documents/BEP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thijslaptop/Documents/BEP /home/thijslaptop/Documents/BEP /home/thijslaptop/Documents/BEP/cmake-build-debug /home/thijslaptop/Documents/BEP/cmake-build-debug /home/thijslaptop/Documents/BEP/cmake-build-debug/CMakeFiles/BEP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BEP.dir/depend

