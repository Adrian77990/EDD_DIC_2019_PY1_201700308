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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documentos\Programacion\C++\Music++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documentos\Programacion\C++\Music++\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Music__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Music__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Music__.dir/flags.make

CMakeFiles/Music__.dir/main.cpp.obj: CMakeFiles/Music__.dir/flags.make
CMakeFiles/Music__.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documentos\Programacion\C++\Music++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Music__.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Music__.dir\main.cpp.obj -c D:\Documentos\Programacion\C++\Music++\main.cpp

CMakeFiles/Music__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Music__.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documentos\Programacion\C++\Music++\main.cpp > CMakeFiles\Music__.dir\main.cpp.i

CMakeFiles/Music__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Music__.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documentos\Programacion\C++\Music++\main.cpp -o CMakeFiles\Music__.dir\main.cpp.s

CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.obj: CMakeFiles/Music__.dir/flags.make
CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.obj: ../EDD/ArbolBinario/NodoBinario.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documentos\Programacion\C++\Music++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Music__.dir\EDD\ArbolBinario\NodoBinario.cpp.obj -c D:\Documentos\Programacion\C++\Music++\EDD\ArbolBinario\NodoBinario.cpp

CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documentos\Programacion\C++\Music++\EDD\ArbolBinario\NodoBinario.cpp > CMakeFiles\Music__.dir\EDD\ArbolBinario\NodoBinario.cpp.i

CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documentos\Programacion\C++\Music++\EDD\ArbolBinario\NodoBinario.cpp -o CMakeFiles\Music__.dir\EDD\ArbolBinario\NodoBinario.cpp.s

# Object files for target Music__
Music___OBJECTS = \
"CMakeFiles/Music__.dir/main.cpp.obj" \
"CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.obj"

# External object files for target Music__
Music___EXTERNAL_OBJECTS =

Music__.exe: CMakeFiles/Music__.dir/main.cpp.obj
Music__.exe: CMakeFiles/Music__.dir/EDD/ArbolBinario/NodoBinario.cpp.obj
Music__.exe: CMakeFiles/Music__.dir/build.make
Music__.exe: CMakeFiles/Music__.dir/linklibs.rsp
Music__.exe: CMakeFiles/Music__.dir/objects1.rsp
Music__.exe: CMakeFiles/Music__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documentos\Programacion\C++\Music++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Music__.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Music__.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Music__.dir/build: Music__.exe

.PHONY : CMakeFiles/Music__.dir/build

CMakeFiles/Music__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Music__.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Music__.dir/clean

CMakeFiles/Music__.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documentos\Programacion\C++\Music++ D:\Documentos\Programacion\C++\Music++ D:\Documentos\Programacion\C++\Music++\cmake-build-debug D:\Documentos\Programacion\C++\Music++\cmake-build-debug D:\Documentos\Programacion\C++\Music++\cmake-build-debug\CMakeFiles\Music__.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Music__.dir/depend

