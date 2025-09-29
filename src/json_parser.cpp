#include "json_parser.hpp"
#include <iostream>

std::vector<Activity> JsonParser::parse(const std::string& json) {
    std::vector<Activity> activities;

    size_t pos = 0;
    while (true) {
        // Find the next "type"
        size_t tpos = json.find("\"type\"", pos);
        if (tpos == std::string::npos) break;

        // Find the colon after "type"
        size_t colon = json.find(":", tpos);
        if (colon == std::string::npos) break;

        // Find the start of the string value
        size_t quote1 = json.find("\"", colon + 1);
        size_t quote2 = json.find("\"", quote1 + 1);
        if (quote1 == std::string::npos || quote2 == std::string::npos) break;

        std::string type = json.substr(quote1 + 1, quote2 - quote1 - 1);

        // Now find "repo"
        size_t rpos = json.find("\"repo\"", quote2);
        if (rpos == std::string::npos) break;

        size_t namepos = json.find("\"name\"", rpos);
        if (namepos == std::string::npos) break;

        size_t colon2 = json.find(":", namepos);
        size_t quote3 = json.find("\"", colon2 + 1);
        size_t quote4 = json.find("\"", quote3 + 1);
        if (quote3 == std::string::npos || quote4 == std::string::npos) break;

        std::string repo = json.substr(quote3 + 1, quote4 - quote3 - 1);

        activities.push_back({type, repo});

        // Move forward
        pos = quote4 + 1;
    }

    return activities;
}
