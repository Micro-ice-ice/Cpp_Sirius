cmake_minimum_required(VERSION 3.0.0)
project(Polynom VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Polynom main.cpp "Polynom.h" "Quat.h" "Bernstein.h" "Complex.h") 
