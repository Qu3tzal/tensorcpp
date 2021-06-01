cmake_minimum_required(VERSION 3.16)
project(tensor)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})
add_executable(tensor main.cpp tensor/Memory.cpp tensor/Index.cpp tensor/IndexEngine.cpp tensor/TensorShape.cpp)