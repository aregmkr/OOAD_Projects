#pragma once
#include "AddOnDecorator.h"

class Mocha : public AddOnDecorator {
public:
    Mocha(Beverage *beverage);
    std::string getDescription() const override;
    double cost() const override;
};