#pragma once
#include "HttpClient.h"
#include <string>

// Handles currency conversion business logic
class CurrencyService
{
private:
    HttpClient client;

public:
    double convert(double amount,
                   const std::string &from,
                   const std::string &to) const;
};