cmake_minimum_required (VERSION 2.8.11)

# executable 
add_executable(test_undirected_graph test_undirected_graph.cpp)
target_link_libraries(test_undirected_graph ${PROJECT_NAME})
