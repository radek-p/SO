cmake_minimum_required(VERSION 3.0)
project(SO_lab2_assembly C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -fno-omit-frame-pointer")

# dodatkowy cel -- wykonanie komendy make dla źródeł
# celowo to make a nie CMake, bo inaczej CLion "zauważy"
# nasz kod i przestanie wyświetlać wynik dekompilacji
add_custom_target(
        object_files
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(
        SO_lab2_assembly
        main.c
        ex1_square.h
        ex2_mul_div.h
        ex3_passing_arguments.h
        ex4_passing_arguments2.h
        ex5_casts.h
        ex6.h
)

target_link_libraries(
        SO_lab2_assembly
        ${CMAKE_CURRENT_SOURCE_DIR}/ex1_square.o
        ${CMAKE_CURRENT_SOURCE_DIR}/ex2_mul_div.o
        ${CMAKE_CURRENT_SOURCE_DIR}/ex3_passing_arguments.o
        ${CMAKE_CURRENT_SOURCE_DIR}/ex4_passing_arguments2.o
        ${CMAKE_CURRENT_SOURCE_DIR}/ex5_casts.o
        ${CMAKE_CURRENT_SOURCE_DIR}/ex6.o
)

# wykonuj zdefiniowane wyżej polecenie make przed kompilacją SO_lab2_assembly
add_dependencies(SO_lab2_assembly object_files)
