cmake_minimum_required(VERSION 3.4)
project(_ CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(mainapp mainapp.cpp "src/Point.h" "src/Point.cpp" "src/f.h" "src/f.cpp" "src/Edge.h" "src/Edge.cpp")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/gtest)

target_link_libraries(${BINARY} Polygon)
