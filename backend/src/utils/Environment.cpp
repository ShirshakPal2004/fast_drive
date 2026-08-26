#include "utils/Environment.h"

#include <cstdlib>
#include <stdexcept>

namespace Environment {

    std::string get(const std::string& key) {

        const char* value = std::getenv(key.c_str());

        if (value == nullptr) {
            throw std::runtime_error(
                "Missing environment variable: " + key
            );
        }

        return std::string(value);
    }

}
