cmake_minimum_required(VERSION 3.16)

project(my_WC VERSION 1.0)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

#target_link_libraries(${PROJECT_NAME} stdc++fs)

link_libraries(stdc++fs)

add_executable(${PROJECT_NAME} my_WC.cpp)

add_library(dirClass DirectoryInfo.cpp)

target_link_libraries(${PROJECT_NAME} dirClass)



