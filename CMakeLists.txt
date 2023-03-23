cmake_minimum_required(VERSION 3.25)

project(mockfish
  VERSION 1.0
  DESCRIPTION "My chess library"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

