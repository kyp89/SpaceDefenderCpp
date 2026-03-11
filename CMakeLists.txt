cmake_minimum_required(VERSION 3.28)

project(SpaceDefenderCpp LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

# ================= SFML =================
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

# ================= Assets Manager =================
FetchContent_Declare(
    ASSET_MANAGER
    GIT_REPOSITORY https://github.com/kyp89/assets-manager.git
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(ASSET_MANAGER)

FetchContent_GetProperties(ASSET_MANAGER)

# ================= Game Common =================
FetchContent_Declare(
    GAME_COMMON
    GIT_REPOSITORY https://github.com/kyp89/game-common.git
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GAME_COMMON)

FetchContent_GetProperties(GAME_COMMON)

# ================= Sources =================
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# ================= AssetsManager INTERFACE =================


# ================= Link libraries =================
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        GameCommon
        AssetsManager
        SFML::System
        SFML::Window
        SFML::Graphics
)

# ================= Windows DLL copy =================
if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMAND_EXPAND_LISTS
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
    )
endif()
