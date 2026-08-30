#include "utils/PasswordHasher.h"

#include <argon2.h>

#include <stdexcept>
#include <vector>

namespace {

constexpr uint32_t TIME_COST = 3;
constexpr uint32_t MEMORY_COST = 65536;
constexpr uint32_t PARALLELISM = 4;

constexpr size_t SALT_LENGTH = 16;
constexpr size_t HASH_LENGTH = 32;

}

std::string PasswordHasher::hash(const std::string& password) {

    const size_t encodedLength =
        argon2_encodedlen(
            TIME_COST,
            MEMORY_COST,
            PARALLELISM,
            SALT_LENGTH,
            HASH_LENGTH,
            Argon2_id
        );

    std::vector<char> encodedHash(encodedLength);

    std::vector<unsigned char> salt(SALT_LENGTH);

    int result = argon2id_hash_encoded(
        TIME_COST,
        MEMORY_COST,
        PARALLELISM,
        password.data(),
        password.size(),
        salt.data(),
        SALT_LENGTH,
        HASH_LENGTH,
        encodedHash.data(),
        encodedHash.size()
    );

    if (result != ARGON2_OK) {
        throw std::runtime_error(
            "Password hashing failed"
        );
    }

    return std::string(encodedHash.data());
}

bool PasswordHasher::verify(
    const std::string& password,
    const std::string& passwordHash
) {

    return argon2id_verify(
        passwordHash.c_str(),
        password.data(),
        password.size()
    ) == ARGON2_OK;
}
