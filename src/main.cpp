#include "cli.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: github-activity <username>\n";
        return 1;
    }

    std::string username = argv[1];
    CLI cli;
    cli.run(username);

    return 0;
}
