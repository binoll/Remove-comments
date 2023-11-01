cmake_minimum_required(VERSION 3.26)
project(remcom C)

set(CMAKE_C_STANDARD 23)

add_executable(prog main.c src/parse.c)

