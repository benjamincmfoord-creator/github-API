#include "http_client.hpp"
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
#include <cstdio>

std::string HttpClient::get(const std::string& host, const std::string& path, int port) {
    // Ignore port, just use HTTPS curl
    std::string command = "curl -s https://" + host + path;

    std::array<char, 128> buffer{};
    std::string result;

    // Open pipe to run curl
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}
