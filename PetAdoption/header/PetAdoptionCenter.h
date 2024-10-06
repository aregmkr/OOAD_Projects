#pragma once
#include "AbstractPetFactory.h"

class AbstractPetFactory;
class DomesticPetFactory;
class WildPetFactory;

enum Type {
    Domestic,
    Wild
};

class PetAdoptionCenter {
public:
    // PetAdoptionCenter(Type type);
    static PetAdoptionCenter* getInstance(Type type); 
    AbstractPetFactory* getPointer() const;
    ~PetAdoptionCenter();
private:
    PetAdoptionCenter(Type type);
    static PetAdoptionCenter* instance;
    AbstractPetFactory* pet_ptr;
};