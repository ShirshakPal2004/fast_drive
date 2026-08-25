#include "routes/HealthRoutes.h"
#include "controllers/HealthController.h"

void registerHealthRoutes(crow::SimpleApp& app) {

    CROW_ROUTE(app, "/api/health")
    ([] {
        return HealthController::check();
    });
}
