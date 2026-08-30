#include "routes/AuthRoutes.h"

#include "controllers/AuthController.h"

void registerAuthRoutes(crow::SimpleApp& app) {

    CROW_ROUTE(app, "/api/auth/register")
        .methods(crow::HTTPMethod::POST)
    ([](const crow::request& request) {

        return AuthController::registerUser(request);

    });
}
