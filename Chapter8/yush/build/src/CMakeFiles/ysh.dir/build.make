# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/yux/Linux_pra/Chapter8/yush

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yux/Linux_pra/Chapter8/yush/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ysh.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ysh.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ysh.dir/flags.make

src/CMakeFiles/ysh.dir/yush1.o: src/CMakeFiles/ysh.dir/flags.make
src/CMakeFiles/ysh.dir/yush1.o: ../src/yush1.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yux/Linux_pra/Chapter8/yush/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/ysh.dir/yush1.o"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ysh.dir/yush1.o   -c /home/yux/Linux_pra/Chapter8/yush/src/yush1.c

src/CMakeFiles/ysh.dir/yush1.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ysh.dir/yush1.i"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/yux/Linux_pra/Chapter8/yush/src/yush1.c > CMakeFiles/ysh.dir/yush1.i

src/CMakeFiles/ysh.dir/yush1.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ysh.dir/yush1.s"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/yux/Linux_pra/Chapter8/yush/src/yush1.c -o CMakeFiles/ysh.dir/yush1.s

src/CMakeFiles/ysh.dir/yush1.o.requires:
.PHONY : src/CMakeFiles/ysh.dir/yush1.o.requires

src/CMakeFiles/ysh.dir/yush1.o.provides: src/CMakeFiles/ysh.dir/yush1.o.requires
	$(MAKE) -f src/CMakeFiles/ysh.dir/build.make src/CMakeFiles/ysh.dir/yush1.o.provides.build
.PHONY : src/CMakeFiles/ysh.dir/yush1.o.provides

src/CMakeFiles/ysh.dir/yush1.o.provides.build: src/CMakeFiles/ysh.dir/yush1.o

src/CMakeFiles/ysh.dir/execute.o: src/CMakeFiles/ysh.dir/flags.make
src/CMakeFiles/ysh.dir/execute.o: ../src/execute.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yux/Linux_pra/Chapter8/yush/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/ysh.dir/execute.o"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ysh.dir/execute.o   -c /home/yux/Linux_pra/Chapter8/yush/src/execute.c

src/CMakeFiles/ysh.dir/execute.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ysh.dir/execute.i"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/yux/Linux_pra/Chapter8/yush/src/execute.c > CMakeFiles/ysh.dir/execute.i

src/CMakeFiles/ysh.dir/execute.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ysh.dir/execute.s"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/yux/Linux_pra/Chapter8/yush/src/execute.c -o CMakeFiles/ysh.dir/execute.s

src/CMakeFiles/ysh.dir/execute.o.requires:
.PHONY : src/CMakeFiles/ysh.dir/execute.o.requires

src/CMakeFiles/ysh.dir/execute.o.provides: src/CMakeFiles/ysh.dir/execute.o.requires
	$(MAKE) -f src/CMakeFiles/ysh.dir/build.make src/CMakeFiles/ysh.dir/execute.o.provides.build
.PHONY : src/CMakeFiles/ysh.dir/execute.o.provides

src/CMakeFiles/ysh.dir/execute.o.provides.build: src/CMakeFiles/ysh.dir/execute.o

# Object files for target ysh
ysh_OBJECTS = \
"CMakeFiles/ysh.dir/yush1.o" \
"CMakeFiles/ysh.dir/execute.o"

# External object files for target ysh
ysh_EXTERNAL_OBJECTS =

src/ysh: src/CMakeFiles/ysh.dir/yush1.o
src/ysh: src/CMakeFiles/ysh.dir/execute.o
src/ysh: src/CMakeFiles/ysh.dir/build.make
src/ysh: src/CMakeFiles/ysh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ysh"
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ysh.dir/build: src/ysh
.PHONY : src/CMakeFiles/ysh.dir/build

src/CMakeFiles/ysh.dir/requires: src/CMakeFiles/ysh.dir/yush1.o.requires
src/CMakeFiles/ysh.dir/requires: src/CMakeFiles/ysh.dir/execute.o.requires
.PHONY : src/CMakeFiles/ysh.dir/requires

src/CMakeFiles/ysh.dir/clean:
	cd /home/yux/Linux_pra/Chapter8/yush/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ysh.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ysh.dir/clean

src/CMakeFiles/ysh.dir/depend:
	cd /home/yux/Linux_pra/Chapter8/yush/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yux/Linux_pra/Chapter8/yush /home/yux/Linux_pra/Chapter8/yush/src /home/yux/Linux_pra/Chapter8/yush/build /home/yux/Linux_pra/Chapter8/yush/build/src /home/yux/Linux_pra/Chapter8/yush/build/src/CMakeFiles/ysh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ysh.dir/depend

