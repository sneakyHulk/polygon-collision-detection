cmake_minimum_required(VERSION 3.12)
project(polygon_collision_detection)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
add_executable(polygon_collision_detection src/main.cpp)
target_link_libraries(polygon_collision_detection sfml-graphics)

find_package(benchmark REQUIRED)
add_executable(benchmark src/benchmark.cpp)
target_link_libraries(benchmark benchmark::benchmark)

add_executable(line_strip_collision_detection src/line_strip.cpp)
target_link_libraries(line_strip_collision_detection sfml-graphics)