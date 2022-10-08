cmake_minimum_required(VERSION 3.16)
project(Sorting_Algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(
    sorting_algorithms
    print_array.c
    print_list.c
    0-bubble_sort.c
    1-insertion_sort_list.c
    2-selection_sort.c
    3-quick_sort.c
    100-shell_sort.c
    100-main.c
)