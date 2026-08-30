#pragma once

#include <cstdint>
#include <string>

struct Session {
    std::uint64_t id;
    std::uint64_t userId;
    std::string tokenHash;
    std::string expiresAt;
};
