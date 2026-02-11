cmake_minimum_required(VERSION 3.28)

project(SpaceDefenderCpp LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(SFML)

# add_executable(SpaceDefenderCpp src/main.cpp)

# Źródła
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp" "src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(SpaceDefenderCpp
    SFML::System
    SFML::Window
    SFML::Graphics
)

if (WIN32)
    add_custom_command(TARGET SpaceDefenderCpp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:SpaceDefenderCpp>
            $<TARGET_FILE_DIR:SpaceDefenderCpp>
        COMMAND_EXPAND_LISTS
    )
endif()

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
    )
endif()
