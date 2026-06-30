#pragma once
#include <pqxx/pqxx>
#include <memory>
#include <string>

// Responsible for database connection management
class DatabaseManager {
private:
    std::unique_ptr<pqxx::connection> connection;

public:
    DatabaseManager(const std::string& connectionString);

    bool isConnected() const;

    pqxx::connection& getConnection();
};