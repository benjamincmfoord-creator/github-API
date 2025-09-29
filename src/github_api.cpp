#include "github_api.hpp"
#include "http_client.hpp"
#include "json_parser.hpp"

std::vector<Activity> GitHubAPI::fetchUserActivity(const std::string& username) {
    HttpClient client;
    std::string body = client.get("api.github.com", "/users/" + username + "/events");

    if (body.empty()) return {};

    JsonParser parser;
    return parser.parse(body);
}
