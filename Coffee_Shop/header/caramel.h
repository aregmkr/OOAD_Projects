#pragma once
#include "AddOnDecorator.h"

class Caramel : public AddOnDecorator {
public:
    Caramel(Beverage *beverage);
    std::string getDescription() const override;
    double cost() const override;
};