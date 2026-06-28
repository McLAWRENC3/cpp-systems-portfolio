#pragma once
#include <string>
// Represents one saved credential
struct Credential
{
    int id;
    std::string service;
    std::string username;
    std::string encryptedPassword;
};