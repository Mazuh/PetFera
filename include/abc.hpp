#ifndef ABC_HPP
#define ABC_HPP
/**
 * Base classes for data handling.
 */

#include <vector>

namespace model
{
    /**
     * Abstract class for all data object that can be persisted.
     * A model implementation will define the business rules, without UI or DB concerns.
     */
    class Model
    {
    };
}

namespace infra
{
    /**
     * A read-only models container created by a Repository, wrapping a vector.
     */
    class QueryResult
    {
        private:
            std::vector<model::Model*> container;
        public:
            /**
             * Constructor to make a vector as a read-only generic container for Model.
             */
            QueryResult(std::vector<model::Model*> models);
            /**
             * Returns the number of elements in the container,
             * i.e. std::distance(begin(), end()). 
             */
            std::vector<model::Model*>::size_type size();
            /**
             * Returns an iterator to the first element of the container.
             * If the container is empty, the returned iterator will be equal to end().
             */
            std::vector<model::Model*>::iterator begin();
            /**
             * Returns an iterator to the element following the last element of the container.
             * This element acts as a placeholder;
             * attempting to access it results in undefined behavior.
             */
            std::vector<model::Model*>::iterator end();
    };

    /**
     * Abstract class for all repositories implementations.
     * A repository design pattern implementation concerns only persistence operations.
     * 
     * Already has a few CRUD methods that must be overrided;
     * and all operations will be auto committed on the persistence file.
     */
    class Repository
    {
        protected:
            std::string filename;
        public:
            Repository();
            Repository(std::string _filename);
            /**
             * Performs CREATE operation.
             */
            virtual void add(model::Model*) = 0;
            /**
             * Performs READ (all) operation.
             */
            virtual QueryResult getAll() = 0;
            /**
             * Performs (a single) READ operation.
             */
            virtual model::Model* get(model::Model*) = 0;
            /**
             * Performs UPDATE operation.
             */
            virtual void update(model::Model*) = 0;
            /**
             * Performs DELETE operation.
             */
            virtual void remove(model::Model*) = 0;
    };
}

#endif
