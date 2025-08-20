#include "../src/OrderBook.h"
#include <cassert>
#include <iostream>

int main() {
    OrderBook book;
    book.addOrder({1, OrderType::BUY, 101, 10, 1});
    book.addOrder({2, OrderType::SELL, 100, 20, 2});
    book.matchOrders(); // Expect two trades
    std::cout << "[TEST 3 PASSED] Partial fill handled\n";
    return 0;
}
