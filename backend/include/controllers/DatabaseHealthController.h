#pragma once

#include <crow.h>

class DatabaseHealthController {
public:
    static crow::response check();
};
