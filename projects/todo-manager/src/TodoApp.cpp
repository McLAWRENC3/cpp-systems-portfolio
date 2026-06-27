#include "../include/TodoApp.h"
#include "../include/TodoManager.h"
#include <iostream>

void TodoApp::run()
{
    TodoManager manager;
    int choice;

    while (true)
    {
        std::cout << "\n===== To-Do Manager =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Delete Task\n";
        std::cout << "3. Complete Task\n";
        std::cout << "4. View Tasks\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string description;

            std::cout << "Task Description: ";
            std::getline(std::cin, description);

            manager.addTask(description);
            std::cout << "Task added.\n";
        }
        else if (choice == 2)
        {
            int id;

            std::cout << "Task ID to delete: ";
            std::cin >> id;

            if (manager.deleteTask(id))
            {
                std::cout << "Task deleted.\n";
            }
            else
            {
                std::cout << "Task not found.\n";
            }
        }
        else if (choice == 3)
        {
            int id;

            std::cout << "Task ID to complete: ";
            std::cin >> id;

            if (manager.completeTask(id))
            {
                std::cout << "Task completed.\n";
            }
            else
            {
                std::cout << "Task not found.\n";
            }
        }
        else if (choice == 4)
        {
            const auto &tasks = manager.getTasks();

            if (tasks.empty())
            {
                std::cout << "No tasks available.\n";
            }

            for (const auto &task : tasks)
            {
                std::cout << task.id << " | "
                          << task.description << " | "
                          << (task.completed ? "Completed" : "Pending")
                          << "\n";
            }
        }
        else if (choice == 5)
        {
            manager.saveToFile();
            std::cout << "Tasks saved.\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}