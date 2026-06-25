#pragma once
#include <string>

// Handles HTTP GET requests using libcurl
class HttpClient
{
public:
    std::string get(const std::string &url) const;
};