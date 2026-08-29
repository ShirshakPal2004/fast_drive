#include "routes/DatabaseHealthRoutes.h"

#include "controllers/DatabaseHealthController.h"

void registerDatabaseHealthRoutes(crow::SimpleApp& app) {

    CROW_ROUTE(app, "/api/health/db")
    ([] {
        return DatabaseHealthController::check();
    });
}
