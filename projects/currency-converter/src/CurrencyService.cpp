#include "../include/CurrencyService.h"
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <sstream>

using json = nlohmann::json;

double CurrencyService::convert(double amount,
                                const std::string &from,
                                const std::string &to) const
{

    // Build API URL
    std::string url =
        "https://api.frankfurter.app/latest?from=" + from + "&to=" + to;

    // Fetch JSON response
    std::string response = client.get(url);

    // Parse JSON
    json parsed = json::parse(response);

    // Validate response
    if (!parsed.contains("rates"))
    {
        throw std::runtime_error("Invalid API response");
    }

    if (!parsed["rates"].contains(to))
    {
        throw std::runtime_error("Currency not found");
    }

    double rate = parsed["rates"][to];
    return amount * rate;
}