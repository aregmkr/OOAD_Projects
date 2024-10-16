#include <iostream>
#include "./header/beverage.h"
#include "./header/AddOnDecorator.h"
#include "./header/coffee.h"
#include "./header/milk.h"
#include "./header/caramel.h"
#include "./header/sugar.h"

void manage_beverage(Beverage *p) {
    int act = 0;
    while(act != 4) {
        std::cout << "Add Milk: 1\nAdd Sugar: 2\nAdd Caramel: 3\nExit: 4\n";
        std::cin >> act;
        switch(act) {
            case 1:
                p = new Milk(p);
                std::cout << p->getDescription() << std::endl;
                std::cout << "Cost: " << p->cost() << std::endl;
                break;
            case 2:
                p = new Sugar(p);
                std::cout << p->getDescription() << std::endl;
                std::cout << "Cost: " << p->cost() << std::endl;
                break;
            case 3:
                p = new Caramel(p);
                std::cout << p->getDescription() << std::endl;
                std::cout << "Cost: " << p->cost() << std::endl;
                break;
            case 4:
                break;
        }
    }
}

int main() {
    Beverage *p1 = new Coffee();
    manage_beverage(p1);
    delete p1;
    return 0;
}