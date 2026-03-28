cmake_minimum_required(VERSION 3.24)

project(Soru VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(SORU_BUILD_TESTS "Build Soru unit tests" OFF)

add_library(Soru INTERFACE)
add_library(Soru::Soru ALIAS Soru)

target_compile_features(Soru INTERFACE cxx_std_20)
add_subdirectory(src)

if(SORU_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
