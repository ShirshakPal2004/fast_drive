#include "utils/TokenHasher.h"

#include <openssl/evp.h>

#include <iomanip>
#include <sstream>
#include <stdexcept>

std::string TokenHasher::hash(
    const std::string& token
) {

    unsigned char digest[EVP_MAX_MD_SIZE];

    unsigned int digestLength = 0;

    EVP_MD_CTX* context = EVP_MD_CTX_new();

    if (!context) {
        throw std::runtime_error(
            "Failed to create hash context"
        );
    }

    if (
        EVP_DigestInit_ex(
            context,
            EVP_sha256(),
            nullptr
        ) != 1 ||

        EVP_DigestUpdate(
            context,
            token.data(),
            token.size()
        ) != 1 ||

        EVP_DigestFinal_ex(
            context,
            digest,
            &digestLength
        ) != 1
    ) {

        EVP_MD_CTX_free(context);

        throw std::runtime_error(
            "Token hashing failed"
        );
    }

    EVP_MD_CTX_free(context);

    std::ostringstream result;

    result << std::hex
           << std::setfill('0');

    for (unsigned int i = 0;
         i < digestLength;
         ++i) {

        result << std::setw(2)
               << static_cast<int>(digest[i]);
    }

    return result.str();
}
