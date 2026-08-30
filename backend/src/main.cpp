#include <crow.h>

#include "routes/HealthRoutes.h"
#include "routes/DatabaseHealthRoutes.h"
#include "routes/AuthRoutes.h"

int main() {

    crow::SimpleApp app;

    registerHealthRoutes(app);
    registerDatabaseHealthRoutes(app);
    registerAuthRoutes(app);

    app.port(8080)
       .multithreaded()
       .run();

    return 0;
}
