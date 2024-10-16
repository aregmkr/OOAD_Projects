#pragma once
#include <iostream>

class Beverage {
public:
    virtual ~Beverage() = default;

    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    // virtual void setDescription(const std::string& description) = 0;
    // virtual void setCost(double cost) = 0;
};