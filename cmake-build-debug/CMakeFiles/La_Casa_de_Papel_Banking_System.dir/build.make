# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/home/abdullah/Downloads/JetBrains CLion 2020.2 Linux64/CLion-2020.2_DownLoadLy.iR/clion-2020.2/bin/cmake/linux/bin/cmake"

# The command to remove a file.
RM = "/home/abdullah/Downloads/JetBrains CLion 2020.2 Linux64/CLion-2020.2_DownLoadLy.iR/clion-2020.2/bin/cmake/linux/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/La_Casa_de_Papel_Banking_System.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/La_Casa_de_Papel_Banking_System.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/La_Casa_de_Papel_Banking_System.dir/flags.make

CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.o: CMakeFiles/La_Casa_de_Papel_Banking_System.dir/flags.make
CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.o -c "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/main.cpp"

CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/main.cpp" > CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.i

CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/main.cpp" -o CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.s

# Object files for target La_Casa_de_Papel_Banking_System
La_Casa_de_Papel_Banking_System_OBJECTS = \
"CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.o"

# External object files for target La_Casa_de_Papel_Banking_System
La_Casa_de_Papel_Banking_System_EXTERNAL_OBJECTS =

La_Casa_de_Papel_Banking_System: CMakeFiles/La_Casa_de_Papel_Banking_System.dir/main.cpp.o
La_Casa_de_Papel_Banking_System: CMakeFiles/La_Casa_de_Papel_Banking_System.dir/build.make
La_Casa_de_Papel_Banking_System: CMakeFiles/La_Casa_de_Papel_Banking_System.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable La_Casa_de_Papel_Banking_System"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/La_Casa_de_Papel_Banking_System.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/La_Casa_de_Papel_Banking_System.dir/build: La_Casa_de_Papel_Banking_System

.PHONY : CMakeFiles/La_Casa_de_Papel_Banking_System.dir/build

CMakeFiles/La_Casa_de_Papel_Banking_System.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/La_Casa_de_Papel_Banking_System.dir/cmake_clean.cmake
.PHONY : CMakeFiles/La_Casa_de_Papel_Banking_System.dir/clean

CMakeFiles/La_Casa_de_Papel_Banking_System.dir/depend:
	cd "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System" "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System" "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug" "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug" "/home/abdullah/Innopolis-MS-Rob-Semester-1/OOP & SW Architecture/Assignments/La-Casa-de-Papel-Banking-System/cmake-build-debug/CMakeFiles/La_Casa_de_Papel_Banking_System.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/La_Casa_de_Papel_Banking_System.dir/depend

