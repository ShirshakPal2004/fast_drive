#include "controllers/HealthController.h"

crow::response HealthController::check() {
    crow::json::wvalue response;

    response["status"] = "ok";
    response["service"] = "Fast Drive Backend";

    return crow::response(response);
}
