#include "../header/whippedCream.h"

WhippedCream::WhippedCream(Beverage *beverage) : AddOnDecorator(beverage) {}

std::string WhippedCream::getDescription() const {
    return beverage_->getDescription() + "+ Cream";
}

double WhippedCream::cost() const {
    return beverage_->cost() + 3;
}