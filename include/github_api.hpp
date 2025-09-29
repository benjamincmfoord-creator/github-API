#ifndef GITHUB_API_HPP
#define GITHUB_API_HPP

#include <string>
#include <vector>

struct Activity {
    std::string action;
    std::string repo;
}; 


class GitHubAPI {
public:
    std::vector<Activity> fetchUserActivity(const std::string& username);
};

#endif