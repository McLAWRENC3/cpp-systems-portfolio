#include "../include/PasswordGenerator.h"
#include <random>
#include <stdexcept>

// Generate secure-ish random password using Mersenne Twister
std::string PasswordGenerator::generate(int length,
                                        bool useLowercase,
                                        bool useUppercase,
                                        bool useDigits,
                                        bool useSymbols) const
{
    if (length <= 0)
    {
        throw std::invalid_argument("Password length must be greater than zero.");
    }

    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string symbols = "!@#$%^&*()-_=+[]{};:,.<>?/";

    std::string charset;

    // Build character pool based on user selections
    if (useLowercase)
        charset += lowercase;
    if (useUppercase)
        charset += uppercase;
    if (useDigits)
        charset += digits;
    if (useSymbols)
        charset += symbols;

    if (charset.empty())
    {
        throw std::invalid_argument("At least one character set must be selected.");
    }

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, charset.size() - 1);

    std::string password;

    for (int i = 0; i < length; i++)
    {
        password += charset[dist(gen)];
    }

    return password;
}