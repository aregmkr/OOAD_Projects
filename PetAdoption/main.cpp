#include <iostream>
#include "./header/PetAdoptionCenter.h"
#include "../header/pet.h"
#include "../header/dog.h"

void control(Pet *pet) {
    int t = 10;
    while(t != 4) {
        std::cout << "\nEat: 1\nMake sound: 2\nDisplay information about pet: 3\nExit: 4\nYour input: ";
        std::cin >> t;
        switch(t) {
            case 1:
                pet->eat();
                break;
            case 2:
                pet->makeSound();
                break;
            case 3:
                pet->displayInfo();
                break;
            case 4:
                t = 4;
                break;
        }
    }
}

int main() {
    std::string name;
    int age = 0, p = 0, t = 0;
    PetAdoptionCenter *center = nullptr;
    Pet *pet = nullptr;
    std::cout << "Welcome to the Virtual Pet Adoption Center!\n";
    std::cout << "Please chosse an option: \n1. Adopt a Domestic Pet\n2. Adopt a Wild Pet\n3. Exit\n";
    std::cin >> t;
    std::cout << "Enter pet name: ";
    std::getline(std::cin >> std::ws, name);    
    std::cout << "Enter pet age: ";
    std::cin >> age;
    switch(t) {
        case 1:
            std::cout << "|Selected Domestic| \n";
            center = center->getInstance(Domestic);
            std::cout << "Dog: 1\nParrot: 2\n";
            std::cin >> p;
            if (p == 1) {
                pet = center->getPointer()->createMammal(name, age);
            } else if (p == 2) {
                pet = center->getPointer()->createBird(name, age);
            }
            break;
        case 2:
            std::cout << "|Selected Wild| \n";
            center = center->getInstance(Wild);
            std::cout << "Lion: 1\nEagle: 2\n";
            std::cin >> p;
            if (p == 1) {
                pet = center->getPointer()->createMammal(name, age);
            } else if (p == 2) {
                pet = center->getPointer()->createBird(name, age);
            }
            break;
        case 3:
            return 0;
        default:
            std::cout << "Invalid input\n";
    }
    control(pet);
    delete pet;
    delete center;
    pet = nullptr;
    return 0;
}