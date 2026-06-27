#pragma once
#include <string>

// Handles password generation logic
class PasswordGenerator
{
public:
    std::string generate(int length,
                         bool useLowercase,
                         bool useUppercase,
                         bool useDigits,
                         bool useSymbols) const;
};