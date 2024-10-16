#pragma once
#include "AddOnDecorator.h"

class WhippedCream : public AddOnDecorator {
public:
    WhippedCream(Beverage *beverage);
    std::string getDescription() const override;
    double cost() const override;
};