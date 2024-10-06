#pragma once
#include "AbstractPetFactory.h"
#include "lion.h"
#include "eagle.h"

class WildPetFactory : public AbstractPetFactory {
public:
    Pet* createMammal(const std::string& name, int age) override;
    Pet* createBird(const std::string& name, int age) override;
};