#pragma once
#include "beverage.h"
#include <iostream>

class Espresso : public Beverage {
public:
    std::string getDescription() const override;
    double cost() const override;
}; 