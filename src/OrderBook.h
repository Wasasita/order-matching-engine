#pragma once
#include "Order.h"
#include <queue>
#include <mutex>
#include <vector>
#include <functional>

// Holds two priority queues:
class OrderBook {
private:
    // bids (BUY orders, sorted by highest price first).
    // asks (SELL orders, sorted by lowest price first).
    std::priority_queue<Order, std::vector<Order>, std::function<bool(const Order&, const Order&)>> bids;
    std::priority_queue<Order, std::vector<Order>, std::function<bool(const Order&, const Order&)>> asks;
    std::mutex mtx;

public:
    OrderBook();
    void addOrder(const Order& order); // Adds a new order to the book.
    void matchOrders(); // Matches buy and sell orders when possible.
};
