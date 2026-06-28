#pragma once
#include "Credential.h"
#include <vector>
#include <string>

// Handles authentication, encryption, and credential storage
class PasswordManager
{
private:
    std::vector<Credential> credentials;
    std::string credentialsFile;
    std::string masterHashFile;
    int nextId;

    std::string encrypt(const std::string &text) const;
    std::string decrypt(const std::string &text) const;
    size_t hashPassword(const std::string &password) const;

public:
    PasswordManager(
        const std::string &credentialsPath = "data/credentials.csv",
        const std::string &masterPath = "data/master.hash");

    bool masterPasswordExists() const;
    void setupMasterPassword(const std::string &password);
    bool login(const std::string &password) const;

    void addCredential(
        const std::string &service,
        const std::string &username,
        const std::string &password);

    bool deleteCredential(int id);

    const std::vector<Credential> &getCredentials() const;
    std::string revealPassword(int id) const;

    void saveToFile() const;
    void loadFromFile();
};