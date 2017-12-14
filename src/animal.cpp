#include "animal.hpp"

#include <string>

namespace data
{
    char
    Animal::getSexChar()
    {
        switch (sex)
        {
            case Sex::MALE:
                return 'M';
            case Sex::FEMALE:
                return 'F';
            default:
                return '?';
        }
    }

    void
    Animal::setSexByChar(char _sex)
    {
        switch (_sex)
        {
            case 'M':
            case 'm':
                sex = Sex::MALE;
            case 'F':
            case 'f':
                sex = Sex::FEMALE;
            default:
                break;
        }
    }
    
    Vet
    Animal::getVet()
    {
        return vet;
    }
    
    void
    Animal::setVet(Vet _vet)
    {
        vet = _vet;
    }
    
    Carer
    Animal::getCarer()
    {
        return carer;
    }
    
    void
    Animal::setCarer(Carer _carer)
    {
        carer = _carer;
    }
    
    std::string
    Animal::getScientificName()
    {
        return scientificName;
    }
    
    void
    Animal::setScientificName(std::string _scientificName)
    {
        scientificName = _scientificName;
    }
    
    std::string
    Animal::getCaringName()
    {
        return caringName;
    }
    
    void
    Animal::setCaringName(std::string _caringName)
    {
        caringName = _caringName;
    }
    
    std::string
    Animal::getOrigin()
    {
        return origin;
    }
    
    void
    Animal::setOrigin(std::string _origin)
    {
        origin = _origin;
    }
    
    std::string
    Animal::getFeeding()
    {
        return feeding;
    }
    
    void
    Animal::setFeeding(std::string _feeding)
    {
        feeding = _feeding;
    }

    bool
    Animal::isThreatened()
    {
        return threatened;
    }

    void
    Animal::setThreatened(bool _threatened)
    {
        threatened = _threatened;
    }
    
    float
    Animal::getApproximateSizeInM()
    {
        return approximateSizeInM;
    }
    
    void
    Animal::setApproximateSizeInM(float _approximateSizeInM)
    {
        approximateSizeInM = _approximateSizeInM;
    }
    
    Animal
    make_animal_model(Animal::Kind kind)
    {
        switch (kind)
        {
            case Animal::Kind::ANFIBIAN:
                return Anfibian();
            case Animal::Kind::BIRD:
                return Bird();
            case Animal::Kind::MAMMAL:
                return Mammal();
            case Animal::Kind::REPTILE:
                return Reptile();
            default:
                return Animal();
        }
    }
}