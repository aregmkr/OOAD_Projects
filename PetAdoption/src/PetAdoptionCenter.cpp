#include <iostream>
#include "../header/PetAdoptionCenter.h"
#include "../header/DomesticPetFactory.h"
#include "../header/WildPetFactory.h"

PetAdoptionCenter* PetAdoptionCenter::instance = nullptr;


PetAdoptionCenter::PetAdoptionCenter(Type type) {
    if (type == Domestic) {
        std::cout << "Creating Domestic Pet Factory\n";
        pet_ptr = new DomesticPetFactory();
    } else if (type == Wild) {
        std::cout << "Creating Wild Pet Factory\n";
        pet_ptr = new WildPetFactory();
    }
}

PetAdoptionCenter* PetAdoptionCenter::getInstance(Type type) {
    if (instance == nullptr) {
        instance = new PetAdoptionCenter(type);
    } 
    return instance;
}

AbstractPetFactory* PetAdoptionCenter::getPointer() const {
    if (pet_ptr != nullptr) {
        return pet_ptr;
    }
    return nullptr;
}

PetAdoptionCenter::~PetAdoptionCenter() {
    if (pet_ptr != nullptr) {
        delete pet_ptr;
    }
}