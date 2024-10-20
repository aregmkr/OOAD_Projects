#pragma once
#include <iostream>

class Stock {
public:
    Stock(const std::string& name, double price);
    ~Stock() = default;
    std::string getName() const;
    double getPrice() const;
    void setPrice(double price);
private:
    std::string name_;
    double price_;
};