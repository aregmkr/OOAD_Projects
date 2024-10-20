#include <iostream>
#include "../header/broker.h"

void Broker::update(Stock& stock, double price) {
    std::cout << "Stock: " << stock.getName() << " old price: " << stock.getPrice() << " new price: " << price << std::endl;
}