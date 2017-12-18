#include "abc.hpp"
#include "employee.hpp"
#include "animal.hpp"

namespace infra
{
    class EmployeeRepository: public Repository
    {
        public:
            EmployeeRepository();
            EmployeeRepository(std::string _filename);
            virtual void add(model::Model*);
            virtual QueryResult getAll();
            virtual model::Model* get(model::Model*);
            virtual void update(model::Model*);
            virtual void remove(model::Model*);
    };

    std::string modelToCSV(model::Employee*);
    model::Employee* modelFromCSV(std::string);

    /*
    class AnimalRepository: public Repository
    {
        public:
            AnimalRepository();
            AnimalRepository(std::string _filename);
            ~AnimalRepository();
            virtual void add(Model animal);
            virtual QueryResult getAll();
            virtual Model get(Model animal);
            virtual void update(Model animal);
            virtual void remove(Model animal);
    }
    */

    

}