#pragma once
#include "observer.h"
#include "stock.h"

class Broker : public Observer{
public:
    void update(Stock& stock, double price) override;
};