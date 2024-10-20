#include "../header/stock.h"
#include <iostream> 

Stock::Stock(const std::string& name, double price) : name_{name}, price_{price} {}

std::string Stock::getName() const {
    return name_;
}

double Stock::getPrice() const {
    return price_;
}

void Stock::setPrice(double price) {
    price_ = price;
}