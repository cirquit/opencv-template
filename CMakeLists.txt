set(PROJECT_NAME OpenCVTemplate)
set(EXEC_NAME opencv-exec)
set(LIB_NAME opencvexample)
set(TEST_NAME opencv-test)

# image directory name (used in the src/CMakeLists.txt)
set(IMAGE_DIR images)

project (${PROJECT_NAME})
cmake_minimum_required (VERSION 3.5.1)

## this flag is used to set the compiler flags and should be used in the code
## with #if DEBUG_MODE <code> #else <code> #endif OR the debug print macro
OPTION(DEBUG_MODE "Enables the DEBUG messages and -O0 flags" 1)

# set compiler flags
set (CMAKE_CXX_COMPILER=gcc)

## Compile as C++14
add_compile_options(-std=c++14)

# Compile differently if DEBUG_MODE is active
if(DEBUG_MODE)
    message("DEBUG_MODE is ON - no optimizations enabled")
    add_definitions(-DDEBUG_MODE=1)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -pthread -Wall -Wextra -Wfatal-errors -pedantic -g -fPIC")
else()
    message("DEBUG_MODE is OFF - O2 optimizations enabled")
    add_definitions(-DDEBUG_MODE=0)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -pthread -Wall -Wextra -Werror -Wfatal-errors -pedantic -fPIC")
endif()

# OpenCV Flag
if (WITH_OPENCV_DEBUG)
  MESSAGE(STATUS "OpenCV enabled")
  add_definitions(-DOPENCV_DEBUG=1)
  find_package( OpenCV REQUIRED )
else()
  add_definitions(-DOPENCV_DEBUG=0)
  MESSAGE(STATUS "OpenCV disabled. To enable it, use -DWITH_OPENCV_DEBUG=ON")
endif()

# add the code
add_subdirectory(src)
add_subdirectory(test)
