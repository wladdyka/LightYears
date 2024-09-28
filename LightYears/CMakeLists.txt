add_executable(
    ${LIGHT_YEARS_GAME_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp
)

target_include_directories(
        ${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# linking dependencies
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)