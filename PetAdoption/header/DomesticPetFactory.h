#pragma once
#include "AbstractPetFactory.h"
#include "dog.h"
#include "parrot.h"

class DomesticPetFactory : public AbstractPetFactory {
public:
    Pet* createMammal(const std::string& name, int age) override;
    Pet* createBird(const std::string& name, int age) override;
};