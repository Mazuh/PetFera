#include "employee.hpp"
using data::EmployeeModel;

#include <string>

std::string
EmployeeModel::getId()
{
    return id;
}

void
EmployeeModel::setId(std::string _id)
{
    name = _id;
}

std::string
EmployeeModel::getName()
{
    return name;
}

void
EmployeeModel::setName(std::string _name)
{
    name = _name;
}
