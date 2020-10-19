cmake_minimum_required(VERSION 3.15)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_executable(singly_linked_list data_structures/linked_lists/singly_linked_list.cc)
add_executable(doubly_linked_list data_structures/linked_lists/doubly_linked_list.cc)
add_executable(circularly_linked_list data_structures/linked_lists/circularly_linked_list.cc)

add_executable(stack data_structures/stacks/stack.cc)

add_executable(queue data_structures/queues/queue.cc)
add_executable(max_priority_queue data_structures/queues/max_priority_queue.cc)
add_executable(min_priority_queue data_structures/queues/min_priority_queue.cc)

add_executable(max_heap data_structures/heaps/max_heap.cc)
add_executable(min_heap data_structures/heaps/min_heap.cc)

add_executable(binary_tree data_structures/trees/binary_tree.cc)
add_executable(binary_search_tree data_structures/trees/binary_search_tree.cc)

add_executable(hash_table_separate_chaining data_structures/hashing/hash_table_separate_chaining.cc)

add_executable(insertion_sort sorting/insertion_sort.cc)
add_executable(bubble_sort sorting/bubble_sort.cc)
add_executable(merge_sort sorting/merge_sort.cc)
add_executable(heap_sort sorting/heap_sort.cc)
add_executable(quick_sort sorting/quick_sort.cc)
add_executable(counting_sort sorting/counting_sort.cc)
add_executable(radix_sort sorting/radix_sort.cc)
add_executable(bucket_sort sorting/bucket_sort.cc)

add_executable(linear_search searching/linear_search.cc)
add_executable(binary_search searching/binary_search.cc)

add_executable(fibonacci mathematics/fibonacci.cc)
add_executable(factorial mathematics/factorial.cc)

add_executable(maximum_subarray divide_conquer/maximum_subarray.cc)

add_executable(knight_tour backtracking/knight_tour.cc)
