#include "../header/WildPetFactory.h"

Pet* WildPetFactory::createBird(const std::string& name, int age) {
    return new Eagle(name, age);
}

Pet* WildPetFactory::createMammal(const std::string& name, int age) {
    return new Lion(name, age);
}