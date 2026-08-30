#pragma once

#include "models/User.h"
#include "utils/DatabaseConnection.h"

#include <optional>
#include <string>

class UserRepository {
public:
    explicit UserRepository(DatabaseConnection& database);

    bool emailExists(const std::string& email);

    User createUser(
        const std::string& name,
        const std::string& email,
        const std::string& passwordHash
    );

    std::optional<User> findByEmail(const std::string& email);

private:
    DatabaseConnection& database;
};
