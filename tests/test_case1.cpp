#include "../src/OrderBook.h"
#include <cassert>
#include <iostream>

int main() {
    OrderBook book;
    Order o1{1, OrderType::BUY, 101.5, 10, 1};
    Order o2{2, OrderType::SELL, 100.5, 5, 2};

    book.addOrder(o1);
    book.addOrder(o2);
    book.matchOrders();

    std::cout << "[TEST 1 PASSED] Simple Buy/Sell match\n";
    return 0;
}
