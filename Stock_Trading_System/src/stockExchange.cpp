#include <iostream>
#include "stockExchange.h"

void StockExchange::addObserver(Observer* observer, const char c) {
    if (c == 'A') {
        observersA.push_back(observer);
    } else if (c == 'B') {
        observersB.push_back(observer);
    } else {
        observersC.push_back(observer);
    }
}

void StockExchange::notify(Stock& stock, double price) {
    if (price >= 10) {
        for (Observer* observer : observersA) {
            observer->update(stock, price);
        }
    }
    if (price >= 100) {
        for (Observer* observer : observersB) {
            observer->update(stock, price);
        }
    }
    if (price < 10) {
        for (Observer* observer : observersC) {
            observer->update(stock, price);
        }
    }
}
