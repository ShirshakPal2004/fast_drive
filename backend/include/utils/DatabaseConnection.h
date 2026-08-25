#pragma once

#include <mysql_driver.h>
#include <mysql_connection.h>

#include <memory>
#include <string>

class DatabaseConnection {
public:
    DatabaseConnection(
        const std::string& host,
        const std::string& username,
        const std::string& password,
        const std::string& database
    );

    std::unique_ptr<sql::Connection> getConnection();

private:
    sql::mysql::MySQL_Driver* driver;

    std::string host;
    std::string username;
    std::string password;
    std::string database;
};
