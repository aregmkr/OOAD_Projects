#include <iostream>
#include "../header/mobile_app.h"

void Mobile_app::update(Stock& stock, double price) {
    std::cout << "Stock: " << stock.getName() << " old price: " << stock.getPrice() << " new price: " << price << std::endl;
}