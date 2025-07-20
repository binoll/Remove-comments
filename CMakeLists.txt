cmake_minimum_required(VERSION 3.00)
project(comment_remover C)

set(CMAKE_C_STANDARD 11)

add_executable(comment_remover src/main.c src/parse.c)

