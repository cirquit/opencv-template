# define all tests here
set(TESTS simple_test.cpp)

add_executable(${TEST_NAME} catch.h main.cpp ${TESTS})

# add all used libraries
if (WITH_OPENCV_DEBUG)
  target_link_libraries(${TEST_NAME} ${LIB_NAME} ${OpenCV_LIBS})
else()
  target_link_libraries(${TEST_NAME} ${LIB_NAME})
endif()

