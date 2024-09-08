cmake_minimum_required(VERSION 3.29)
project(Fractals)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_PREFIX_PATH "${SFML_LIBRARY_DIRECTORY}/lib/cmake/SFML")
set(SFML_DIR "${SFML_LIBRARY_DIRECTORY}/lib/cmake/SFML")

add_executable(${PROJECT_NAME}
        main.cpp
        include/Complex.h
        source/Complex.cpp
)

include_directories(
        include
)

find_package(SFML 2.6.1 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(${PROJECT_NAME}
        sfml-network
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
)
