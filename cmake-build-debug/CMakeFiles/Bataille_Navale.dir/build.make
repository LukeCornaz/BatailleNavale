# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "P:\ProjetsClion\Bataille Navale"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "P:\ProjetsClion\Bataille Navale\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bataille_Navale.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bataille_Navale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bataille_Navale.dir/flags.make

CMakeFiles/Bataille_Navale.dir/main.c.obj: CMakeFiles/Bataille_Navale.dir/flags.make
CMakeFiles/Bataille_Navale.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="P:\ProjetsClion\Bataille Navale\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Bataille_Navale.dir/main.c.obj"
	C:\MinGw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Bataille_Navale.dir\main.c.obj   -c "P:\ProjetsClion\Bataille Navale\main.c"

CMakeFiles/Bataille_Navale.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bataille_Navale.dir/main.c.i"
	C:\MinGw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "P:\ProjetsClion\Bataille Navale\main.c" > CMakeFiles\Bataille_Navale.dir\main.c.i

CMakeFiles/Bataille_Navale.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bataille_Navale.dir/main.c.s"
	C:\MinGw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "P:\ProjetsClion\Bataille Navale\main.c" -o CMakeFiles\Bataille_Navale.dir\main.c.s

# Object files for target Bataille_Navale
Bataille_Navale_OBJECTS = \
"CMakeFiles/Bataille_Navale.dir/main.c.obj"

# External object files for target Bataille_Navale
Bataille_Navale_EXTERNAL_OBJECTS =

Bataille_Navale.exe: CMakeFiles/Bataille_Navale.dir/main.c.obj
Bataille_Navale.exe: CMakeFiles/Bataille_Navale.dir/build.make
Bataille_Navale.exe: CMakeFiles/Bataille_Navale.dir/linklibs.rsp
Bataille_Navale.exe: CMakeFiles/Bataille_Navale.dir/objects1.rsp
Bataille_Navale.exe: CMakeFiles/Bataille_Navale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="P:\ProjetsClion\Bataille Navale\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Bataille_Navale.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Bataille_Navale.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bataille_Navale.dir/build: Bataille_Navale.exe

.PHONY : CMakeFiles/Bataille_Navale.dir/build

CMakeFiles/Bataille_Navale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Bataille_Navale.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Bataille_Navale.dir/clean

CMakeFiles/Bataille_Navale.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "P:\ProjetsClion\Bataille Navale" "P:\ProjetsClion\Bataille Navale" "P:\ProjetsClion\Bataille Navale\cmake-build-debug" "P:\ProjetsClion\Bataille Navale\cmake-build-debug" "P:\ProjetsClion\Bataille Navale\cmake-build-debug\CMakeFiles\Bataille_Navale.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Bataille_Navale.dir/depend

