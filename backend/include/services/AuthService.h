#pragma once

#include "models/User.h"
#include "repositories/UserRepository.h"

#include <string>

class AuthService {
public:
    explicit AuthService(UserRepository& userRepository);

    User registerUser(
        const std::string& name,
        const std::string& email,
        const std::string& password
    );

private:
    UserRepository& userRepository;
};
