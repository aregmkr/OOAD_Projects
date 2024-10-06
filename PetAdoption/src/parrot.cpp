#include "../header/parrot.h"
#include <iostream>
#include "../header/pet.h"

Parrot::Parrot(const std::string& name, int age) : Pet(name, age) {}

void Parrot::makeSound() {
    std::cout << "Parrot: shefy takanqna" << std::endl;
}

void Parrot::eat() {
    std::cout << "Parrot:: eat" << std::endl;
}