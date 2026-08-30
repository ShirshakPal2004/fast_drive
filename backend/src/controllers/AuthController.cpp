#include "controllers/AuthController.h"

#include "repositories/UserRepository.h"
#include "services/AuthService.h"
#include "utils/DatabaseConnection.h"

#include <cstdlib>
#include <string>

crow::response AuthController::registerUser(
    const crow::request& request
) {

    try {

        auto body = crow::json::load(request.body);

        if (!body) {
            return crow::response(
                400,
                R"({"error":"Invalid JSON request"})"
            );
        }

        if (!body.has("name") ||
            !body.has("email") ||
            !body.has("password")) {

            return crow::response(
                400,
                R"({"error":"Name, email and password are required"})"
            );
        }

        std::string name =
            body["name"].s();

        std::string email =
            body["email"].s();

        std::string password =
            body["password"].s();

        const char* host = std::getenv("DB_HOST");
        const char* port = std::getenv("DB_PORT");
        const char* user = std::getenv("DB_USER");
        const char* dbPassword = std::getenv("DB_PASSWORD");
        const char* database = std::getenv("DB_NAME");

        if (!host ||
            !port ||
            !user ||
            !dbPassword ||
            !database) {

            return crow::response(
                500,
                R"({"error":"Database configuration missing"})"
            );
        }

        DatabaseConnection connection(
            host,
            std::stoi(port),
            user,
            dbPassword,
            database
        );

        UserRepository repository(connection);

        AuthService authService(repository);

        User userData =
            authService.registerUser(
                name,
                email,
                password
            );

        crow::json::wvalue response;

        response["message"] =
            "User registered successfully";

        response["user"]["id"] =
            userData.id;

        response["user"]["name"] =
            userData.name;

        response["user"]["email"] =
            userData.email;

        return crow::response(201, response);

    }
    catch (const std::invalid_argument& e) {

        crow::json::wvalue response;

        response["error"] = e.what();

        return crow::response(400, response);

    }
    catch (const std::runtime_error& e) {

        crow::json::wvalue response;

        response["error"] = e.what();

        return crow::response(409, response);

    }
    catch (const std::exception&) {

        return crow::response(
            500,
            R"({"error":"Internal server error"})"
        );
    }
}
