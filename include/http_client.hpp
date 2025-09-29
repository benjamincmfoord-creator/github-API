#ifndef HTTP_CLIENT_HPP
#define HTTP_CLIENT_HPP

#include <string>

class HttpClient {
public:
    std::string get(const std::string& host, const std::string& path, int port = 80);
};

#endif // HTTP_CLIENT_HPP
