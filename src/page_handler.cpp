#include "page_handler.hpp"
#include <fstream>
#include <sstream>

PageHandler::PageHandler(const std::string& staticDir)
    : staticDirectory(staticDir)
{}

std::string PageHandler::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file)
        return "";
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void PageHandler::setupRoutes(crow::SimpleApp &app) {
    // Route for serving any static file.
    CROW_ROUTE(app, "/static/<string>")
    ([this](const std::string& filename) {
        std::string filepath = staticDirectory + "/" + filename;
        std::ifstream file(filepath);
        if (!file)
            return crow::response(404);
        std::stringstream buffer;
        buffer << file.rdbuf();
        crow::response res(buffer.str());

        if (filename.size() >= 5 && filename.substr(filename.size() - 5) == ".html")
            res.add_header("Content-Type", "text/html");
        else if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".css")
            res.add_header("Content-Type", "text/css");
        else if (filename.size() >= 3 && filename.substr(filename.size() - 3) == ".js")
            res.add_header("Content-Type", "application/javascript");
        return res;
    });

    // Home page route: index.html
    CROW_ROUTE(app, "/")
    ([this]() {
        std::string html = readFile(staticDirectory + "/index.html");
        if (html.empty())
            return crow::response(404);
        return crow::response(html);
    });

    // Backtest page route: backtest.html
    CROW_ROUTE(app, "/backtest")
    ([this]() {
        std::string html = readFile(staticDirectory + "/backtest.html");
        if (html.empty())
            return crow::response(404);
        return crow::response(html);
    });

    // Data Save page route: datasave.html
    CROW_ROUTE(app, "/datasave")
    ([this]() {
        std::string html = readFile(staticDirectory + "/datasave.html");
        if (html.empty())
            return crow::response(404);
        return crow::response(html);
    });

    // Realtime Trade page route: realtimetrade.html
    CROW_ROUTE(app, "/realtimetrade")
    ([this]() {
        std::string html = readFile(staticDirectory + "/realtimetrade.html");
        if (html.empty())
            return crow::response(404);
        return crow::response(html);
    });
}
