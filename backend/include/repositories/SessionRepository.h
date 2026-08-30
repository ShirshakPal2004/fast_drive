#pragma once

#include "models/Session.h"
#include "utils/DatabaseConnection.h"

#include <cstdint>
#include <optional>
#include <string>

class SessionRepository {
public:

    explicit SessionRepository(
        DatabaseConnection& database
    );

    Session createSession(
        std::uint64_t userId,
        const std::string& tokenHash
    );

    std::optional<Session> findValidSession(
        const std::string& tokenHash
    );

    void deleteSession(
        const std::string& tokenHash
    );

private:

    DatabaseConnection& database;
};
