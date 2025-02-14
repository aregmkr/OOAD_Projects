#include "../header/caramel.h"

Caramel::Caramel(Beverage *beverage) : AddOnDecorator(beverage) {}

std::string Caramel::getDescription() const {
    return beverage_->getDescription() + " + Caramel";
}

double Caramel::cost() const {
    return beverage_->cost() + 5;
}