#pragma once

#include <string>

class TokenHasher {
public:
    static std::string hash(
        const std::string& token
    );
};
