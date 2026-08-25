#include <crow.h>

#include "routes/HealthRoutes.h"

int main() {

    crow::SimpleApp app;

    registerHealthRoutes(app);

    app.port(8080)
       .multithreaded()
       .run();

    return 0;
}
