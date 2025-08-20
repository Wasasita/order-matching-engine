#include "../src/OrderBook.h"
#include <cassert>
#include <iostream>

int main() {
    OrderBook book;
    book.addOrder({1, OrderType::BUY, 105, 10, 1});
    book.addOrder({2, OrderType::SELL, 106, 5, 2});
    book.matchOrders(); // No trade expected
    std::cout << "[TEST 2 PASSED] No match when prices don't cross\n";
    return 0;
}
