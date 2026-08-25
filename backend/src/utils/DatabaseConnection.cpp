#include "utils/DatabaseConnection.h"

DatabaseConnection::DatabaseConnection(
    const std::string& host,
    const std::string& username,
    const std::string& password,
    const std::string& database
)
    : host(host),
      username(username),
      password(password),
      database(database) {

    driver = sql::mysql::get_mysql_driver_instance();
}

std::unique_ptr<sql::Connection>
DatabaseConnection::getConnection() {

    return std::unique_ptr<sql::Connection>(
        driver->connect(host, username, password)
    );
}
