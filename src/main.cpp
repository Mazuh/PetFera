#include <iostream>

#include "infra.hpp"
#include "employee.hpp"
#include "animal.hpp"

using namespace model;
using namespace infra;

int main()
{
    Carer* me = (Carer*) model::make_employee(Employee::CARER, "1");
    me->setName("Marcell");
    std::cout << me->getName() << " is " << me->getRoleName() << std::endl;
    Animal* pet = new Animal();
    pet->setSexByChar('f');
    pet->setCarer(me);
    std::cout << "Pet is a " << pet->getSexChar()
              << " cared by " << pet->getCarer()->getName() << std::endl;

    EmployeeRepository repo;
    repo.add(me);

    return 0;
}
