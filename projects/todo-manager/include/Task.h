#pragma once
#include <string>
// represents a single task in the system
struct Task
{
    int id;
    std::string description;
    bool completed;
};
