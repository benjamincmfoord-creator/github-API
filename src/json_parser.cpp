#include "json_parser.hpp"
#include <iostream>

std::vector<Activity> JsonParser::parse(const std::string& json) {
    std::vector<Activity> activities;

    size_t pos = 0;
    while (true) {
        size_t typePos = json.find("\"type\":\"", pos);
        if (typePos == std::string::npos) break;

        typePos += 8; // skip `"type":"`
        size_t typeEnd = json.find("\"", typePos);
        std::string type = json.substr(typePos, typeEnd - typePos);

        size_t repoPos = json.find("\"name\":\"", typeEnd);
        if (repoPos == std::string::npos) break;

        repoPos += 8; // skip `"name":"`
        size_t repoEnd = json.find("\"", repoPos);
        std::string repo = json.substr(repoPos, repoEnd - repoPos);

        activities.push_back({type, repo});
        pos = repoEnd;
    }

    return activities;
}
