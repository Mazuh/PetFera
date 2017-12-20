#include "infra.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "abc.hpp"
#include "employee.hpp"
#include "animal.hpp"

namespace infra
{
    QueryResult::QueryResult(std::vector<model::Model*> models)
    {
        container = models;
    }

    std::vector<model::Model*>::size_type
    QueryResult::size()
    {
        return container.size();
    }

    std::vector<model::Model*>::iterator
    QueryResult::begin()
    {
        return container.begin();
    }

    std::vector<model::Model*>::iterator
    QueryResult::end()
    {
        return container.end();
    }

    BufferedLineReaderCSV::BufferedLineReaderCSV(std::string line)
    {
        lineStream = std::istringstream(line);
    }

    std::string
    BufferedLineReaderCSV::nextString(char delimiter)
    {
        std::string value;
        std::getline(lineStream, value, delimiter);
        return value;
    }

    int
    BufferedLineReaderCSV::nextInteger(char delimiter)
    {
        std::string value;
        std::getline(lineStream, value, delimiter);
        return std::atoi(value.c_str());
    }

    double
    BufferedLineReaderCSV::nextFloating(char delimiter)
    {
        std::string value;
        std::getline(lineStream, value, delimiter);
        return std::atof(value.c_str());
    }

    Repository::Repository()
    {
        filename = "unknown_data.csv";
    }

    EmployeeRepository::EmployeeRepository()
    {
        filename = "./data/employees.csv";
    }

    std::string
    modelToCSV(model::Employee* model)
    {
        std::stringstream row;
        row << model::employeeRoleToString(model->getRole()) << ';'
            << model->getId() << ';'
            << model->getName() << ';'
            << model->getResume();
        return row.str();
    }

    void
    EmployeeRepository::add(model::Model* employee)
    {
        std::ofstream file;
        file.open(filename, std::ofstream::app);
        file << modelToCSV((model::Employee*) employee) << '\n';
        file.close();
    }

    QueryResult
    EmployeeRepository::getAll()
    {
        std::vector<model::Model*> models;
        std::ifstream file;
        file.open(filename);
        std::string row, value;
        while (std::getline(file, row))
        {
            BufferedLineReaderCSV buffer(row);
            std::string roleStr = buffer.nextString(';');
            model::Employee::Role role = model::stringToEmployeeRole(roleStr);
            auto employee = model::make_employee(role);
            employee->setId(buffer.nextString(';'));
            employee->setName(buffer.nextString(';'));
            employee->setResume(buffer.nextString('\n'));
            models.push_back(employee);
        }
        file.close();
        return QueryResult(models);
    }

    model::Model*
    EmployeeRepository::get(model::Model*)
    {
        return new model::Model();
    }

    void
    EmployeeRepository::update(model::Model*)
    {

    }

    void
    EmployeeRepository::remove(model::Model*)
    {

    }

    /*

    AnimalRepository::AnimalRepository()
    {
        filename = "animals.csv";
    }

    AnimalRepository::AnimalRepository(std::string _filename)
    {
        filename = _filename;
    }

    QueryResult::QueryResult(std::vector<Model> models)
    {
        container = models;
    }

    void
    AnimalRepository::add(Model animal)
    {

    }
    
    QueryResult
    AnimalRepository::getAll()
    {
        std::vector<Model> v;
        return QueryResult(v);
    }
    
    Model
    AnimalRepository::get(Model animal)
    {
        return Animal();
    }
    
    void
    AnimalRepository::update(Model animal)
    {

    }
    
    void
    AnimalRepository::remove(Model animal)
    {

    }

    AnimalRepository::~AnimalRepository()
    {

    }*/

}
