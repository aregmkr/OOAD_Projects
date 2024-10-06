#pragma once
#include "pet.h"

class Dog : public Pet {
public:
    explicit Dog(const std::string& name, int age);
    void makeSound() override;
    void eat() override;

    Dog(const Dog&) = delete;
    Dog(Dog&&) = delete;
    Dog& operator=(const Dog&) = delete;
    Dog& operator=(Dog&&) = delete;
    ~Dog() = default;
};