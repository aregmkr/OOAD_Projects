#pragma once
#include "pet.h"

class Parrot : public Pet {
public:
    explicit Parrot(const std::string& name, int age);
    void makeSound() override;
    void eat() override;

    Parrot(const Parrot&) = delete;
    Parrot(Parrot&&) = delete;
    Parrot& operator=(const Parrot&) = delete;
    Parrot& operator=(Parrot&&) = delete;
    ~Parrot() = default;
};