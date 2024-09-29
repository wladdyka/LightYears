cmake_minimum_required(VERSION 3.29)

project(
        LightYearsEngine
        VERSION 1.0.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXTENSIONS OFF)

# dependencies
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

# custom variables
set(LIGHT_YEARS_ENGINE_TARGET_NAME LightYearsEngine)
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

add_subdirectory(LightYearsEngine)
add_subdirectory(LightYearsGame)

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
