#include "../header/milk.h"

Milk::Milk(Beverage *beverage) : AddOnDecorator(beverage) {}

std::string Milk::getDescription() const {
    return beverage_->getDescription() + " + Milk";
}


double Milk::cost() const {
    return beverage_->cost() + 1;
}