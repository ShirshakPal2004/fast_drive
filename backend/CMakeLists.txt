cmake_minimum_required(VERSION 3.20)

project(FastDriveBackend
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ========================================
# Dependencies
# ========================================

include(FetchContent)

# Crow
FetchContent_Declare(
    Crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG v1.2.1
)

FetchContent_MakeAvailable(Crow)

# MySQL Connector/C++
find_package(mysql-concpp REQUIRED)


# ========================================
# Backend
# ========================================

add_executable(fast_drive

    src/main.cpp

    src/controllers/HealthController.cpp
    src/controllers/DatabaseHealthController.cpp

    src/routes/HealthRoutes.cpp
    src/routes/DatabaseHealthRoutes.cpp

    src/utils/DatabaseConnection.cpp
    src/utils/Environment.cpp
)


# ========================================
# Include directories
# ========================================

target_include_directories(fast_drive
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# ========================================
# Libraries
# ========================================

target_link_libraries(fast_drive

    PRIVATE

        Crow::Crow

        mysql::concpp
)
