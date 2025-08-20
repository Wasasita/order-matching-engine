#include "OrderBook.h"
#include <iostream>

// initializes the priority queues with custom comparators.
OrderBook::OrderBook()
    : bids([](const Order& a, const Order& b) {
        return (a.price < b.price) || (a.price == b.price && a.timestamp > b.timestamp);
    }),
      asks([](const Order& a, const Order& b) {
        return (a.price > b.price) || (a.price == b.price && a.timestamp > b.timestamp);
    }) {}

//   adds orders to bids or asks (with thread safety via
void OrderBook::addOrder(const Order& order) {
    std::lock_guard<std::mutex> lock(mtx);
    if (order.type == OrderType::BUY) {
        bids.push(order);
    } else {
        asks.push(order);
    }
}

// checks if top bid price ≥ top ask price, executes trades, adjusts quantities, prints results.
void OrderBook::matchOrders() {
    std::lock_guard<std::mutex> lock(mtx);
    while (!bids.empty() && !asks.empty() && bids.top().price >= asks.top().price) {
        auto buy = bids.top();
        auto sell = asks.top();
        bids.pop();
        asks.pop();

        int tradedQty = std::min(buy.quantity, sell.quantity);
        std::cout << "Trade executed: " << tradedQty << " @ " << sell.price << "\n";

        if (buy.quantity > tradedQty) {
            buy.quantity -= tradedQty;
            bids.push(buy);
        }
        if (sell.quantity > tradedQty) {
            sell.quantity -= tradedQty;
            asks.push(sell);
        }
    }
}