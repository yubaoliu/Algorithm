project (Algorithm-C)

include_directories("${PROJECT_SOURCE_DIR}/sources")

add_definitions(-g -Wall)

#add_executable(InsertSort-c InsertSrot-c.c)
add_executable(InsertSort-c ./sources/InsertSort-c.c)
