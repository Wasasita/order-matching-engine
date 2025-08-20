#pragma once
#include <string>

enum class OrderType { BUY, SELL };

struct Order {
    int id;
    OrderType type;
    double price;
    int quantity;
    long timestamp; // For price-time priority
};
