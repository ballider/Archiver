cmake_minimum_required(VERSION 2.8)

project(zipper)

set(zipper_src main.cpp zipper.cpp AutoTest.cpp LZW.cpp)
set(zipper_hdr head.hpp zipper.hpp AutoTest.hpp)

add_executable(${PROJECT_NAME} ${zipper_src} ${zipper_hdr})