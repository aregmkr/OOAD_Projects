#pragma once
#include "AddOnDecorator.h"

class Milk : public AddOnDecorator {
public:
    Milk(Beverage *beverage);
    std::string getDescription() const override;
    double cost() const override;
};