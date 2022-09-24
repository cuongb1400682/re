cmake_minimum_required(VERSION 3.23)
project(re C)

set(CMAKE_C_STANDARD 99)

include_directories(
        .
)

add_executable(
        re
        main.c
        collections/linked_list.c collections/linked_list.h
        collections/hash_set.c collections/hash_set.h
        regex/transition_graph.c regex/transition_graph.h
        regex/regex.c regex/regex.h
        tests/collections/linked_list.c tests/collections/linked_list.h
        collections/linked_node.c collections/linked_node.h tests/collections/linked_node.c tests/collections/linked_node.h check/check.c check/check.h)
