#include "../include/PasswordManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>

PasswordManager::PasswordManager(
    const std::string &credentialsPath,
    const std::string &masterPath)
    : credentialsFile(credentialsPath),
      masterHashFile(masterPath),
      nextId(1)
{
    loadFromFile();
}

// Simple XOR encryption for learning purposes
std::string PasswordManager::encrypt(const std::string &text) const
{
    std::string result = text;
    char key = 'K';

    for (char &c : result)
    {
        c ^= key;
    }

    return result;
}

std::string PasswordManager::decrypt(const std::string &text) const
{
    return encrypt(text); // XOR is reversible
}

size_t PasswordManager::hashPassword(const std::string &password) const
{
    return std::hash<std::string>{}(password);
}

bool PasswordManager::masterPasswordExists() const
{
    std::ifstream file(masterHashFile);
    return file.good();
}

void PasswordManager::setupMasterPassword(const std::string &password)
{
    std::ofstream file(masterHashFile);
    file << hashPassword(password);
}

bool PasswordManager::login(const std::string &password) const
{
    std::ifstream file(masterHashFile);

    size_t storedHash;
    file >> storedHash;

    return storedHash == hashPassword(password);
}

void PasswordManager::addCredential(
    const std::string &service,
    const std::string &username,
    const std::string &password)
{
    credentials.push_back({nextId++,
                           service,
                           username,
                           encrypt(password)});
}

bool PasswordManager::deleteCredential(int id)
{
    auto it = std::remove_if(
        credentials.begin(),
        credentials.end(),
        [id](const Credential &c)
        {
            return c.id == id;
        });

    if (it == credentials.end())
    {
        return false;
    }

    credentials.erase(it, credentials.end());
    return true;
}

const std::vector<Credential> &PasswordManager::getCredentials() const
{
    return credentials;
}

std::string PasswordManager::revealPassword(int id) const
{
    for (const auto &c : credentials)
    {
        if (c.id == id)
        {
            return decrypt(c.encryptedPassword);
        }
    }

    return "";
}

void PasswordManager::saveToFile() const
{
    std::ofstream file(credentialsFile);

    for (const auto &c : credentials)
    {
        file << c.id << ","
             << c.service << ","
             << c.username << ","
             << c.encryptedPassword << "\n";
    }
}

void PasswordManager::loadFromFile()
{
    std::ifstream file(credentialsFile);

    if (!file.is_open())
    {
        return;
    }

    credentials.clear();
    std::string line;
    int maxId = 0;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string service;
        std::string username;
        std::string password;

        std::getline(ss, idStr, ',');
        std::getline(ss, service, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');

        Credential c;
        c.id = std::stoi(idStr);
        c.service = service;
        c.username = username;
        c.encryptedPassword = password;

        credentials.push_back(c);

        if (c.id > maxId)
        {
            maxId = c.id;
        }
    }

    nextId = maxId + 1;
}