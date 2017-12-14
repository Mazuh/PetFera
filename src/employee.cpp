#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "employee.hpp"

#include <string>

namespace data
{
    std::string
    Employee::getRoleName()
    {
        switch (role)
        {
            case Role::VET:
                return "Vet";
            case Role::CARER:
                return "Carer";
            default:
                return "NA";
        }
    }

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

    std::string
    Employee::getResume()
    {
        return resume;
    }

    void
    Employee::setResume(std::string _resume)
    {
        name = _resume;
    }

    Vet::Vet()
    {
        role = Role::VET;
    }

    Carer::Carer()
    {
        role = Role::CARER;
    }

    Employee
    make_employee_model(Employee::Role role, std::string id)
    {
        switch (role)
        {
            case Employee::Role::VET:
                return Vet();
            case Employee::Role::CARER:
                return Carer();
            default:
                return Employee();
        }
    }
}

#endif
