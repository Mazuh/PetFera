#include <iostream>

#include "infra.hpp"
#include "employee.hpp"
#include "animal.hpp"

using namespace model;
using namespace infra;

int main()
{
    auto professor = (Vet*) make_employee(Employee::Role::VET);
    professor->setId("1");
    professor->setName("Silvio");
    professor->setResume("PhD");
    auto me = (Carer*) make_employee(Employee::Role::CARER);
    me->setId("2");
    me->setName("Marcell");
    me->setResume("Student");
    Animal* pet = new Animal();
    pet->setSexByChar('f');
    pet->setCarer(me);
    std::cout << "Pet is a " << pet->getSexChar()
              << " cared by " << pet->getCarer()->getName() << std::endl;
    EmployeeRepository repo;
    repo.add(professor);
    repo.add(me);
    auto all = repo.getAll();
    for (auto model = all.begin(); model < all.end(); model++)
    {
        auto employee = (Employee*) *model;
        std::cout << employee->getName() << std::endl;
    }
    return 0;
}
