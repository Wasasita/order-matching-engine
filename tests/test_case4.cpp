#include "../src/OrderBook.h"
#include <cassert>
#include <iostream>

int main() {
    OrderBook book;
    book.addOrder({1, OrderType::BUY, 101.5, 10, 1});
    book.addOrder({2, OrderType::SELL, 100.5, 5, 2});
    book.addOrder({3, OrderType::SELL, 101.0, 5, 3});
    book.matchOrders();
    std::cout << "[TEST 4 PASSED] Example input scenario\n";
    return 0;
}
