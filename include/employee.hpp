/**
 * Employees models.
 */

#include <string>
#include "abc.hpp"

namespace data
{
    /**
     * Generic employee model.
     */
    class EmployeeModel: public Model
    {
        private:
            std::string name;
            std::string id;
        public:
            std::string getId();
            void setId(std::string _id);
            std::string getName();
            void setName(std::string _name);
    };

    /**
     * Specific employee type.
     */
    class Carer: public EmployeeModel
    {};

    /**
     * Another specific employee type.
     */
    class Vet: public EmployeeModel
    {};
}
