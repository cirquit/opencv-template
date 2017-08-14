# all library sources
set(SOURCES map.hpp)

# create library
add_library(${LIB_NAME} ${SOURCES})
target_link_libraries(${LIB_NAME}) #{OTHER SOURCES}
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# create exectuable 
add_executable(${EXEC_NAME} main.cpp)

# add exectuable dependencies
if (WITH_OPENCV_DEBUG)
  target_link_libraries(${EXEC_NAME} ${LIB_NAME} ${OpenCV_LIBS})
else()
  target_link_libraries(${EXEC_NAME} ${LIB_NAME})
endif()

# this creates a directory at the binary destination folder
# we have to create a new target, which is named "${EXEC_NAME}-create-dir" for that
add_custom_target(${EXEC_NAME}-create-image-directory ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGE_DIR})

# this copies the whole image directory to the binary destination
add_custom_target(${EXEC_NAME}-copy-images-to-binary-destination ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/images ${CMAKE_BINARY_DIR}/src/images)