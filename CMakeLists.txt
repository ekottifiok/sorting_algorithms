cmake_minimum_required(VERSION 3.16)
project(Sorting_Algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(
    sorting_algorithms
    print_array.c
    print_list.c
    check_for_sort.c
    0-bubble_sort.c
    1-insertion_sort_list.c
    1-main.c
    2-selection_sort.c
    3-quick_sort.c
    1-main.c
)