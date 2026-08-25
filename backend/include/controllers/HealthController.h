#pragma once

#include <crow.h>

class HealthController {
public:
    static crow::response check();
};
