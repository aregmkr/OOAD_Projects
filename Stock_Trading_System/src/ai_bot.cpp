#include <iostream>
#include "../header/ai_bot.h"

void Ai_bot::update(Stock& stock, double price) {
    std::cout << "Stock: " << stock.getName() << " old price: " << stock.getPrice() << " new price: " << price << std::endl;
}