cmake_minimum_required(VERSION 3.00)
project(remove C)

set(CMAKE_C_STANDARD 11)

add_executable(remove main.c src/parse.c)

