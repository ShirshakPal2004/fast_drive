#include "utils/ApplicationContext.h"

ApplicationContext::ApplicationContext(
    DatabaseConnection& database
)
    : database(database) {
}

DatabaseConnection& ApplicationContext::getDatabase() {
    return database;
}
