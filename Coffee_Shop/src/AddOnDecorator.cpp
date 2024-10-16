#include "../header/AddOnDecorator.h"

AddOnDecorator::AddOnDecorator(Beverage *beverage) : beverage_{beverage}{}

std::string AddOnDecorator::getDescription() const {
    return beverage_->getDescription();
}

double AddOnDecorator::cost() const {
    return beverage_->cost();
}

AddOnDecorator::~AddOnDecorator() {
    delete beverage_;
}