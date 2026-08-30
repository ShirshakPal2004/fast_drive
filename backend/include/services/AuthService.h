#pragma once

#include "models/User.h"
#include "models/Session.h"
#include "repositories/UserRepository.h"
#include "repositories/SessionRepository.h"

#include <string>

class AuthService {
public:

    AuthService(
        UserRepository& userRepository,
        SessionRepository& sessionRepository
    );

    User registerUser(
        const std::string& name,
        const std::string& email,
        const std::string& password
    );

    Session loginUser(
        const std::string& email,
        const std::string& password,
        std::string& rawToken
    );

private:

    UserRepository& userRepository;
    SessionRepository& sessionRepository;
};
