# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\INSTALLATIONS\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\INSTALLATIONS\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Programing\Clion Projects\BMPtest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Programing\Clion Projects\BMPtest\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BMPtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BMPtest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BMPtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BMPtest.dir/flags.make

CMakeFiles/BMPtest.dir/main.c.obj: CMakeFiles/BMPtest.dir/flags.make
CMakeFiles/BMPtest.dir/main.c.obj: D:/Programing/Clion\ Projects/BMPtest/main.c
CMakeFiles/BMPtest.dir/main.c.obj: CMakeFiles/BMPtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Programing\Clion Projects\BMPtest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BMPtest.dir/main.c.obj"
	"D:\INSTALLATIONS\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BMPtest.dir/main.c.obj -MF CMakeFiles\BMPtest.dir\main.c.obj.d -o CMakeFiles\BMPtest.dir\main.c.obj -c "D:\Programing\Clion Projects\BMPtest\main.c"

CMakeFiles/BMPtest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BMPtest.dir/main.c.i"
	"D:\INSTALLATIONS\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Programing\Clion Projects\BMPtest\main.c" > CMakeFiles\BMPtest.dir\main.c.i

CMakeFiles/BMPtest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BMPtest.dir/main.c.s"
	"D:\INSTALLATIONS\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Programing\Clion Projects\BMPtest\main.c" -o CMakeFiles\BMPtest.dir\main.c.s

# Object files for target BMPtest
BMPtest_OBJECTS = \
"CMakeFiles/BMPtest.dir/main.c.obj"

# External object files for target BMPtest
BMPtest_EXTERNAL_OBJECTS =

BMPtest.exe: CMakeFiles/BMPtest.dir/main.c.obj
BMPtest.exe: CMakeFiles/BMPtest.dir/build.make
BMPtest.exe: CMakeFiles/BMPtest.dir/linkLibs.rsp
BMPtest.exe: CMakeFiles/BMPtest.dir/objects1.rsp
BMPtest.exe: CMakeFiles/BMPtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\Programing\Clion Projects\BMPtest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BMPtest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BMPtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BMPtest.dir/build: BMPtest.exe
.PHONY : CMakeFiles/BMPtest.dir/build

CMakeFiles/BMPtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BMPtest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BMPtest.dir/clean

CMakeFiles/BMPtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Programing\Clion Projects\BMPtest" "D:\Programing\Clion Projects\BMPtest" "D:\Programing\Clion Projects\BMPtest\cmake-build-debug" "D:\Programing\Clion Projects\BMPtest\cmake-build-debug" "D:\Programing\Clion Projects\BMPtest\cmake-build-debug\CMakeFiles\BMPtest.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/BMPtest.dir/depend

