add_library(
        ${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC

        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/world.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/world.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/assetManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/assetManager.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/object.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/object.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/core.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/core.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/entrypoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/entrypoint.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/actor.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/actor.cpp
)

target_include_directories(
    ${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
