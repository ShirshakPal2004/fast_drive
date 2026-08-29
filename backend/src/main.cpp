#include <crow.h>

#include "routes/HealthRoutes.h"
#include "routes/DatabaseHealthRoutes.h"

int main() {

    crow::SimpleApp app;

    registerHealthRoutes(app);
    registerDatabaseHealthRoutes(app);

    app.port(8080)
       .multithreaded()
       .run();

    return 0;
}
