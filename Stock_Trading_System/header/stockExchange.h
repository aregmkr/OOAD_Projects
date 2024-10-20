#pragma once
#include <vector>
#include <iostream>
#include "observer.h"
#include "stock.h"

class StockExchange {
public:
    void addObserver(Observer *observer, char c);
    void notify(Stock& stock, double price);
private:
    std::vector<Observer*> observersA;
    std::vector<Observer*> observersB;
    std::vector<Observer*> observersC;
    // std::vector<Stock> stocks_;
};