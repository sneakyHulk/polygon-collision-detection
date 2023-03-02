cmake_minimum_required(VERSION 3.12)
project(polygon_collision_detection)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
add_executable(polygon_collision_detection src/main.cpp)
target_link_libraries(polygon_collision_detection sfml-graphics)

find_package(benchmark REQUIRED)
add_executable(benchmark src/benchmark.cpp)
target_link_libraries(benchmark benchmark::benchmark)