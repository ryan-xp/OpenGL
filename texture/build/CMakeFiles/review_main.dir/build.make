# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/json/zxp/OpenGL/OpenGL/texture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/json/zxp/OpenGL/OpenGL/texture/build

# Include any dependencies generated for this target.
include CMakeFiles/review_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/review_main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/review_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/review_main.dir/flags.make

CMakeFiles/review_main.dir/main/texture_main.cpp.o: CMakeFiles/review_main.dir/flags.make
CMakeFiles/review_main.dir/main/texture_main.cpp.o: ../main/texture_main.cpp
CMakeFiles/review_main.dir/main/texture_main.cpp.o: CMakeFiles/review_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/json/zxp/OpenGL/OpenGL/texture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/review_main.dir/main/texture_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/review_main.dir/main/texture_main.cpp.o -MF CMakeFiles/review_main.dir/main/texture_main.cpp.o.d -o CMakeFiles/review_main.dir/main/texture_main.cpp.o -c /home/json/zxp/OpenGL/OpenGL/texture/main/texture_main.cpp

CMakeFiles/review_main.dir/main/texture_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/review_main.dir/main/texture_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/json/zxp/OpenGL/OpenGL/texture/main/texture_main.cpp > CMakeFiles/review_main.dir/main/texture_main.cpp.i

CMakeFiles/review_main.dir/main/texture_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/review_main.dir/main/texture_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/json/zxp/OpenGL/OpenGL/texture/main/texture_main.cpp -o CMakeFiles/review_main.dir/main/texture_main.cpp.s

CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o: CMakeFiles/review_main.dir/flags.make
CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o: ../src/GlslDealConfig.cpp
CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o: CMakeFiles/review_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/json/zxp/OpenGL/OpenGL/texture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o -MF CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o.d -o CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o -c /home/json/zxp/OpenGL/OpenGL/texture/src/GlslDealConfig.cpp

CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/json/zxp/OpenGL/OpenGL/texture/src/GlslDealConfig.cpp > CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.i

CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/json/zxp/OpenGL/OpenGL/texture/src/GlslDealConfig.cpp -o CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.s

# Object files for target review_main
review_main_OBJECTS = \
"CMakeFiles/review_main.dir/main/texture_main.cpp.o" \
"CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o"

# External object files for target review_main
review_main_EXTERNAL_OBJECTS =

review_main: CMakeFiles/review_main.dir/main/texture_main.cpp.o
review_main: CMakeFiles/review_main.dir/src/GlslDealConfig.cpp.o
review_main: CMakeFiles/review_main.dir/build.make
review_main: CMakeFiles/review_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/json/zxp/OpenGL/OpenGL/texture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable review_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/review_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/review_main.dir/build: review_main
.PHONY : CMakeFiles/review_main.dir/build

CMakeFiles/review_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/review_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/review_main.dir/clean

CMakeFiles/review_main.dir/depend:
	cd /home/json/zxp/OpenGL/OpenGL/texture/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/json/zxp/OpenGL/OpenGL/texture /home/json/zxp/OpenGL/OpenGL/texture /home/json/zxp/OpenGL/OpenGL/texture/build /home/json/zxp/OpenGL/OpenGL/texture/build /home/json/zxp/OpenGL/OpenGL/texture/build/CMakeFiles/review_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/review_main.dir/depend

