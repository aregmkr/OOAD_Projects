#include "../header/eagle.h"
#include <iostream>
#include "../header/pet.h"

Eagle::Eagle(const std::string& name, int age) : Pet(name, age) {}

void Eagle::makeSound() {
    std::cout << "Eagle: tsf" << std::endl;
}

void Eagle::eat() {
    std::cout << "Eagle:: eat" << std::endl;
}