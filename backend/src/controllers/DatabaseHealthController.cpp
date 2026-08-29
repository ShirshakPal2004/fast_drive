#include "controllers/DatabaseHealthController.h"

#include "utils/DatabaseConnection.h"

#include <cstdlib>
#include <string>

crow::response DatabaseHealthController::check() {

    try {

        const char* host = std::getenv("DB_HOST");
        const char* port = std::getenv("DB_PORT");
        const char* user = std::getenv("DB_USER");
        const char* password = std::getenv("DB_PASSWORD");
        const char* database = std::getenv("DB_NAME");

        if (!host || !port || !user || !password || !database) {
            crow::json::wvalue response;

            response["status"] = "error";
            response["database"] = "configuration missing";

            return crow::response(500, response);
        }

        DatabaseConnection connection(
            host,
            std::stoi(port),
            user,
            password,
            database
        );

        auto& session = connection.getSession();

        auto result = session.sql("SELECT 1").execute();

        auto row = result.fetchOne();

        if (row) {
            crow::json::wvalue response;

            response["status"] = "ok";
            response["database"] = "connected";

            return crow::response(response);
        }

        crow::json::wvalue response;

        response["status"] = "error";
        response["database"] = "query failed";

        return crow::response(500, response);

    } catch (const std::exception& e) {

        crow::json::wvalue response;

        response["status"] = "error";
        response["database"] = "connection failed";

        return crow::response(500, response);
    }
}
