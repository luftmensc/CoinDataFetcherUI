#include "crow.h"
#include "page_handler.hpp"

int main() {
    crow::SimpleApp app;
    
    // Instantiate the PageHandler with the static folder directory.
    PageHandler pageHandler("static");
    pageHandler.setupRoutes(app);
    
    app.port(18080).multithreaded().run();
    return 0;
}
