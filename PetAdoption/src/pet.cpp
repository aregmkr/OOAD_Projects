#include "../header/pet.h"

Pet::Pet(const std::string& name, int age) : name_{name}, age_{age} {}

void Pet::displayInfo() const {
    std::cout << "Pet name: " << name_ << std::endl;
    std::cout << "Pet age: " << age_ << std::endl; 
}