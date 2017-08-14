set(PROJECT_NAME OpenCVTemplate)
set(EXEC_NAME opencv-exec)
set(LIB_NAME opencvexample)
set(TEST_NAME opencv-test)

# image directory name (used in the src/CMakeLists.txt)
set(IMAGE_DIR images)

project (${PROJECT_NAME})
cmake_minimum_required (VERSION 3.5.1)

# set compiler flags
set (CMAKE_CXX_COMPILER=gcc)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g") #-pthread -Wall -Wextra -Werror -Wfatal-errors -pedantic -g")

# OpenCV Flag
if (WITH_OPENCV_DEBUG)
  MESSAGE(STATUS "OpenCV enabled")
  add_definitions(-DOPENCV_DEBUG)
  find_package( OpenCV REQUIRED )
else()
  MESSAGE(STATUS "OpenCV disabled. To enable it, use -DWITH_OPENCV_DEBUG=ON")
endif()

# add the code
add_subdirectory(src)
add_subdirectory(test)
