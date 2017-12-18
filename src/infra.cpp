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
        row << model->getId() << ';'
            << model->getName() << ';'
            << model->getResume() << ';'
            << model->getRoleName();
        return row.str();
    }

    void
    EmployeeRepository::add(model::Model* employee)
    {
        std::ofstream file(filename);
        file << modelToCSV((model::Employee*) employee) << '\n';
        file.close();
    }

    QueryResult
    EmployeeRepository::getAll()
    {
        std::vector<model::Model*> models;
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
