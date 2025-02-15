cmake_minimum_required(VERSION 3.27)
project(COP_Cplusplus_FirstLaboratory)

set(CMAKE_CXX_STANDARD 23)

add_executable(COP_Cplusplus_FirstLaboratory main.cpp
        include/Matrix.h
        src/Matrix.cpp
        src/IMatrix.cpp)
