#pragma once

#include <cstdint>
#include <string>

struct User {
    std::uint64_t id;
    std::string name;
    std::string email;
    std::string passwordHash;
};
