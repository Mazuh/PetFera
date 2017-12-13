/**
 * Animal models.
 */

#include <string>
#include "abc.hpp"
#include "employee.hpp"

namespace data
{
    /**
     * Generic animal model.
     */
    class Animal: public Model
    {
        public:
            enum Kind
            {
                ANFIBIAN,
                REPTILE,
                BIRD,
                MAMMAL
            };
            enum Sex
            {
                MALE,
                FEMALE
            };
            enum ThreatStatus
            {
                OK,
                THREATENED,
                EXTINTED
            };
        private:
            Sex sex;
            Vet vet;
            Carer carer;
            ThreatStatus threatStatus;
            std::string cientificName;
            std::string caringName;
            std::string origin;
            std::string feeding;
            float approximateSizeInM;
    };

    /**
     * Specific animal model.
     */
    class Anfibian: public Animal
    {
        private:
            std::string lastMoulting;
            float moultingsQtt;
    };

    /**
     * Specific animal model.
     */
    class Reptile: public Animal
    {
        private:
            std::string venom;
    };

    /**
     * Specific animal model.
     */
    class Bird: public Animal
    {
        private:
            int beakSizeInCm;
            int wingspanSizeInCm;
    };

    /**
     * Specific animal model.
     */
    class Mammal: public Animal
    {
        private:
            std::string hair;
    };

    /**
     * Animal model factory.
     */
    Animal make_animal_model(Animal::Kind kind);
}
