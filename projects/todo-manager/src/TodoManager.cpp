#include "../include/TodoManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>

TodoManager::TodoManager(const std::string &path)
    : filePath(path), nextId(1)
{
    loadFromFile();
}

void TodoManager::addTask(const std::string &description)
{
    tasks.push_back({nextId++, description, false});
}

bool TodoManager::deleteTask(int id)
{
    auto it = std::remove_if(tasks.begin(), tasks.end(),
                             [id](const Task &task)
                             {
                                 return task.id == id;
                             });

    if (it == tasks.end())
    {
        return false;
    }

    tasks.erase(it, tasks.end());
    return true;
}

bool TodoManager::completeTask(int id)
{
    for (auto &task : tasks)
    {
        if (task.id == id)
        {
            task.completed = true;
            return true;
        }
    }

    return false;
}

const std::vector<Task> &TodoManager::getTasks() const
{
    return tasks;
}

void TodoManager::saveToFile() const
{
    std::ofstream file(filePath);

    for (const auto &task : tasks)
    {
        file << task.id << ","
             << task.description << ","
             << task.completed << "\n";
    }
}

void TodoManager::loadFromFile()
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        return;
    }

    tasks.clear();
    std::string line;
    int maxId = 0;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string description;
        std::string completedStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, description, ',');
        std::getline(ss, completedStr, ',');

        Task task;
        task.id = std::stoi(idStr);
        task.description = description;
        task.completed = (completedStr == "1");

        tasks.push_back(task);

        if (task.id > maxId)
        {
            maxId = task.id;
        }
    }

    nextId = maxId + 1;
}