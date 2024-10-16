#pragma once
#include <iostream>
#include "beverage.h"

class AddOnDecorator : public Beverage {
public:
    explicit AddOnDecorator(Beverage *beverage);
    virtual ~AddOnDecorator();

    std::string getDescription() const override;
    double cost() const override;
protected:
    Beverage *beverage_;
};