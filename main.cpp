#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <crow.h>

using json = nlohmann::json;

int main() {
    crow::SimpleApp app;
    CROW_ROUTE(app, "/watan/ilovecats")
        .methods("GET"_method)
        ([](const crow::request& req) {
        auto user_p = req.url_params.get("user");
        auto pass_p = req.url_params.get("password");

        if (!user_p || !pass_p) {
            return crow::response(400, "Missing parameters");
        }

        std::string user_value = user_p;
        std::string pass_value = pass_p;

        json users;
        std::ifstream users_file("db/users.json");
        users_file >> users;

        std::map<std::string, std::string> authenticatedUser;

        for (const auto& user : users["authors"]) {
            if (user["user"] == user_value && user["password"] == pass_value) {
                authenticatedUser = user;
                break;
            }
        }

        if (!authenticatedUser.empty()) {
            return crow::response(200, json({
                {"status", "success"},
                {"message", "success"},
                }).dump());
        }
        else {
            return crow::response(401, "Authentication failed");
        }
        });
    app.port(80).multithreaded().run();
    return 0;
}