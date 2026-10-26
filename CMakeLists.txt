cmake_minimum_required(VERSION 3.14)
project(conways_game_life_v0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# SFML 2.6 (package libsfml-dev for Debian/Ubuntu)
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(conways_game_life_v0 
    main.cpp 
    grid.cpp
) 

target_compile_options(conways_game_life_v0 PRIVATE -Wall -Wextra)

target_link_libraries(conways_game_life_v0 PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    
)