#include "../header/lion.h"
#include <iostream>
#include "../header/pet.h"

Lion::Lion(const std::string& name, int age) : Pet(name, age) {}

void Lion::makeSound() {
    std::cout << "Lion: rrrrr" << std::endl;
}

void Lion::eat() {
    std::cout << "Lion:: eat" << std::endl;
}