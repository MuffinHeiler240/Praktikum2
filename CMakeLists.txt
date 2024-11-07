cmake_minimum_required(VERSION 3.29)
project(Praktikum2 C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_COMPILE_WARNING_AS_ERROR  true)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -pedantic -pedantic-errors -ansi")

add_executable(Praktikum2 main.c
        zahlen.h
        zahlen.c)
