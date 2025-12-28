
cmake_minimum_required(VERSION 3.15)
project(SmartTaskManager CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SRC "src/*.cpp")
add_executable(smt ${SRC})
