# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam/projects/tydzien07/zad01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/projects/tydzien07/zad01/build

# Include any dependencies generated for this target.
include CMakeFiles/zad01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zad01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zad01.dir/flags.make

CMakeFiles/zad01.dir/zad01.cpp.o: CMakeFiles/zad01.dir/flags.make
CMakeFiles/zad01.dir/zad01.cpp.o: ../zad01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/projects/tydzien07/zad01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zad01.dir/zad01.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zad01.dir/zad01.cpp.o -c /home/adam/projects/tydzien07/zad01/zad01.cpp

CMakeFiles/zad01.dir/zad01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad01.dir/zad01.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/projects/tydzien07/zad01/zad01.cpp > CMakeFiles/zad01.dir/zad01.cpp.i

CMakeFiles/zad01.dir/zad01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad01.dir/zad01.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/projects/tydzien07/zad01/zad01.cpp -o CMakeFiles/zad01.dir/zad01.cpp.s

CMakeFiles/zad01.dir/Graph.cpp.o: CMakeFiles/zad01.dir/flags.make
CMakeFiles/zad01.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/projects/tydzien07/zad01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zad01.dir/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zad01.dir/Graph.cpp.o -c /home/adam/projects/tydzien07/zad01/Graph.cpp

CMakeFiles/zad01.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad01.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/projects/tydzien07/zad01/Graph.cpp > CMakeFiles/zad01.dir/Graph.cpp.i

CMakeFiles/zad01.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad01.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/projects/tydzien07/zad01/Graph.cpp -o CMakeFiles/zad01.dir/Graph.cpp.s

CMakeFiles/zad01.dir/GUI.cpp.o: CMakeFiles/zad01.dir/flags.make
CMakeFiles/zad01.dir/GUI.cpp.o: ../GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/projects/tydzien07/zad01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zad01.dir/GUI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zad01.dir/GUI.cpp.o -c /home/adam/projects/tydzien07/zad01/GUI.cpp

CMakeFiles/zad01.dir/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad01.dir/GUI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/projects/tydzien07/zad01/GUI.cpp > CMakeFiles/zad01.dir/GUI.cpp.i

CMakeFiles/zad01.dir/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad01.dir/GUI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/projects/tydzien07/zad01/GUI.cpp -o CMakeFiles/zad01.dir/GUI.cpp.s

CMakeFiles/zad01.dir/Simple_window.cpp.o: CMakeFiles/zad01.dir/flags.make
CMakeFiles/zad01.dir/Simple_window.cpp.o: ../Simple_window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/projects/tydzien07/zad01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zad01.dir/Simple_window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zad01.dir/Simple_window.cpp.o -c /home/adam/projects/tydzien07/zad01/Simple_window.cpp

CMakeFiles/zad01.dir/Simple_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad01.dir/Simple_window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/projects/tydzien07/zad01/Simple_window.cpp > CMakeFiles/zad01.dir/Simple_window.cpp.i

CMakeFiles/zad01.dir/Simple_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad01.dir/Simple_window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/projects/tydzien07/zad01/Simple_window.cpp -o CMakeFiles/zad01.dir/Simple_window.cpp.s

CMakeFiles/zad01.dir/Window.cpp.o: CMakeFiles/zad01.dir/flags.make
CMakeFiles/zad01.dir/Window.cpp.o: ../Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/projects/tydzien07/zad01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zad01.dir/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zad01.dir/Window.cpp.o -c /home/adam/projects/tydzien07/zad01/Window.cpp

CMakeFiles/zad01.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad01.dir/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/projects/tydzien07/zad01/Window.cpp > CMakeFiles/zad01.dir/Window.cpp.i

CMakeFiles/zad01.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad01.dir/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/projects/tydzien07/zad01/Window.cpp -o CMakeFiles/zad01.dir/Window.cpp.s

# Object files for target zad01
zad01_OBJECTS = \
"CMakeFiles/zad01.dir/zad01.cpp.o" \
"CMakeFiles/zad01.dir/Graph.cpp.o" \
"CMakeFiles/zad01.dir/GUI.cpp.o" \
"CMakeFiles/zad01.dir/Simple_window.cpp.o" \
"CMakeFiles/zad01.dir/Window.cpp.o"

# External object files for target zad01
zad01_EXTERNAL_OBJECTS =

zad01: CMakeFiles/zad01.dir/zad01.cpp.o
zad01: CMakeFiles/zad01.dir/Graph.cpp.o
zad01: CMakeFiles/zad01.dir/GUI.cpp.o
zad01: CMakeFiles/zad01.dir/Simple_window.cpp.o
zad01: CMakeFiles/zad01.dir/Window.cpp.o
zad01: CMakeFiles/zad01.dir/build.make
zad01: CMakeFiles/zad01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam/projects/tydzien07/zad01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable zad01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zad01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zad01.dir/build: zad01

.PHONY : CMakeFiles/zad01.dir/build

CMakeFiles/zad01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zad01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zad01.dir/clean

CMakeFiles/zad01.dir/depend:
	cd /home/adam/projects/tydzien07/zad01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/projects/tydzien07/zad01 /home/adam/projects/tydzien07/zad01 /home/adam/projects/tydzien07/zad01/build /home/adam/projects/tydzien07/zad01/build /home/adam/projects/tydzien07/zad01/build/CMakeFiles/zad01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zad01.dir/depend

