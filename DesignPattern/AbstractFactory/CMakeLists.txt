cmake_minimum_required(VERSION 3.0.0)
project(abstractFactory VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11) # Try C++11

# add all .cpp and .h files
file(GLOB SOURCE_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB SOURCE_H_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(abstractFactory ${SOURCE_H_FILES} ${SOURCE_CPP_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
