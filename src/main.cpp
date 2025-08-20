#include "OrderBook.h"
#include <iostream>
#include <chrono>

int main() {
    OrderBook book;
    int id = 1;
    std::string type;
    double price;
    int quantity;

    std::cout << "Order Matching Engine Started\n";
    std::cout << "Enter orders in format: BUY/SELL price quantity (or type EXIT to quit)\n";

    while (true) {
        std::cout << "> ";
        std::cin >> type;
        if (type == "EXIT") break;

        std::cin >> price >> quantity;

        OrderType oType = (type == "BUY") ? OrderType::BUY : OrderType::SELL;

        auto timestamp = std::chrono::system_clock::now().time_since_epoch().count();

        Order order{id++, oType, price, quantity, timestamp};
        book.addOrder(order);

        book.matchOrders();
    }

    return 0;
}
