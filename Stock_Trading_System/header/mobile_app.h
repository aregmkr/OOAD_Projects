#pragma once
#include "observer.h"
#include "stock.h"


class Mobile_app : public Observer{
public:
    void update(Stock& stock, double price) override;
};