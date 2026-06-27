#pragma once
#include "Task.h"
#include <vector>
#include <string>

// Handles task storage and business logic
class TodoManager
{
private:
    std::vector<Task> tasks;
    std::string filePath;
    int nextId;

public:
    TodoManager(const std::string &path = "data/tasks.csv");

    void addTask(const std::string &description);
    bool deleteTask(int id);
    bool completeTask(int id);

    const std::vector<Task> &getTasks() const;

    void saveToFile() const;
    void loadFromFile();
};