#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
/**
 * Employee models.
 */

#include <string>
#include "abc.hpp"

namespace model
{
    /**
     * Generic employee model.
     */
    class Employee: public Model
    {
        public:
            enum Role
            {
                VET,
                CARER
            };
            Role getRole();
            std::string getId();
            void setId(std::string id);
            std::string getName();
            void setName(std::string _name);
            std::string getResume();
            void setResume(std::string _resume);
        protected:
            Role role;
            std::string id;
            std::string name;
            std::string resume;
    };

    /**
     * Specific employee model.
     */
    class Vet: public Employee
    {
        public:
            Vet();
    };

    /**
     * Specific employee model.
     */
    class Carer: public Employee
    {
        public:
            Carer();
    };

    /**
     * Employee model factory.
     */
    Employee* make_employee(Employee::Role role);

    Employee::Role stringToEmployeeRole(std::string roleName);
    std::string employeeRoleToString(Employee::Role role);
}

#endif
