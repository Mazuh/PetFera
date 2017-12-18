#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include "animal.hpp"

#include <string>
#include <vector>

namespace model
{
    std::string
    Animal::getKindName()
    {
        switch (kind)
        {
            case Kind::ANFIBIAN:
                return "Anfibian";
            case Kind::BIRD:
                return "Bird";
            case Kind::MAMMAL:
                return "Mammal";
            case Kind::REPTILE:
                return "Reptile";
            default:
                return "?";
        }
    }

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
    
    Vet*
    Animal::getVet()
    {
        return vet;
    }
    
    void
    Animal::setVet(Vet* _vet)
    {
        vet = _vet;
    }
    
    Carer*
    Animal::getCarer()
    {
        return carer;
    }
    
    void
    Animal::setCarer(Carer* _carer)
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

    Anfibian::Anfibian()
    {
        kind = Animal::Kind::ANFIBIAN;
    }

    std::string
    Anfibian::getLastMoulting()
    {
        return lastMoulting;
    }

    void
    Anfibian::setLastMoulting(std::string _lastMoulting)
    {
        lastMoulting = _lastMoulting;
    }

    int
    Anfibian::getMoultingsQtt()
    {
        return moultingsQtt;
    }

    void
    Anfibian::setMoultingsQtt(int _moultingsQtt)
    {
        moultingsQtt = _moultingsQtt;
    }

    Reptile::Reptile()
    {
        kind = Animal::Kind::REPTILE;
        venomous = false;
    }

    std::string
    Reptile::getVenom()
    {
        return venom;
    }

    void
    Reptile::setVenom(std::string _venom)
    {
        venom = _venom;
        venomous = true;
    }

    bool
    Reptile::isVenomous()
    {
        return venomous;
    }

    Bird::Bird()
    {
        kind = Animal::Kind::BIRD;
    }

    int
    Bird::getBeakSizeInCm()
    {
        return beakSizeInCm;
    }

    void
    Bird::setBeakSizeInCm(int _beakSizeInCm)
    {
        beakSizeInCm = _beakSizeInCm;
    }

    int
    Bird::getWingspanSizeInCm()
    {
        return wingspanSizeInCm;
    }

    void
    Bird::setWingspanSizeInCm(int _wingspanSizeInCm)
    {
        wingspanSizeInCm = _wingspanSizeInCm;
    }

    Mammal::Mammal()
    {
        kind = Animal::Kind::MAMMAL;
    }

    std::string
    Mammal::getHair()
    {
        return hair;
    }

    void
    Mammal::setHair(std::string _hair)
    {
        hair = _hair;
    }
    
    Animal*
    make_animal(Animal::Kind kind)
    {
        switch (kind)
        {
            case Animal::Kind::ANFIBIAN:
                return new Anfibian();
            case Animal::Kind::BIRD:
                return new Bird();
            case Animal::Kind::MAMMAL:
                return new Mammal();
            case Animal::Kind::REPTILE:
                return new Reptile();
            default:
                return new Animal();
        }
    }
}

#endif
