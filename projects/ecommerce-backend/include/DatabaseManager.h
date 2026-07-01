#pragma once
#include <memory>
#include <string>
#include <pqxx/pqxx>
class DatabaseManager
{
private:
    std::unique_ptr<pqxx::connection> connection;

public:
    DatabaseManager(const std::string &connectionString);

    bool isConnected() const;

    pqxx::connection &getConnection();
};