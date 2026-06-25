#include "../include/HttpClient.h"
#include <curl/curl.h>
#include <stdexcept>
#include <string>

// Callback used by libcurl to write received data into string
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t totalSize = size * nmemb;
    std::string *buffer = static_cast<std::string *>(userp);

    buffer->append(static_cast<char *>(contents), totalSize);

    return totalSize;
}

std::string HttpClient::get(const std::string &url) const
{
    CURL *curl = curl_easy_init();

    if (!curl)
    {
        throw std::runtime_error("Failed to initialize CURL");
    }

    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::string error = curl_easy_strerror(res);
        curl_easy_cleanup(curl);
        throw std::runtime_error("HTTP request failed: " + error);
    }

    curl_easy_cleanup(curl);
    return response;
}