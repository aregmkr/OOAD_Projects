#include "../header/sugar.h"

Sugar::Sugar(Beverage *beverage) : AddOnDecorator(beverage) {}

std::string Sugar::getDescription() const {
    return AddOnDecorator::getDescription() + " + Sugar ";
}

double Sugar::cost() const {
    return beverage_->cost() + 2;
}