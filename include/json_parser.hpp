#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include <string>
#include <vector>
#include "github_api.hpp" // we need Activity struct here

class JsonParser {
public:
 
    std::vector<Activity> parse(const std::string& json);
};

#endif 
