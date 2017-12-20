#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

#include "employee.hpp"

#include <string>
#include <iostream>

namespace model
{
    Employee::Role
    Employee::getRole()
    {
        return role;
    }

    std::string
    Employee::getId()
    {
        return id;
    }

    void
    Employee::setId(std::string _id)
    {
        id = _id;
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

    std::string
    Employee::getResume()
    {
        return resume;
    }

    void
    Employee::setResume(std::string _resume)
    {
        resume = _resume;
    }

    Vet::Vet()
    {
        role = Role::VET;
    }

    Carer::Carer()
    {
        role = Role::CARER;
    }

    Employee::Role
    stringToEmployeeRole(std::string roleStr)
    {
        if (roleStr == "Carer" || roleStr == "CARER" || roleStr == "carer")
        {
            return Employee::Role::CARER;
        }
        else if (roleStr == "Vet" || roleStr == "VET" || roleStr == "vet")
        {
            return Employee::Role::VET;
        }
        return Employee::Role::CARER; // TODO: exception
    }

    std::string
    employeeRoleToString(Employee::Role role)
    {
        switch (role)
        {
            case Employee::Role::CARER:
                return "Carer";
            case Employee::Role::VET:
                return "Vet";
            default:
                return "?";
        }
    }

    Employee*
    make_employee(Employee::Role role)
    {
        switch (role)
        {
            case Employee::Role::CARER:
                return new Carer();
            case Employee::Role::VET:
                return new Vet();
            default:
                return new Employee();
        }
    }
}

#endif
