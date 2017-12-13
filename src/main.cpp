#include <iostream>

#include "employee.hpp"

using data::Employee;

int main()
{
    Employee me = make_employee_model(Employee::CARER, "1");
    me.setName("Marcell");
    std::cout << me.getName() << " is " << me.getRoleName() << std::endl;
    return 0;
}
