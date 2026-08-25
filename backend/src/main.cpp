#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/health")
    ([] {
        crow::json::wvalue response;

        response["status"] = "ok";
        response["service"] = "Fast Drive Backend";

        return response;
    });

    app.port(8080).multithreaded().run();

    return 0;
}
