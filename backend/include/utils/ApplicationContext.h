#pragma once

#include "utils/DatabaseConnection.h"

class ApplicationContext {
public:
    explicit ApplicationContext(DatabaseConnection& database);

    DatabaseConnection& getDatabase();

private:
    DatabaseConnection& database;
};
