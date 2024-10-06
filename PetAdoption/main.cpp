#include <iostream>
#include "./header/PetAdoptionCenter.h"
#include "../header/pet.h"
#include "../header/dog.h"

int main() {
    PetAdoptionCenter *center = nullptr;
    Pet *pet = nullptr;
    int t;
    std::cout << "Domestic - 1\n";
    std::cout << "Wild - 2\n";
    std::cin >> t;
    switch(t) {
        case 1:
            std::cout << "|Selected Domestic| \n";
            center = center->getInstance(Domestic); 
            pet = center->getPointer()->createMammal("Bob", 12);
            pet->makeSound();
            break;
        case 2:
            std::cout << "|Selected Wild| \n";
            center = center->getInstance(Wild);
            pet = center->getPointer()->createMammal("Bob", 12);
            pet->makeSound();
            break;
        default:
            std::cout << "Invalid input\n";
    }
    delete pet;
    delete center;
    pet = nullptr;
    return 0;
}