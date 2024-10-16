#pragma once
#include "AddOnDecorator.h"

class Sugar : public AddOnDecorator {
public:
    Sugar(Beverage *beverage);
    std::string getDescription() const override;
    double cost() const override;
};