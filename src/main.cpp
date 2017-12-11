#include <iostream>

#include "employee.hpp"

int main()
{
    data::EmployeeModel me;
    me.setName("Marcell");
    std::cout << "hello there, " << me.getName() << "!" << std::endl;
    return 0;
}
