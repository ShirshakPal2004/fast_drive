cmake_minimum_required(VERSION 3.20)

project(FastDriveBackend
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    Crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG v1.2.1
)

FetchContent_MakeAvailable(Crow)

add_executable(fast_drive
    src/main.cpp
    src/controllers/HealthController.cpp
    src/routes/HealthRoutes.cpp
)

target_include_directories(fast_drive
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(fast_drive
    PRIVATE
        Crow::Crow
)
