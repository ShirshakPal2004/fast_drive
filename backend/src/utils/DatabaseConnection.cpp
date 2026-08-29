#include "utils/DatabaseConnection.h"

DatabaseConnection::DatabaseConnection(
    const std::string& host,
    int port,
    const std::string& username,
    const std::string& password,
    const std::string& database
)
    : session(
        host,
        port,
        username,
        password
      ),
      database(database) {
}

mysqlx::Session& DatabaseConnection::getSession() {
    return session;
}
