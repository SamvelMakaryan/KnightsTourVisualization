cmake_minimum_required(VERSION 3.0)

project(KnightsTour)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    src/main.cpp
	src/solver.cpp
)

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
)

