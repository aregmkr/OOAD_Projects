#pragma once
#include "pet.h"

class Eagle : public Pet {
public:
    explicit Eagle(const std::string& name, int age);
    void makeSound() override;
    void eat() override;

    Eagle(const Eagle&) = delete;
    Eagle(Eagle&&) = delete;
    Eagle& operator=(const Eagle&) = delete;
    Eagle& operator=(Eagle&&) = delete;
    ~Eagle() = default;
};