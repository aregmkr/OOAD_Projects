#include "../header/dog.h"
#include <iostream>
#include "../header/pet.h"

Dog::Dog(const std::string& name, int age) : Pet(name, age) {}

void Dog::makeSound() {
    std::cout << "Dog: gaf" << std::endl;
}

void Dog::eat() {
    std::cout << "Dog:: eat" << std::endl;
}