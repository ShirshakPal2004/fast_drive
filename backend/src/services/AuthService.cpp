#include "services/AuthService.h"
#include "utils/PasswordHasher.h"

#include <stdexcept>

AuthService::AuthService(UserRepository& userRepository)
    : userRepository(userRepository) {
}

User AuthService::registerUser(
    const std::string& name,
    const std::string& email,
    const std::string& password
) {

    if (name.empty()) {
        throw std::invalid_argument("Name is required");
    }

    if (email.empty()) {
        throw std::invalid_argument("Email is required");
    }

    if (password.empty()) {
        throw std::invalid_argument("Password is required");
    }

    if (password.length() < 8) {
        throw std::invalid_argument(
            "Password must contain at least 8 characters"
        );
    }

    if (userRepository.emailExists(email)) {
        throw std::runtime_error(
            "Email already registered"
        );
    }

    std::string passwordHash =
        PasswordHasher::hash(password);

    return userRepository.createUser(
        name,
        email,
        passwordHash
    );
}
