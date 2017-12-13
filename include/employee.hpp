/**
 * Employee models.
 */

#include <string>
#include "abc.hpp"

namespace data
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
            std::string getId();
            void setId(std::string id);
            std::string getName();
            void setName(std::string _name);
            std::string getResume();
            void setResume(std::string _resume);
        private:
            std::string id;
            std::string name;
            std::string resume;
    };

    /**
     * Specific employee model.
     */
    class Vet: public Employee
    {};

    /**
     * Specific employee model.
     */
    class Carer: public Employee
    {};

    /**
     * Employee model factory.
     */
    Employee make_employee_model(Employee::Role role, std::string id);
}
