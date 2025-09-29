#include "cli.hpp"
#include "github_api.hpp"
#include <iostream>

void CLI::run(const std::string& username) {
    GitHubAPI api;
    auto activities = api.fetchUserActivity(username);

    if (activities.empty()) {
        std::cout << "No activity found or failed to fetch data.\n";
        return;
    }

    for (const auto& act : activities) {
        std::cout << "- " << act.action << " in " << act.repo << std::endl;
    }
}
