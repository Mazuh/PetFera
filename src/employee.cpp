#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

#include "employee.hpp"

#include <string>

namespace model
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
                return "?";
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

    
    Employee*
    make_employee(Employee::Role role, std::string id)
    {
        switch (role)
        {
            case Employee::Role::VET:
                return new Vet();
            case Employee::Role::CARER:
                return new Carer();
            default:
                return new Employee();
        }
    }
}

#endif
