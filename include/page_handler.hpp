#ifndef PAGE_HANDLER_HPP
#define PAGE_HANDLER_HPP

#include "crow.h"
#include <string>

class PageHandler {
public:
    PageHandler(const std::string& staticDir = "static");
    void setupRoutes(crow::SimpleApp &app);

private:
    std::string staticDirectory;
    std::string readFile(const std::string& filename);
};

#endif // PAGE_HANDLER_HPP
