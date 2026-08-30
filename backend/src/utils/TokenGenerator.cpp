#include "utils/TokenGenerator.h"

#include <openssl/rand.h>

#include <iomanip>
#include <sstream>
#include <stdexcept>

std::string TokenGenerator::generate() {

    unsigned char bytes[32];

    if (RAND_bytes(bytes, sizeof(bytes)) != 1) {
        throw std::runtime_error(
            "Failed to generate secure session token"
        );
    }

    std::ostringstream token;

    token << std::hex
          << std::setfill('0');

    for (unsigned char byte : bytes) {
        token << std::setw(2)
              << static_cast<int>(byte);
    }

    return token.str();
}
