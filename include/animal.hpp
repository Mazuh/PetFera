#ifndef ANIMAL_HPP
#define ANIMAL_HPP
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
            char getSexChar();
            void setSexByChar(char _sex);
            Vet getVet();
            void setVet(Vet _vet);
            Carer getCarer();
            void setCarer(Carer _carer);
            std::string getScientificName();
            void setScientificName(std::string _scientificName);
            std::string getCaringName();
            void setCaringName(std::string _caringName);
            std::string getOrigin();
            void setOrigin(std::string _origin);
            std::string getFeeding();
            void setFeeding(std::string _feeding);
            bool isThreatened();
            void setThreatened(bool _threatened);
            float getApproximateSizeInM();
            void setApproximateSizeInM(float _approximateSizeInM);
        private:
            Sex sex;
            Vet vet;
            Carer carer;
            std::string scientificName;
            std::string caringName;
            std::string origin;
            std::string feeding;
            bool threatened;
            float approximateSizeInM;
    };

    /**
     * Specific animal model.
     */
    class Anfibian: public Animal
    {
        public:
            
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

#endif
