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
find_package(OpenSSL REQUIRED)


# ========================================
# Source Files
# ========================================

add_executable(fast_drive

    # Application
    src/main.cpp

    # Controllers
    src/controllers/HealthController.cpp
    src/controllers/DatabaseHealthController.cpp
    src/controllers/AuthController.cpp

    # Routes
    src/routes/HealthRoutes.cpp
    src/routes/DatabaseHealthRoutes.cpp
    src/routes/AuthRoutes.cpp

    # Repositories
    src/repositories/UserRepository.cpp
    src/repositories/SessionRepository.cpp

    # Services
    src/services/AuthService.cpp

    # Utilities
    src/utils/DatabaseConnection.cpp
    src/utils/Environment.cpp
    src/utils/ApplicationContext.cpp
    src/utils/PasswordHasher.cpp
    src/utils/TokenGenerator.cpp
    src/utils/TokenHasher.cpp
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
        OpenSSL::Crypto
)
