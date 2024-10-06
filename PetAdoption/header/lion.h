#pragma once
#include "pet.h"

class Lion : public Pet {
public:
    explicit Lion(const std::string& name, int age);
    void makeSound() override;
    void eat() override;

    Lion(const Lion&) = delete;
    Lion(Lion&&) = delete;
    Lion& operator=(const Lion&) = delete;
    Lion& operator=(Lion&&) = delete;
    ~Lion() = default;
};