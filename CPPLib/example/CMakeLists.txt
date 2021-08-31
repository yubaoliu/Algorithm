cmake_minimum_required (VERSION 2.8.11)

# executable 
add_executable(test_undirected_graph test_undirected_graph.cpp)
target_link_libraries(test_undirected_graph ${PROJECT_NAME})

add_executable(test_fabonacci test_fabonacci.cpp)
target_link_libraries(test_fabonacci ${PROJECT_NAME})

add_executable(test_wheterSumIsS test_wheterSumIsS.cpp)
target_link_libraries(test_wheterSumIsS ${PROJECT_NAME})

