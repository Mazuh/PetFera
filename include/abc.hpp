#ifndef ABC_HPP
#define ABC_HPP
/**
 * Base classes for data handling.
 */

#include <vector>

namespace data
{
    /**
     * Abstract class for all data object that can be persisted.
     * A model implementation will define the business rules, without UI or DB concerns.
     */
    class Model
    {
    };

    /**
     * A read-only models container created by a Repository, wrapping a vector.
     */
    class QueryResult
    {
        private:
            std::vector<Model> container;
        public:
            /**
             * Constructor to make a vector as a read-only generic container for Model.
             */
            QueryResult(std::vector<Model> models);
            /**
             * Returns the number of elements in the container,
             * i.e. std::distance(begin(), end()). 
             */
            std::vector<Model>::size_type size();
            /**
             * Returns an iterator to the first element of the container.
             * If the container is empty, the returned iterator will be equal to end().
             */
            std::vector<Model>::iterator begin();
            /**
             * Returns an iterator to the element following the last element of the container.
             * This element acts as a placeholder;
             * attempting to access it results in undefined behavior.
             */
            std::vector<Model>::iterator end();
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
        private:
            std::string filename;
        public:
            /**
             * Performs CREATE operation.
             */
            virtual void add(Model) = 0;
            /**
             * Performs READ (all) operation.
             */
            virtual QueryResult getAll() = 0;
            /**
             * Performs (a single) READ operation.
             */
            virtual Model get(Model) = 0;
            /**
             * Performs UPDATE operation.
             */
            virtual void update(Model) = 0;
            /**
             * Performs DELETE operation.
             */
            virtual void remove(Model) = 0;
    };
}

#endif
