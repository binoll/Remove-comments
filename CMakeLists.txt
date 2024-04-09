cmake_minimum_required(VERSION 3.26)
project(remove C)

set(CMAKE_C_STANDARD 23)

add_executable(remove main.c src/parse.c)

