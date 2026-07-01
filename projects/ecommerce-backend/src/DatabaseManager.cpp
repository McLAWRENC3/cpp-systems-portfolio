#include "../include/DatabaseManager.h"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string &connectionString)
{
    try
    {
        connection = std::make_unique<pqxx::connection>(connectionString);

        if (connection->is_open())
        {
            std::cout << "Connected to "
                      << connection->dbname()
                      << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}

bool DatabaseManager::isConnected() const
{
    return connection && connection->is_open();
}

pqxx::connection &DatabaseManager::getConnection()
{
    return *connection;
}