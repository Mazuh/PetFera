#include "employee.hpp"
using data::Employee;

#include <string>

std::string
Employee::getId()
{
    return id;
}

void
Employee::setId(std::string _id)
{
    name = _id;
}

std::string
Employee::getName()
{
    return name;
}

void
Employee::setName(std::string _name)
{
    name = _name;
}
