#pragma once
#include <memory>

class Pet;

class AbstractPetFactory {
public:
    virtual Pet* createMammal(const std::string& name, int age) = 0;
    virtual Pet* createBird(const std::string& name, int age) = 0;
    virtual ~AbstractPetFactory() = default;
};