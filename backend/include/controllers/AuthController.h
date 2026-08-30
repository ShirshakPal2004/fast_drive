#pragma once

#include <crow.h>

class AuthController {
public:

    static crow::response registerUser(
        const crow::request& request
    );
};
