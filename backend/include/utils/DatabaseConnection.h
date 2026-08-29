#pragma once

#include <mysqlx/xdevapi.h>

#include <string>

class DatabaseConnection {
public:
    DatabaseConnection(
        const std::string& host,
        int port,
        const std::string& username,
        const std::string& password,
        const std::string& database
    );

    mysqlx::Session& getSession();

private:
    mysqlx::Session session;
    std::string database;
};
