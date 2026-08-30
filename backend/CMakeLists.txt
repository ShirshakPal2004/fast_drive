cmake_minimum_required(VERSION 3.20)

project(FastDriveBackend
    VERSION 1.0
    LANGUAGES CXX
)

# ========================================
# C++ Configuration
# ========================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# ========================================
# Dependencies
# ========================================

find_package(Crow CONFIG REQUIRED)
find_package(mysql-concpp CONFIG REQUIRED)
find_package(argon2 CONFIG REQUIRED)


# ========================================
# Source Files
# ========================================

add_executable(fast_drive

    src/main.cpp

    # Controllers
    src/controllers/HealthController.cpp
    src/controllers/DatabaseHealthController.cpp

    # Routes
    src/routes/HealthRoutes.cpp
    src/routes/DatabaseHealthRoutes.cpp

    # Repositories
    src/repositories/UserRepository.cpp

    # Services
    src/services/AuthService.cpp

    # Utilities
    src/utils/DatabaseConnection.cpp
    src/utils/Environment.cpp
    src/utils/ApplicationContext.cpp
    src/utils/PasswordHasher.cpp
)


# ========================================
# Include Directories
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
        argon2::argon2
)
