# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/drowlia/code_save/ds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drowlia/code_save/ds/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ds.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ds.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ds.dir/flags.make

CMakeFiles/ds.dir/main.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/main.cpp.o: /home/drowlia/code_save/ds/main.cpp
CMakeFiles/ds.dir/main.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ds.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/main.cpp.o -MF CMakeFiles/ds.dir/main.cpp.o.d -o CMakeFiles/ds.dir/main.cpp.o -c /home/drowlia/code_save/ds/main.cpp

CMakeFiles/ds.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/main.cpp > CMakeFiles/ds.dir/main.cpp.i

CMakeFiles/ds.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/main.cpp -o CMakeFiles/ds.dir/main.cpp.s

CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o: /home/drowlia/code_save/ds/LinkedList/LinkedListTest.cpp
CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o -MF CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o.d -o CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o -c /home/drowlia/code_save/ds/LinkedList/LinkedListTest.cpp

CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/LinkedList/LinkedListTest.cpp > CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.i

CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/LinkedList/LinkedListTest.cpp -o CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.s

CMakeFiles/ds.dir/Stack/StackTest.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/Stack/StackTest.cpp.o: /home/drowlia/code_save/ds/Stack/StackTest.cpp
CMakeFiles/ds.dir/Stack/StackTest.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ds.dir/Stack/StackTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/Stack/StackTest.cpp.o -MF CMakeFiles/ds.dir/Stack/StackTest.cpp.o.d -o CMakeFiles/ds.dir/Stack/StackTest.cpp.o -c /home/drowlia/code_save/ds/Stack/StackTest.cpp

CMakeFiles/ds.dir/Stack/StackTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/Stack/StackTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/Stack/StackTest.cpp > CMakeFiles/ds.dir/Stack/StackTest.cpp.i

CMakeFiles/ds.dir/Stack/StackTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/Stack/StackTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/Stack/StackTest.cpp -o CMakeFiles/ds.dir/Stack/StackTest.cpp.s

CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o: /home/drowlia/code_save/ds/SeqTable/SeqTableTest.cpp
CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o -MF CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o.d -o CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o -c /home/drowlia/code_save/ds/SeqTable/SeqTableTest.cpp

CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/SeqTable/SeqTableTest.cpp > CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.i

CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/SeqTable/SeqTableTest.cpp -o CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.s

CMakeFiles/ds.dir/Queue/QueueTest.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/Queue/QueueTest.cpp.o: /home/drowlia/code_save/ds/Queue/QueueTest.cpp
CMakeFiles/ds.dir/Queue/QueueTest.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ds.dir/Queue/QueueTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/Queue/QueueTest.cpp.o -MF CMakeFiles/ds.dir/Queue/QueueTest.cpp.o.d -o CMakeFiles/ds.dir/Queue/QueueTest.cpp.o -c /home/drowlia/code_save/ds/Queue/QueueTest.cpp

CMakeFiles/ds.dir/Queue/QueueTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/Queue/QueueTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/Queue/QueueTest.cpp > CMakeFiles/ds.dir/Queue/QueueTest.cpp.i

CMakeFiles/ds.dir/Queue/QueueTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/Queue/QueueTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/Queue/QueueTest.cpp -o CMakeFiles/ds.dir/Queue/QueueTest.cpp.s

CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o: /home/drowlia/code_save/ds/Tree/BinaryTreeTest.cpp
CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o -MF CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o.d -o CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o -c /home/drowlia/code_save/ds/Tree/BinaryTreeTest.cpp

CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/Tree/BinaryTreeTest.cpp > CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.i

CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/Tree/BinaryTreeTest.cpp -o CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.s

CMakeFiles/ds.dir/Graph/GraphTest.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/Graph/GraphTest.cpp.o: /home/drowlia/code_save/ds/Graph/GraphTest.cpp
CMakeFiles/ds.dir/Graph/GraphTest.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ds.dir/Graph/GraphTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/Graph/GraphTest.cpp.o -MF CMakeFiles/ds.dir/Graph/GraphTest.cpp.o.d -o CMakeFiles/ds.dir/Graph/GraphTest.cpp.o -c /home/drowlia/code_save/ds/Graph/GraphTest.cpp

CMakeFiles/ds.dir/Graph/GraphTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/Graph/GraphTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drowlia/code_save/ds/Graph/GraphTest.cpp > CMakeFiles/ds.dir/Graph/GraphTest.cpp.i

CMakeFiles/ds.dir/Graph/GraphTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/Graph/GraphTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drowlia/code_save/ds/Graph/GraphTest.cpp -o CMakeFiles/ds.dir/Graph/GraphTest.cpp.s

# Object files for target ds
ds_OBJECTS = \
"CMakeFiles/ds.dir/main.cpp.o" \
"CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o" \
"CMakeFiles/ds.dir/Stack/StackTest.cpp.o" \
"CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o" \
"CMakeFiles/ds.dir/Queue/QueueTest.cpp.o" \
"CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o" \
"CMakeFiles/ds.dir/Graph/GraphTest.cpp.o"

# External object files for target ds
ds_EXTERNAL_OBJECTS =

ds: CMakeFiles/ds.dir/main.cpp.o
ds: CMakeFiles/ds.dir/LinkedList/LinkedListTest.cpp.o
ds: CMakeFiles/ds.dir/Stack/StackTest.cpp.o
ds: CMakeFiles/ds.dir/SeqTable/SeqTableTest.cpp.o
ds: CMakeFiles/ds.dir/Queue/QueueTest.cpp.o
ds: CMakeFiles/ds.dir/Tree/BinaryTreeTest.cpp.o
ds: CMakeFiles/ds.dir/Graph/GraphTest.cpp.o
ds: CMakeFiles/ds.dir/build.make
ds: /usr/lib/x86_64-linux-gnu/libgtest.a
ds: CMakeFiles/ds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ds.dir/build: ds
.PHONY : CMakeFiles/ds.dir/build

CMakeFiles/ds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ds.dir/clean

CMakeFiles/ds.dir/depend:
	cd /home/drowlia/code_save/ds/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/drowlia/code_save/ds /home/drowlia/code_save/ds /home/drowlia/code_save/ds/cmake-build-debug /home/drowlia/code_save/ds/cmake-build-debug /home/drowlia/code_save/ds/cmake-build-debug/CMakeFiles/ds.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ds.dir/depend

